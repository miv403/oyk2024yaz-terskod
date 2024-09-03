#include <stdbool.h> // Bool veri tipi için
#include <stdio.h>

void print_lkd() { printf("Merhaba LKD\n"); }

int main() {

  char *char_var;
  float *float_var ;
  double *double_var ;
  int *integer_var;
  short *short_var;
  bool *bool_var;
  long *long_var;
  unsigned char *uchar_var;
  unsigned int *uinteger_var;
  unsigned short *ushort_var;
  unsigned long *ulong_var;
  void *abc;

  print_lkd();

  printf("Char boyutu: %ld\n", sizeof(char_var));
  printf("Float boyutu: %ld\n", sizeof(float_var));
  printf("Double boyutu: %ld\n", sizeof(double_var));
  printf("Integer boyutu: %ld\n", sizeof(integer_var));
  printf("Short boyutu: %ld\n", sizeof(short_var));
  printf("Bool boyutu: %ld\n", sizeof(bool_var));
  printf("Long boyutu: %ld\n", sizeof(long_var));
  printf("Unsigned Char boyutu: %ld\n", sizeof(uchar_var));
  printf("Unsigned Integer boyutu: %ld\n", sizeof(uinteger_var));
  printf("Unsigned Short boyutu: %ld\n", sizeof(ushort_var));
  printf("Unsigned Long boyutu: %ld\n", sizeof(ulong_var));
  printf("Void boyutu: %ld\n", sizeof(abc));

  int x = 20;
  float z = 0.3;

  printf("X Degeri: %d\n", x);
  printf("Y Degeri: %f\n", z);

  return 0;
}

int toplam(int a, int b) {
  int c = a + b;
  return c;
}