// Allocating memory dynamically helps us to store data without initially knowing the size of the data in the time we wrote the program.

// sizeof 是一個編譯時運算符，它在編譯期間就被處理和解析，不會等到程式執行時才執行。
// sizeof 沒有運算開銷

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} point;


void dynamic_allocation() {
    point *mypoint = (point *)malloc(sizeof(point));
    mypoint->x = 10;
    mypoint->y = 5;
    printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);
    free(mypoint);
}

void static_allocation() {
    point mypoint;
    mypoint.x = 10;
    mypoint.y = 5;
    printf("mypoint coordinates: %d, %d\n", mypoint.x, mypoint.y);
}

int main() {
    dynamic_allocation();
    static_allocation();
  return 0;
}