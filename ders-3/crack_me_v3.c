#include <stdio.h>

void myfunc() {
    int x;
    *(&x+3) += 7;
}

int main() {
    int a = 0;
    a = 2;
    myfunc();
    a = 5;
    printf("%d\n", a);
}
