#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char input[10];
    int num,coin;
    scanf("%s",&input);
    char *temp = strtok(input, ",");
    num = atoi(temp);
    temp = strtok(NULL, ",");
    coin = atoi(temp);
    printf("num=%d  coin=%d\n",num,coin);
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
