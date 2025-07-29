# CS-420 Project README
## Project Overview
CS-420 is a compiler development project focused on implementing lexical analysis, parsing, and code generation for custom programming languages. The core functionality includes:
- Lexical analysis using Lex (`.l` files)
- Syntax parsing with Yacc/Bison (`.c` files)
- Target code generation for multiple platforms (Linux/macOS/Windows)
- Support for both standard coursework assignments and personal experimentation
The project contains multiple submodules for different homework assignments and experimental implementations.
## File Structure
.
├── Homework-5
│   ├── ClassExample
│   └── PersonalExperiment
│
├── Week1-SimpleCompiler
│   ├── .vscode
│   ├── Class_Example
│   │   ├── Linux_Version
│   │   ├── Windows_Version
│   │   └── macOS_Version
│   └── Homework
│
├── .sample
├── .c
├── .main
├── .HEAD
├── .json
├── .target
├── .s
├── .myscanner
├── .l
├── .h
├── .rev
├── .pdf
├── .packed-refs
├── .pack
├── .index
├── .in
├── .idx
├── .fe890118ba1860004e961568bf44b15aa6f400
├── .f3acd788d40fff4d1d024d35347883e1de2b72
└── .exclude
## Installation
1. Clone the repository
2. Install dependencies:
   ```bash
   sudo apt-get install flex bison g++
   ```
3. Configure environment variables for cross-compilation (if needed)
## Usage
1. Compile the lexical analyzer:
   ```bash
   flex -o scanner.c scanner.l
   ```
2. Build the parser:
   ```bash
   bison -d -o parser.c parser.y
   ```
3. Compile the target code:
   ```bash
   gcc -o compiler main.c scanner.c parser.c -lm
   ```
4. Run the compiler:
   ```bash
   ./compiler inputfile
   ```
## Dependencies
- GNU Flex (for lexical analysis)
- GNU Bison (for syntax parsing)
- GCC compiler suite
- Standard C library (libc)
## Contribution Guidelines
- Submit bug reports via GitHub Issues
- Propose new features with detailed specifications
- Pull requests should include:
  - Clear commit messages
  - Documentation updates
  - Automated test cases
  - Compatibility checks across platforms
## Development Notes
- The project contains multiple submodules for different homework assignments
- Platform-specific implementations are separated by OS type
- Experimental code is contained in the `PersonalExperiment` directory
- All source files follow standard C programming practices

---

## 中文版本

# CS-420 项目文档
## 项目简介
## 安装方式
1. 确保系统安装 C 编译器（如 `gcc`）
2. 安装 Lex/Yacc 工具链（用于生成词法/语法分析器）
3. 克隆项目仓库后，直接编译对应模块的 `.c` 文件
## 使用方法
1. 编译词法分析器：  
   ```bash
   flex ClassExample/Linux_Version/lexer.l
   gcc -o lexer ClassExample/Linux_Version/lexer.c
   ```
2. 运行编译器主程序：  
   ```bash
   ./Homework/your_compiler_entry_point
   ```
3. 查看实验报告：  
   `Homework-5/PersonalExperiment/` 目录包含实验文档与实现说明
## 项目结构说明
.
├── Homework-5
│   ├── .vscode
│   ├── ClassExample
│   ├── PersonalExperiment
├── Week1-SimpleCompiler
│   ├── .vscode
│   ├── Class_Example
│   │   ├── Linux_Version
│   │   ├── Windows_Version
│   │   └── macOS_Version
│   └── Homework
├── .sample
├── .c
├── .main
├── .json
├── .target
├── .s
├── .myscanner
├── .l
├── .h
├── .rev
├── .pdf
└── .index
## 依赖项
- C 编译器（gcc/clang）
- Lex 工具（flex）
- Yacc 工具（bison）
- 标准 C 库（libc）
## 开发与贡献指南
1. 代码规范：遵循标准 C 语言编码规范，注释采用 Doxygen 格式
2. 提交规范：提交前运行 `make check` 验证代码规范性
3. 问题报告：通过 `Homework-5/PersonalExperiment/issue_report.md` 提交问题
4. 贡献流程：  
   - Fork 项目仓库  
   - 创建功能分支  
   - 提交代码变更  
   - 开发者接受后合并至主分支
