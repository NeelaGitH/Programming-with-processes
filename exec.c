#include <stdio.h>
#include <unistd.h>

int main(){

	if (fork() == 0) {
		printf("I'm the child with process id - %d\n", getpid());
		execlp("ls", "ls", "-al", NULL); // equivalent to ls -al in terminal 
		printf("after execlp\n");
	}
	else printf("I'm the parent with process id - %d\n", getpid());
	
	return 0;
}

/*
execlp → replace the current process with a new program and search for it in the PATH.

First argument "ls" → the name of the program you want to run. Since it’s execlp, it will look in the directories listed in PATH.

Second argument "ls" → this becomes argv[0] in the new program. By convention, it’s usually the program name.

Third argument "-al" → this is argv[1], a command-line argument for ls.

NULL → marks the end of arguments. Without it, execlp wouldn’t know where the arguments stop.

*/
