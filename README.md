# Minitalk

## At first, some terminology:

## Processes in UNIX
### Definition:
A process is an instance of a program that is being executed. Each process has its own address space, memory, and resources allocated by the operating system.

### Key Attributes of a Process:
**Process ID (PID)**: A unique identifier assigned to each process.<br />
**Parent Process ID (PPID)**: The PID of the process that created (or spawned) this process.<br />
**User and Group ID**: Identifiers indicating the user and group ownership of the process.<br />
**Process State**: The current state of the process (running, sleeping, stopped, etc.).<br />
**Memory Layout**: Includes the stack, heap, text (code), and data segments.<br />

### Examples of Processes:
A web server (e.g., **httpd** or **nginx**)<br />
A shell (e.g., **bash** or **zsh**)<br />
A user application (e.g., a text editor like **vim**)<br />

## Signals in UNIX
### Definition:
Signals are a form of inter-process communication (IPC) used to notify processes that a specific event has occurred. Signals can be sent by the operating system, other processes, or the process itself.

### Common Signals:
**SIGINT (2)**: Interrupt signal, usually initiated by the user pressing Ctrl+C.<br />
**SIGTERM (15)**: Termination signal, used to politely ask a process to terminate.<br />
**SIGKILL (9)**: Kill signal, forcefully terminates a process without cleanup.<br />
**SIGSTOP (19)**: Stop signal, pauses the process execution.<br />
**SIGCONT (18)**: Continue signal, resumes a paused process.<br />

### Sending Signals:
From the command line using kill command:

```bash
kill -SIGTERM <PID>   # Sends SIGTERM to the process with the specified PID
kill -9 <PID>         # Sends SIGKILL to forcefully terminate the process
```

## Signal Handlers
### Definition:
A signal handler is a function that gets executed in response to a specific signal. When a process receives a signal, it can either:

**Perform the default action**: Predefined by the operating system (e.g., terminate on SIGINT).<br />
**Ignore the signal**: The signal will have no effect on the process.<br />
**Handle the signal**: Execute a custom function defined by the process.<br />

### Setting a Signal Handler:
You use the signal function to set a signal handler for a particular signal.
Example Code:

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Custom signal handler function
void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("Received SIGINT (Ctrl+C). Custom handler executed.\n");
    }
}

int main() {
    // Set the signal handler for SIGINT
    signal(SIGINT, handle_signal);

    // Infinite loop to keep the program running
    while (1) {
        printf("Running...\n");
        sleep(1); // Sleep for a second
    }

    return 0;
}
```
**Signal Handler Function**: **handle_signal** is a custom function that will be called when the **SIGINT** signal is received.<br />
**Setting the Handler**: **signal(SIGINT, handle_signal)** sets handle_signal as the handler for **SIGINT**.<br />
**Infinite Loop**: The program runs an infinite loop, printing "Running..." every second. When Ctrl+C is pressed, instead of terminating, the custom handler prints a message.<br />

## Summary
**Process**: An executing instance of a program.
**Signal**: A notification sent to a process to indicate an event.<br />
**Handler**: A function that defines how a process responds to a signal.<br />
These concepts are fundamental in UNIX programming and allow for effective control and communication between processes.<br />



