#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        FILE *inputFile = fopen(argv[1], "r");
        FILE *meanFile = fopen(argv[2], "r");
        FILE *outputFile = fopen(argv[3], "w");

        int n = 0, flag = 0;
        double mean, pc, x, lo, hi, c = 0;

        fscanf(meanFile, "%lf", &mean);
        lo = 0.8 * mean;
        hi = 1.2 * mean;

        while (1)
        {
            flag = (fscanf(inputFile, "%lf", &x));
            if (flag < 0)
                break;
            if (x >= lo && x <= hi)
                c++;
            n++;
        }

        pc = (double)(100 * c) / (double)n;

        fprintf(outputFile, "%lf %%\n", pc);
        printf("%lf %%\n", pc);

        fclose(inputFile);
        fclose(meanFile);
        fclose(outputFile);
    }
    return 0;
}
