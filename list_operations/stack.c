#include<stdio.h>

int stack[10],choice,n,top,x,i;

void push(void);
void pop(void);
void display(void);

int main()
{
   
    top=-1;
    printf("\n Enter the size of STACK (maximum 10):");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS ");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}

void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is full");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t No elements to pop");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK are, \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}