<br />
<p align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1200px-42_Logo.svg.png" alt="42 Logo" width="250" height="250">
  </a>

  <h1 align="center">Minitalk</h1>

  <p align="center">
    A messaging project from 42 School based on inter-process communication using signals.
    <br /><br />
    <img src="https://github.com/doooriian/42-Badges/blob/main/badges/minitalkm.png" alt="Minitalk Bonus Badge" width="150">
  </p>
</p>

<p align="center">
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/doooriian/Minitalk?color=1A237E" />
  <img alt="Code language count" src="https://img.shields.io/github/languages/count/doooriian/Minitalk?color=00BCD4" />
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/doooriian/Minitalk?color=7B1FA2" />
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/doooriian/Minitalk?color=D32F2F" />
</p>

---

## ✨ Overview

**Minitalk** is an individual project at 42 School that challenges students to implement a simple yet robust communication system between processes using UNIX signals. In this project, a server process waits for incoming messages sent by a client process using `SIGUSR1` and `SIGUSR2` signals. The goal is to reliably transmit complete messages from the client to the server, handling data conversion and synchronization without using standard inter-process communication methods.

For the bonus part, I extended the project capabilities to handle more complex scenarios such as:
- **Enhanced communication protocol**: Allowing for larger and multibyte messages.
- **Reliable transmission**: Implementations to confirm message receipt and handle potential data loss.
- **Improved synchronization**: Managing the signal flow efficiently even with overlapping transmissions.

---

## 📑 Key Features

- **Signal-Based Communication**: Uses UNIX signals (`SIGUSR1` and `SIGUSR2`) to transmit data bit by bit.
- **Server-Client Architecture**: 
  - **Server**: Continuously listens for incoming signals and reconstructs messages.
  - **Client**: Converts the message into binary format and sends it to the server.
- **Bonus Implementations**:
  - Support for extended messaging, ensuring that the entire message is reliably transmitted.
  - Implemented acknowledgement signals for improved synchronization between client and server.
- **Error Handling**: Robust error handling to manage unexpected signals and invalid inputs.

---

## 🛠️ Technologies Used

- **[C](https://devdocs.io/c/)** — Core programming language.
- **[Makefile](https://www.gnu.org/software/make/manual/make.html)** — Build automation tool.
- **[UNIX Signals](https://www.math.stonybrook.edu/~ccc/dfc/dfc/signals.html)** — For inter-process communication.

---

## 🚀 How to Build and Run

Clone the repository and use the following commands in your terminal:

```bash
# Compile the project
make all

# Remove object files
make clean

# Remove object files and executable
make fclean

# Clean and recompile
make re
