#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    FILE *outputFile = fopen(argv[1], "w");

    int freq[62] = {0};
    int i, a, j;
    char c;

    FILE *inputFile;

    for (j = 2; j < argc; j++)
    {
        inputFile = fopen(argv[j], "r");
        while (1)
        {
            c = fgetc(inputFile);
            if (c == EOF)
                break;
            a = (int)c;
            if (a >= 48 && a <= 57)
                freq[a - 48]++;
            else if (a >= 65 && a <= 90)
                freq[a - 55]++;
            else if (a >= 97 && a <= 122)
                freq[a - 61]++;
        }
        fclose(inputFile);
    }

    for (i = 0; i < 62; i++)
    {
        if (i < 10)
            a = 48 + i;
        else if (i >= 10 && i <= 35)
            a = i + 55;
        else if (i >= 36 && i <= 61)
            a = i + 61;
        c = (char)a;
        fprintf(outputFile, "%c:%d\n", c, freq[i]);
    }

    fclose(outputFile);

    return 0;
}