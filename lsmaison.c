#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> /*permet d'acceder a ino_t et d_ino de sys/types.h et de faire des struct*/
#include <sys/types.h> /*fournis ino_t et d_ino*/

int main(int argc, char* argv[]){

	struct dirent *contenuRepertoire; //déclaration d'une structure
	DIR *repertoire; //je suppose qu'on crée un repertoire ??

	repertoire = opendir(argv[1]);
	if(repertoire == NULL){
		printf("Erreur lors de l'ouverture du répertoire/n");
		return -1;
	}

	while((contenuRepertoire= readdir(repertoire)) != NULL){
//		contenuRepertoire = readdir(repertoire);
		printf("nom: %s | ",contenuRepertoire->d_name);
		printf("ID: %d \n", contenuRepertoire->d_ino);
	}

	closedir(repertoire);
	return 0;
}
