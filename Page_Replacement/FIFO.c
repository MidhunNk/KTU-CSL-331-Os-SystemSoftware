#include <stdio.h>

void main()
{
    int n, f, fr[20], p[50], rep = 0, found, fi = 0;
    int i, k;
    printf("Enter the number of pages ");
    scanf("%d", &n);

    printf("Enter the reffrence string : ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the frame number  :");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        fr[i] = -1;

    printf("\n\nPages\t\tFrames\n\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", p[i]);
        found = 1;
        for (k = 0; k < f; k++)
        {

            if (p[i] == fr[k])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {

            fr[fi] = p[i];
            rep++;
            fi = (fi + 1) % f;
            for (k = 0; k < f; k++)
                printf("%d\t", fr[k]);
        }
        printf("\n");
    }
    printf("\n\nNumber of page fault : %d\n", rep);
}
