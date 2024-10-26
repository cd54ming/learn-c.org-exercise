// 遞迴常見的使用範例：
// 遍歷遞迴數據結構，如鏈表、二叉樹等。
// 探索遊戲中的可能場景，如國際象棋

// 遞迴總是由兩個主要部分組成：
// 表示遞迴何時結束的終止情況，及一個必須向終止情況進展的自身調用。
#include <stdio.h>
#include <stdlib.h>

void print_pascal(int n) {
    int **pascal = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
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

int find_pascal(int i, int j) {
    if (j == 0 || j == i) {
        return 1;
    }
    return find_pascal(i - 1, j - 1) + find_pascal(i - 1, j);
}

int fratorial (int n) {
    if (n == 0) {
        return 1;
    }
    return n * fratorial(n - 1);
}

int main () {
    int LEVEL = 2;
    int pascal_row = LEVEL - 1;
    int pascal_column = 0;

    print_pascal(LEVEL);
    printf("pascal [%d, %d] = %d\n", pascal_row, pascal_column, find_pascal(pascal_row, pascal_column));

    printf("-----------------\n");

    int n = 5;
    printf("fratorial(%d) = %d\n", n, fratorial(n));
    return 0;
}
