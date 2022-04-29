#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    srand(time(0));

    if (argc == 4)
    {
        FILE *input = fopen(argv[1], "r");
        FILE *key = fopen(argv[2], "w");
        FILE *output = fopen(argv[3], "w");

        int k[127];
        int bin[8];

        int i, a, j, bni = 126;
        unsigned char c;

        for (i = 0; i < 127; i++)
        {
            k[i] = rand() % 2;
            fprintf(key, "%d", k[i]);
        }

        fclose(key);
        int flag = 0;
        while (1)
        {
            // taking one character
            flag = fscanf(input, "%c", &c);
            if (flag < 0)
                break;
            // taking its ascii value
            a = (int)c;

            j = 7;

            while (a > 0)
            {
                bin[j--] = a % 2;
                a /= 2;
            }
            for (i = 0; i <= j; i++)
                bin[i] = 0;
            // 8 binary bits generated correctly (verified)

            for (i = 0; i < 8; i++)
            {
                bni++;

                // getting key value
                if (bni % 127 == 0)
                {
                    //if (flag > 0)
                        
                    k[bni - 127] = k[bni - 1] ^ k[bni - 127];
                    bni -= 127;
                }
                else
                    k[bni] = k[bni - 1] ^ k[bni];

                //flag = 1;

                // printf("%d", k[bni-127]);
                fprintf(output, "%d", (bin[i] ^ k[bni]));
                // printf("%d", (bin[i] ^ k[bni]));
            }
        }
        fclose(input);
        fclose(output);
    }
    return 0;
}