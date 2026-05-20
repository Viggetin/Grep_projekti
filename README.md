# Grep

A simplified C++ command-line implementation of the Unix `grep` utility. The program supports searching for a string in user-provided text or in a file, with several optional search modifiers.

## Usage

The program has three modes depending on the number of arguments provided.

### Interactive mode

```sh
./Grep
```

The program prompts for an input string and a search word, then reports whether the search word was found and at which position.

### File search

```sh
./Grep <search_word> <file>
```

Searches the given file line by line and prints every line that contains `<search_word>`.

### File search with options

```sh
./Grep <options> <search_word> <file>
```

Options can be combined into a single argument (e.g. `-lo`):

| Option | Description                                          |
|--------|------------------------------------------------------|
| `-l`   | Prefix each matching line with its line number       |
| `-o`   | Print the total number of matching lines at the end  |
| `-r`   | Reverse search — print lines that do NOT match       |
| `-i`   | Case-insensitive search                              |

**Example:**

```sh
./Grep -lo error logfile.txt
```

Prints all lines containing "error" with line numbers, followed by the total count.

## Building

The project uses CMake with C++20.

```sh
cmake -S . -B build
cmake --build build
./build/Grep
```

## Project Structure

| File                      | Description                                      |
|---------------------------|--------------------------------------------------|
| `main.cpp`                | Entry point; dispatches to the correct mode      |
| `functions.cpp`           | Implementation of all three search modes         |
| `main.h`                  | Includes and header guard                        |
| `CMakeLists.txt`          | CMake build configuration                        |
| `man_grep_plain_ASCII.txt`| Reference man page for standard Unix grep        |
