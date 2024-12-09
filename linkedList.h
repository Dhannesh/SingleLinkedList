#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void add_beg(struct node **start, int data)
{
    struct node *temp = createNode(data);
    if(*start != NULL)
    {
        temp->next = *start;
    }
    *start = temp;
}
void add_last(struct node **start, int data)
{
    struct node *temp =createNode(data);
    if(*start == NULL)
    {
        *start = temp;
        return;
    }
    struct node *p = *start;
    while(p->next != NULL)
        p = p->next;
    p->next = temp;
}

void show(struct node *start)
{
    while(start!=NULL)
    {
        printf("%d ",start->data);
        start = start->next;
    }
}

void del_beg(struct node **start)
{
    if(*start == NULL)
        return;
    struct node *temp = *start;
    *start = (*start)->next;
    free(temp);    
}

void del_last(struct node **start)
{
    if(*start == NULL)
        return;
    struct node *p =*start;
    struct node *prev = *start;
    
    while(p->next != NULL)
    {
        prev =p;
        p=p->next;
    }
    prev->next = NULL;
    free(p);
}