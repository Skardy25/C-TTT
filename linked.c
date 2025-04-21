// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* Insert(struct Node* head, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

void Print(struct Node* heap){
    while( heap != NULL)
    {
        printf(" %d", heap->data);
        heap = heap->next;
    }
    printf("\n");
}

struct Node* InsertPos(struct Node* head, int n, int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if(n == 0){
        temp->next = head;
        head = temp;
        return head;
    }
    struct Node* aux = head;
    for(int i=0; i< n-1;i++){
        if(aux == NULL){ 
            printf("Posición inválida.\n");
            free(temp);
            return head;
        }
        aux = aux->next;
    }
    
    if(aux == NULL){
        struct Node* current = head;
        if(head == NULL){ 
            temp->next = head;
            head = temp;
            return head;
        }
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
        return head;
    }

    temp->next = aux->next;
    aux->next = temp;
    return head; 
}
int get(struct Node* heap, int idx){
    int counter= 0;
    while(heap != NULL){
        if(counter == idx){
            return heap->data;
        }
        heap = heap->next;
        counter++;
    }
    printf("Valor no encontrado , retorna -1");
    return -1;
}

int main() {
    // Write C code here
    struct Node* head = NULL;
    int n,i,x;
    printf("¿Cuantos numeros deseas agregar? \n");
    scanf("%d", &n);
    for(i =0; i < n; i++){
        printf("Ingresa el numero \n");
        scanf("%d", &x);
        head = Insert(head,x);
    }
    head = InsertPos(head,0,90);
    Print(head);
    return 0;
}
