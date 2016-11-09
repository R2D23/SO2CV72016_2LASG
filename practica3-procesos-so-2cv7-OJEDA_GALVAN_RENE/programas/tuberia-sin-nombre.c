#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define MAX 256

int main () {

	pid_t hijo;
	int tuberia[2];
	char mensaje[MAX];

	if ( pipe (tuberia) == -1) {

		perror("Error al crear la tuberia sin nombre con pipe");
		return(-1);

	} else {

		hijo = fork();

		switch (hijo) {

			case -1 :

				perror("Error al crear el proceso hijo con fork");
				return (-1);

			break;

			case 0 :

				while( read (tuberia[0], mensaje, MAX) > 0 && strcmp (mensaje, "FIN\n") != 0 )
					printf("\n El proceso hijo recibe el mensaje: %s \n", mensaje);

				close(tuberia[0]);
				close(tuberia[1]);

				return (0);

			break;

			default :

				do{

					printf("\n Escriba el mensaje del padre: ");

					if ( fgets (mensaje, sizeof(mensaje),stdin) != NULL )
						write (tuberia[1], mensaje, strlen(mensaje) + 1);

				} while( strcmp (mensaje,"FIN\n") != 0 );

				close(tuberia[0]);
				close(tuberia[1]);

				return (0);

			break;

		}

	}

	return (0);

}
