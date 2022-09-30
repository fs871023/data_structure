#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int partition(int num[], int left, int right)
{
    int i = left;
    int j, pivot, temp;
    pivot = num[left];
    for(j=left+1; j<=right; j++)
        if(pivot >= num[j])
        {
            i++;
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
    num[left]=num[i];
    num[i]=pivot;
    return i;
}

void quick_sort(int num[], int left, int right, int n)
{
    int mid;
    if(left<right)
    {
        mid = partition(num, left, right);
        for(int i=0; i<n-1; i++)
            printf("%d, ",num[i]);
        printf("%d\n",num[n-1]);
        quick_sort(num, left, mid-1, n);
        quick_sort(num, mid+1, right, n);
    }
}
int main()
{
    char input[10000];
    fgets(input, 10000, stdin);
    int i,j=0,k=0;
    char temp[20];
    int n=0;
    for(i=0; input[i]; i++)//check by character
        if(input[i]==',')
            n++;
    ++n;
    int num[n];
    for(i=0; input[i]; i++)//check by character
    {
        if( isdigit( input[i] ) )//judge
            temp[j++] = input[i];
        else if( strlen(temp) != 0 )//when we have '.' next to ' ' or vise versa
        {
            temp[j] = '\0';
            j = 0;
            num[k++] = atoi(temp);
            memset(temp, '\0', sizeof(temp));//input another number
        }
    }
    quick_sort(num, 0, n-1, n);
    return 0;
}
//43, 10, 84, 37, 95, 71, 29, 57, 62
