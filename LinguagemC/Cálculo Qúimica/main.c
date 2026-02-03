#include <stdio.h>

// Função para calcular a concentração comum (C = m/V)
void calcular_concentracao(double massa_soluto, double volume_solucao, double *concentracao) {
    // Validação química: volume deve ser positivo
    if (volume_solucao > 0) {
        *concentracao = massa_soluto / volume_solucao;
    } else {
        // Valor sentinela para indicar erro
        *concentracao = -1; 
    }
}

int main() {
    double massa_soluto, volume_solucao, concentracao;

    printf("Digite a massa do soluto (g): ");
    if (scanf("%lf", &massa_soluto) != 1) {
        printf("Erro: Entrada invalida!\n");
        return 1;
    }

    printf("Digite o volume da solucao (L): ");
    if (scanf("%lf", &volume_solucao) != 1) {
        printf("Erro: Entrada invalida!\n");
        return 1;
    }

    // Passagem por referência usando o operador &
    calcular_concentracao(massa_soluto, volume_solucao, &concentracao);

    if (concentracao >= 0) {
        printf("A concentracao da solucao e: %.2f g/L\n", concentracao);
    } else {
        printf("Erro: O volume deve ser maior que zero.\n");
    }

    return 0;
}
