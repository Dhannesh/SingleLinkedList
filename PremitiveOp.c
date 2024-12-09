#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start;

struct node *get_node()
{
    return (struct node *)malloc(sizeof(struct node));
}
struct node *find(int item)
{
    if (start == NULL)
        return NULL;
    struct node *temp = start;
    while (temp != NULL)
    {
        if (temp->data == item)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int getData()
{
    int item;
    printf("Enter data: ");
    scanf("%d", &item);
    return item;
}

void show()
{
    if (start == NULL)
        printf("List is empty\n");
    else
    {
        struct node *temp = start;
        printf("Nodes are\n");
        while (temp != NULL)
        {
            printf("%d|%u  ", temp->data, temp->next);
            temp = temp->next;
        }
        printf("\n");
    }
}
void add_beg(int info)
{
    struct node *temp = get_node();
    temp->data = info;
    temp->next = NULL;
    if (start != NULL)
        temp->next = start;

    start = temp;
    printf("Node added at beginning\n");
}
void add_last(int info)
{
    struct node *newnode = get_node();
    newnode->data = info;
    newnode->next = NULL;
    if (start == NULL)
        start = newnode;
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("node added at last\n");
}
void add_after(struct node *q, int item)
{
    if (q == NULL)
    {
        printf("Insertion not possible\n");
        return;
    }
    struct node *p = get_node();
    p->data = item;
    p->next = q->next;
    q->next = p;
    printf("%d inserted after %d\n", item, q->data);
}

void del_beg()
{
    if (start == NULL)
    {
        printf("Deletion not possible! List is Empty\n");
        return;
    }
    struct node *p = start;
    start = start->next;
    p->next = NULL;
    printf("%d deleted\n", p->data);
    free(p);
}

void del_end()
{
    if (start == NULL)
    {
        printf("Deletion not possible! List is Empty\n");
        return;
    }
    struct node *p = start;
    struct node *q;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    printf("%d deleted\n", p->data);
    free(p);
}

void del_after(struct node *q)
{
    if (q == NULL || q->next == NULL)
    {
        printf("Deletion is not possible\n");
        return;
    }
    struct node *p = q->next;
    q->next = p->next;
    printf("%d deleted\n", p->data);
    free(p);
}
int main()
{
    start = NULL;
    struct node *q;
    int ch, item;
    do
    {
        printf("\n1............Insert at begining\n");
        printf("2............Insert at end\n");
        printf("3............Insert after\n");
        printf("4............Delete from begining\n");
        printf("5............Delete from end\n");
        printf("6............Delete after\n");
        printf("7............Show\n");
        printf("0............Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            item = getData();
            add_beg(item);
            break;
        case 2:
            item = getData();
            add_last(item);
            break;
        case 3:
            printf("Search ");
            item = getData();
            printf("Insertion ");
            int info = getData();
            q = find(item);
            add_after(q, info);
        case 4:
            del_beg();
            break;
        case 5:
            del_end();
            break;
        case 6:
            printf("Search ");
            int item = getData();
            q = find(item);
            del_after(q);
        case 7:
            show();
            break;
        case 0:
            break;
        }
    } while (ch);
}