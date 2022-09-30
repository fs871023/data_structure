#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node * nodeptr;
void test(nodeptr top,int num)
{
    if(top == NULL)
    {
        top = (nodeptr)malloc(sizeof(struct node));
        top->data = num;
        top->left = NULL;
        top->right = NULL;
        printf("put %d\n",top->data);
    }
}
int main()
{
    char input[10];
    int num;
    nodeptr top = NULL;
    scanf("%s",&input);
    num = atoi(input);
    test(top, num);
    printf("top: %d",top->data);
}
