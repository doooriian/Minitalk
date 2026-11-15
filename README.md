<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/minitalkm.png" width="125" alt="Minitalk 42 project badge" /></a>

# Minitalk

**Inter-process communication with Unix signals**

<img src="https://img.shields.io/badge/42%20School-Project-7C3AED?style=flat-square" alt="42 School project" />

</div>

---

## 🔎 Overview

**Minitalk** is an individual project at 42 School that challenges students to implement a simple yet robust communication system between processes using UNIX signals. In this project, a server process waits for incoming messages sent by a client process using `SIGUSR1` and `SIGUSR2` signals. The goal is to reliably transmit complete messages from the client to the server, handling data conversion and synchronization without using standard inter-process communication methods.

For the bonus part, I extended the project capabilities to handle more complex scenarios such as:
- **Enhanced communication protocol**: Allowing for larger and multibyte messages.
- **Reliable transmission**: Implementations to confirm message receipt and handle potential data loss.
- **Improved synchronization**: Managing the signal flow efficiently even with overlapping transmissions.

---

## ✨ Key Features

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

# Compile the bonus
make bonus

# Remove object files
make clean

# Remove object files and executable
make fclean

# Clean and recompile
make re

```

Start the server first, which will display its PID, ready to receive messages:

```bash
./server
How to Run the Client

In another terminal, run the client with the server PID and the message as arguments:

./client <SERVER_PID> "Your message here"

Example:

./client 12345 "Hello, 42 School!"
```
## 🧪 Testing

The implementation was thoroughly tested using multiple scenarios, including:

- Sending short and long messages.
- Handling multibyte characters.
- Simulating rapid consecutive messages to validate synchronization.
- **Bonus:** Stress tests for ensuring reliable transmission under heavy loads.

Additional custom scripts and tools were developed to simulate edge cases and verify the successful receipt of messages by the server.


## 📬 Contact

Feel free to reach out or contribute to this project on [GitHub](https://github.com/doooriian)!
