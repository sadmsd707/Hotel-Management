#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define size 80

struct stack
{
    double s[size];
    int top;
} st;

void push(double val)
{
    if (st.top >= size - 1)
        printf("\n stack full");
    st.top++;
    st.s[st.top] = val;
}

double pop()
{
    double val;
    if(st.top == -1)
        printf("\n stack is empty");
    val = st.s[st.top];
    st.top--;
    return val;
}

double post(char exp[])
{
    char ch, *type;
    double result, val, op1, op2;
    void push(double);
    double pop();
    int i;
    st.top = -1;
    i = 0;
    ch = exp[i];

    while(ch != '$')
    {
        if(ch >= '0' && ch <= '9')
            type = "operand";
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            type = "operator";

        if(strcmp(type, "operand") == 0)
        {
            val = ch - 48;
            push(val);
        }
        else if(strcmp(type, "operator") == 0)
        {
            op2 = pop();
            op1 = pop();
            switch(ch)
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }
            push(result);
        }
        i++;
        ch = exp[i];
    }
    result = pop();
    return result;
}

void main()
{
    char exp[size];
    int len;
    double result;
    double post(char []);
    clrscr();
    printf("\nEnter a postfix expression : ");
    scanf("%s", exp);
    len = strlen(exp);
    exp[len] = '$';
    result = post(exp);
    printf("\n the value of the expression is %f", result);
    getch();
}
