#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;

};
struct node* SortedMerge(struct node* a, struct node* b);
void mergesort(struct node** head);
void add(struct node**head,int t);
void delet(struct node**head);
void FrontBackSplit(struct node* source,struct node** frontRef, struct node** backRef);
void display(struct node*head);

int main()
{
    FILE *fp=fopen("data.txt","r+");
    char str[10];
    struct node*head=NULL;
    int t;
    while(!feof(fp))
    {
        fscanf(fp,"%s",str);
        t=atoi(str);
        add(&head,t);
    }
    delet(&head);
    printf("The inputs from file are:\n");
    display(head);
    printf("\n");
    mergesort(&head);
    printf("Sorted list\n");
    display(head);
    struct node*cur=head;
    while(cur)
    {
        fprintf(fp,"%d\t",cur->data);
        cur=cur->next;
    }
}
void random(int l, int h, int n)
{
    int i, r;
    FILE *fp;
    fp = fopen("input.txt", "w");
    for (i = 0; i < n; i++)
    {
        r = rand() % (h - l) + l;
        fprintf(fp, "%d\t", r);
    }
    fclose(fp);
}
void delet(struct node**head)
{
    struct node *cur=*head;
    *head=(*cur).next;
    free(cur);
}
void display(struct node*head)
{
    struct node*cur=head;
    while(cur)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
}
void add(struct node**head,int t)
{
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        perror("space not available\n");
        return;
    }
    p->data=t;
    p->next=*head;

    *head=p;
}
void mergesort(struct node** head)
{
    struct node* cur = *head;
    struct node* a;
    struct node* b;


    if ((cur == NULL) || (cur->next == NULL)) {
        return;
    }


    FrontBackSplit(cur, &a, &b);


    mergesort(&a);
    mergesort(&b);


    *head = SortedMerge(a, b);
}

struct node* SortedMerge(struct node* a, struct node* b)
{
    struct node* result = NULL;


    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);


    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}


void FrontBackSplit(struct node* source,struct node** frontRef, struct node** backRef)
{
    struct node* fast;
    struct node* slow;
    slow = source;
    fast = source->next;


    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }


    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

