#include <unistd.h>
#include <stdio.h>

void	ft_cd(char *dir) {

}

void	execute(char **arg, char **envp, int start, int len) {
	
	char **args = make_args(arg, start, len);
	execve(args[0], args, envp);
}

char	**make_args(char **argv, int start, int len) {
	char	**res = malloc(sizeof(char *) * (len + 1));
	for (int i = 0; i < len; i++)
		res[i] = argv[start + i];
	res[len] = NULL;
	return (res);
}

int	microshell(char **cmd, char **env) {
	int i = 0;
	while (cmd[++i]) {
		int until = i;
		while (cmd[i] && cmd[i] != '|' && cmd[i] != ';')
			until++;
		execute(i + );
	}
}

int main(int argc, char **argv, char **envp) {
	return (microshell(argv, envp));
}