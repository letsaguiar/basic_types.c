# Basic Types Library

Welcome to Basic Types, a lightweight and versatile C library providing fundamental data structures, including linked lists, stacks, queues, and dictionaries. libbt is designed for simplicity and efficiency, making it ideal for small to mid-sized C projects.

## Table of Contents
- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

---

## About

`libbt.a` (Basic Types) provides a set of essential data structures implemented in C with straightforward APIs for list, stack, queue, and dictionary operations. The library leverages POSIX for compatibility, offering a streamlined alternative to manually managing data structures in C.

## Features

- **Linked List**: Create, manipulate, and iterate through singly linked lists.
- **Stack**: Basic Last-In-First-Out (LIFO) operations.
- **Queue**: First-In-First-Out (FIFO) operations with efficient head and tail management.
- **Dictionary**: Key-value storage with basic hashing and collision handling.

---

## Installation

To install `libbt.a`, clone the repository, build the library, and include it in your project.

### Prerequisites
Ensure you have a C compiler (GCC recommended) and `make`.

### Building the Library

```bash
# Clone the repository
git clone https://github.com/letsaguiar/basic_types.c.git
cd basic_types.c

# Compile the library
make
```

This will generate `libbt.a`, which can then be linked to your projects.

## Cleaning Build Files
```bash
make clean
```

## Usage

To use `libbt.a` in your C project:

1. Include the header file in your source code:
```c
#include "basic-types.h"
```

2. Link `libbt.a` when compiling:
```bash
gcc your_program.c -L. -lbt -o your_program
```

## License
This project is licensed under the MIT License.