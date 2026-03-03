#include <stdio.h>
int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    x+=y;
    x%=12;
    if(x==0) x=12;
    printf("%d\n", x);
}