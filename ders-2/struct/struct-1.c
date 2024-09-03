#include <stdio.h>
#include <stdlib.h>



struct Oyuncu {
    int can;
};

void hasar_ver(struct Oyuncu* oyuncu, int n);

int main (void) {

    char isim[10];
    scanf("%s", isim);
    printf("okunan isim: %s\n", isim);
    int yas;
    scanf("%d", &yas);
    printf("Okunan yas: %d\n", yas);

    int int_array[10];
    int *buyuk_alan = malloc(sizeof(int) * 1000);

    struct Oyuncu *oyuncu2 = (struct Oyuncu*) buyuk_alan;
    oyuncu2->can = 100;
    printf("2 Can degeri once: %d\n", oyuncu2->can);
    
    hasar_ver(oyuncu2, 30);


    return 0;
}

void hasar_ver(struct Oyuncu* oyuncu, int n) {

    oyuncu->can -= n;

}