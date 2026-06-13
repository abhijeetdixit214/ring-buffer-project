# EmbedKit_AbhijeetDixit

## Overview

This project implements an 8-byte Circular Ring Buffer (FIFO) in C using uint8_t data type.

The ring buffer supports:
- Buffer Initialization
- Write Operation
- Read Operation
- Buffer Full Detection
- Buffer Empty Detection
- Buffer Count Tracking
- Circular Wrap-Around Functionality

## Project Structure

```text
EmbedKit_AbhijeetDixit/
│
├── main.c
├── ringbuf.c
├── ringbuf.h
└── README.md
```

## Features

- Fixed-size 8-byte buffer
- FIFO (First In First Out) behavior
- Efficient circular indexing
- Overflow protection
- Underflow protection
- Modular code structure

## Build Instructions

```bash
gcc -Wall -std=c99 main.c ringbuf.c -o ringbuf
```

## Run

```bash
./ringbuf
```

## Author

Abhijeet Dixit
