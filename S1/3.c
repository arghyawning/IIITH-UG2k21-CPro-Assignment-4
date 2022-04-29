#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(13);
    int i, j, freq = 0;
    double x, y, s = 0.0, pi = 0;
    int n[] = {10, 20, 100, 1000, 10000, 100000, 1000000};

    FILE *outputFile = fopen("q3output.txt", "w");

    for (j = 0; j < 7; j++)
    {
        freq = 0;
        for (i = 0; i < n[j]; i++)
        {
            // generating co-ordinates of random points within the square
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;

            s = (x * x) + (y * y);
            if (s < 1.0)
                freq++;
        }

        pi = (double)freq / (double)n[j];
        pi *= 4.0;

        // writing the values of pi
        fprintf(outputFile, "%lf\n", pi);
    }

    fclose(outputFile);
    return 0;
}