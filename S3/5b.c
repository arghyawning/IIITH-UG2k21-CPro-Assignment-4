#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));

    int i, n = 1000000, x0 = 0, r0 = 0, x1 = 0, r1 = 0, x, y, cx1 = 0, cx0 = 0, cr0 = 0, cr1 = 0;
    int a[1000000];
    double px0, px1, pr0, pr1;

    for (i = 0; i < 127; i++)
        a[i] = rand() % 2;
    x = a[126];

    for (i = 127; i < n; i++)
    {
        y = rand() % 2;
        if (x == 0)
        {
            cr0++;
            if (y == 0)
                r0++;
        }
        else
        {
            cr1++;
            if (y == 0)
                r1++;
        }
        x = y;

        a[i] = a[i - 1] ^ a[i - 127];
        if (a[i - 1] == 0)
        {
            cx0++;
            if (a[i] == 0)
                x0++;
        }
        else
        {
            cx1++;
            if (a[i] == 0)
                x1++;
        }
    }

    px0 = (double)x0 / (double)cx0;
    px1 = (double)x1 / (double)cx1;
    pr0 = (double)r0 / (double)cr0;
    pr1 = (double)r1 / (double)cr1;

    printf("P(0/0) for XOR method: %lf\n", px0);
    printf("P(0/1) for XOR method: %lf\n\n", px1);

    printf("P(0/0) for rand() method: %lf\n", pr0);
    printf("P(0/1) for rand() method: %lf\n", pr1);
}