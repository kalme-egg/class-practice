//すーぱー依存関係逆転マン
class AbstractJudgeClient {

  /**
     * @param {Array} files [{name: "main.cpp", code: "..."}, ...]
     * @param {string} stdin 標準入力
     * @returns {Promise<{status: string, message: string, output: string}>}
     */

  async submit(files, stdin) {
    throw new Error("Not implemented");
  }
}

class WandboxJudgeClient extends AbstractJudgeClient {
    async submit(files, stdin) {
        const mainFile = files.find(f => f.file === "main.cpp");
        const otherFiles = files.filter(f => f.file !== "main.cpp").map(f => ({
            file: f.file, code: f.code
        }));

        const compileStr = otherFiles.filter(f => f.file.split(".").at(-1) === "cpp").map(f => f.file).join("\n");
        console.log(compileStr);

        const res = await runOnWandbox(mainFile.code, {
            compiler: "gcc-head",
            codes: otherFiles,
            stdin: stdin,
            compiler_option_raw: compileStr
        });

        // Wandbox特有のレスポンスを、共通のフォーマットに変換して返す
        return {
            status: res.status === "0" ? "SUCCESS" : "ERROR",
            message: res.compiler_message || "",
            output: res.program_output || ""
        };
    }
}


async function runOnWandbox(code, options = {}) {
  const body = {
    compiler: options.compiler || "g++20",   // コンパイラ名（必須）
    code: code,                                  // 実行したいコード（文字列）
    codes: options.codes || [],
    options: options.options || "",              // コンパイラオプション（カンマ区切り）
    stdin: options.stdin || "",                  // 標準入力
    // 必要に応じて追加
    //ex -O3\n-DDEBUG
    "compiler-option-raw": options.compiler_option_raw || "",
    // "runtime-option-raw": "",
    // save: true,  // trueにするとpermlinkが返ってくる
  };

  const res = await fetch("https://wandbox.org/api/compile.json", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(body),
  });

  if (!res.ok) {
    throw new Error(`HTTP error! status: ${res.status}`);
  }

  const result = await res.json();
  console.log(result);
  return result;
}

// 使用例
// const code = `#include <iostream>
// int main() {
//     std::cout << "Hello Wandbox!" << std::endl;
//     return 0;
// }`;

// runOnWandbox(code, {
//   compiler: "gcc-head",
//   options: "warning,gnu++1y",
// }).then(result => {
//   console.log("出力:", result.program_output);
//   console.log("終了コード:", result.status);
// });
