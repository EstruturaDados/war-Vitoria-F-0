#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Struct do território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

//Função para cadrastar os territórios
void cadastrarTerritorios(Territorio* mapa, int total) {
    for (int i = 0; i < total; i++) {
        printf("\nCadrastre o Território %d\n", i + 1);

        printf("Nome do território: ");
        fgets(mapa[i].nome, 30, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(mapa[i].cor, 10, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        while (scanf("%d", &mapa[i].tropas) != 1) {
            printf("Digite um número válido: ");
            while (getchar() != '\n');
        }
        getchar(); //Para limpar o buffer
    }
}

//Função para exibição do mapa
void exibirTerritorios(Territorio* mapa, int total) {
    printf("\n--- Mapa do Mundo ---\n");
    for (int i = 0; i < total; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }
}

//Função para simular o ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    int dadoA = rand() % 6 + 1; //Serve para simular um dado de 6 faces
    int dadoD = rand() % 6 + 1;

    printf("\nAtaque: %d | Defesa: %d\n", dadoA, dadoD);

    if (dadoA > dadoD) {
        printf("Atacante venceu!\n");

        int tropasTransferidas = atacante->tropas / 2;
        if (tropasTransferidas < 1) tropasTransferidas = 1;

        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = tropasTransferidas;

        atacante->tropas -= tropasTransferidas;

    } else {
        printf("Defensor venceu!\n");

        if (atacante->tropas > 1)
            atacante->tropas--;
    }
}

//Liberação de memória
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

int main() {
    int total;

    printf("Defina a quantidade de territórios: ");
    scanf("%d", &total);
    getchar();

    Territorio* mapa = calloc(total, sizeof(Territorio)); //Para armazenar o total selecionado no início

    if (mapa == NULL) {
        printf("Erro de memória!\n");
        return 1;
    }

    cadastrarTerritorios(mapa, total);
    exibirTerritorios(mapa, total);

    srand(time(NULL)); //Necessário para rodar rand e srand

    int atk, def;

    printf("\n--- Escolha o ataque ---\n");

    printf("Território atacante (1 a %d): ", total);
    scanf("%d", &atk);

    printf("Território defensor (1 a %d): ", total);
    scanf("%d", &def);

    atk--;
    def--;

    if (atk == def || atk < 0 || atk >= total || def < 0 || def >= total) {
        printf("Escolha inválida!\n");
    }
    else if (strcmp(mapa[atk].cor, mapa[def].cor) == 0) {
        printf("Não é possível atacar território da mesma cor!\n");
    }
    else if (mapa[atk].tropas <= 1) {
        printf("Tropas insuficientes para atacar!\n");
    }
    else {
        atacar(&mapa[atk], &mapa[def]);
        exibirTerritorios(mapa, total);
    }

    liberarMemoria(mapa);

    return 0;
}