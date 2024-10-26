// char can range from -128 to 127
// long can range from -2,147,483,648 to 2,147,483,647 (32bit, but range from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 in 64-bit systems)

//  C does not have a boolean type. Usually, it is defined using the following notation:
 #define BOOL char
 #define FALSE 0
 #define TRUE 1

#include <stdio.h>

int main() {
  int a = 3;
  float b = 4.5;
  double c = 5.25;
  float sum;

    sum = a + b + c;

  printf("The sum of a, b, and c is %f.", sum);
  return 0;
}