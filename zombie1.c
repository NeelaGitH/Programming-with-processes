#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	pid_t pid = fork();
	int status;
	
	if (pid == 0) // do childish things
	else {
		waitpid(pid, &status, 0);
		// wait for the child to die
		// parent process if any
	}

	return 0;	
}


/* NOTE: waitpid() will block (pause the parent) until:

The child with the given pid terminates, or

An error occurs.

*/


/*

waitpid() needs a place to store the child’s exit information.

status is an int variable in the parent.

&status is the address of that variable — you are passing a pointer to waitpid() so it can write the child’s exit info into it.

What gets stored in status?

It contains information like:

Did the child exit normally?

What was the exit code?

Did the child terminate due to a signal?

*/
