# Get Next Line

> A 42 project to implement a function that reads a line from a file descriptor, one call at a time.

## 📚 Description

The **get_next_line** project is designed to create a C function that reads one line at a time from a file descriptor, handling buffer memory and partial reads efficiently. It must support multiple file descriptors simultaneously and avoid data loss between function calls.

This function is essential when dealing with file reading, sockets, or standard input in low-level programming.

---

## 🧠 Rules & Constraints

- You may only use a limited set of C standard library functions.
- The code must follow the **42 coding style**.
- Your project:
  - Must return a full line including `\n`, if present.
  - Should return `NULL` if there's nothing more to read or if an error occurs.
- You can use **a maximum of 5 helper functions**.
- The `get_next_line` function must be the **only** function in the `get_next_line.c` file.

---

## 🧪 Function Prototype

```c
char *get_next_line(int fd);
```

- `fd`: File descriptor to read from.
- Returns: A pointer to the next line read, or `NULL` if EOF is reached or an error occurs.

---

## ⚙️ How to Use

1. Compile your files into an executable or link them in your project:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

> Replace `42` with the buffer size you want to test.

2. Example usage in C:

```c
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
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

---

## 🛠️ Files

| File                  | Description                        |
|-----------------------|------------------------------------|
| `get_next_line.c`     | Main function implementation       |
| `get_next_line.h`     | Header file with prototypes/macros |
| `get_next_line_utils.c` | Helper functions                  |

---

## 🧪 Bonus (if applicable)

If you're doing the bonus part, your function should also be able to:

- Handle **multiple file descriptors** at the same time.
- Avoid memory leaks and unnecessary copies.

---

## 📦 Notes

- Make sure your code handles edge cases, like:
  - Empty lines
  - Files without a trailing newline
  - Invalid file descriptors
- Run your tests with various `BUFFER_SIZE` values!

---

## 📜 License

This project is part of the 42 school curriculum and follows its academic policies.
