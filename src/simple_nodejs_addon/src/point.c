#include "point.h"
#include <node_api.h>
#include <stdio.h>
#include <stdlib.h>

Point create_point(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

void print_point(Point p) {
    printf("Point: (x: %d, y: %d)\n", p.x, p.y);
}

void move_point(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

int get_x(Point *p) {
    return p->x;
}

int get_y(Point *p) {
    return p->y;
}
