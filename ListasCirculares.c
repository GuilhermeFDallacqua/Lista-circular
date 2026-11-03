# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <locale.h>

// Aqui to criando o caralho do No com o campo info e o campo de proximo

typedef struct no{
    int info;        // Campo pra salvar o valor
    struct no *prox; // Seta que aponto pro proximo da lista
} no;

no* inicializa(){
    return NULL;
}

no* insereInicio(no *inicio, int valor) {
    no *novo;                  // Cria o novo no
    novo = malloc(sizeof(no)); // Aloca a memoria necessaria para o novo no
    novo->info = valor;        // A informacaoo do novo no recebe o valor do parametro
    novo->prox = inicio;       // O novo no aponta para o antigo inicio (o no a frente)
    return novo;               // O novo no vira o inicio da lista
}

no* removeInicio(no *inicio) {
    no *aux;                   // Cria a seta aux para o no
    if (inicio == NULL) {      // Verifica se o inicio existe
        printf("\nNao foi possivel remover o ultimo item (lista vazia)\n\n");
    } else {
        aux = inicio;          // A seta auxiliar aponta para onde a seta inicio aponta
        inicio = aux->prox;    // A seta inicio comeca a apontar para o proximo do auxiliar
        free(aux);             // E liberado o no que o auxiliar aponta
        printf("\nRemovendo o inicio da lista...\n\n");
    };
    return inicio;             // Retorna o novo inicio da lista de nos

}

int main() {
    setlocale(LC_ALL, "portuguese");
    int valor;
    char opcao; // String pq e mais facil de validar
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
                inicio = insereInicio(inicio, valor);
                printf("Valor inserido com sucesso!\n\n");
                system("pause");
                break;
            case '2':
                inicio = removeInicio(inicio);
                system("pause");
                break;
            case '3':
                system("pause");
                break;
            case '4':
                system("pause");
                break;
            case '5':
                system("pause");
                break;
            case '6':
                system("pause");
                break;
            case '7':
                system("pause");
                break;

        }
    } while (opcao != '0');

    return 0;
}