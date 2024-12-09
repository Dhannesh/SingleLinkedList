#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe, pow;
    struct node *next;
};

struct node *poly;
struct node *get_node()
{
    return (struct node *)malloc(sizeof(struct node));
}
void show()
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

void add_last(int coe, int pow)
{
    struct node *q = get_node();
    q->coe = coe;
    q->pow = pow;
    q->next = NULL;
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

int main()
{
    poly = NULL;
    // 3x^4 + 10x^3 - 5x^2 + 15x -10
    add_last(3, 4);
    add_last(10, 3);
    add_last(-5, 2);
    add_last(15, 1);
    add_last(-10, 0);
    show();
}