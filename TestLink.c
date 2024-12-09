#include "linkedList.h"

int main()
{
    struct node *start = NULL;
    add_beg(&start, 10);
    add_beg(&start, 20);
    add_beg(&start, 30);
    add_beg(&start, 40);

    show(start);
}