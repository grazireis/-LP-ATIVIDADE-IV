#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct dados_alunos
{
    char data_de_nascimento[250];
    char nome[200];
    float nota[5];
    float media;
};

void titulo()
{
    system("cls || clear");
    printf("Programa Aprovado/Reprovado\n");
}

float calcularMedia(float numero[])
{
    int i;
    float soma = 0, media;

    for (i = 0; i < 2; i++)
    {
        soma += numero[i];
    }
    return media = soma / 2;
}

char *conceito(float valor)
{
    char turma[250];

    if (valor >= 7)
    {
        strcpy(turma, "Aprovado");
    }
    else
    {
        strcpy(turma, "Reprovado");
    }

    return turma;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    // Variáveis

    int i, j;
    struct dados_alunos estudante[5];

    // Comandos

    titulo();
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("Nome do %dº estudante: ", i + 1);
        gets(estudante[i].nome);
        printf("Data de nascimento: ");
        gets(estudante[i].data_de_nascimento);

        for (j = 0; j < 2; j++)
        {
            do
            {
                printf("Digite a %dª nota: ", j + 1);
                scanf("%f", &estudante[i].nota[j]);

                if (estudante[i].nota[j] < 0 || estudante[i].nota[j] > 10)
                {
                    printf("\nNOTA INVÁLIDA! Por favor, informe uma nota entre 0 e 10\n\n");
                }

            } while (estudante[i].nota[j] < 0 || estudante[i].nota[j] > 10);
        }
        fflush(stdin);
        printf("\n");

        estudante[i].media = calcularMedia(estudante[i].nota);
    }

    titulo();
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("Nome do %dº estudante: %s\n", i + 1, estudante[i].nome);
        printf("Data de nascimento: %s\n", estudante[i].data_de_nascimento);
        for (j = 0; j < 2; j++)
        {
            printf("%dª nota: %.2f\n", j + 1, estudante[i].nota[j]);
        }
        printf("Média: %.2f\n", estudante[i].media);
        printf("-> %s\n\n", conceito(estudante[i].media));
    }

    return 0;
}