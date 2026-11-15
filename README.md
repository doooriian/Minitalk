# Minitalk

> **42 School project** · C · UNIX signals · IPC

## Overview

A small client/server messaging application that transmits text using UNIX signals rather than sockets.

## Features

- Start a server process and display its PID
- Send messages from a client to a chosen server PID
- Encode and reconstruct message data through signals
- Separate mandatory and bonus client/server implementations

## Technical approach

The code is split between client and server programs; `SIGUSR1` and `SIGUSR2` are the transport mechanism. Signal handling and synchronization are the core of the exercise.

**Stack:** C · POSIX signals · Make.

## Build and usage

```bash
git clone https://github.com/doooriian/Minitalk.git
cd Minitalk
make
./server
```

In another terminal, replace `<server_pid>` with the PID shown by the server:

```bash
./client <server_pid> 'Hello, 42!'
```

Build separate bonus executables with `make bonus` (`server_bonus` and `client_bonus`).

## Verification

Build in the documented environment, exercise normal scenarios and edge cases, and compare actual behaviour with the expected output. No automated CI test suite is included in this repository.

## Notes and limitations

Signals are used as a learning exercise in inter-process communication; this is not a network chat service.

---

Part of the [42 curriculum](https://42.fr/). Explore the other projects on [my GitHub profile](https://github.com/doooriian).
