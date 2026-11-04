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

no* insereInicio(no *inicio, int valor) {
    no *novo;                  

    novo = malloc(sizeof(no));
    novo->info = valor; 
    
    if (inicio == NULL) {
        novo->prox = novo;
        return novo;
    }
          
    novo->prox = inicio;
    inicio->prox = novo;
    return novo;     
}

no* removeInicio(no *inicio) {
    no *aux;  
    
    if (inicio == NULL) {      
        printf("\nNao foi possivel remover o ultimo item (lista vazia)\n\n");
        return NULL;
    } else {
        aux = inicio; 

        while (aux->prox != inicio) {
            aux = aux->prox;
        }
        
        inicio = inicio->prox;
        free(aux->prox);
        aux->prox = inicio;
    
        printf("\nRemovendo o inicio da lista...\n\n");

        return inicio;
    };
    return inicio;            
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int valor;
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
