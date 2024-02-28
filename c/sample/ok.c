#include<stdio.h>
#include<stdlib.h>
struct SLL
{
    int sem;
    char usn[11],name[20],branch[20],phno[10];
    struct SLL *next; 
};
typedef struct SLL node;
node *start=NULL;
node *createnode()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\n Enter usn,name,branch,sem,phno:");
    scanf("%s",newnode->usn);
    scanf("%s",newnode->name);
    scanf("%s",newnode->branch);
    scanf("%d",&newnode->sem);
    scanf("%s",newnode->phno);
    
}

