#include <stdio.h>

int compararStrings(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }
    return (s1[i] == '\0' && s2[i] == '\0'); //
}

int main() {
    int tentativas = 3;
    int escolha = 0;
    char palpite[20];
    char culpado[] = "Ronaldo";
    int acertou = 0;
    int sairDoJogo = 0;

    printf("Bem-vindo ao Jogo do Detetive - Edicao Futebol!\n");
    printf("Descubra qual jogador de futebol cometeu a falta:\n\n");
    printf("1. Neymar (usa faixa, 37 anos)\n");
    printf("2. Messi (usa chuteira azul, 38 anos)\n");
    printf("3. Ronaldo (usa faixa, 39 anos)\n");
    printf("4. Vinicius (usa chuteira vermelha, 24 anos)\n");
    printf("5. Rafael Leao (usa faixa, 25 anos)\n\n");

    while (tentativas > 0 && acertou == 0 && sairDoJogo == 0) {
        printf("\nMenu:\n");
        printf("1 - Pedir uma pista\n");
        printf("2 - Tentar adivinhar\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            int pista;
            printf("Escolha a pista (1 a 3): ");
            scanf("%d", &pista);

            if (pista == 1) {
                printf("Pista 1: O culpado tem mais de 35 anos.\n");
            } else if (pista == 2) {
                printf("Pista 2: O culpado usa faixa na cabeca.\n");
            } else if (pista == 3) {
                printf("Pista 3: O nome do culpado comeca com R.\n");
            } else {
                printf("Pista invalida.\n");
            }

        } else if (escolha == 2) {
            printf("Digite o nome do jogador: ");
            scanf("%s", palpite);

            if (compararStrings(palpite, culpado)) {
                printf("Parabens! Voce descobriu o culpado: %s.\n", culpado);
                acertou = 1;
            } else {
                tentativas--;
                printf("Errado! Tentativas restantes: %d\n", tentativas);
            }

        } else if (escolha == 3) {
            printf("Saindo do jogo. Ate a proxima!\n");
            sairDoJogo = 1;

        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    if (acertou == 0 && sairDoJogo == 0) {
        printf("\nFim de jogo! O culpado era: %s.\n", culpado);
    }

    return 0;
}
