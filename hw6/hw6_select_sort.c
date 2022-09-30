#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int find_min(int i, int n, int num[])
{
    int j, min;
    min = i;
    for(j=i+1; j<n; j++)
    {
        if(num[j] < num[min])
            min = j;
    }
    return min;
}
void select_sort(int n, int num[])
{
    int i, min, t, j;
    int count = 0;
    for (i = 0; i < n; i++)
    {
        min = find_min(i, n, num);//pick the smallest element
        if(i!=min)
        {
            t = num[i];//swap
            num[i] = num[min];
            num[min] = t;
            for(j=0; j<n-1; j++)
                printf("%d, ",num[j]);
            printf("%d\n",num[n-1]);
            count++;
        }
    }
    if(count==0)//if we are not moving any element
    {
        for(j=0; j<n-1; j++)
            printf("%d, ",num[j]);
        printf("%d\n",num[n-1]);
    }

}
int main()
{
    char input[10000];
    fgets(input, 10000, stdin);
    int i,j=0,k=0;
    char temp[10];
    int n=1;
    for(i=0; input[i]; i++){//check by character
        if(input[i]==','){
            n++;
        }
    }
    input[i]='x';//for the sake of reading the last int
    int num[n];
    for(i=0; input[i]; i++)//check by character
    {
        if( isdigit( input[i] ) )//judge
            temp[j++] = input[i];
        else if( strlen(temp) != 0 )//when we have '.' next to ' ' or vise versa
        {
            temp[j] = '\0';
            j = 0;
            num[k] = atoi(temp);
            if(k < n-1) k++;
            memset(temp, '\0', sizeof(temp));//input another number
        }
    }
    select_sort(n, num);
    return 0;
}
//43, 10, 84, 37, 95, 71, 29, 57, 62
//10, 89, 100, 56759, 1238, 567, 2, 98, 8971357, 45687, 21, 10, 89
