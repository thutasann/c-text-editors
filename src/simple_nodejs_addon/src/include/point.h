#ifndef POINT_H
#define POINT_H

/** Custom Data Structured named `Point` */
typedef struct {
    /** x value */
    int x; 
    /** y value */
    int y;
} Point;

/** Create Point Function Prototype */
Point create_point(int x, int y);

/** Print Point Function Prototype */
void print_point(Point p);

/** Move Point Function Prototype */
void move_point(Point *p, int dx, int xy); 

/** Get X Function Prototype */
int get_x(Point *p);

/** Get Y Function Prototype */
int get_y(Point *p);

#endif