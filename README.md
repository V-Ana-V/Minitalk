# Minitalk

## At first, some terminology:

### Processes in UNIX
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

Signals in UNIX
Definition:
Signals are a form of inter-process communication (IPC) used to notify processes that a specific event has occurred. Signals can be sent by the operating system, other processes, or the process itself.

Common Signals:

SIGINT (2): Interrupt signal, usually initiated by the user pressing Ctrl+C.
SIGTERM (15): Termination signal, used to politely ask a process to terminate.
SIGKILL (9): Kill signal, forcefully terminates a process without cleanup.
SIGSTOP (19): Stop signal, pauses the process execution.
SIGCONT (18): Continue signal, resumes a paused process.
Sending Signals:

From the command line using kill command:

```
kill -SIGTERM <PID>   # Sends SIGTERM to the process with the specified PID
kill -9 <PID>         # Sends SIGKILL to forcefully terminate the process
```


