#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int pipes[2];
    int flg;
    char buff[20];
    flg = pipe(pipes);

    // Create pipe fail
    if (flg == -1) {
	perror("pipe");
	exit(1);
    }

    pid = fork();
    // Child Process
    if (pid == 0) {
	close(pipes[0]);
	write(pipes[1], "Hello there", 12);
    }
    // Parent Process
    else {
        close(pipes[1]);
    	read(pipes[0], buff, 15);
	printf("buf: %s\n", buff);
    }
    return 0;
}
