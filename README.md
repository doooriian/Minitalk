<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/minitalkm.png" alt="Minitalk 42 badge" width="125" /></a>

# Minitalk

**42 School project · Inter-process messaging with Unix signals**

<img src="https://img.shields.io/badge/42_Project-C%20%7C%20IPC-7C3AED?style=flat-square" alt="Minitalk technology" />
<img src="https://img.shields.io/badge/Documentation-Project_Overview-334155?style=flat-square" alt="Project documentation" />

</div>

## 🔎 Overview

A small client/server messaging application that transmits text using UNIX signals rather than sockets.

## ✨ Features

- Start a server process and display its PID
- Send messages from a client to a chosen server PID
- Encode and reconstruct message data through signals
- Separate mandatory and bonus client/server implementations

## 🧩 Technical approach

The code is split between client and server programs; `SIGUSR1` and `SIGUSR2` are the transport mechanism. Signal handling and synchronization are the core of the exercise.

> **Tech stack** · C · POSIX signals · Make.

## 🚀 Build and usage

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

## 🧪 Verification

Build in the documented environment, exercise normal scenarios and edge cases, and compare actual behaviour with the expected output. No automated CI test suite is included in this repository.

## ⚠️ Notes and limitations

Signals are used as a learning exercise in inter-process communication; this is not a network chat service.

---

<div align="center">

<sub>Part of the <a href="https://42.fr/">42 curriculum</a> · <a href="https://github.com/doooriian">Back to my GitHub profile</a></sub>

</div>
