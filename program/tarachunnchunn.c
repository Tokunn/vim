#include <stdio.h>
#define N 20
void msort(int a[],int p,int n){
    int i,j,k,h,b[N];
    if(n>1){
        h=n/2;
        msort(a,p,h);
        msort(a,p+h,n-h);
        i=p;
        j=p+h;
        for(k=p;k<p+n;k++){
            if((i<p+h)&&((j>=p+n)||a[i]<=a[j])){
                b[k]=a[i];
                i++;
            }
            else{
                b[k]=a[j];
                j++;
            }
        }
        for(i=p;i<p+n;i++){
            a[i]=b[i];
        }
        for(i=0;i<N;i++){
           printf("%d:", a[i]);
        }
        printf("\n");
    }
}

int main(void){
    int a[N]={14,1,20,18,8,11,13,10,2,19,4,15,3,17,16,5,12,9,6,7};
    msort(a,0,N);
    return(0);
}
