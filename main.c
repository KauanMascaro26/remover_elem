#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct _Lista {
    int info; 
    struct _Lista *prox; 
}Lista;

Lista *inicio = NULL, *fim = NULL;

int inserir(int elem) {
    Lista *no;
    no = (Lista *)malloc(sizeof(Lista));
    if (no == NULL) 
        return 0;
    no->info = elem; 
    if (inicio == NULL) { 
        no->prox = NULL;
        inicio = no;
        fim = no;
    } else {
        int pos;
        printf("Escolha a posição onde deseja inserir o elemento\n");
        printf("1-início; 2-final; 3-algum local específico\n");
        scanf("%d", &pos);
        if (pos == 1) { 
            no->prox = inicio; 
            inicio = no;
        } else if (pos == 2) { 
            no->prox = NULL; 
            fim->prox = no;
            fim = no;
        } else { 
            int item, achou = 0;
            printf("\nDigite o número do elemento que já se encontra na lista para inserir depois dele: ");
            scanf("%d", &item);
            Lista *aux = inicio; 
            while (aux != NULL) { 
                if (aux->info == item) { 
                    no->prox = aux->prox; 
                    aux->prox = no; 
                    if (aux == fim) 
                        fim = no;
                    achou = 1;
                    break;
                }
                aux = aux->prox;
            }
            if (achou == 1)
                return 1;
            else
                return 0;
        }
    }
    return 1; 
}

void imprimir() {
    Lista *aux = inicio;
    if (aux == NULL) {
        printf("\nNenhum elemento foi encontrado!\n");
    } else {
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
    printf("\n");
}

int remover(int elem) {
    if (inicio == NULL) { 
        printf("A lista está vazia.\n");
        return 0;
    }

    Lista *aux = inicio;
    Lista *anterior = NULL;

    while (aux != NULL) {
        if (aux->info == elem) { 
            if (aux == inicio) { 
                inicio = inicio->prox;
                if (inicio == NULL) 
                    fim = NULL;
            } else if (aux == fim) { 
                fim = anterior;
                fim->prox = NULL;
            } else { 
                anterior->prox = aux->prox;
            }
            free(aux);
            return 1; 
        }
        anterior = aux;
        aux = aux->prox;
    }
    return 0; 
}

int main() {
    int opcao, elem, res;
    do {
        printf("\nMenu:\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elem);
                res = inserir(elem);
                if (res)
                    printf("Elemento inserido com sucesso!\n");
                else
                    printf("Erro ao inserir o elemento!\n");
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elem);
                res = remover(elem);
                if (res)
                    printf("Elemento removido com sucesso!\n");
                else
                    printf("Erro ao remover o elemento!\n");
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}

