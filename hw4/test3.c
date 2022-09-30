#include<stdio.h>
#include<stdlib.h>
void test(int a, int count)
{
    if (a>0)
    {
        printf("Trajectory %d\n",count);
        count++;
    }
    a--;
    test(a,count);
}
int main()
{
    int a=10;
    test(a,1);
    return 0;
}
