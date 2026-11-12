# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <locale.h>

typedef struct no{
    int info;
    struct no *prox;
} no;

no* inicializa(){
    return NULL;
}

no* insere_inicio(no *inicio, int valor) {
    no *novo, *aux = inicio;

    novo = malloc(sizeof(no));
    novo->info = valor;

    if (inicio == NULL) {
        novo->prox = novo;
        return novo;
    }

    novo->prox = inicio;

    while (aux->prox != inicio) {
        aux = aux->prox;
    }

    aux->prox = novo;

    return novo;
}

no* remove_inicio(no *inicio) {
    no *aux = inicio;

    if (inicio == NULL) {
        printf("\nNao foi possivel remover o ultimo item (lista vazia)\n\n");
        return NULL;
    } else if (inicio->prox == inicio) {
        free(aux);
        printf("\nRemovendo o inicio da lista...\n\n");
        return NULL;
    } else {
        while (aux->prox != inicio) {
            aux = aux->prox;
        }

        inicio = inicio->prox;
        free(aux->prox);
        aux->prox = inicio;

        printf("\nRemovendo o inicio da lista...\n\n");

        return inicio;
    };
}

no* insere_fim(no *inicio, int valor) {
    no *novo, *aux = inicio;

    novo = malloc(sizeof(no));
    novo->info = valor;

    if (inicio == NULL) {
        novo->prox = novo;
        return novo;
    }

    novo->prox = inicio;

    while (aux->prox != inicio) {
        aux = aux->prox;
    }

    aux->prox = novo;

    return inicio;
}

no* remove_fim(no *inicio) {
    no *aux = inicio;

    if (inicio == NULL) {
        printf("\nNao foi possivel remover (lista vazia)\n\n");
        return NULL;
    } else if (inicio->prox == inicio) {
        free(inicio);
        printf("\nRemovendo o final da lista...\n\n");
        return NULL;
    } else {
        while (aux->prox->prox != inicio) {
            aux = aux->prox;
        }

        free(aux->prox);
        aux->prox = inicio;

        printf("\nRemovendo o final da lista...\n\n");

        return inicio;
    }
}

void exibir_lista(no *inicio) {
    no *aux = inicio;

    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    do {
        printf("%d", aux->info);
        aux = aux->prox;

        if (aux != inicio) {
            printf(" -> ");
        }
    } while (aux != inicio);

    printf("\n\n");
}

no* atualizar_valor(no *inicio, int valor_antigo, int valor_novo) {
    no *aux = inicio;

    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    do {
        if (aux->info == valor_antigo) {
            printf("Valor encontrado, atualizando...\n");
            aux->info = valor_novo;
            return inicio;
        }
        aux = aux->prox;
    } while (aux != inicio);

    printf("Valor não encontrado!\n");

    return inicio;
}

no* limpar_tudo(no *inicio) {

    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    no *aux;
    while (inicio->prox != inicio) {
        aux = inicio->prox;
        inicio->prox = aux->prox;
        free(aux);
    }
    free(inicio);

    printf("Memoria liberada com sucesso!\n\n");
    return NULL;
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int valor, valor_antigo, valor_novo;
    char opcao;
    no *inicio = inicializa();

    do{
        system("cls");
        printf("\n======================= MENU - LISTA CIRCULAR ======================\n");
        printf("\n");
        printf("[1] Inserir no inicio da lista\n");
        printf("[2] Remover no inicio da lista\n");
        printf("[3] Inserir no final da lista\n");
        printf("[4] Remover no final da lista\n");
        printf("[5] Exibir a lista por completo\n");
        printf("[6] Buscar um valor na lista e atualiza-lo\n");
        printf("[7] Liberar a memoria utilizada na lista\n");
        printf("\n");
        printf("[0] Fechar o programa\n");
        printf("\n");
        printf("=====================================================================\n");
        printf("\n> ");
        scanf("%s", &opcao);
        switch (opcao){
            case '0':
                printf("\nFechando programa...\n");
                break;
            case '1':
                printf("\nDigite o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                inicio = insere_inicio(inicio, valor);
                printf("Valor inserido com sucesso!\n\n");
                system("pause");
                break;
            case '2':
                inicio = remove_inicio(inicio);
                system("pause");
                break;
            case '3':
                printf("\nDigite o valor a ser inserido no fim: ");
                scanf("%d", &valor);
                inicio = insere_fim(inicio, valor);
                printf("Valor inserido com sucesso!\n\n");
                system("pause");
                break;
            case '4':
                inicio = remove_fim(inicio);
                system("pause");
                break;
            case '5':
                printf("\n");
                exibir_lista(inicio);
                system("pause");
                break;
            case '6':
                printf("\nInsira o valor que deseja atualizar: ");
                scanf("%d", &valor_antigo);

                printf("Insira o valor substituto: ");
                scanf("%d", &valor_novo);

                inicio = atualizar_valor(inicio, valor_antigo, valor_novo);
                system("pause");
                break;
            case '7':
                inicio = limparTudo(inicio);
                system("pause");
                break;

        }
    } while (opcao != '0');

    return 0;
}
