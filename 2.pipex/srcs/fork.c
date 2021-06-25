#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t	pid;
	pid = fork();
	if (pid > 0) // parent process
	{
		printf("parent PID: %d\n", getpid());
		printf("PID from fork() to the parent: %d\n", pid);
	}
	else if (pid == 0) // child process
	{
		printf("child PID: %d\n", getpid());
		printf("PID from fork() to the child: %d\n", pid);
	}
	return (0);
}

int main(int argc, char const *argv[])
{

    int pipefd[2];
    pid_t pid;

    pipe(pipefd);
    pid = fork();

    char *arr[2];
    arr[0] = ".";
    arr[1] = 0;
    if (pid > 0)
    {
        ft_stdout(argv[argc - 1]);
        dup2(pipefd[READ], STDIN_FILENO);
        close(pipefd[READ]);
        close(pipefd[WRITE]);
        execve("/bin/ls", arr, 0);
    }
    else if (pid == 0)
    {
        ft_stdin(argv[1]);
        dup2(pipefd[WRITE], STDOUT_FILENO);
        close(pipefd[READ]);
        close(pipefd[WRITE]);
        execve("/bin/cat", 0, 0);
    }
    return (SUCCESS);
}