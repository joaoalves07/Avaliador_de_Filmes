#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int lancamentoAno;
    float notaMedia;
    int avaliacoes;
} Filme;

Filme filmes[MAX];
int totalFilmes = 0;

int cadastrarFilme() {
    if (totalFilmes >= MAX) {
        printf("O limite de filmes foi atingido.\n");
        return 0;
    }

    Filme novoFilme;

    printf("Digite o nome do filme: ");
    scanf(" %[^\n]s", novoFilme.nome);

    printf("Digite o ano de lancamento do filme: ");
    scanf("%d", &novoFilme.lancamentoAno);

    novoFilme.notaMedia = 0.0;
    novoFilme.avaliacoes = 0;

    filmes[totalFilmes] = novoFilme;
    totalFilmes++;

    printf("Filme cadastrado com sucesso!\n");
    return 1;
}

int adicionarAvaliacao() {
    char nomeFilme[50];
    float nota;

    printf("Digite o nome do filme que deseja avaliar: ");
    scanf(" %[^\n]s", nomeFilme);

    for (int i = 0; i < totalFilmes; i++) {
        if (strcmp(filmes[i].nome, nomeFilme) == 0) {
            printf("Digite a nota que deseja dar para o filme (0 a 5): ");
            scanf("%f", &nota);

            if (nota < 0 || nota > 5) {
                printf("Nota invalida. Deve ser entre 0 e 5.\n");
                return 0;
            }

            filmes[i].notaMedia = ((filmes[i].notaMedia * filmes[i].avaliacoes) + nota) / (filmes[i].avaliacoes + 1);
            filmes[i].avaliacoes++;

            printf("Avaliacao adicionada com sucesso!\n");
            return 1;
        }
    }

    printf("Filme nao encontrado.\n");
    return 0;
}

void exibirFilmes() {
    if (totalFilmes == 0) {
        printf("Nenhum filme cadastrado.\n");
        return;
    }

    printf("\nFilmes cadastrados:\n");
    for (int i = 0; i < totalFilmes; i++) {
        printf("Nome: %s\n", filmes[i].nome);
        printf("Ano de Lancamento: %d\n", filmes[i].lancamentoAno);
        printf("Quantidade de Avaliacoes: %d\n", filmes[i].avaliacoes);
        printf("Nota Media: %.2f\n\n", filmes[i].notaMedia);
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar um novo filme\n");
        printf("2. Adicionar uma avaliacao a um filme\n");
        printf("3. Exibir todos os filmes cadastrados\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFilme();
                break;
            case 2:
                adicionarAvaliacao();
                break;
            case 3:
                exibirFilmes();
                break;
            case 0:
                printf("Encerando o programa...\n");
                break;
            default:
                printf("Opcao incorreta. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

