# Simple File Transfer Protocol (FTP) Implementation in C

This project provides a basic implementation of a File Transfer Protocol (FTP) using the C programming language. It consists of two programs: a client and a server, allowing users to transfer files between them over a network connection.

## Features

- **Download Images**: Allows users to connect to a server and download images from it.
- **Simple File Transfer**: Implements basic file transfer functionality for image files.

## Getting Started

### Prerequisites

- Ensure you have a C compiler installed on your system (e.g., GCC).

### Compilation

Compile the client and server programs using the provided Makefile:

```bash
make
```
## Usage
1. Server Setup:
  * Run the server program, providing the port number on which the server will listen for incoming connections.
     ```bash
     ./server <port>
     ```
     
2. Client Connection:
  * Run the client program, providing the IP address and port number of the server to connect to.
    ```bash
    ./client <server_ip_address> <server_port>
    ```
## File Structure
* **Client.c**: Source code for the FTP client program.
* **Server.c**: Source code for the FTP server program.
* **Makefile**: Makefile for compiling the client and server programs.
