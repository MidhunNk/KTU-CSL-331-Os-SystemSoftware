#include<stdio.h>
#include<stdlib.h>

void main()
{
 int rq[10];
 int n,cr,d,i;

 printf("Enter the number of requests: ");
 scanf("%d",&n);
    printf("Enter the requests: ");
    for(int i=0;i<n;i++)
    scanf("%d",&rq[i]);

    printf("Enter the current request: ");
    scanf("%d",&cr);

 
    printf("Enter the direction: ");
    scanf("%d",&d);

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(rq[i]>rq[j])
            {
                int temp=rq[i];
                rq[i]=rq[j];
                rq[j]=temp;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(rq[i]>cr)
        break;
    }

    int total_dis =0;
   printf("Order of service :");
   
    if(d==1)
    {
        for(int j=i;j<n;j++)
        {
            printf("%d ",rq[j]);
            total_dis+=abs(rq[j]-cr);
            cr=rq[j];
        }
       for(int j=i-1;j>=0;j--)
        {
            printf("%d ",rq[j]);
            total_dis+=abs(rq[j]-cr);
            cr=rq[j];
        }
    }
    else
    {
        for(int j=i-1;j>=0;j--)
        {
            printf("%d ",rq[j]);
            total_dis+=abs(rq[j]-cr);
            cr=rq[j];
        }
        for(int j=i;j<n;j++)
        {
            printf("%d ",rq[j]);
            total_dis+=abs(rq[j]-cr);
            cr=rq[j];
        }
    }
    printf("\nTotal distance : %d",total_dis);   
}

   


