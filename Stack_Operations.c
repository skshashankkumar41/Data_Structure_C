#include <stdio.h>
#include <stdlib.h>

int stack[5];
int top=0;

int isFull()
{
    if(top==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int ele)
{
    if(isFull())
    {
        printf("Stack is Full...\n");
    }
    else
    {
        stack[top]=ele;
        top++;
        printf("Element Pushed...\n");
    }

}

int isEmpty()
{
    if(top==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty...\n");
    }
    else
    {
        int ele;
        top--;
        ele=stack[top];
        printf("Item Popped:%d\n",ele);
    }
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("Stack is Empty...\n");
    }
    else
    {
      for(i=top-1;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
    }

}

int main()
{
    int ch;


    while(ch!=4)
    {
    printf("Data Structure Stack\n");
    printf("Choose Options\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
         switch(ch)
    {
        case 1:printf("Enter Element to Insert\n");
        int ele;
        scanf("%d",&ele);
        push(ele);
        break;

        case 2:pop();
        break;

        case 3:display();
        break;

        case 4:exit(0);
        break;

        default:printf("Invalid Entry\n");
    }
    }
    return 0;
}
