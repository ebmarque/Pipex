# Project README

## Pipex

This repository contains the Pipex project, developed as part of the curriculum at School 42. Pipex is a program that simulates the functionality of the shell command pipeline in Unix systems. It allows the user to redirect the output of one command as the input to another, effectively chaining multiple commands together.

## Introduction

Pipex is a fundamental project that aims to deepen understanding of Unix processes, file descriptors, and command execution. By implementing the pipeline functionality from scratch, this project provides an opportunity to gain insights into how commands are executed in a Unix environment.

The project consists of writing a program that takes four parameters: `file1`, `cmd1`, `cmd2`, and `file2`. It reads the input from `file1`, executes `cmd1` with the input as its standard input, redirects the output of `cmd1` as the input to `cmd2`, and finally saves the output of `cmd2` to `file2`.

## Installation

To use the Pipex project, follow these steps:

1. Clone the repository:
      ```shell
      git clone https://github.com/your-username/pipex.git](https://github.com/ebmarque/Pipex.git)

2. Change to the project directory:
      ```shell
      cd pipex

3. Compile the program:
      ```shell
      make

4. The Pipex executable will be created. You can then use it according to the usage instructions.

## Usage

To execute the Pipex program, use the following command:
      ```shell
      ./pipex file1 cmd1 cmd2 file2

Replace `file1` with the name of the input file, `cmd1` with the first command, `cmd2` with the second command, and `file2` with the output file name. The program will execute the commands and generate the desired output.

## Contributing

Contributions to the Pipex project are welcome. If you find any issues or have ideas for improvements, please feel free to submit a pull request or open an issue on the https://github.com/ebmarque/Pipex.git.

When contributing, please ensure that your code adheres to the existing code style and conventions. Provide clear and concise commit messages to facilitate the review process.
