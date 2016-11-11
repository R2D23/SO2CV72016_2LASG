#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>


union semun 
{ 
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *__buf;
};


int main(int argc, char *argv[])
{
	key_t key;
	int semId;
	struct sembuf operacion;
	union semun arg;
	int i=0;

	key = ftok (argv[1], 13);
	if (key == (key_t)-1)
	{
		printf("No se puede obtener Llave para el semáforo  \n");
		exit(0);
	}


	semId = semget (key, 10, 0600 | IPC_CREAT);
	if (semId == -1)
	{
		printf("Error al crear el semáforo  \n");
		exit (0);
	}

	arg.val = 0;
	semctl (semId, 0, SETVAL, &arg);

	operacion.sem_num = 0;
	operacion.sem_op = -1;
	operacion.sem_flg = 0;

	while (1)
	{
		printf(" %d Esperando senal de semaforo  \n",i);
		semop (semId, &operacion, 1);
		printf("%d Recibi senal de semaforo y realizo mi tarea\n",i);
		printf(" \n");
		i++;
	}

	return 0;

}
