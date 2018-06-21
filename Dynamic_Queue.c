#include <stdio.h>
#include <stdlib.h>

int *queue,*front,*rear;
int size;
size=5;

void create()
{
    queue=(int *)calloc(size,sizeof(int));
    if(queue==NULL)
    {
        printf("Out of Memory\n");

    }
    else
    {
        front=rear=queue;
    }
}

int isFull()
{
    if(queue+size==rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert(ele)
{
        if(isFull())
        {
            size++;
            queue=(int *)realloc(queue,size*sizeof(int));
            if(queue==NULL)
            {
                printf("Memory Full...\n");
            }
            else
            {
                *rear=ele;
                rear++;
                printf("Inserted...\n");
            }
        }

        else
        {
            *rear=ele;
            rear++;
            printf("Inserted...\n");
        }
}

int isEmpty()
{
    if(front==rear)
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
        int ele,*i;
        ele=*front;
        for(i=front;i<rear-1;i++)
        {
            *i=*(i+1);
        }
        rear--;
         if (size>5)
    {
        size--;
        queue=(int *)realloc(queue,size*sizeof(int));
    }
    printf("Deleted Element is %d\n",ele);
            }

}

void display()
{
    int *i;
    for(i=front;i<rear;i++)
    {
        printf("%d\n",*i);
    }
    printf("\n");
}

int main()
{
    create();
   int ch;


    while(ch!=4)
    {
    printf("Data Structure Dynamic_Queue\n");
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
