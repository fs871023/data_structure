#include<stdio.h>
int main()
{
    char maze[2][101][101];
    int i,j,k;
    int floor;
    for(i=0; i<2; i++)
    {
        scanf("%d",&floor);
        floor--;
        for(j=0; j<101; j++)
            scanf("%s",&maze[floor][j]);
    }
    int romeo_ways[4][3]= { {0,0,1},{0,1,0},{0,-1,0},{0,0,-1} }; //Romeo's directions
    int juliet_ways[4][3]= { {0,0,-1},{0,-1,0},{0,1,0},{0,0,1} }; //Juliet's directions
    int romeo_pos[3]= {1,1,0}; //Romeo start point
    int juliet_pos[3]= {99,99,0}; //Juliet start point
    int reachable[2][101][101]={0};
    int stack[10000][3]={0};
    int stack_j[10000][3]={0};
    int top=0;
    stack[0][0]=romeo_pos[0];
    stack[0][1]=romeo_pos[1];
    stack[0][2]=romeo_pos[2];
    while((romeo_pos[0]!=99||romeo_pos[1]!=99)&&top>-1)
    {

    }

    if(meet==1)
        printf("They do not encounter each other in this maze.\n");
    else
        printf("They encounter each other in (%d,%d,%d)\n",romeo_pos[0],romeo_pos[1],romeo_pos[2]);
    return 0;
}
