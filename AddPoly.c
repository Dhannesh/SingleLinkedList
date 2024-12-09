#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe, pow;
    struct node *next;
};

struct node *poly1, *poly2, *poly3;

struct node *get_node()
{
    return (struct node *)malloc(sizeof(struct node));
}
void show(struct node *poly)
{
    struct node *p = poly;
    printf("\n");
    while (p != NULL)
    {
        if (p->coe > 0)
            printf("+%dx^%d ", p->coe, p->pow);
        else
            printf("%dx^%d ", p->coe, p->pow);
        p = p->next;
    }
    printf("\n");
}

void add_last(int coe, int pow, int no)
{
    struct node *poly;
    struct node *q = get_node();
    q->coe = coe;
    q->pow = pow;
    q->next = NULL;
    if (no == 1)
    {
        if(poly1==NULL)
        {
            poly1 = q;
            poly = poly1;
        }
    }
    else if (no == 2)
    {
        if (poly2 == NULL)
        {
            poly2 = q;
            poly = poly2;
        }
        
    }
    else
    {
        if (poly3 == NULL)
        {
            poly3 = q;
            poly = poly3;
        }
    }
    if (poly == NULL)
    {
        poly = q;
    }
    else
    {
        struct node *p = poly;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
}

void addPoly(struct node *p, struct node *q)
{
    int coe, pow;
    while (p != NULL && q != NULL)
    {
        if (p->pow == q->pow)
        {
            coe = p->coe + q->coe;
            pow = p->pow;
            p = p->next;
            q = q->next;
        }
        else if (p->pow > q->pow)
        {
            coe = p->coe;
            pow = p->pow;
            p = p->next;
        }
        else
        {
            coe = q->coe;
            pow = q->pow;
            q = q->next;
        }
        add_last(coe, pow, 3);
    }
    while (p != NULL)
    {
        add_last(p->coe, p->pow, 3);
        p = p->next;
    }
    while (q != NULL)
    {
        add_last(q->coe, q->pow, 3);
        q = q->next;
    }
}
int main()
{
    poly1 = NULL;
    poly2 = NULL;
    poly3 = NULL;
    // 3x^4 + 10x^3 - 5x^2 + 15x -10
    add_last(3, 4, 1);
    add_last(10, 3, 1);
    add_last(-5, 2, 1);
    add_last(15, 1, 1);
    add_last(-10, 0, 1);
    // 10x^4 + 23x^2 - 12x + 5
    add_last(10, 4, 2);
    add_last(23, 2, 2);
    add_last(-12, 1, 2);
    add_last(5, 0, 2);
    printf("Polynomial 1");
    show(poly1);
    printf("Polynomial 2");
    show(poly2);
    addPoly(poly1, poly2);
    printf("Addition of polynomial:");
    show(poly3);
}