# Monty ByteCode Interpreter

The Monty ByteCode Interpreter is a program that reads and executes Monty ByteCode files, which are scripts written in the Monty scripting language. This interpreter allows you to manipulate a stack data structure with various operations.

## Table of Contents

- [Requirements](#requirements)
- [Usage](#usage)
- [Supported Opcodes](#supported-opcodes)
- [File Structure](#file-structure)

## Requirements

Before using the Monty ByteCode Interpreter, ensure that you meet the following requirements:

- Supported Editors: vi, vim, emacs
- Compilation: Ubuntu 20.04 LTS, gcc with options `-Wall -Werror -Wextra -pedantic`
- Files should end with a newline character
- A `README.md` file at the root of the project folder is mandatory
- Code should follow the Betty style (checked using `betty-style.pl` and `betty-doc.pl`)
- Maximum of one global variable allowed
- No more than 5 functions per file
- Allowed to use the C standard library
- Prototypes of all functions should be included in the header file `monty.h`
- Header files should be include guarded
- The program should be implemented in the order specified in the project

## Usage

To run the Monty ByteCode Interpreter, use the following command:

`./monty file`

- `global.h`: Header file defining the global variable for the stack.
- `monty.c`: Main program that reads and executes Monty ByteCode files.
- `monty.h`: Header file defining data structures, function prototypes, and opcodes.
- Opcode-specific files (e.g., `opcode_push.c`, `opcode_pall.c`, etc.): Implementations of individual opcodes.

Make sure to follow the project structure and requirements when working on the Monty ByteCode Interpreter.

For more information about the Monty scripting language and additional details about the project, please refer to the project's specific requirements.
