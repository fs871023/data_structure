#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int a;
    int b;
} Test;
typedef struct list_node list_ptr;
struct list_node
{
    char data[10];
    list_ptr *link;
};
int main()
{
    Test _test;
    scanf("%d",&_test.a);
    scanf("%d",&_test.b);
    printf("%d,%d\n",_test.a,_test.b);
}
