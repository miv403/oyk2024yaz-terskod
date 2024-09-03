#include <stdio.h>
#include <stdlib.h>

struct Ogrenci {
  char isim[32];
  char soyisim[32];
  int no;
};

int main(void) {

  struct Ogrenci *ogrenciler;
  int i = 0;

  ogrenciler = malloc(sizeof(struct Ogrenci) * 10000);

  for(i = 0; i < 15; i++) {
  printf("Ogrenci %d isimi giriniz\n", i);
  scanf("%31s",ogrenciler->isim);

  printf("Ogrenci %d soy isimi giriniz\n", i);
  scanf("%31s",ogrenciler->soyisim);

  printf("Ogrenci %d numara giriniz\n", i);
  scanf("%d",&ogrenciler->no);
  }

  for(i = 0; i < 15; i++) {
  printf("%d. Okunan isim: %s\n",i,ogrenciler[i].isim);

  printf("%d. Okunan soyisim: %s\n",i,ogrenciler[i].soyisim);

  printf("%d. Okunan no: %d\n",i,ogrenciler[i].no);
  }

  return 0;
}