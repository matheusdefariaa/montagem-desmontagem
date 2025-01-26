#include <stdio.h>
#include <sys/mount.h>
#include <string.h>

void montar_disco();
void desmontar_disco();
void ajuda();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Entrada Inválida\n");
    }

    else {
        // Compara as entradas

        if (strcmp(argv[1], "-m") == 0) {
            montar_disco();
	    }

        else if (strcmp(argv[1], "-d") == 0) {
            desmontar_disco();
        }

        else if (strcmp(argv[1], "-h") == 0) {
            ajuda();
        }

        else {
            ajuda();
        }
    }

    return 0;
}

void montar_disco() {
    int montar = mount("/dev/sda","/mnt","ext4",0,NULL);

    // Verifica se o retorno de montar é 0 para sucesso
    if (montar == 0) {
        printf("Disco montado com sucesso\n");
    }

    else {
        perror("Falha na montagem do disco");
    }
}

void desmontar_disco() {
    int desmontar = umount("/mnt");

    // Verifica se o retorno de desmontar é 0 para sucesso
    if (desmontar == 0) {
        printf("Disco desmontado com sucesso\n");
    }

    else {
        perror("Falha ao desmontar disco");
    }
}

void ajuda() {
    printf("----------------------------------\n");
    printf("Autor: Matheus de Faria\n");
    printf("Versão: 0.1\n");
    printf("Data de lançamento: 26/01/2025\n\n");
    
    printf("\tMontagem e Desmontagem de disco\n\n");
    printf("Montagem:\n\t mnt -m\n");
    printf("Desmontagem:\n\tmnt -d\n");
    printf("----------------------------------\n");
}
