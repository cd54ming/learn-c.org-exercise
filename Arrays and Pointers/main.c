// 取得變數地址的方法： &variable_name, variable_name + index
// 取得變數值的方法： variable_name[index], *(variable_name + index)

// the name of an array itself is a *constant* pointer to the first element of the array.

// 使用陣列時，我們需要事先知道陣列元素的數量，這可能導致記憶體分配過多或過少。
// 過多會造成記憶體浪費，過少則可能導致記憶體區段錯誤 (segmentation fault)。
// 使用動態記憶體分配 (Dynamic Memory Allocation) 可以在程式執行時分配適當的記憶體空間，避免上述問題。
// 當不再需要這些記憶體時，可以使用 free() 釋放它們。
// 但同時，也需要注意避免記憶體洩漏 (Memory Leak)。

#include <stdio.h>
#include <stdlib.h>

void print_vowels() {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char *pvowels = vowels;

    printf("print address: \n");
    for (int i = 0; i < 5; i++) {
        printf("&vowels[%d]: %p, vowels + %d: %p\n", i, &vowels[i], i, vowels + i);
        printf("&pvowels[%d]: %p, pvowels + %d: %p\n", i, &pvowels[i], i, pvowels + i);
        printf("----------------------------------------\n");
    }

    printf("\n\n\n");

    printf("print value: \n");
    for (int i = 0; i < 5; i++) {
        printf("vowels[%d]: %c, *(vowels + %d): %c\n", i, vowels[i], i, *(vowels + i));
        printf("pvowels[%d]: %c, *(pvowels + %d): %c\n", i, pvowels[i], i, *(pvowels + i));
        printf("----------------------------------------\n");
    }
}

void pointer_to_a_pointer () {
    char vowels[2][5] = {
        {'a', 'e', 'i', 'o', 'u'},
        {'A', 'E', 'I', 'O', 'U'}
    };

    int rows = 2;
    int cols = 5;
    int **pvowels = (int **) malloc(rows * sizeof(int *));
    pvowels[0] = (int *) malloc(cols * sizeof(int));
    pvowels[1] = (int *) malloc(cols * sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pvowels[i][j] = vowels[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", pvowels[i][j]);
        }
        printf("\n");
    }

    free(pvowels[0]);
    free(pvowels[1]);
    free(pvowels);
}

void pascal_triangle(int n) {
    int **pascal = (int **) malloc(n * sizeof (int *));

    for (int i  = 0; i < n; i++) {
        pascal[i] = (int *) malloc((i + 1) * sizeof(int));
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(pascal[i]);
    }
    free(pascal);
}

int main () {
    print_vowels();
    printf("\n\n\n");
    pointer_to_a_pointer();
    printf("\n\n\n");
    pascal_triangle(5);
    return 0;
}