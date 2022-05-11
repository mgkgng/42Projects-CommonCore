#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char**	get_args(char *argv) {

}

int main(int argc, char **argv, char **envp) {
	int	i = 0;
	while (argv[++i]) {
		int j = 0;
		while (argv[i + j] && strcmp(argv[i + j], ";")) {
			int fd[2];
			pipe(fd);
			pid_t pid = fork();
			if (!pid) {
				if (!strcmp(argv[i], "cd")) {

				}
				execve(argv[i], get_args(argv[i]), envp);
				write(2, "error: fatal\n", 12);
			} else {
				waitpid(pid, NULL, 0);
			}
		}
		i += j;
	}
}