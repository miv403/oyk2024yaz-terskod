#include <stdio.h>


int topla(int a, int b) {

    return a + b;
}

int main(void) {

    int a = 5, b = 4;
    int c = topla(a, b);
    printf("%s%d%s", "sonuc: ", c, "\n");
    return 0;
}


