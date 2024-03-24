<p align="center">
  <img src="img/gnl.png" width="70%"/>
</p>

## 🚀 SYNOPSIS

The `get_next_line` project at 42 school challenges students to implement a function that reads a line from a file descriptor.

This project delves into file I/O and dynamic memory allocation in the C language, requiring students to handle various edge cases and efficiently manage memory.

Successful completion of the get_next_line project demonstrates proficiency in input/output operations and memory management, providing a practical understanding of handling file reading scenarios in C.

This project serves as a fundamental exploration of reading data from file descriptors and managing dynamic memory in the context of C programming.

## 🛠️ FUNCTION PROTOTYPES

`char *get_netx_line(int fd)`

## ⚙️ USAGE

### Step 1 :

Run in your shell environment :

```bash
git clone https://github.com/maitreverge/get_next_line.git get_next_line && cd get_next_line
```

### Step 2 :

Create a file with with some ✨ orginal ✨ content in it :
```bash
touch lorem_ipsum && chmod 666 lorem_ipsum && echo  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Porttitor massa id neque aliquam vestibulum morbi blandit cursus. Vitae et leo duis ut diam quam nulla. Et malesuada fames ac turpis egestas maecenas. Arcu bibendum at varius vel. Urna nec tincidunt praesent semper. Ut ornare lectus sit amet est placerat in egestas erat. Eu lobortis elementum nibh tellus. Et molestie ac feugiat sed lectus vestibulum mattis ullamcorper velit. Id venenatis a condimentum vitae sapien. Enim neque volutpat ac tincidunt vitae semper quis lectus. Hac habitasse platea dictumst quisque sagittis purus. Pretium fusce id velit ut tortor pretium viverra suspendisse potenti. Ac turpis egestas integer eget aliquet nibh praesent." > lorem_ipsum
```

### Step 3 : Create a `main.c` function.

```c
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

char *get_next_line(int fd);

int main(void)
{
  // opens up a file descriptor from which get_next_line will access and read the file.
  int fd = open("lorem_ipsum", O_RDONLY);
  // The buffer in which we'll store the current line
  char *master_buffer;

  while (1)
  {
    master_buffer = get_next_line(fd);
    if (master_buffer == NULL)
	    break;
    printf("%s", master_buffer); // prints the current line from `fd`.
    free(master_buffer);
  }
  if (master_buffer)
	  free(master_buffer);
  // don't forget to close the opened fd from `read` function.
  close (fd);
}

```

### Step 4 : Compilation.

```bash
gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl && ./gnl
```

You should now see on your terminal the actual `lorem_ipsum` file read by get_next_line.



## 🤝 CONTRIBUTION
Contributions are open, make a pull request or open an issue 🚀
