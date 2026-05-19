# C++ Modules

This repository contains my 42 C++ module exercises. Each exercise is stored in
its own directory, has its own `Makefile`, and is intended to be compiled
independently.

The projects follow the 42 C++ rules, including C++98 and strict compiler
warnings.

## Repository Layout

```text
.
|-- cpp00/
|-- cpp01/
|-- cpp02/
|-- cpp03/
|-- cpp04/
|-- cpp05/
|-- cpp06/
|-- cpp07/
|-- cpp08/
`-- cpp09/
```

Each module contains exercise folders such as `ex00`, `ex01`, `ex02`, and so
on. A typical exercise folder looks like this:

```text
cpp02/ex03/
|-- Makefile
|-- main.cpp
|-- Fixed.cpp
|-- Fixed.hpp
|-- Point.cpp
|-- Point.hpp
`-- bsp.cpp
```

## Modules

| Module | Exercises | Main topics |
| --- | --- | --- |
| `cpp00` | `ex00` - `ex02` | Namespaces, classes, member functions, stdio streams, initialization lists, static members |
| `cpp01` | `ex00` - `ex06` | Memory allocation, references, pointers, file streams, switch statements |
| `cpp02` | `ex00` - `ex03` | Orthodox Canonical Form, fixed-point numbers, operator overloading |
| `cpp03` | `ex00` - `ex03` | Inheritance, derived classes, constructors, destructors |
| `cpp04` | `ex00` - `ex03` | Polymorphism, abstract classes, interfaces, deep copies |
| `cpp05` | `ex00` - `ex03` | Exceptions, validation, forms, bureaucrats, class relationships |
| `cpp06` | `ex00` - `ex02` | Type conversion, serialization, runtime type identification |
| `cpp07` | `ex00` - `ex02` | Function templates, class templates, generic programming |
| `cpp08` | `ex00` - `ex02` | STL containers, iterators, algorithms, stack adaptation |
| `cpp09` | `ex00` - `ex02` | STL parsing projects, Bitcoin exchange data, RPN, merge-insert sort |

## Requirements

You need:

- A C++ compiler such as `c++`, `g++`, or `clang++`
- `make`
- A Unix-like shell

The exercises are built with C++98. Most Makefiles use:

```sh
-Wall -Wextra -Werror -std=c++98
```

## Build

Go into the exercise directory you want to test and run `make`:

```sh
cd cpp01/ex05
make
```

This creates the executable for that exercise in the same directory.

Common Makefile commands:

```sh
make        # build the exercise
make clean  # remove object files
make fclean # remove object files and the executable
make re     # rebuild from scratch
```

## Run Examples

Build and run `megaphone`:

```sh
cd cpp00/ex00
make
./megaphone "hello world"
```

Build and run `harl`:

```sh
cd cpp01/ex05
make
./harl
```

Build and run the Bitcoin exchange exercise:

```sh
cd cpp09/ex00
make
./btc infile.txt
```

Build and run the RPN exercise:

```sh
cd cpp09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

Build and run the merge-insert sort exercise:

```sh
cd cpp09/ex02
make
./PmergeMe 3 5 9 7 4
```

## Notes

- Each exercise should be built from inside its own directory.
- Some generated files, object files, and local executables may appear while
  testing. Use `make fclean` in the relevant exercise directory to remove them.
- The repository currently contains modules from `cpp00` through `cpp09`.
- This is a learning repository, so exercises may be updated as I review and
  improve the code.

## Useful Commands

Build one exercise:

```sh
cd cppXX/exXX
make
```

Clean one exercise:

```sh
cd cppXX/exXX
make fclean
```

Find every Makefile:

```sh
find . -name Makefile
```
