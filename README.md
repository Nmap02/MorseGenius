# MorseGenius Program

MorseGenius is a command-line program written in C that allows you to convert text to Morse code and vice versa. It also supports batch conversion of text files to Morse code files and vice versa. This program uses a dictionary to map characters to their corresponding Morse code representations and provides a user-friendly interface for interaction.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Features](#features)
- [Dictionary](#dictionary)
- [Compilation](#compilation)
- [Contributing](#contributing)
- [License](#license)

## Introduction

MorseGenius provides a simple and efficient way to convert text and Morse code in various formats. You can convert individual text and Morse code inputs or process entire text files and Morse code files.

## Usage

1. Run the program using a C compiler. The program will present you with a menu:

```
[1] Morse -> Text
[2] Morse File -> Text File
[3] Text -> Morse
[4] Text File -> Morse File
[0] Exit

[?] Choose an option:
```

2. Choose an option by entering the corresponding number and pressing Enter.

## Features

- **Morse -> Text Conversion:** Converts Morse code to plain text.
- **Morse File -> Text File Conversion:** Processes an input Morse code file and generates a corresponding text file.
- **Text -> Morse Conversion:** Converts text to Morse code.
- **Text File -> Morse File Conversion:** Processes an input text file and generates a corresponding Morse code file.
- **Interactive Menu:** User-friendly menu-driven interface for easy interaction.

## Dictionary

The program uses a dictionary that maps characters to their Morse code representations. The dictionary contains both uppercase letters, numbers, and a space character, along with their respective Morse code equivalents.

## Compilation

Compile the program using a C compiler (e.g., GCC) as follows:

```bash
gcc -o morsegenius morsegenius.c
```

## Contributing

Contributions to MorseGenius are welcome! If you find any bugs or want to enhance the program's features, feel free to create a pull request.

## License

MorseGenius is released under the [MIT License](LICENSE). You can use, modify, and distribute the code as per the terms of the license.

---
