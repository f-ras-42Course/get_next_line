# Get Next Line

## Overview

**Get Next Line** is a project that adds an efficient line-reading function to your C toolbox. This function, `get_next_line()`, reads a line from a file descriptor and returns it. It is designed to handle repeated calls, returning a new line each time until the end of the file is reached. The project is also a great opportunity to explore concepts like **static variables** and effective **buffer management**.

This implementation has been optimized to:
- Handle various buffer sizes.
- Minimize redundant reads by using as few `read()` system calls as possible.
- Manage dynamic memory efficiently, freeing all allocated memory correctly.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Design Choices](#design-choices)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Testing](#testing)

---

## Features

- **Efficient Reading:** Reads from a file descriptor one line at a time, until EOF.
- **Customizable Buffer Size:** Users can set the buffer size using a compiler flag.
- **Memory Safety:** All dynamically allocated memory is freed properly.
- **Multiple File Descriptor Support:** (Bonus) Handles multiple file descriptors simultaneously without losing track of any.

---

## Design Choices

1. **Static Variable**: The use of static variables allows the function to retain its state across multiple invocations. This is critical to managing the reading position in the file between function calls.
   
2. **Minimal Reads**: Instead of reading the entire file or excessive amounts of data at once, the function reads just enough to find a line, ensuring optimal memory and performance usage.
   
3. **Edge Case Handling**: This implementation ensures that even with an extremely small buffer size (like 1 byte), the function behaves as expected, reading one character at a time without causing memory leaks or crashes.

4. **Dynamic Buffer Allocation**: Memory for each line is dynamically allocated and freed by the caller, giving the user flexibility in managing the resources.

---

## Mandatory Part

### Function Prototype
```c
char *get_next_line(int fd);
```

### Description
The `get_next_line()` function reads a line from a given file descriptor `fd`:
- **Returns a single line**: The function should return a single line, including the newline character `\n`, unless it’s the end of the file.
- **Repeated Calls**: Calling the function multiple times will return successive lines until the end of the file is reached.
- **Error Handling**: If there is an error or nothing left to read, the function returns `NULL`.

### Allowed Functions
- `read()`
- `malloc()`
- `free()`

### Compilation Example
Compile the project using the following command:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```
### Forbidden Functions
- `lseek()`
- Global variables
- Any functions from my `libft` library

---

## Bonus Part

If the mandatory part is perfectly completed, you can try the bonus features. These include:

- **Multiple File Descriptors**: The function can handle multiple file descriptors at once, maintaining the reading state for each. This allows the function to be called for different files alternately without losing track of the reading position.
  
- **Single Static Variable**: Implement the function using only one static variable, even when managing multiple file descriptors.

### Bonus Files
- `get_next_line_bonus.c`
- `get_next_line_utils_bonus.c`
- `get_next_line_bonus.h`

---

## Installation

To set up the project, clone the repository and compile the code using the provided `Makefile`. Ensure that you have a C compiler like `gcc` installed.

```bash
git clone https://github.com/f-ras-42Course/get_next_line.git
cd get_next_line
make
```

### Compilation with Custom Buffer Size
You can customize the buffer size by adding the `BUFFER_SIZE` definition during compilation:
```bash
make BUFFER_SIZE=128
```
---

## Usage

1. **Basic Usage**
   Once compiled, you can use `get_next_line()` in your C programs to read lines from any file descriptor (including standard input).

2. **Example Code**
   Here is a basic example demonstrating the use of `get_next_line()` in a loop:
   ```c
   #include "get_next_line.h"
   #include <fcntl.h>
   #include <stdio.h>

   int main(void)
   {
       int fd = open("example.txt", O_RDONLY);
       char *line;

       while ((line = get_next_line(fd)) != NULL)
       {
           printf("%s", line);
           free(line);
       }
       close(fd);
       return 0;
   }
   ```

3. **Edge Case Considerations**
   - Testing with small and large buffer sizes.
   - Handling empty files, files without a newline at the end, and binary files.
   - Standard input handling (`fd = 0`).

---

## Project Structure

```plaintext
get_next_line/
├── get_next_line.c          # Main function implementation
├── get_next_line_utils.c    # Helper functions
├── get_next_line.h          # Header file with prototypes
├── Makefile                 # Compilation rules
└── README.md                # Project documentation
```

---

## Testing

Creating a comprehensive set of tests is essential for validating the implementation. These tests should cover:

- Different buffer sizes: (`BUFFER_SIZE=1`, `BUFFER_SIZE=10000`).
- Files of varying line lengths, including very short and very long lines.
- Edge cases like empty files and files without newline at the end.

### Running Tests
You can test with custom buffer sizes using the command:
```bash
./your_program <file.txt>
```
---

Made by Ferry
