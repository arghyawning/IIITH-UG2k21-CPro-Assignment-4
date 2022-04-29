#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char str[][21], int n)
{
    int sc = 0;
    char temp[21];

    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (strcmp(&str[i][0], &str[i + 1][0]) < 0)
            continue;
        else
        {
            sc++;
            strcpy(temp, &str[i][0]);
            strcpy(&str[i][0], &str[i + 1][0]);
            strcpy(&str[i + 1][0], temp);
        }
    }

    if (sc > 0)
        sort(str, n - 1);
}

int main(int argc, char **argv)
{
    FILE *outputFile = fopen(argv[1], "w");

    int i, a, flag, n = 0, j;
    char c;
    char str[1001][21];

    FILE *inputFile;

    for (j = 2; j < argc; j++)
    {
        inputFile = fopen(argv[j], "r");

        while (1)
        {
            flag = (fscanf(inputFile, "%s", &str[n][0]));

            if (flag < 0)
                break;
            else
                n++;
        }
        fclose(inputFile);
    }

    int freq[n];
    for (i = 0; i < n; i++)
        freq[i] = 0;

    sort(str, n);

    int p = 0;
    freq[p] = 1;
    for (i = 1; i < n; i++)
    {

        if (strcmp(str[i], str[i - 1]) == 0)
            freq[p]++;
        else
        {
            fprintf(outputFile, "%s:%d\n", &str[i - 1][0], freq[p]);
            freq[++p] = 1;
        }
    }
    if (i == n)
        fprintf(outputFile, "%s:%d\n", &str[i - 1][0], freq[p]);

    fclose(outputFile);

    return 0;
}