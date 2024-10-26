// By default, variables are local to the scope in which they are defined.
// Variables can be declared as static to increase their scope up to file containing them.

// 在 C 語言中，如果將函數宣告為 static，會發生以下幾件事：
// 限制作用域：static 函數的作用域被限制在定義它的文件內。這意味著該函數不能被其他文件中的代碼直接調用。這有助於實現封裝，防止命名衝突。
// 內部鏈接：static 函數具有內部鏈接（internal linkage），這意味著編譯器在編譯該文件時只會考慮該函數，而不會將其導出到其他文件。

// Static vs Global?
// While static variables have scope over the file containing them making them accessible only inside a given file,
// global variables can be accessed outside the file too.

// In this exercise, try to find the sum of some numbers by using the static keyword. Do not pass any variable representing the running total to the sum() function.

#include <stdio.h>
int sum(int num)
{
    static int total = 0;
    total += num;
    return total;
}

int main()
{
    printf("%d ", sum(55));
    printf("%d ", sum(45));
    printf("%d ", sum(50));
    return 0;
}