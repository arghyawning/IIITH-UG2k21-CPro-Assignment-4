#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //printf("HI\n");
    if (argc == 4)
    {

        int i, a, flag, n = 0, j;
        
        int mw=1000000,ml=15,nl;
        //max words, max length, now length

        char **str;
        str=(char **)malloc(mw*sizeof(char *));

        FILE *inputFile;

        // inputting file 1 words
        inputFile = fopen(argv[1], "r");
        //printf("HI\n");
        while (1)
        {
            char temp[ml];
            flag = (fscanf(inputFile, "%s", temp));

            if (flag < 0)
                break;
            else
            {
                nl=strlen(temp);
                str[n]=(char *)malloc(nl+1);
                strcpy(str[n++],temp);
                //printf("1%s\n", &str[n][0]);
            }
        }
        fclose(inputFile);

        // dealing with file 2 now
        inputFile = fopen(argv[2], "r");
        FILE *outputFile = fopen(argv[3], "w");

        i = 0;
        while (1)
        {
            char temp[16];
            flag = (fscanf(inputFile, "%s", &temp[0]));

            if (flag < 0)
                break;
            else
            {
                for (; i < n; i++)
                {
                    if (strcmp(&str[i][0], &temp[0]) <= 0)
                        fprintf(outputFile, "%s\n", &str[i][0]);
                    else
                    {
                        fprintf(outputFile, "%s\n", &temp[0]);
                        break;
                    }
                }
                if (i == n)
                    fprintf(outputFile, "%s\n", &temp[0]);
            }
        }
        fclose(inputFile);
        
        fclose(outputFile);
    }
    return 0;
}