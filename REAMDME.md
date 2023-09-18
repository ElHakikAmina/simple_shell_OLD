# Simple Shell

## Introduction
This repository is an ALX SE School Project aimed at creating a shell similar to the Bourne Shell (sh) by Stephen Bourne, written in **C**. Instead of relying on an extensive set of standard library functions, we've chosen to employ custom functions developed over the past three months. You can find our custom functions [here](https://github.com/ElHakikAmina/alx-low_level_programming/) and [here](https://github.com/Mehdibe04/alx-low_level_programming/).

The primary objective of this project is to gain a deep understanding of how a shell operates. Key areas of focus include comprehending the concept of the *environment*, distinguishing between *functions* and *system calls*, and mastering the creation of *processes* using `execve`.

## Usage
To run this program:

1. Clone this repository:

```shell
git clone https://github.com/ElHakikAmina/simple_shell
```

2. Compile it using the following command:

```shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

3. Run it by invoking:

```shell
./hsh
```

### How to Use It
To utilize this shell, open a terminal and execute the following command:

```shell
prompt$ ./hsh
```

This will display a simple prompt, waiting for your commands:

```shell
$ 
```

You can enter commands in the format $ command. The shell supports two types of commands: built-ins and normal programs.

### List of Built-ins
The built-ins we have implemented include:

* cd [directory]: Change to the specified directory (path).
* env: Display environment variables.
* exit [exitstatus]: Terminate the program with an exit status (default is 0).
* getenv NAME: Retrieve the value of the specified environmental variable.
* help [command]: Show the syntax for a specific command or list all available commands.
* history: Display the most recent user commands.
* echo [$$] or [$?] or [$PATH]: Return the process ID, exit status, and PATH.

### Command
The shell can handle various types of commands:

* Single-word commands like ls.
* Commands with paths like ls /tmp.
* Commands with options like ls -l.
* Commands with both paths and options like ls -l /var.
* Command paths like /bin/ls with options and paths like /bin/ls -l /var.
* It also supports comments indicated by #.

### Additional Features
The shell has the following additional features:

* Ctrl+C handling: The shell won't exit when the user inputs ^C.
* If no argument is provided for cd, it will interpret it as cd $HOME.
* Support for cd - to switch to the previous directory.
* Variable replacement, including $? and $$.
* The ability to execute command files, e.g., ./hsh test, where test contains commands and built-ins.

### List of Functions and System Calls Used
Here's a list of allowed functions and system calls employed in this project:

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* fork (man 2 fork)
* free (man 3 free)
* fstat (man 2 fstat)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* kill (man 2 kill)
* lstat (man 2 lstat)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (man 2 stat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
* _exit (man 2 _exit)

To access additional details about these functions, consult the respective manual pages.
kjwj

The project reached completion within a span of 15 days.

## Authors
* El Hakik Amina (GitHub: ElHakikAmina / Email: amina.el.hakik2@gmail.com)
* Belaazri El Mehdi (GitHub: Mehdibe04 / Email: belaazrielmehdi@gmail.com)
