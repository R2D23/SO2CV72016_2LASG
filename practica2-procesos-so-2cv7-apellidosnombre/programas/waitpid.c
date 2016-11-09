#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int main (){

	pid_t hijo;
	int cond;

	hijo = fork();

	switch (hijo) {

	case -1:

		perror("fork");
		exit(EXIT_FAILURE);

	break;

	case 0:

		printf("PROCESO HIJO \n");
		printf("\t pid hijo: %d \n", getpid());
		printf("\t pid del padre: %d \n", getppid());

		exit(EXIT_SUCCESS);

	break;

	default :

		waitpid(hijo, &cond, 0);

		printf("PROCESO PADRE: \n");
		printf("\t pid de proceso padre = %d \n", getpid());
		printf("\t pid de proceso abuelo = %d \n", getppid());
		printf("\t mi hijo envio la condicion = %d \n", cond);

	break;

	}

	exit (EXIT_SUCCESS);

}
