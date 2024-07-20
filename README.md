# Minitalk

# At first, some terminology:

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

# Now, let's break down the allowed functions mentioned in subject:
## `signal`
#### Purpose
To set a handler for a signal.
#### Prototype
```c
void (*signal(int signum, void (*handler)(int)))(int);
```
#### Parameters
* **`signum`**: Signal number.<br />
* **`handler`**: Pointer to the signal handling function.<br />
#### Return value
* Previous signal handler, or SIG_ERR on error.


## `sigemptyset`
#### Purpose
The `sigemptyset` function is used in UNIX-like operating systems to initialize a signal set to exclude all signals. A signal set is a data structure used to represent a group of signals. 
#### Prototype
```c
int sigemptyset(sigset_t *set);
```
#### Parameters
* **`set`**: A pointer to a sigset_t data structure that represents the signal set to be initialized.
#### Return value
* Returns 0 on success.
* Returns -1 on failure and sets `errno` to indicate the error.


## `sigaddset`
#### Purpose
The `sigaddset` function is used in UNIX-like operating systems to add a specific signal to a signal set. A signal set is a data structure used to represent a group of signals. Adding a signal to a set means that the signal will be part of the set and can be managed (blocked, unblocked, or checked) by various signal handling functions.
#### Prototype
```c
int sigaddset(sigset_t *set, int signum);
```
#### Parameters
* **`set`**: A pointer to a sigset_t data structure that represents the signal set to which a signal will be added.
* **`signum`**: The signal number to be added to the signal set. Signal numbers are defined in `<signal.h>` and typically start with `SIG`, such as `SIGINT`, `SIGTERM`, `SIGKILL`, etc.
#### Return value
* Returns 0 on success.
* Returns -1 on failure and sets `errno` to indicate the error.


## `sigaction`
#### Purpose
The `sigaction` function is used to change the action taken by a process on receipt of a specific signal. It is more powerful and flexible than the older `signal` function, providing better control over signal handling and ensuring portability across different UNIX-like systems.
#### Prototype
```c
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```
#### Parameters
* **`signum`**: The signal number for which the action is to be changed. Signal numbers are defined in `<signal.h>` and typically start with `SIG`, such as `SIGINT`, `SIGTERM`, `SIGKILL`, etc.
* **`act`**: A pointer to a `struct sigaction` that specifies the new action for the signal.
* **`oldact`**: A pointer to a `struct sigaction` that, if not `NULL`, is used to return the previous action for the signal.

#### `struct sigaction`
The struct sigaction structure specifies the action to be associated with a signal and has the following members:
```c
struct sigaction {
    void (*sa_handler)(int);      // Pointer to signal-catching function or one of the special values SIG_IGN or SIG_DFL
    void (*sa_sigaction)(int, siginfo_t *, void *); // Pointer to a signal-catching function that takes three arguments
    sigset_t sa_mask;             // Set of signals to be blocked during execution of the signal-catching function
    int sa_flags;                 // Flags modifying the behavior of the signal
    void (*sa_restorer)(void);    // (Unused) Pointer to a function to restore context after the signal handler returns
};
```
##### Structure members explanation
* **sa_handler**: Specifies the action to be associated with the signal. It can be a pointer to a signal-catching function, or one of the special values `SIG_IGN` (to ignore the signal) or `SIG_DFL` (to set the default action).
* **sa_sigaction**: An alternate signal-catching function that takes three arguments. This member is used if the `SA_SIGINFO` flag is set in `sa_flags`.
* **sa_mask**: Specifies a set of signals to be blocked during execution of the signal-catching function. This can be used to prevent other signals from interrupting the handler.
* **sa_flags**: A set of flags that modify the behavior of the signal. Common flags include:
* * `SA_RESTART`: Automatically restart certain interrupted system calls.
  * `SA_SIGINFO`: Use sa_sigaction instead of sa_handler for the signal-catching function.
  * `sa_restorer`: Unused in modern systems, reserved for future use or compatibility.
