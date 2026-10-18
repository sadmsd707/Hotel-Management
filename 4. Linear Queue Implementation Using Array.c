#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 5

struct Queue
{
    int que[size];
    int front, rear;
} Q;

int Qfull()
{
    if(Q.rear >= size - 1)
        return 1;
    else
        return 0;
}

int insert(int item)
{
    if(Q.front == -1)
        Q.front++;
    Q.que[++Q.rear] = item;
    return Q.rear;
}

int Qempty()
{
    if((Q.front == -1) || (Q.front > Q.rear))
        return 1;
    else
        return 0;
}

int delet()
{
    int item;
    item = Q.que[Q.front];
    Q.front++;
    printf("\nDeleted item is %d ", item);
    return Q.front;
}

void display()
{
    int i;
    printf("\nThe elements are:- \n");
    for(i = Q.front; i <= Q.rear; i++)
        printf("%d ", Q.que[i]);
}

void main()
{
    int choice, item;
    char ans;
    clrscr();
    Q.front = -1;
    Q.rear = -1;
    do
    {
        printf("\nMain Menu");
        printf("\n1.Insert\n2.Delete\n3.Display");
        printf("\nEnter your choice:- ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(Qfull())
                    printf("\nQUEUE is FULL");
                else
                {
                    printf("\nEnter the element to be inserted:- ");
                    scanf("%d", &item);
                    insert(item);
                }
                break;

            case 2:
                if(Qempty())
                    printf("\nQUEUE is EMPTY");
                else
                    item = delet();
                break;

            case 3:
                if(Qempty())
                    printf("\nQUEUE is EMPTY");
                else
                    display();
                break;

            default:
                printf("\nWRONG CHOICE");
                break;
        }
        printf("\nDo you want to continue?");
        ans = getche();
    }
    while(ans == 'Y' || ans == 'y');
}
