#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node*next;
};

 int main()
{
    int n;
    strucct node*head=NULL;
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    if(head=NULL)
    {
        perror();
        exit(0);
    }
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%d",&e);
        add(&head,e);
    }
    display(head);
}
void display(struct node*head)
{
    if(head=NULL)
    {
        printf("empty");
        return;
    }
    struct node *cur=head;
    while((cur->next)!=NULL)
    {
        printf("Elements are:");
        printf("%d\t",cur->data);

    }

}

void add(struct node**head,int e)
{
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    if(head=NULL)
    {
        perror();
        exit(0);
    }
    p->data=e;
    p->next=NULL;
    if(head=NULL)
       *head=p;
    else
    {
        p->next=*head;

    }


}
