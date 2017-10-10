#include	"unp.h"
#include	"myerr.h"

void sig_int(int signo)
{
	printf("Interrupt!\n >>");
	exit(0);
}
int main(void)
{
	pid_t	pid;;
	int status;
	char buf[MAXLINE];

	if(signal(SIGINT, sig_int) == SIG_ERR) {
		err_sys("signal error");
	}

	printf("lyb>");
	while((Fgets(buf, MAXLINE, stdin)) != NULL) {
		if(buf[0] == '\n') {
			printf("lyb>");
			continue;
		} 
		buf[strlen(buf) - 1] = 0; /* replace Enter (nweline) to NULL*/

		if((pid = fork()) < 0) {
			err_sys("fork error!");
		} else if(pid == 0) {	/* child */ 
			execlp(buf, buf, (char *) 0);
			err_ret("couldn't execute : %s", buf);
			printf("\n");
			exit(127);
		}
	
		/* wait child over */
		if((pid = waitpid(pid, &status, 0)) < 0) {
			err_sys("waitpid error");
			printf("\n");
		}
		
		printf("lyb>");
	}
	exit(0);
}
