#include<stdio.h>
#include<string.h>
#define MAX 999999
//use all-pairs shortest-path
int shortest_path(int n, int a[n][n])
{
    int i, j, k;
    int post_pnt[n][n];
//post_pnt[i][j] means the last intermediate vertex of the shortest path
//from vertex i to j
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(a[i][j] == -1)
                a[i][j] = MAX;
            post_pnt[i][j] = j;
        }
//a[i][j] is the length from i to j.
//if (i,j) not adjacent, then a[i][j]=max
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                if(a[i][k]+a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k]+a[k][j];
                    post_pnt[i][j] = post_pnt[i][k];
                    //record the last intermediate vertex
                }
            }
//now a[i][j] is the length of the shortest path from i to j
    int path_sum[n];
    for(i=0; i<n; i++)
        path_sum[i] = 0;
//record the whole path length from i to every point
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            if(a[i][j]!=MAX && i!=j)
                path_sum[i] = path_sum[i]+a[i][j];
    }
//find the minimum path length for i to every point
    int min_path=path_sum[0];
    int min=0;
    for(i=1; i<n; i++)
        if(min_path > path_sum[i])
        {
            min_path = path_sum[i];
            min = i;
        }
    return min;
}

int main()
{
    int m, n;//n=vertexes, m=edges
    int i, j;
    char name[20];
    char namelist[20][20];//store names into char array
    int cost, s, d;
    int count = 0;//how many times to execute
    while(1)
    {
        scanf("%d%d", &n, &m);
        if(m == 0 && n == 0)
            break;
        count++;

        int adjarray[n][n];//use adjacent array to implement graph
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                adjarray[i][j]=-1;//initialize the adjacent array

        for(i=0; i<n; i++)
        {
            scanf("%s",name);//store name
            strcpy(namelist[i],name);
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d", &s, &d, &cost);//construct adjacent list

            s--;
            d--;//because the adjacent array starts form 0
            adjarray[s][d] = cost;
            adjarray[d][s] = cost;
        }
//find shortest path ,return the vertex
        int ans = shortest_path(n, adjarray);
        printf("Case #%d %s\n", count, namelist[ans]);
    }
}
