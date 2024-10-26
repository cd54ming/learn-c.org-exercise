#include <stdio.h>
#include <stdbool.h>

void test()
{
    // "break" directive test
    while (true)
    {
        printf("This will not print forever.\n");
        break;
    }

    // "continue" directive test
    int i = 0;
    while (i <= 10)
    {
        i++;

        if (i % 2 == 1)
        {
            continue;
        }
        printf("The number %d is even.\n", i);
    }
}

// The array variable consists of a sequence of ten numbers. Inside the while loop, you must write two if conditions, which change the flow of the loop in the following manner (without changing the printf command):

// If the current number which is about to printed is less than 5, don't print it.
// If the current number which is about to printed is greater than 10, don't print it and stop the loop.
// Notice that if you do not advance the iterator variable i and use the continue derivative, you will get stuck in an infinite loop.

int main()
{
    test();

    int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int i = 0;

    while (i < 10)
    {
        if (array[i] < 5)
        {
            i++;
            continue;
        }
        else if (array[i] > 10)
        {
            break;
        }

        printf("%d\n", array[i]);
        i++;
    }

    return 0;
}