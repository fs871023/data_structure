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

void printInfixOrder(nodeptr top)
{
    if(top!=NULL)
    {
        printInfixOrder(top->left);
        printf(" %d",top->data);
        printInfixOrder(top->right);
    }
}
void printLevelOrder(nodeptr top)
{
    if(top!=NULL)
    {
        nodeptr queue[1000];//construct a node queue
        int head,tail;
        head = tail = 0;
        queue[tail++] = top;//let root be the start point of level-order traversal
        while(head!=tail)
        {
            printf(" %d",queue[head]->data);//dequeue the queue
            if(queue[head]->left != NULL)//if we have children, push it into queue
                queue[tail++] = queue[head]->left;
            if(queue[head]->right != NULL)
                queue[tail++] = queue[head]->right;
            head++;
        }
    }
}
int main()
{
    char input[20];
    int num;
    nodeptr top = NULL;
    while(1)
    {
        scanf("%s",input);
        if( strcmp(input,"00")==0 )
            break;
        else//construct the tree
        {
            num = atoi(input);
            nodeptr cur,pre;
            cur = top;
            pre = NULL;
            while(cur!=NULL)
            {
                pre=cur;
                if(num < cur->data)
                    cur = cur->left;
                else cur = cur->right;
            }
            cur = (nodeptr)malloc(sizeof(struct node));
            cur->data = num;
            cur->left = cur->right = NULL;
            if(pre == NULL) top = cur;
            else if(num < pre->data) pre->left = cur;
            else pre->right = cur;
        }
    }
    printf("Infixorder:");
    printInfixOrder(top);
    printf("\n");
    printf("Levelorder:");
    printLevelOrder(top);
    return 0;
}
/*
8
3
6
7
13
14
4
10
1
00
*/
