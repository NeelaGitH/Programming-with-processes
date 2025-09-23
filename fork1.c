#include <stdio.h>
#include <unistd.h>

int main(){

	if (fork() == 0) {
		printf("I'm the child with process id - %d\n", getpid());
	}
	else printf("I'm the parent with process id - %d and my child process has id - %d\n", getpid(), fork());
	
	return 0;
}

/*
The first fork() splits into parent and child.

The child enters the if branch and prints its PID.

The parent enters the else branch, but inside that printf, you are calling fork() again.

This creates a second child.

So now you have:

Original parent → prints parent PID and the PID of the second child.

Second child → also executes the printf, but in its context, fork() returned 0, so it prints with 0 as child PID.

*/

/* NOTE: 
fork() duplicates the process from the point it is called onward.

The child does not retroactively execute previous code.

Only code after the fork() is duplicated.

*/

/*
Step 1: How printf arguments are evaluated

In C, all arguments to a function are evaluated before the function executes.

That means getpid() and fork() are evaluated before printf actually prints anything.

So this is what happens:

getpid() is called → returns the parent’s PID.

fork() is called → creates a new child process:

In the original parent, fork() returns the child PID.

In the new child, fork() returns 0.

Now both processes continue to execute the same printf statement, but with different argument values.

*/
