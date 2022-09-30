#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct list_node
{
    char data[20];
    struct list_node *link;
};
typedef struct list_node *list_ptr;
void list_cmp(list_ptr head, char a[])
{
    int count = 0;//record the number of the node which we access now
    list_ptr pre = (list_ptr)malloc(sizeof(struct list_node));
    list_ptr q = (list_ptr)malloc(sizeof(struct list_node));
    pre=head;
    q=head->link;
    while(q!=NULL && strcmp(q->data, a)!=0)//list is not end and the strings are different
    {
        pre=q;//traverse
        q=q->link;
        count++;
    }
    if(q==NULL)//no string in list is repeated
    {
        list_ptr p;//push the data to the top
        p = (list_ptr)malloc(sizeof(struct list_node));
        strcpy(p->data, a);
        p->link = head->link;
        head->link = p;
        printf("%s",a);//output string
    }
    else//if strcmp(q->data, a)==0 : there is string repeated
    {
        pre->link=q->link;//move the same node to head
        q->link=head->link;
        head->link=q;
        printf("%d",count+1);//print out the number of the node
    }
}
int main()
{
    char s[20];//a word can not exceed 20 char
    char input_str[10000];//the article can not exceed 10000 char
    list_ptr head;
    head = (list_ptr)malloc(sizeof(struct list_node));
    head->link = NULL;
    fgets(input_str,10000,stdin);
    int i,j=0;
    for(i=0; input_str[i]; i++)//check by character ,when we have special character, then output it
    {
        if( isalnum( input_str[i] ) )//judge
            s[j++] = input_str[i];
        else if( strlen(s) != 0 )//when we have '.' next to ' ' or vise versa
        {
            s[j] = '\0';
            j = 0;
            list_cmp(head, s);//put the string into list
            memset(s,'\0',sizeof(s));//input another word
            printf("%c", input_str[i]);//print the special character
        }
        else
            printf("%c", input_str[i]);
    }
}
//I love dogs. Dogs love me.
