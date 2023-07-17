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
     FILE *fp;
   fp=fopen("data.txt","r+");
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
    delet(&head);
    printf("The inputs from file:\n");
    display(head);
    printf("\n");
    sort(head);
    printf("The sorted list:\n");
    display(head);

    struct node*cur=head;
    while(cur)
    {
        fprintf(fp,"%d\t",cur->data);
        cur=cur->next;
    }

}
void delet(struct node**head)
{
    struct node *cur=*head;
    *head=(*cur).next;
    free(cur);
}
void sort(struct node*head)
{
    struct node*i,*min;
    struct node*j=NULL;
    int temp,si;
    do
    {
        si=0;
        i=head;
        while(i->next!=j)
        {
            if(i->data>i->next->data)
            {
                temp=i->data;
                i->data=i->next->data;
                i->next->data=temp;
                si=1;
            }
            i=i->next;
        }
        j=i;
    }while(si);

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


