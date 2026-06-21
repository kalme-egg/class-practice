class JudgeResult {
    constructor(status, message, output) {
        this.status = status;   // AC, WA, CE, RE
        this.message = message; // コンパイラメッセージ等
        this.output = output;   // 標準出力
    }
}

//すーぱー依存関係逆転マン
class AbstractJudgeClient {
  async submit(mainCode, otherFiles, inText, outText, lang) {
    throw new Error("Not implemented");
  }
}

class WandboxJudgeClient extends AbstractJudgeClient {
    async submit(mainCode, otherFiles, stdin, expectedOutput, lang) {
        const compiler = lang === "rust" ? "rust-head" : "gcc-head";
        const options = lang === "rust" ? "" : "warning,gnu++1y";

        const body = {
            compiler: compiler,
            options: options,
            code: mainCode,
            codes: otherFiles.map(f => ({ file: f.name, code: f.code })),
            stdin: stdin
        };

        const res = await fetch("https://wandbox.org/api/compile.json", {
            method: "POST", headers: { "Content-Type": "application/json" },
            body: JSON.stringify(body)
        });
        const data = await res.json();

        // コンパイルエラー
        if (data.status !== "0" && data.compiler_message) {
            return new JudgeResult("CE", data.compiler_message, "");
        }
        // 実行時エラー
        if (data.status !== "0" && data.program_error) {
              return new JudgeResult("RE", data.program_error, data.program_output || "");
        }

        const actualOut = (data.program_output || "").trim();
        const expectOut = (expectedOutput || "").trim();

        if (actualOut === expectOut) {
            return new JudgeResult("AC", "All testcases passed.", actualOut);
        } else {
            return new JudgeResult("WA", "Output mismatch.", actualOut);
        }
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
