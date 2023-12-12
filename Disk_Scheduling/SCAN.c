#include <stdio.h>
void main()
{
    int ioq[20], i, n, j, ihead, temp, scan, tot;
    float seek = 0, avgs;

    printf("Enter the number of requests\t:");
    scanf("%d", &n);
    printf("Enter the initial head position\t:");
    scanf("%d", &ihead);
    ioq[0] = ihead;
    ioq[1] = 0;
    n += 2;
    printf("Enter the I/O queue requests \n");
    for (i = 2; i < n; i++)
    {
        scanf("%d", &ioq[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {

            if (ioq[j] > ioq[j + 1])
            {

                temp = ioq[j];
                ioq[j] = ioq[j + 1];
                ioq[j + 1] = temp;
            }
        }
    }
    ioq[n] = ioq[n - 1];
    for (i = 0; i < n; i++)
    {

        if (ihead == ioq[i])
        {

            scan = i;
            break;
        }
    }

    printf("\nOrder of request served\n\n");
    tot = 0;
    for (i = scan; i >= 0; i--)
    {
        // rai  tot = ioq[i+1] - ioq[i];
        tot = ioq[i] - ioq[i - 1];        // me
        if (i == 0)                       // me
            tot = ioq[i] - ioq[scan + 1]; // me
        if (tot < 0)
            tot = tot * -1;
        // seek += tot;
        printf("%d\t%d\n", ioq[i], tot);
    }

    for (i = scan + 1; i < n; i++)
    {
        tot = ioq[i + 1] - ioq[i];
        if (tot < 0)
            tot = tot * -1;
        // seek += tot;
        printf("%d\t%d\n", ioq[i], tot);
    }
    seek = ihead + ioq[n - 1];

    avgs = seek / (n - 2);

    printf("\n\nTotal Seek time\t\t: %.2f", seek);
    printf("\nAverage seek time\t: %.2f\n\n", avgs);
}
