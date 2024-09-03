#include <stdio.h>


int topla(int a, int b, int c, int d, int e) {
    return a + b + c + d + e;
}

int main(void) {

    int a = 5, b = 4, c = 3, d = 2, e = 1;
    int f = topla(a, b, c, d, e);
    printf("%s%d%s", "sonuc: ", f, "\n");
    return 0;
}


