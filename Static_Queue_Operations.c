#include <stdio.h>
#include <stdlib.h>

int queue[5];
int front=0;
int rear=0;

int isFull()
{
    if(rear==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert(int ele)
{
    if(isFull())
    {
        printf("Queue is Full...\n");
    }

    else
    {
        queue[rear]=ele;
        rear++;
        printf("Element Inserted...\n");
    }
}

int isEmpty()
{
    if(rear==front)
    {
      return 1;
    }
    else
    {
        return 0;
    }

}

void delete1()
{
    if(isEmpty())
    {
        printf("Queue is Empty...\n");
    }
    else
    {
     int ele;
     ele=queue[front];
     int i;
     for(i=front;i<rear-1;i++)
     {
         queue[i]=queue[i+1];
     }
     rear--;
     printf("Element Deleted %d\n",ele);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is Empty...\n");
    }

    else
    {
    int i;
    for(i=front;i<rear;i++)
    {
        printf("%d\n",queue[i]);
    }
    printf("\n");
    }

}

int main()
{
    int ch;


    while(ch!=4)
    {
    printf("Data Structure Queue\n");
    printf("Choose Options\n");
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
         switch(ch)
    {
        case 1:printf("Enter Element to Insert\n");
        int ele;
        scanf("%d",&ele);
        insert(ele);
        break;

        case 2:delete1();
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
