

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Aviao {
    char nome[50];           
    int identificador;       
    struct Aviao* proximo;   
} Aviao;

// Definição da estrutura da fila
typedef struct Fila {
    Aviao* inicio;           
    Aviao* fim;              
    int tamanho;             
} Fila;


void inicializaFila(Fila* f) {
    f->inicio = NULL;       
    f->fim = NULL;          
    f->tamanho = 0;         
}


void adicionarAviao(Fila* f, char* nome, int id) {
    Aviao* novo = (Aviao*) malloc(sizeof(Aviao)); 
    strcpy(novo->nome, nome);                     
    novo->identificador = id;                     
    novo->proximo = NULL;                         
    
    if (f->fim != NULL) {                         
        f->fim->proximo = novo;                   
    } else {
        f->inicio = novo;                         
    }
    f->fim = novo;                                
    f->tamanho++;                                 
}


void autorizarDecolagem(Fila* f) {
    if (f->inicio != NULL) {                       
        Aviao* temp = f->inicio;                   
        f->inicio = f->inicio->proximo;            
        if (f->inicio == NULL) {                   
            f->fim = NULL;                         
        }
        printf("Avião %s (ID: %d) decolou.\n", temp->nome, temp->identificador); 
        free(temp);                                
        f->tamanho--;                              
    } else {
        printf("Nenhum avião na fila para decolar.\n"); 
    }
}


void listarNumeroAvioes(Fila* f) {
    printf("Número de aviões na fila de decolagem: %d\n", f->tamanho); 
}


void listarAvioes(Fila* f) {
    Aviao* atual = f->inicio;                       
    while (atual != NULL) {                         
        printf("Avião: %s, ID: %d\n", atual->nome, atual->identificador); 
        atual = atual->proximo;                    
    }
}

// Função para listar as características do primeiro avião da fila
void listarPrimeiroAviao(Fila* f) {
    if (f->inicio != NULL) {                        
        printf("Primeiro Avião: %s, ID: %d\n", f->inicio->nome, f->inicio->identificador); 
    } else {
        printf("Nenhum avião na fila.\n");          
    }
}

int main() {
    Fila fila;                                      
    inicializaFila(&fila);                         
    int opcao;                                      
    char nome[50];                                  
    int id;                                         

    do {
        // Menu de opções
        printf("\nControle de Pista de Decolagem\n");
        printf("1. Listar número de aviões na fila\n");
        printf("2. Autorizar decolagem do primeiro avião\n");
        printf("3. Adicionar avião à fila\n");
        printf("4. Listar todos os aviões na fila\n");
        printf("5. Listar características do primeiro avião\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);                       

        switch (opcao) {
            case 1:
                listarNumeroAvioes(&fila);          
                break;
            case 2:
                autorizarDecolagem(&fila);          
                break;
            case 3:
                printf("Digite o nome do avião: ");
                scanf("%s", nome);                  
                printf("Digite o identificador do avião: ");
                scanf("%d", &id);                   
                adicionarAviao(&fila, nome, id);    
                break;
            case 4:
                listarAvioes(&fila);                
                break;
            case 5:
                listarPrimeiroAviao(&fila);         
                break;
            case 0:
                printf("Saindo...\n");              
                break;
            default:
                printf("Opção inválida.\n");        
                break;
        }
    } while (opcao != 0);                           

    return 0;
}
