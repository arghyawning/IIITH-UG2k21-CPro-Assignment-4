#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{

    if (argc == 4)
    {
        FILE *input = fopen(argv[2], "r");
        FILE *key = fopen(argv[1], "r");
        FILE *output = fopen(argv[3], "w");

        int n = 100000;
        int str[8 * n];
        int k[127];

        int i = 0, a, j, p = 0, l = 0, d, flag;
        unsigned char c;

        // extracting key
        /*
                while (1)
                {
                    flag = fscanf(input, "%c", &c);
                    if (flag < 0)
                        break;

                    k[i++] = c - '0';
                }
          */
        for (i = 0; i < 127; i++)
        {
            fscanf(key, "%c", &c);
            k[i] = c - '0';
        }

        fclose(key);

        // extracting encrypted bits
        // printf("HI");
        i = 0;
        while (1)
        {
            flag = fscanf(input, "%c", &c);
            if (flag < 0)
                break;

            str[i++] = (int)c - (int)'0';
            //printf("%c", c);
        }
        l = i;
        fclose(input);

        // getting extended key
        int tk[l + 127];
        for (i = 0; i < l + 127; i++)
        {
            if (i >= 127)
                tk[i] = tk[i - 1] ^ tk[i - 127];
            else
                tk[i] = k[i];
        }

        // decrypting :(
        //printf("%d\n",l);
        p=0;
        for (i = 0; i < l / 8; i++)
        {
            d = 0;
            for (j = 0; j < 8; j++)
            {
                a = str[p] ^ tk[p + 127];
                d = d + a * (int)pow(2, (8 - j - 1));
                //printf("%d\n",d);
                p++;
            }
            //printf("%c\n",(char)d);
            fprintf(output, "%c", (char)d);
        }

        fclose(output);
    }
    return 0;
}
//./a.out k.txt e.txt omg.png
