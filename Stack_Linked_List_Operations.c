#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *link;
};
struct node *top=NULL;

void push()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data:");
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
    printf("Element Pushed...\n");

}

void pop()
{
    if(top==NULL)
    {
        printf("Stack is Empty...\n");
    }
    else
    {
    struct node *temp;
    temp=top;
    int ele;
    ele=temp->data;
    top=temp->link;
    temp->link=NULL;
    printf("Popped Element:%d\n",ele);
    free(temp);
    }

}

void display()
{
    if(top==NULL)
    {
        printf("Stack is Empty...\n");
    }
    else
    {
    struct node *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    }

}

int main()
{
        int ch;


    while(ch!=4)
    {
    printf("Data Structure Linked_List_Stack\n");
    printf("Choose Options\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
         switch(ch)
    {
        case 1:
        push();
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
