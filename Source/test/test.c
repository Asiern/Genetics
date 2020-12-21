#include "stdio.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    int ch1, ch2;

    //Check args
    if (argc != 3)
    {
        printf("ATTENTION: not file names provided \n");
        printf("You can provide arguments as indicated: program file1 file2\n");
        //Open file 1
        f1 = fopen("../results1000.out", "r");
        //Open file 2
        f2 = fopen("../results_s.out", "r");
    }
    else
    {
        //Open file 1
        f1 = fopen(argv[1], "r");
        //Open file 2
        f2 = fopen(argv[2], "r");
    }

    if (f1 == NULL)
    {
        printf("Error opening file %s \n", argv[1]);
        exit(-1);
    }
    else if (f2 == NULL)
    {
        printf("Error opening file %s \n", argv[2]);
        exit(-1);
    }
    else
    {
        ch1 = getc(f1);
        ch2 = getc(f2);
        //Compare characters
        while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2))
        {
            ch1 = getc(f1);
            ch2 = getc(f2);
        }

        if (ch1 == ch2)
        {
            printf("Files are identical");
            printf("\n");
        }
        else
        {
            printf("Files are NOT identical");
            printf("\n");
        }
        fclose(f1);
        fclose(f2);
    }

    return 0;
}