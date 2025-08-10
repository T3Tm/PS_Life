#include <stdio.h>
int a[53],n,V,L=1;
long long C;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(;L;){//
        L=0;
        for(int z=1;z<=n-2;z++){//
            if (a[z-1]+a[z+1]<a[z]*2)V=(a[z-1]+a[z+1])/2,C+=a[z]-V,a[z]=V,L++;
        }
    }
    printf("%ld",C);
    return 0;
}