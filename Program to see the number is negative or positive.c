
//Program to accept a number and check whether the number is positive, negative or zero
#include<stdio.h>
int main()
{
	int a;
	printf(" enter number");
	scanf("%d", &a);

	if(a>0) {
        printf("positive");

	}
	else if(a<0) {
        printf("negative");
	}
	else{
        printf("is zero");
	}
}

