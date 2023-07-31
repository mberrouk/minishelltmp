#include <unistd.h>
#include<stdio.h>
int main() {
    // Changer le répertoire de travail courant vers "/chemin/vers/mon_dossier"
    int result = chdir("a/b/c");
    printf("%d", result);
 if (result == 0) {
        printf("Changement de répertoire réussi !\n");
    } else {
        perror("Erreur lors du changement de répertoire");
    }
    char buffer[1024];
    getcwd(buffer, sizeof(buffer));
    printf("Répertoire de travail actuel : %s\n", buffer);
    return 0;
}
