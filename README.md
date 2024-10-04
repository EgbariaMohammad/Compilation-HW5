# FanC Coding Langauge Code Generator

This repository contains a code generator that transforms FanC (a C-like demo language) code into LLVM. 
The repository was created as part of the Compilation Theory course at the Technion and constituted 12% of my final grade.

## Description

FanC is a C-like coding language that we defined during the course, with the goal of implementing its compiler. The build process was divided into three steps:

1. **Lexical Analysis**: For the first assignment of the course (2% of the final grade), we defined the language by declaring appropriate tokens using Flex.

2. **Syntax & Semantic Analysis**: In the second assignment (6% of the final grade), we defined the Context-Free Grammar (CFG) of the language and implemented the syntax and semantic analysis using Bison.

3. **Code Generation**: For the third and final assignment (this one, 12% of the final grade), we implemented a code generator that translated the code into LLVM code that can be executed.

Achieved a grade of 100 in all three assignments.


## Disclaimer

This code is provided as is for educational purposes and as a reference. The author is not responsible for any consequences, including but not limited to academic misconduct, that may arise from inappropriate use of this code. It is the user's responsibility to abide by their institution's academic integrity policies. Copying this code and using it without understanding or crediting the source may be considered plagiarism by your institution.

## Authors

@EgbariaMohammad
