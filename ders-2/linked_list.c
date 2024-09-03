#include <stdio.h>
#include <stdlib.h>

struct Node {
    void *next;
    int data;
};

int main(void) {

    struct Node *head,*tmp;
    int i = 0;
    int adet = 10;

    printf("%ld\n", sizeof(struct Node));
    head = malloc(sizeof(struct Node));
    tmp = head;

    for(i = 0; i < adet; i++) { // 10 tane düğüm oluşturulur
        tmp->next = malloc(sizeof(struct Node));
        tmp->data = i*7;
        tmp = tmp->next;
    }

    tmp = head;

    while(tmp->next != NULL) {
        printf("Node loc: %p\n",tmp);
        printf("Node data: %d\n",tmp->data);
        tmp = tmp->next;
    }
}
