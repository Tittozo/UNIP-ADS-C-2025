#include <stdio.h>
#include <ctype.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

// Função original intacta
void calcular_concentracao(double massa_soluto, double volume_solucao, double *concentracao){
    if(volume_solucao > 0){
        *concentracao = massa_soluto / volume_solucao;
    } else {
        *concentracao = -1; 
    }
}

// Adição de nova função seguindo o seu padrão
void calcular_molaridade(double massa_soluto, double massa_molar, double volume_solucao, double *molaridade) {
    if (volume_solucao > 0 && massa_molar > 0) {
        *molaridade = massa_soluto / (massa_molar * volume_solucao);
    } else {
        *molaridade = -1;
    }
}

int main() {
    double massa_soluto, volume_solucao, concentracao, massa_molar;
    int opcao;

    // Pausa estética de 2 segundos
    SLEEP_MS(2000);

    printf("=== MENU DE CALCULOS QUIMICOS ===\n");
    printf("1. Concentracao Comum\n");
    printf("2. Molaridade\n");
    printf("Escolha uma opcao: ");
    
    if (scanf("%d", &opcao) != 1) {
        printf("Erro: Opcao invalida!\n");
        return 1;
    }

    if (opcao == 1) {
        printf("Digite a massa do soluto (em gramas): ");
        if (scanf("%lf", &massa_soluto) != 1) {
            printf("Erro: Entrada invalida!\n");
            return 1;
        }

        printf("Digite o volume da solucao (em litros): ");
        if (scanf("%lf", &volume_solucao) != 1) {
            printf("Erro: Entrada invalida!\n");
            return 1;
        }

        calcular_concentracao(massa_soluto, volume_solucao, &concentracao);

        if (concentracao >= 0) {
            printf("A concentracao da solucao e: %.2f g/l\n", concentracao);
        } else {
            printf("Erro: Nao e possivel calcular com volume zero ou negativo.\n");
        }

    } else if (opcao == 2) {
        printf("Digite a massa do soluto (em gramas): ");
        scanf("%lf", &massa_soluto);
        printf("Digite a massa molar (g/mol): ");
        scanf("%lf", &massa_molar);
        printf("Digite o volume da solucao (em litros): ");
        scanf("%lf", &volume_solucao);

        calcular_molaridade(massa_soluto, massa_molar, volume_solucao, &concentracao);

        if (concentracao >= 0) {
            printf("A molaridade da solucao e: %.4f mol/L\n", concentracao);
        } else {
            printf("Erro: Verifique os valores digitados.\n");
        }
    }

    return 0;
}
