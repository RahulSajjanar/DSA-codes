#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void add(struct node**tail,int e);
void display(struct node*tail);
void sort(struct node**tail);

int main()
{
    struct node*tail=NULL;
    int n,e;
    scanf("%d",&n);
    printf("Enter elements:");
    while(n>0)
    {
        scanf("%d",&e);
        add(&tail,e);
        n--;
    }
    display(tail);
    printf("\n");
    sort(&tail);
    display(tail);
}
void sort(struct node**tail)
{
    struct node*i;
    struct node*j;
    struct node*min;
    int temp;
    for(i=(*tail)->next;i->next!=(*tail)->next;i=i->next)
    {
        min=i;
        for(j=i->next;j!=(*tail)->next;j=j->next)

        {
            if(j->data<min->data)
                    min=j;
        }
        temp=i->data;
        i->data=min->data;
        min->data=temp;
    }
}
void display(struct node*tail)
{
    if(tail==NULL)
    {
        printf("List empty\n");
        return;
    }
    struct node*cur=(tail)->next;
    do
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }while(cur!=(tail)->next);
}
void add(struct node**tail,int e)
{
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        perror("");
        return;
        }
        p->data=e;
    p->next=p;
    if(*tail==NULL)
    {
        *tail=p;
    }
    else
    {
        p->next=(*tail)->next;
        (*tail)->next=p;
    }
}


