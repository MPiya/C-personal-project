#include <stdio.h>
int main()
{
    int a, b, c, d;

    printf("Please enter two positive numbers ");
    scanf("%d %d",&a,&b);
if(a < 0 && b < 0) {
        printf("Enter the right numbers");
}
    for(c=1; c <= a && c <= b; c++)

    {

        if(a%c==0 && b%c==0){
          d = c;
        }

    }

    printf("Greatest divisor for %d and %d is %d", a, b, d);

    return 0;
}
