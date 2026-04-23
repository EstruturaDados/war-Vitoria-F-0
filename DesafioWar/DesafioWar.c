#include <stdio.h>
#include <string.h>

#define TOTAL_TERRITORIOS 5

//Definição do struct do território (agrupar nome, cor e número)
struct Territorio {
    char nomeTerritorio [30];
    char corExercito [10];
    int numeroTropa;
};

int main() {
//Vetor para armazenar 5 estruturas tipo Territorio
    struct Territorio exercito[TOTAL_TERRITORIOS];

//Laço for para preencher o cadastro dos territórios
for (int i = 0; i < 5; i++){
 printf("Território %d\n", i + 1);

     printf("Nome do território: ");
     fgets(exercito[i].nomeTerritorio, 30, stdin);
     exercito[i].nomeTerritorio[strcspn(exercito[i].nomeTerritorio, "\n")] = '\0';

     printf("Cor do exército que o dominou: ");
     fgets(exercito[i].corExercito, 10, stdin);
     exercito[i].corExercito[strcspn(exercito[i].corExercito, "\n")] = '\0';

     printf("Quantidade de tropas: ");
    while (scanf("%d", &exercito[i].numeroTropa) != 1) {
    printf("Digite um número válido: ");
    while (getchar() != '\n'); //Limpa o buffer
    }
    getchar(); //Para limpar o que sobrar no buffer que pode causar erro

     printf("\n");

}

//Exibir os dados do cadastro
 printf("--- Territórios cadastrados ---\n");

    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("- Nome: %s\n", exercito[i].nomeTerritorio);
        printf("- Cor do exército: %s\n", exercito[i].corExercito);
        printf("- Número de tropas: %d\n", exercito[i].numeroTropa);
        printf("\n");
    }

    return 0;
}
