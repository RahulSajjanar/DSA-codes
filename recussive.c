#include<stdio.h>


int main()
{
    int n;
    printf("entern:");
    scanf("%d",&n);
    recursion(n);

}
void recursion(int n)
{
    int i;
    if(n>0)
    {
         printf("%d   ",n);
        recursion(n-1);
         recursion(n-1);
    }
}
