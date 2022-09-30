#include<stdio.h>
#include<stdlib.h>
struct node
{
    int to;
    int weight;
    struct node *next;
};
typedef struct node *nodeptr;

void dijkstra(int start, nodeptr graph[])
{

}

int main()
{
    int m, n;//n=vertexes, m=edges
    int i;
    char name[20];
    char namelist[20][20];
    int cost, s, d;
    int count=0;
    while(1)
    {
        scanf("%d%d", &n, &m);
        if(m == 0 && n == 0) break;
        nodeptr headlist[m];
        for(i=0; i<m; i++)
            headlist[i] = NULL;
        count++;

        for(i=0; i<n; i++)
        {
            scanf("%s",name);
            strcpy(namelist[i],name);
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d", &s, &d, &cost);//construct adjacent list

            nodeptr newnode = (nodeptr)malloc(sizeof(struct node));
            newnode->weight = cost;

            newnode->to = d;//add edge from vertex s to vertex d
            newnode->next = headlist[s];
            headlist[s] = newnode;

            newnode->to = s;//add edge from vertex d to vertex s
            newnode->next = headlist[d];
            headlist[d] = newnode;
        }
//find shortest path ,return the vertex
        int ans=span_tree();
        printf("Case #%d %s\n", count, namelist[ans]);
    }
}
/*
4 3
timotius
harry
richard
januar
1 2 10
1 3 8
1 4 6
4 3
rocky
herwin
gaston
jefry
1 2 5
1 3 5
1 4 5
0 0
*/
