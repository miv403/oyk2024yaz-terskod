#include <stdio.h>
#include <stdlib.h>

/*
struct Ogrenci {
    char isim[32];
    char soyisim[32];
    int no;
};
*/

int main(void) {

    int *a = malloc(sizeof(int));
    double *b = malloc(sizeof(double));
    char *c = malloc(sizeof(char));

    printf("A adresi: %p\n", a);
    printf("B adresi: %p\n", b);
    printf("C adresi: %p\n", c);

    printf("A adresi: %p\n", a + 1);
    printf("B adresi: %p\n", b + 1);
    printf("C adresi: %p\n", c + 1);

/*
    char isim[10];
    int int_array[10];
    scanf("%s", isim);
    printf("okunan isim: %s\n", isim);
*/
}