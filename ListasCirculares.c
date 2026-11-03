#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Aqui to criando o caralho do Nó com o campo info e o campo de proximo

typedef struct no{
    int info; // campo de info
    struct no *prox; //seta pro proximo
} no;

no* inicializa(){
    return NULL; //uma lista vazia é representada por NULL
}



// Aqui é a função que insere no inicio

no* insereInicio(no *inicio, int valor) {
    no *novo; // cria o novo nó

    novo = malloc(sizeof(no)); // aloca a memoria para a merda do novo nó
    novo->info = valor; // a informação do novo nó recebe o valor do parametro
    novo->prox = inicio; // o novo nó aponta para o antigo inicio (o nó à frente)
    return novo; // o novo nó vira o inicio da lista
}


// função que remove a merda do final

no* removeInicio(no *inicio) {
    no *aux; // cria a seta aux para o nó

    if (inicio == NULL) { //verifica se o inicio existe
        printf("Lista vazia\n"); // se nao existir printa lista vazia
    } else { // se existir
        aux = inicio; // a seta auxiliar aponta para onde a seta inicio aponta
        inicio = aux->prox; // a porra da seta inicio começa a apontar para o proximo do auxiliar
        free(aux); // é liberado o nó que o auxiliar aponta
        printf("Removendo o inicio da lista...\n");
    };
    return inicio; // retorna o novo inicio da lista de nós

}


void main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao, valor;
    no *inicio = inicializa();

    do{
        printf("MENU DE OPÇÕES\n");
        printf("[0] Sair\n");
        printf("[1] Inserir no inicio da lista\n");
        printf("[2] Remover no inicio da lista\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);
        system("cls");


        switch (opcao){
            case 1:
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                inicio = insereInicio(inicio, valor);
                printf("Valor inserido com sucesso!\n");
                break;

            case 2:
                inicio = removeInicio(inicio);
                break;
        }
    } while (opcao != 0);


}


