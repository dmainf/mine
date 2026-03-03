#include <stdio.h>
int main() {
    int x, c;
    scanf("%d", &x);
    scanf("%d", &c);
    int ans=0;
    while(1) {
        if(x-(1000+c)<0) break;
        x-=1000+c;
        ans+=1000;
    }
    printf("%d\n", ans);
}