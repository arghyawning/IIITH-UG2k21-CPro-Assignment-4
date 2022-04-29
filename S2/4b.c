#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        FILE *inputFile = fopen(argv[1], "r");
        FILE *meanFile = fopen(argv[2], "r");
        FILE *outputFile = fopen(argv[3], "w");

        int i, n = 0, flag = 0;
        double mean, sum = 0.0, x, num, var = 1.0, tvar = 1.0, sumsq = 0.0, tnum, tsum = 0.0;

        fscanf(meanFile, "%lf", &mean);

        while (1)
        {
            flag = (fscanf(inputFile, "%lf", &x));
            if (flag < 0)
                break;
            num = (x - mean) * (x - mean);
            sum = sum + num;
            n++;

            sumsq = sumsq + (x * x);
            tsum = tsum + x;
            tnum = sumsq - ((tsum * tsum) / (double)n);
            if (n == 1)
                tvar = tnum / (double)(n);
            else
                tvar = tnum / (double)(n - 1);
            printf("%lf\n", tvar);
        }

        var = sum / (double)n;

        fprintf(outputFile, "%lf\n", var);

        fclose(inputFile);
        fclose(meanFile);
        fclose(outputFile);
    }
    return 0;
}