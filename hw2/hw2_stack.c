#include<stdio.h>
int Explore(const char _maze[2][101][101],
            const int direction_1[5][3], int current_1[3],
            const int direction_2[5][3], int current_2[3]);
void Romeo_explore(const char _maze[2][101][101], int reachable[2][101][101],
                   const int direction[5][3], const int current[3],
                   int stack[10000][3],int count);
void Juliet_explore(const char _maze[2][101][101], int reachable[2][101][101],
                    const int direction[5][3], const int current[3],
                    int stack[10000][3],int count);
int min(int i,int j)
{
    if(i<j)
        return i;
    else
        return j;
}
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
                scanf("%s",maze[floor][j]);
    }
    int romeo_ways[5][3]= { {1,0,0},{0,0,1},{0,1,0},{0,-1,0},{0,0,-1} }; //Romeo's directions
    int juliet_ways[5][3]= { {-1,0,0},{0,0,-1},{0,-1,0},{0,1,0},{0,0,1} }; //Juliet's directions
    int romeo_pos[3]= {0,1,1}; //Romeo start point
    int juliet_pos[3]= {1,99,99}; //Juliet start point
    int meet=0;
    meet=Explore(maze, romeo_ways, romeo_pos, juliet_ways, juliet_pos);
    if(meet==0)
        printf("They do not encounter each other in this maze.\n");
    else if(meet==1)
        printf("They encounter each other in (%d,%d,%d)\n",romeo_pos[0],romeo_pos[1],romeo_pos[2]);
    return 0;
}

int Explore(const char _maze[2][101][101],
            const int direction_1[5][3], int current_1[3],
            const int direction_2[5][3], int current_2[3])
{
    printf("???\n");
    int step1[10000][3]={0};
    int step2[10000][3]={0};
    int i,j,k;
    int n1=0,n2=0;

    int reachable[2][101][101]= {0}; //record the way that has been walked
    Romeo_explore(_maze, reachable, direction_1, current_1, step1, n1);

    for(i=0;i<2;i++)
        for(j=0;j<101;j++)
            for(k=0;k<101;k++)
                reachable[i][j][k]=0;
    Juliet_explore(_maze, reachable, direction_2, current_2, step2, n2);
    printf("???\n");
    for(int i=1; i<min(n1,n2)+1; i++)
    {
        printf("==Round: %d==\n",i);
        printf("Romeo: (%d,%d,%d)\n",step1[i][0],step1[i][1],step1[i][2]);
        printf("Juliet: (%d,%d,%d)\n",step2[i][0],step2[i][1],step2[i][2]);
        if(step1[i][0]==step2[i][0] &&
                step1[i][1]==step2[i][1] &&
                step1[i][2]==step2[i][2])
        {
            current_1[0]=step1[i][0];
            current_1[1]=step1[i][1];
            current_1[2]=step1[i][2];
            return 1;
        }
    }
    return 0;
}
void Romeo_explore(const char _maze[2][101][101], int reachable[2][101][101],
                   const int direction[5][3], const int current[3], int stack[10000][3], int count)
{
    int i;
    int new_pos[3];
    if(current[0]==0&&_maze[current[0]][current[1]][current[2]]=='o')
    {
        new_pos[0]=current[0]+direction[0][0];
        new_pos[1]=current[1]+direction[0][1];
        new_pos[2]=current[2]+direction[0][2];

        if( _maze[new_pos[0]][new_pos[1]][new_pos[2]]=='.')
        {
            reachable[new_pos[0]] [new_pos[1]] [new_pos[2]]=1;
            stack[count][0]=new_pos[0];
            stack[count][1]=new_pos[1];
            stack[count][2]=new_pos[2];
            count++;
            Romeo_explore(_maze, reachable, direction, new_pos, stack, count);
        }
    }
    if( (current[0]!=1 || current[1]!=99 || current[2]!=99) &&
            _maze[current[0]][current[1]][current[2]]=='.' )//both two people has not reach the end and they can keep walking
    {
        for(i=1; i<5; i++)
        {
            new_pos[0]=current[0];
            new_pos[1]=current[1]+direction[i][1];
            new_pos[2]=current[2]+direction[i][2];

            if( (_maze[new_pos[0]][new_pos[1]][new_pos[2]]=='.'||_maze[new_pos[0]][new_pos[1]][new_pos[2]]=='o')&&
                    reachable[new_pos[0]] [new_pos[1]] [new_pos[2]]==0 )
            {
                reachable[new_pos[0]] [new_pos[1]] [new_pos[2]]=1;
                stack[count][0]=new_pos[0];
                stack[count][1]=new_pos[1];
                stack[count][2]=new_pos[2];
                count++;
                Romeo_explore(_maze, reachable, direction, new_pos, stack, count);
            }
        }
    }
}
void Juliet_explore(const char _maze[2][101][101], int reachable[2][101][101],
                    const int direction[5][3], const int current[3], int stack[10000][3], int count)
{
    int i;
    int new_pos[3];
    if(current[0]==1&&_maze[current[0]][current[1]][current[2]]=='o')
    {
        new_pos[0]=current[0]+direction[0][0];
        new_pos[1]=current[1]+direction[0][1];
        new_pos[2]=current[2]+direction[0][2];

        if( _maze[new_pos[0]][new_pos[1]][new_pos[2]]=='.')
        {
            reachable[new_pos[0]] [new_pos[1]] [new_pos[2]]=1;
            stack[count][0]=new_pos[0];
            stack[count][1]=new_pos[1];
            stack[count][2]=new_pos[2];
            count++;
            Juliet_explore(_maze, reachable, direction, new_pos, stack, count);
        }
    }
    if( (current[0]!=0 || current[1]!=1 || current[2]!=1) &&
            _maze[current[0]][current[1]][current[2]]=='.')//both two people has not reach the end and they can keep walking
    {
        for(i=1; i<5; i++)
        {
            new_pos[0]=current[0];
            new_pos[1]=current[1]+direction[i][1];
            new_pos[2]=current[2]+direction[i][2];

            if( (_maze[new_pos[0]][new_pos[1]][new_pos[2]]=='.'  ||_maze[new_pos[0]][new_pos[1]][new_pos[2]]=='o')&&
                    reachable[new_pos[0]] [new_pos[1]] [new_pos[2]]==0 )
            {
                reachable[new_pos[0]] [new_pos[1]] [new_pos[2]]=1;
                stack[count][0]=new_pos[0];
                stack[count][1]=new_pos[1];
                stack[count][2]=new_pos[2];
                count++;
                Juliet_explore(_maze, reachable, direction, new_pos, stack, count);
            }
        }
    }
}
