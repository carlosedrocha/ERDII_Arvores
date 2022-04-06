#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


typedef struct no{
    int valor;
    struct no* esquerda;
    struct no* direita;
}No;

typedef struct arvore{
    No* raiz;
}Arvore;


// Funcoes

// Retorna ponteiro de arvore
Arvore* criarArvore(){
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

// Insere no de acordo com a lei de formacao: Se valor > pai->valor: Entao filhoDireita || Senao: filhoEsquerda
void insereNo(Arvore *arvore){
    No* novo = (No*)malloc(sizeof(No));
    novo->esquerda = NULL;
    novo->direita = NULL;
    printf("\nDigite o valor: ");
    scanf("%d",&novo->valor);
    printf("\n novo->valor = %d", novo->valor);

    if(arvore->raiz == NULL)
        return arvore->raiz = novo;
    
    No* aux = arvore->raiz;
    
    while(aux){
        if(novo->valor > aux->valor){
            if(aux->direita == NULL)
                return aux->direita = novo;
            aux = aux->direita;
        }
        if(novo->valor < aux->valor){
            if(aux->esquerda == NULL)
                return aux->esquerda = novo;
            aux = aux->esquerda;
        }
    }

}

// Imprime preOrder
void imprimePre(No* raiz){
    if(raiz == NULL)
        return printf("\nArvore vazia");
    No* aux;
    aux = raiz;
    printf("\n%2d", aux->valor);
    if(aux->esquerda != NULL)
        imprimePre(aux->esquerda);
    if(aux->direita != NULL)
        imprimePre(aux->direita);
}

// Buscar valor dentro de uma arvore
No* busca(Arvore* arvore){
    int valor;
    printf("\nDigite o valor a ser buscado: ");
    scanf("%d", &valor);

    if(arvore->raiz == NULL)
        return printf("\nArvore vazia");

    No* aux = arvore->raiz;

    while(aux){
        if(valor > aux->valor)
            aux = aux->direita;
        
        else if(valor < aux->valor){
            aux = aux->esquerda;
        }
        else{
            printf("\nValor do no buscado = %2d", aux->valor);
            return aux;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int finalizar = 0;
    int opcao;

    Arvore* arvore = criarArvore();
    No* solicitado;


 do{
       printf("\n\n1 - Inserir no\n2 - imprimir\n3 - Busca de um no, dado um valor\n8 - Sair\n\nOpcao: ");
       scanf("%d", &opcao);
       switch(opcao){
           case 1:
                insereNo(arvore);
				break;
           case 2:
                imprimePre(arvore->raiz);
				break;
            case 3:
                busca(arvore);
                break;
           case 8:
               	printf("\nFinalizando...\n");
               	finalizar = 1;
               	break;
           default:
               	printf("Opcao invalida!\n");
       }
   } while (!finalizar);

}