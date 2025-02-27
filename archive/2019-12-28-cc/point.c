#include <stdio.h>
#include <stdlib.h>

/* https://stackoverflow.com/questions/12642830/can-i-define-a-function-inside-a-c-structure/12642878#12642878 */

struct point
{
    int x;
    int y;
    void (*print)(const struct point*);
    void (*del)(const struct point*);
};

void point_print(const struct point* self)
{
    printf("x=%d\n", self->x);
    printf("y=%d\n", self->y);
}

void point_del(const struct point* self) {
  free((void *)self);
}

struct point * point_new(int x, int y) {
    struct point *p = malloc(sizeof(*p));
    p->x = x;
    p->y = y;
    p->print = point_print;
    p->del = point_del;
    return p;
}

