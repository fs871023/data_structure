#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int partition(int num[], int left, int right)
{
    int temp;
    if(left==right-1)
    {
        if(num[left] > num[right])
        {
            temp=num[left];
            num[left]=num[right];
            num[right]=temp;
        }
        return left;
    }
    int pivot = num[left];
    int i = left+1;
    int j = right;
    int count = 0;
    while(i<j)
    {
        count++;
        while(num[i] < pivot && i <= j) i++;
        while(num[j] > pivot && i <= j) j--;
        if(i<=j)
        {
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
        }
        if(count > right)
            break;
    }
    temp=num[left];
    num[left]=num[j];
    num[j]=temp;
    return j;
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
        if(left < mid-1)//recursive
            quick_sort(num, left, mid-1, n);
        if(mid+1 < right)
            quick_sort(num, mid+1, right, n);
    }
}
int main()
{
    char input[10000];
    fgets(input, 10000, stdin);
    int i,j=0,k=0;
    char temp[20];
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
    quick_sort(num, 0, n-1, n);
    return 0;
}
//43, 10, 84, 37, 95, 71, 29, 57, 62
//843, 150, 784, 437, 295, 371, 529, 957, 662
//10, 89, 100, 56759, 1238, 567, 2, 98, 8971357, 45687, 21, 10, 89
//1, 2, 56, 100, 101, 456, 2596, 8999, 10002
//10, 10, 10, 10, 10, 10
