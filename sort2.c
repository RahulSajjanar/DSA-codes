#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
   int data;
   struct node*next;
};
void add(struct node**head,int t);

int main()
{
     FILE *fp,*fp2;
   fp=fopen("data.txt","r");
    if(fp==NULL)
    {
        perror("error\n");
        exit(0);
    }
    char temp[10];
    int index=0;
    int t,j;
    struct node*head=NULL;


    while(!feof(fp))
    {
        fscanf(fp,"%s",temp);
        t=atoi(temp);
        add(&head,t);

    }
    display(head);
    printf("\n");
    sort(head);
    display(head);
    fp2=fopen("rec.txt","w");
    struct node*cur=head;
    while(cur)
    {
        fprintf(fp2,"%d\t",cur->data);
        cur=cur->next;
    }

}
void sort(struct node*head)
{
    struct node*i,*j,*min;
    int temp;
    for(i=head;i->next!=NULL;i=i->next)
    {
        min=i;
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(j->data<min->data)
            {
                min=j;
            }
        }
        temp=i->data;
        i->data=min->data;
        min->data=temp;
    }
}
void display(struct node*head)
{
    struct node*cur=head;
    while(cur)
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }
}
void add(struct node**head,int t)
{
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        perror("error of insuff\n");
        return;
    }
    p->data=t;
    p->next=*head;

    *head=p;

}
