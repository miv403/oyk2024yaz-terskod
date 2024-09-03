#include <stdio.h>

#define OGR_MAX 15

struct Ogrenci {
  char isim[32];
  char soyisim[32];
  int no;
};

int main(void) {

  struct Ogrenci ogrenciler[OGR_MAX];
  int i = 0;

  for(i = 0; i < 15; i++) {
  printf("Ogrenci %d isimi giriniz\n", i);
  scanf("%31s",ogrenciler[i].isim);

  printf("Ogrenci %d soy isimi giriniz\n", i);
  scanf("%31s",ogrenciler[i].soyisim);

  printf("Ogrenci %d numara giriniz\n", i);
  scanf("%d",&ogrenciler[i].no);
  }

  for(i = 0; i < 15; i++) {
  printf("%d. Okunan isim: %s\n",i,ogrenciler[i].isim);

  printf("%d. Okunan soyisim: %s\n",i,ogrenciler[i].soyisim);

  printf("%d. Okunan no: %d\n",i,ogrenciler[i].no);
  }

  return 0;
}