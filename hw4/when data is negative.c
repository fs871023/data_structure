#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    int coin;
    struct node *left;
    struct node *right;
};
typedef struct node * nodeptr;

int stack[1000];
int sp = -1;

void push(int data)
{
    stack[++sp]=data;
}
void pop()
{
    sp--;
}
int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}

int find_max(nodeptr root ,int cur_max)
{
    if(root == NULL) return 0;//leaf
//find max sum of children subtree
    int left_sum = find_max(root->left, cur_max);
    int right_sum = find_max(root->right, cur_max);
    //max of the these cases: child sum+coins now we have, coins now we have
    int n_max = max( max(left_sum, right_sum) + root->coin, root->coin );
    int m_max = max(n_max, left_sum + right_sum + root->coin);

    if(m_max > cur_max)//update current max
        cur_max = m_max;
    return n_max;
}

void path(nodeptr root, const int sum, int cur_sum, int *count)
{
    if(root == NULL) return;

    push(root->data);
    cur_sum = cur_sum+ root->coin;
    if(root->left == NULL && root->right == NULL && cur_sum == sum)
    {
        printf("Trajectory %d:",*count);
        for(int i=0; i<=sp; i++)
            printf(" %d",stack[i]);
        printf("\n");
        *count = *count+1;
    }
    else if(root->left != NULL || root->right != NULL)
    {
        if(root->left != NULL)
            path(root->left, sum, cur_sum, count);
        if(root->right != NULL)
            path(root->right, sum, cur_sum, count);
    }
    pop();
    cur_sum = cur_sum- root->coin;
}

int main()
{
    char input[20];
    int num,coins;
    nodeptr top = NULL;
    while(1)
    {
        scanf("%s",input);
        if( strcmp(input,"00")==0 )
            break;
        else
        {
            char *temp = strtok(input, ",");  num = atoi(temp);
            temp = strtok(NULL, ",");  coins = atoi(temp);//string processing

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
            cur->coin = coins;
            cur->left = cur->right = NULL;
            if(pre == NULL) top=cur;
            else if(num < pre->data) pre->left=cur;
            else pre->right = cur;
        }
    }

    int sum=top->coin;
    sum = find_max(top, sum);

    int count=1;
    path(top, sum, 0, &count);
    printf("Coins: %d\n",sum);
    return 0;
}
