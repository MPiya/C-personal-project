/*Made by Piyboot Prasertsuwan  */
/*Do not use this for busniess purpose! */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void run_calc();
void scandata(char *op, double  *operand);
void do_calc(char operatior, double number, double *sum);
/* 2 pointer declaration functions and 1 void function*/

int main()
{
    /* enclosure function*/
    run_calc();
    return 0;

}
void run_calc(){
    double sum, operand; /* float declaration*/
    char op, answer; /* string declaration */

    printf("Press enter to use the calculator\n");
    scanf("%c", &answer);
    while(answer!='q'&& answer!='Q')
    {
    printf("Enter an operator (+, -, *, /, # ,^ , @, %% or ! ) and optional operand. Enter 'q' to exit the program.");
    scandata(&op, &operand); /*store char value and float value*/
    do_calc(op, operand, &sum);  /* This function recieves inputs from scandata and calculate based on the user's decision*/
    printf("Result so far is: %.2lf \n", sum);
    }
}
void scandata(char *op, double *operand) /* store a char and number in decimal */
{
    scanf(" %c", op);
    if(*op =='+' || *op == '-' || *op == '*' || *op =='/' || *op =='^' )
    {
    scanf ("%lf", operand);
    }
}

void do_calc(char sign, double number, double *sum)
{
switch(sign)
    {
    case '+': *sum += number; break;
    case '-': *sum -= number; break;
    case '*': *sum *= number; break;
    case '/': *sum = (number == 0) ? *sum  : *sum / number; break;
    case '^': *sum = pow(*sum,number); break;
    case '#': *sum = (*sum >= 0) ? sqrt(*sum) : *sum; break; /* root of number */
    case '%': *sum *= *sum -1; break; /* change sign */
    case '!': *sum =  (1 / *sum); break;
    case '@': *sum = log(*sum); break; /*calculate natural log of number */
    case 'q': printf(" The final value of the accumulator is %.2lf \n", *sum);  exit(0); default: break;
    }
}
