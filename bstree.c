#include <stdio.h>
#include<stdlib.h>
#include<time.h>
struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

struct tnode *CreateBST(struct tnode *, int);
void Inorder(FILE*,struct tnode *);
void Preorder(FILE*,struct tnode *);
void Postorder(FILE*,struct tnode *);
void random(int l,int h,int n);
int main()
{
    FILE*fp=fopen("input.txt","r");
    FILE*fp1=fopen("inorder.txt","w");
    FILE*fp2=fopen("preorder.txt","w");
    FILE*fp4=fopen("postorder.txt","w");
    struct tnode *root = NULL;
    char str[20];
    int choice, item,  i,r,l=30,h=40,n=9;
    clock_t start,stop;
    float time_r;
    random(l,h,n);
    do
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            root = NULL;
            //printf("\n\nBST for How Many Nodes ? ");
            //scanf("%d",&n);
            for(i = 0; i < n; i++)
            {
                while(!feof(fp))
                {
                   fscanf(fp,"%s",str);
                   r=atoi(str);
                   //printf("%d\t",r);
                   root = CreateBST(root,r);
                   //printf("%d\t",root->data);
                }
                //printf("\nEnter data for node %d : ", i);

            }
            //printf("\nBST with %d nodes is ready to Use!!\n", n);
            break;
        case 2:
            printf("\nBST Traversal in INORDER \n");
            start=clock();
            Inorder(fp1,root);
            stop=clock();
            time_r=(float)(stop-start)/CLOCKS_PER_SEC;
            fprintf(fp1,"Time taken = %f\n",time_r);
            break;
        case 3:
            printf("\nBST Traversal in PREORDER \n");
            start=clock();
            Preorder(fp2,root);
            stop=clock();
            time_r=(float)(stop-start)/CLOCKS_PER_SEC;
            fprintf(fp2,"Time taken = %f\n",time_r);
            break;
        case 4:
            printf("\nBST Traversal in POSTORDER \n");
            start=clock();
            Postorder(fp4,root);
            stop=clock();
            time_r=(float)(stop-start)/CLOCKS_PER_SEC;
            fprintf(fp4,"Time taken = %f\n",time_r);
            break;
        case 5:
            printf("\n\n Terminating \n\n");
            break;
        default:
            printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
    } while(choice != 5);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp4);
    return 0;
}

struct tnode *CreateBST(struct tnode *root, int item)
{
    if(root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if(item < root->data )
            root->left = CreateBST(root->left,item);
        else if(item > root->data )
            root->right = CreateBST(root->right,item);
        //else
            //printf(" Duplicate Element !! Not Allowed !!!");

        return(root);
    }
}

void Inorder(FILE*fp,struct tnode *root)
{
    if( root != NULL)
    {
        Inorder(fp,root->left);
        fprintf(fp,"%d\t ",root->data);
        Inorder(fp,root->right);
    }
    //fprintf(fp,"\n");
}

void Preorder(FILE*fp,struct tnode *root)
{
    if( root != NULL)
    {
        fprintf(fp,"%d\t",root->data);
        Preorder(fp,root->left);
        Preorder(fp,root->right);
    }
    //fprintf(fp,"\n");
}

void Postorder(FILE*fp,struct tnode *root)
{
    if( root != NULL)
    {
        Postorder(fp,root->left);
        Postorder(fp,root->right);
        fprintf(fp,"%d\t",root->data);
    }
    //fprintf(fp,"\n");
}

void random(int l,int h,int n)
{
    FILE*fp=fopen("input.txt","w");
    int i,r;
    for(i=0;i<n;i++)
    {
        r=rand()%(h-l)+l;
        fprintf(fp,"%d\t",r);
    }
    fclose(fp);

}
