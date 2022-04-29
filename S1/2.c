#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(13);
    int i, x, y, n = 1e6;
    int freq[11] = {0};
    for (i = 0; i < n; i++)
    {
        // generating random number within 1 to 6
        x = (rand() % 6) + 1;
        y = (rand() % 6) + 1;

        freq[x + y - 2]++;
    }

    FILE *outputFile = fopen("q2output.txt", "w");

    // printing output
    printf("Sum\tFrequency\n");
    for (i = 0; i < 11; i++)
    {
        printf("%d\t%d\n", (i + 2), freq[i]);
        fprintf(outputFile, "%d\n", freq[i]);
    }

    fclose(outputFile);
    return 0;
}