#### Return value
* Returns 0 on success.
* Returns -1 on failure and sets `errno` to indicate the error.

## `kill`
#### Purpose
The `kill` function is used to send a signal to a process or a group of processes. It can be used to notify a process to perform a specific action, such as terminating or reloading its configuration. Despite its name, `kill` can send any signal, not just signals that terminate a process.
#### Prototype
```c
int kill(pid_t pid, int sig);
```
#### Parameters
* **`pid`**: Specifies the process or process group to which the signal should be sent.
* * **`pid > 0`**: The signal is sent to the process with the PID equal to `pid`.
  * **`pid == 0`**: The signal is sent to all processes in the process group of the sender.
  * **`pid < -1`**: The signal is sent to all processes in the process group with a process group ID equal to the absolute value of pid.
  * **`pid == -1`**: The signal is sent to all processes that the sender has permission to send signals to, except for process 1 (init).
* **`sig`**: Specifies the signal to be sent. Signal numbers are defined in `<signal.h>` and typically start with `SIG`, such as `SIGINT`, `SIGTERM`, `SIGKILL`, etc.
#### Return value
* Returns 0 on success.
* Returns -1 on failure and sets `errno` to indicate the error.
#### Common Errors
* `EINVAL`: The signal specified is invalid.
* `EPERM`: The process does not have permission to send the signal to the target process.
* `ESRCH`: The target process or process group does not exist.
#### Example Usage
Here is an example demonstrating how to use the kill function to send a SIGTERM signal to a specific process:
```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid = (pid_t)atoi(argv[1]);

    // Send SIGTERM to the specified process
    if (kill(pid, SIGTERM) != 0) {
        perror("kill");
        exit(EXIT_FAILURE);
    }

    printf("Sent SIGTERM to process %d\n", pid);

    return 0;
}
```


## `getpid`
#### Purpose
The `getpid` function is used to obtain the process ID (PID) of the calling process. This unique identifier is used by the operating system to manage and control processes.
#### Prototype
```c
pid_t getpid(void);
```
#### Parameters
The getpid function takes no parameters.
#### Return value
Returns the PID of the calling process.
#### Example Usage
Here is an example demonstrating how to use the getpid function to obtain and print the PID of the calling process:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    // Obtain the PID of the current process
    pid_t pid = getpid();

    // Print the PID
    printf("The PID of this process is %d\n", pid);

    return 0;
}
```


## `pause`
#### Purpose
The `pause` function is used to suspend the execution of the calling process until a signal is received. It is typically used in scenarios where a process needs to wait for a signal to continue execution.
#### Prototype
```c
int pause(void);
```
#### Parameters
The pause function takes no parameters.
#### Return Value
The function always returns -1.
errno is set to `EINTR` (indicating that the call was interrupted by a signal).
#### Example Usage
Here is an example demonstrating how to use the pause function to suspend a process until a signal is received:
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Caught signal %d (SIGINT)\n", sig);
}

int main() {
    // Set up the signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    printf("Waiting for SIGINT (press Ctrl+C)...\n");

    // Suspend the process until a signal is received
    pause();

    printf("Pause returned, process continuing...\n");

    return 0;
}
```
The `pause` function suspends the calling process until a signal is received by relying on the fundamental behavior of the operating system's signal handling mechanism. Here's how it works:

##### Suspension Mechanism:
When pause is called, the operating system puts the calling process in a "sleep" state, meaning the process will not consume any CPU resources while it is suspended.
The process remains in this suspended state until it receives a signal.
##### Signal Handling:
A signal is an asynchronous notification sent to a process to notify it of an event (e.g., `SIGINT` when the user presses Ctrl+C).
When a signal is delivered to the process, the operating system temporarily interrupts the process's current state, runs the appropriate signal handler (if one is set), and then resumes the process's execution.
##### Resuming Execution:
After the signal handler completes execution (or if the signal has the default action), the pause function returns.
pause always returns with an error (-1) and sets errno to EINTR, indicating the function was interrupted by a signal.







