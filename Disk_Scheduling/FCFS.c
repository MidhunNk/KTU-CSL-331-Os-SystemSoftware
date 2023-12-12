
#include <stdio.h>
void main()
{

    int ioq[20], i, n, ihead, tot;
    float seek = 0, avgs;

    printf("Enter the number of requests\t:");
    scanf("%d", &n);
    printf("Enter the initial head position\t:");
    scanf("%d", &ihead);
    ioq[0] = ihead;
    ioq[n + 1] = 0;

    printf("Enter the I/O queue requests \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &ioq[i]);
    }
    ioq[n + 1] = ioq[n]; // to set the last seek zero

    printf("\nOrder of request served\n");
    for (i = 0; i <= n; i++)
    {

        tot = ioq[i + 1] - ioq[i];
        if (tot < 0)
            tot = tot * -1;
        seek += tot;
        // printf("%d\t%d\n",ioq[i],tot);// to display each seek
        printf("%d --> ", ioq[i]);
    }

    avgs = seek / (n);

    printf("\nTotal Seek time\t\t: %.2f", seek);
    printf("\nAverage seek time\t: %.2f\n\n", avgs);
}
