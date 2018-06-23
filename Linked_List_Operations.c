#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *link;
};

struct node *root=NULL;

void create()
{
    struct node *temp,*p;
    while(1)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter Node Data:");
        scanf("%d",&temp->data);

        if(root==NULL)
        {
            root=temp;
            p=temp;
        }
        else
        {
            p->link=temp;
            p=temp;
        }
        printf("Do you want to Continue (y/n):");
        if(getche()=='n')
        {
            p->link=NULL;
            printf("\n");
            break;
        }
        else{
            printf("\n");
        }

    }


}

void append()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data:");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL)
    {
        root=temp;
        printf("Inserted...\n");
    }
    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
        printf("Inserted...\n");
    }
}

void addfirst()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data:");
    scanf("%d",&temp->data);
    temp->link=root;
    root=temp;
    printf("Inserted...\n");
}

int length()
{
    struct node *temp;
    int c=0;
    temp=root;
    if(root==NULL)
    {
        return 0;
    }
    else
    {


    while(temp!=NULL)
    {
        c++;
        temp=temp->link;
    }
    return c;
    }
}

void addafter()
{

    int loc,len;
    printf("Enter Location:");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid Location...\n");
        printf("Length of list is %d\n",len);
    }
    else
    {
        int i;
        struct node *p,*temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter Node Data:");
        scanf("%d",&temp->data);
        temp->link=NULL;
        p=root;
        for(i=1;i<loc;i++)
        {
            p=p->link;
        }
        temp->link=p->link;
        p->link=temp;
        printf("Inserted...\n");
    }

}

void delete1()
{
    int loc,len;
    printf("Enter Location:");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid Location...\n");
        printf("Length of list is %d\n",len);
    }
    else
    {
        if(loc==1)
        {
            struct node *temp;
            temp=root;
            root=temp->link;
            temp->link=NULL;
            free(temp);
        }
        else
        {
            struct node *p,*temp;
            p=root;
            int i;
            for(i=1;i<loc-1;i++)
            {
                p=p->link;
            }
            temp=p->link;
            p->link=temp->link;
            temp->link=NULL;
            free(temp);
        }
        printf("Deleted...\n");
    }
}

void swap()
{
    int loc1,loc2,len;
    printf("Enter First Location:");
    scanf("%d",&loc1);
    printf("Enter Second Location:");
    scanf("%d",&loc2);
    len=length();

    if(loc1>len||loc2>len)
    {
        printf("Invalid Location...\n");
        printf("Length of list is %d\n",len);
    }
    else
    {
        int i,j;
        struct node *p,*q;
        p=q=root;
        for(i=1;i<loc1;i++)
        {
            p=p->link;
        }
        for(j=1;j<loc2;j++)
        {
            q=q->link;
        }
        int temp;
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        printf("Swapped...\n");
    }
}

void reverse()
{
    int i,j;
    struct node *p,*q;
    i=0;
    j=length()-1;
    p=root;
    while(i<j)
    {
        int k;
        k=0;
        q=root;
        while(k<j)
        {
            q=q->link;
            k++;
        }
        int temp;
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        i++;
        j--;
        p=p->link;


    }
     printf("List Reversed...\n");
}

void sort()
{
    struct node *p,*q;
    int i,j,temp,len;
    len=length();
    for(i=0;i<len-1;i++)
    {
        p=root;
        q=p->link;
        for(j=0;j<len-1-i;j++)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            p=p->link;
            q=q->link;
        }
    }
    printf("List Sorted...\n");
}

void display()
{
    struct node *temp;
    temp=root;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{
    int ch,c;


    while(ch!=11)
    {
    printf("Data Structure Linked List\n");
    printf("Choose Options\n");
    printf("1.Create\n2.Append\n3.Add First\n4.Length\n5.Add After\n6.Delete\n7.Swap\n8.Reverse\n9.Sort\n10.Display\n11.Exit\n");
    scanf("%d",&ch);
         switch(ch)
    {
        case 1:
            create();
        break;
        case 2:append();
        break;
        case 3:addfirst();
        break;
        case 4:c=length();
               printf("Length of List is %d\n",c);
        break;
        case 5:addafter();
        break;
        case 6:delete1();
        break;
        case 7:swap();
        break;
        case 8:reverse();
        break;
        case 9:sort();
        break;
        case 10:display();
        break;
        case 11:exit(0);
        break;
        default:printf("Invalid Entry\n");
    }
    }
    return 0;

}
