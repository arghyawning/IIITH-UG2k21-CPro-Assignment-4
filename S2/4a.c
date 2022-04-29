#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        FILE *inputFile = fopen(argv[1], "r");
        FILE *outputFile = fopen(argv[2], "w");

        int i, n = 0, flag = 0;
        double mean, sum = 0.0, num;

        while (1)
        {
            flag = (fscanf(inputFile, "%lf", &num));
            if (flag < 0)
                break;
            sum = sum + num;
            n++;
        }

        mean = sum / (double)n;

        printf("Mean: %lf\n", mean);
        fprintf(outputFile, "%lf\n", mean);

        fclose(inputFile);
        fclose(outputFile);
    }
    return 0;
}