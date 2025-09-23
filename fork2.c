#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

	pid_t pid = fork();

	if (pid == 0) {
		printf("I'm the child with process id - %d\n", getpid());
	}
	else printf("I'm the parent with process id - %d and my child process has id - %d\n", getpid(), pid);
	
	return 0;
}

/*
The process being cloned by fork() is the calling process itself — the one that executes fork().

So if your program is compiled into, say, a.out and you run it from the shell:

The shell starts a.out as a process.

Inside a.out, when it calls fork(), the kernel clones the entire running process (a.out).

This includes:

Code (the program instructions).

Data and heap segments.

Stack (with a copy of the current execution state).

File descriptors (e.g., stdout).

After cloning:

The parent process is still the original a.out.

The child process is a new a.out process (same program image at the start).

That’s why both run the same code after fork(), but they diverge based on the return value of fork()

After fork(), both parent and child processes have a copy of the entire code, including the if-else.

But the if condition evaluates differently in each process:

In the child, fork() == 0 → true → executes the if block.

In the parent, fork() == 0 → false → executes the else block.

So yes, the parent has both if and else in its code, but it only executes the else part because for the parent fork() does not return 0.
*/
