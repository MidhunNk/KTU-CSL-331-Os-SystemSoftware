#include<stdio.h>
void main(){
    int tr[20],n,cr,i,new,sum=0;
    printf("Enter the number of tracks: ");
    scanf("%d",&n);
    printf("Enter the current track: ");
    scanf("%d",&cr);
    printf("Enter the tracks: ");
    for(i=0;i<n;i++){
        new =0;
        scanf("%d",&tr[i]);
        new = cr - tr[i];
        if(new<0){
            new = tr[i]-cr;
        }
        cr = tr[i];
        sum = sum + new;

    }
    printf("The Traversed path is: ");
    for(i=0;i<n;i++){
        printf("%d =>",tr[i]);
    }
    printf("\nTotal Seek Time: %d",sum);
}