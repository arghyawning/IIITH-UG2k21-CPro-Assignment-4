#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));

    int i, n = 1000000, x0 = 0, r0 = 0, x1 = 0, r1 = 0, x;
    int a[1000000];
    double px0, px1, pr0, pr1;
    
    for (i = 0; i < 127; i++)
        a[i] = rand() % 2;
    for (i = 127; i < n; i++)
    {
        x = rand() % 2;
        if (x == 0)
            r0++;
        else
            r1++;

        a[i] = a[i - 1] ^ a[i - 127];
        if (a[i] == 0)
            x0++;
        else
            x1++;
    }

    px0 = (double)x0 / (double)(n - 127);
    px1 = (double)x1 / (double)(n - 127);
    pr0 = (double)r0 / (double)(n - 127);
    pr1 = (double)r1 / (double)(n - 127);

    printf("P(0) for XOR method: %lf\n", px0);
    printf("P(1) for XOR method: %lf\n\n", px1);

    printf("P(0) for rand() method: %lf\n", pr0);
    printf("P(1) for rand() method: %lf\n", pr1);
}