#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	pid_t pid = fork();
	int status;
	
	if (pid == 0) {
	
		printf("child started and done - %d\n", getpid());
		return 0;
	}
	else {
		wait(NULL);
		printf("parent just wont die\n");
		sleep(5);
	}

	return 0;	
}
