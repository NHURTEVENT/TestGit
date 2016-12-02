#include <stdio.h> /*fonctions I/O*/
#include <stdlib.h> /*allocation mémoire, controle de processus*/
#include <fcntl.h> /*contient open()*/
#include <sys/types.h> /*sert pour les blocs*/
#include <unistd.h> /*constantes, types et fonctions POSIX, genre le UNIX TIME*/
#define BUF_SIZE 512

int main(int argc, char* argv[]) {   /*argc est le nombre d'argument passés 
au programme et argv est un tableau de Strings donc chaque String est un 
argument passé au prog*/

	int idFichierLu, idFichierEcrit;
	int byteLu,byteEcrit;
	char buffer[BUF_SIZE];
	char nomFichier[255];

	if(argc ==2){
		idFichierLu = open (argv[1], O_RDONLY);
		if (idFichierLu == -1) {
			printf("Erreur de lecture");
/*ligne 20*/			return -1;
		}
		sprintf(nomFichier, "/home/exia/save/%s", argv[1]);
		idFichierEcrit = open(nomFichier, O_WRONLY | O_CREAT, 0777);
		if(idFichierEcrit == -1){
			printf("Erreur d'ecriture");
			return -2;
		}
		while((byteLu = read (idFichierLu, &buffer, BUF_SIZE)) >0) {
			byteEcrit = write(idFichierEcrit, &buffer, byteLu);
			if(byteEcrit !=byteLu) {
				printf ("Erreur d'ecriture das le fichier");
				return -3;
			}
			else{
				printf("%d byte lus, %d byte ecrit\n", byteLu,byteEcrit);
			}
		}
	}
	else{
		printf("Nombre de parametre incorrect");
/*ligne 40*/	}
	close (idFichierLu);
	close (idFichierEcrit);
	return 0;
}

