#include <stdio.h>

int topla(int a,
          int b,
          int c,
          int d,
          int e,
          int f,
          int g,
          int h,
          int i,
          int j,
          int k,
          int l,
          int m,
          int n,
          int o
        ){
            return a + b + c + d + e + f + g + h + i + j + k + l + m + n + o;
        }

int main(void) {

    int arr[15];
    for(int i = 0; i < 15; ++i) {
        arr[i] = i;
    }
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;
    int h = 8;
    int i = 9;
    int j = 10;
    int k = 11;
    int l = 12;
    int m = 13;
    int n = 14;
    int o = 15;

    int s = topla(  a,
                    b,
                    c,
                    d,
                    e,
                    f,
                    g,
                    h,
                    i,
                    j,
                    k,
                    l,
                    m,
                    n,
                    o );
    printf("%s%d%s", "sonuc: ", s, "\n");
}