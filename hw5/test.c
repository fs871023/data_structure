#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct edge
{
    int from;
    int to;
    struct edge *next;
};
typedef struct edge *edgptr;
int main()
{
    int m, n;//n=vertexes m=edges
    int i;
    char name[20];
    char namelist[20][20];
    int cost, loc1, loc2;
    int count=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s",name);
        strcpy(namelist[i],name);
    }

    printf("Case #%d \n",count);
    for(i=0; i<n; i++)
        printf("%s\n",namelist[i]);

}
