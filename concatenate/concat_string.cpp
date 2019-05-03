#include <stdio.h>
#include <string.h>

#define DEST_SIZE 40

int main()
{
        char src[DEST_SIZE] = "Look Here";
        char dest[DEST_SIZE] = "Unimaginable";

        strcat(dest, src);
        printf(dest);

        return 0;
}
