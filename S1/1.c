#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(41214);
    int i, x, n = 1e6;
    int freq[6] = {0};
    for (i = 0; i < n; i++)
    {
        // generating random number within 1 to 6
        x = (rand() % 6) + 1;

        freq[x - 1]++;
    }

    FILE *outputFile = fopen("q1output.txt", "w");

    // printing output
    printf("Number\tFrequency\n");
    for (i = 0; i < 6; i++)
    {
        printf("%d\t%d\n", (i + 1), freq[i]);
        fprintf(outputFile, "%d\n", freq[i]);
    }

    fclose(outputFile);
    return 0;
}