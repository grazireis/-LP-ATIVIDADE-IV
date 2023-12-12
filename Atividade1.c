#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct dados_contatos
{
    char nome[100];
    char telefone[100];
    char email[100];
};
void buscartelefonepelonome(struct dados_contatos contato[], char *contatodesejado)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (strcmp(contato[i].nome, contatodesejado) == 0)
        {
            printf("Telefone de %s: %s", contato[i].nome, contato[i].telefone);
            return;
        }
    }
    printf("CONTATO NÃO ENCONTRADO");
};

int main()
{

    setlocale(LC_ALL, "portuguese");

    int i;
    char contatodesejado[200];

    struct dados_contatos contato[3];

    printf("\nSolicitando os dados dos Contatos...\n");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        fflush(stdin);

        printf("Nome %dº do contato:", i + 1);
        gets(contato[i].nome);

        printf("Telefone do contato:");
        gets(contato[i].telefone);

        printf("Email do contato:");
        gets(contato[i].email);
    }

    system("cls|| clear");

    printf("Nome do contato desejado:");
    gets(contatodesejado);

    buscartelefonepelonome(contato, contatodesejado);

    return 0;
}