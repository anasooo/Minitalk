# Minitalk

Minitalk is a small data exchange program that demonstrates inter-process communication using UNIX signals (`SIGUSR1` and `SIGUSR2`).

## Features

- Server-client architecture
- Communication using only UNIX signals (`SIGUSR1` & `SIGUSR2`)
- Support for multiple client connections
- Fast and efficient string transmission
- Real-time string display on server

## Installation

```bash
git clone git@github.com:anasooo/Minitalk.git
cd Minitalk
make
```

## Usage

### Starting the Server

```bash
./server
```
The server will display its `PID` upon startup.

### Using the Client

```bash
./client [server_pid] [string_to_send]
```

Example:
```bash
./client 4242 "Hello, Server!"
```
