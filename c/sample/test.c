#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct polynomial
{
    int coeff, expo1, expo2, expo3;
    int flag;
    struct polynomial *next;
};
typedef struct polynomial node;
void insertend(node *head, int c, int e1, int e2, int e3)
{
    node *temp;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->coeff = c;
    newnode->expo1 = e1;
    newnode->expo2 = e2;
    newnode->expo3 = e3;
    newnode->flag = 0;
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void readpoly(node *head)
{
    int n, c, e1, e2, e3, i;
    printf("\n Enter no.of.terms:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter coeff expo1 expo2 expo3: ");
        scanf("%d %d %d %d", &c, &e1, &e2, &e3);
        insertend(head, c, e1, e2, e3);
    }
}

void addpoly(node *head1, node *head2, node *head3)
{
    node *temp1 = head1->next;
    node *temp2 = head2->next;

    while (temp1 != NULL)
    {
        while (temp2 != NULL)
        {
            if (temp1->expo1 == temp2->expo1 &&
                temp1->expo2 == temp2->expo2 &&
                temp1->expo3 == temp2->expo3)
            {
                insertend(head3, temp1->coeff + temp2->coeff,
                          temp1->expo1, temp1->expo2, temp1->expo3);
                temp1->flag = 1;
                temp2->flag = 1;
                break;
            }
            temp2 = temp2->next;
        }
        if (temp1->flag == 0)
        {
            insertend(head3, temp1->coeff, temp1->expo1,
                      temp1->expo2, temp1->expo3);
        }
        temp1 = temp1->next;
        temp2 = head2->next;
    }
}

void display(node *head)
{
    node *temp = head->next;
    while (temp != NULL)
    {
        printf("%dx^%dy^%dz^%d + ", temp->coeff,
               temp->expo1, temp->expo2, temp->expo3);
        temp = temp->next;
    }
}

void evaluate(node *head)
{
    node *temp = head->next;
    int x, y, z, sum = 0;

    printf("\nEnter the value of x, y, z: ");
    scanf("%d%d%d", &x, &y, &z);

    while (temp != NULL)
    {
        sum += temp->coeff * pow(x, temp->expo1) * pow(y, temp->expo2) * pow(z, temp->expo3);
        temp = temp->next;
    }

    printf("\nThe result = %d\n", sum);
}

int main()
{
    node *head1 = (node *)malloc(sizeof(node));
    head1->next = NULL;

    node *head2 = (node *)malloc(sizeof(node));
    head2->next = NULL;

    node *head3 = (node *)malloc(sizeof(node));
    head3->next = NULL;

    printf("\nRead 1st polynomial\n");
    readpoly(head1);

    printf("\nRead 2nd polynomial\n");
    readpoly(head2);

    printf("\n1st polynomial: ");
    display(head1);

    printf("\n2nd polynomial: ");
    display(head2);

    addpoly(head1, head2, head3);

    printf("\nResultant polynomial: ");
    display(head3);

    evaluate(head3);

    free(head1);
    free(head2);
    free(head3);

    return 0;
}
