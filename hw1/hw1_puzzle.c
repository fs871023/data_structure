#include<stdio.h>
#include<stdlib.h>
int Compare_puzzle(const int a1[],const int a2[],int a1_size,int a2_size)
{//compare two shape array
    for (int i=0; i<a1_size; i++)
        if(a1[i]!=a2[i])
                return -1;//shape is not equal
    return 0;
}
int int_compare( const void *a, const void *b)
{
    if( *(int*)a == *(int*)b )
    {
        int *c = (int*)a+2;
        int *d = (int*)b+2;
        return *d - *c;
    }
    else
        return *(int *)a-*(int *)b;
}
int main()
{
    int n=0;//amount of question
    int immove[3][3];//immovable puzzle
    int movabl[3][3];//movable puzzle
    scanf("%d",&n);//how many question
    int j=0,k=0;
    int row;

    for(int i=0; i<n; ++i)
    {
        int count0=0;//record the size of immovable puzzle
        int count2=0;//record the size of movable one
        int success=0;//1 if success
        for(j=0; j<3; ++j)//record the immovable puzzle
        {
            scanf("%d",&row);
            immove[j][0]=row/100;
            if(immove[j][0]==0)
                count0++;

            row=row%100;

            immove[j][1]=row/10;
            if(immove[j][1]==0)
                count0++;

            row=row%10;

            immove[j][2]=row;
            if(immove[j][2]==0)
                count0++;
        }
        for(j=0; j<3; j++)//record the movable puzzle
        {
            scanf("%d",&row);
            movabl[j][0]=row/100;
            if(movabl[j][0]==2)
                count2++;

            row=row%100;

            movabl[j][1]=row/10;
            if(movabl[j][1]==2)
                count2++;

            row=row%10;

            movabl[j][2]=row;
            if(movabl[j][2]==2)
                count2++;
        }
        int space[count0]; //record the shape of immovable puzzle
        int brick[count2];//record the shape of movable puzzle
        count0=0;
        count2=0;
        int left0=3,up0=3;//record the leftest block/element
        int left2=3,up2=3;
        for(j=0; j<3; j++)
        {
            for(k=0; k<3; k++)
            {
                if(immove[j][k]==0)
                {
                    space[count0++]=j*3+k;
                    if(left0>k)//record the leftest one
                        left0=k;
                    if(up0>j)//record the top one
                        up0=j;
                }
                if(movabl[j][k]==2)
                {
                    brick[count2++]=3*j+k;
                    if(left2>k)//record the leftest one
                        left2=k;
                    if(up2>j)
                        up2=j;
                }

            }
        }
        for(j=0; j<count0; j++)//standardize to top-left
        {
            space[j]-=left0;
            space[j]=space[j]-3*up0;
            brick[j]=brick[j]-3*up2;
            brick[j]-=left2;
        }
        int rotate=0;
        for(rotate=0; rotate<4; rotate++)
        {
            if(count0!=count2)//size is not equal
                break;
            if( Compare_puzzle(brick, space, count2, count0)!=0 )//compare two array,equal return 0,if not equal
            {
                for(j=0; j<count2; j++)
                    brick[j]=3*(brick[j]%3)+2-brick[j]/3;//rotate the movable array
                qsort(brick,count2,sizeof(int),int_compare);

                left2=3;
                up2=3;
                for(j=0; j<count2; j++)
                {
                    if(brick[j]/3<up2)
                        up2=brick[j]/3;
                    if(brick[j]%3<left2)
                        left2=brick[j]%3;
                }
                for(j=0; j<count2; j++)
                {
                    brick[j]=brick[j]-3*up2;
                    brick[j]-=left2;
                }
            }
            else//if equal,
            {
                success=1;
                break;
            }
        }
        if(success==1)//print out the massage
        {
            printf("YES\n");
            for(j=0; j<3; j++)
            {
                for(k=0; k<3; k++)
                {
                    if(immove[j][k]==0)
                        immove[j][k]=2;
                    printf("%d",immove[j][k]);
                }
                printf("\n");
            }
        }
        else if(success==0)
            printf("NO\n");
    }
}
