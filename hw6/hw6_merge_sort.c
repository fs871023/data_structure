#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int min(int a, int b)
{
    if (a>b) return b;
    else return a;
}
void merge(int a[], int k, int m, int n, int b[])//
{
    int i,j;
    i = k;j = m+1;
    while(i<=m && j<=n)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m) b[k++]=a[i++];
    while(j<=n) b[k++]=a[j++];
}
void merge_sort(int a[], int b[], int n)
{
    int len;
    int s;
    int i,j;
    int tmp[n];
    for(len=1; len<n; len*=2)
    {
        for(s=1; s+len<=n; s+=2*len)//divide by 2
            merge(a, s, s+len-1, min(s+2*len-1, n), b);
        for(i=0; i<n; i++)//copy the result back to A
        {
            tmp[i]=a[i];
            a[i]=b[i];
            b[i]=tmp[i];
        }
        for(j=1; j<n-1; j++)
            printf("%d, ",a[j]);
        printf("%d\n",a[n-1]);
    }
}
int main()
{
    char input[10000];
    fgets(input, 10000, stdin);
    int i,j=0,k=1;
    char temp[10];
    int n=1;
    for(i=0; input[i]; i++){//check by character
        if(input[i]==','){
            n++;
        }
    }
    input[i]='x';//for the sake of reading the last int
    int num[n+1];//the way I sort can't sort the first element, so it starts from 1
    for(i=0; input[i]; i++)//check by character
    {
        if( isdigit( input[i] ) )//judge
            temp[j++] = input[i];
        else if( strlen(temp) != 0 )//when we have '.' next to ' ' or vise versa
        {
            temp[j] = '\0';
            j = 0;
            num[k] = atoi(temp);
            if(k < n) k++;
            memset(temp, '\0', sizeof(temp));//input another number
        }
    }
    int sort[n+1];//the array to store the result of every pass
    merge_sort(num, sort, n+1);
    int min_gap = 9999;
    for(i=1; i<n; i++)//find the minimum gap form comparing element
    {
        if(num[i+1]-num[i] < min_gap)
            min_gap = num[i+1]-num[i];
        //printf("min=%d\n",min_gap);
    }
    printf("Minimum gap: %d\n",min_gap);
    return 0;
}
//43, 10, 84, 37, 95, 71, 29, 57, 62
//10, 89, 100, 56759, 1238, 567, 2, 98, 8971357, 45687, 21, 10, 89
