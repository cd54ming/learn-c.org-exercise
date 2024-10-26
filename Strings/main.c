// can only use for reading.
// char * name = "John";

// The reason that we need to add one, although the string John Smith is exactly 10 characters long, is for the string termination: a special character (equal to 0) which indicates the end of the string. 
// char name[] = "John Smith";
// char name[11] = "John Smith";


// strlen(str)
// strncmp(str1, str2, n)
// strncat(dest, src, n)


// Define the string first_name with the value John using the pointer notation, and define the string last_name with the value Doe using the local array notation.

#include <stdio.h>
#include <string.h>

int main() {
    char name2[5] = "John";

    if (strncmp(name2, "John", sizeof(name2)) == 0) {
        printf("Hello, John!\n");
    } else {
        printf("You are not John. Go away.\n");
    }

    char dest[20]="Hello";
    char src[20]="World";
    strncat(dest,src,3);
    printf("%s\n",dest);
    strncat(dest,src,20);
    printf("%s\n",dest);


    char * first_name = "John";
    char last_name[] = "Doe";
    char name[100];

    last_name[0] = 'B';
    sprintf(name, "%s %s", first_name, last_name);
    if (strncmp(name, "John Boe", 100) == 0) {
        printf("Done!\n");
    }
    name[0]='\0';
    strncat(name, first_name, 4);
    strncat(name, last_name, 20);
    printf("%s\n", name);

    return 0;
}