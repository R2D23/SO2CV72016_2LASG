//BIBLIOTECAS
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//MAIN
int main () {

	//DECLARACION DE VARIABLES
	pid_t pid, ppid;
	uid_t uid, euid;
	gid_t gid, egid;

	//OBTENCION DE ID's
	pid = getpid();
	ppid = getppid();

	uid = getuid();
	euid = geteuid();

	gid = getgid();
	egid = getegid();

	//DESPLIEGUE DE RESULTADOS
	printf ("Mi PID es: %d\n", pid);
	printf ("El PID de mi padre es: %d \n", ppid);
	printf ("El ID de usuario (UID) es: %d \n", uid);
	printf ("El ID efectivo de usuario (EUID) es: %d \n", euid);
	printf ("El ID de grupo (GID) es: %d\n", gid);
	printf ("El ID de grupo efectivo (EGID) es: %d \n", egid);

	return 0;

}
