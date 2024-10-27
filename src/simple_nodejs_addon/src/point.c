#include "./include/point.h"
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

/** Wrap a Point Data Structure in a Javascript Object */
napi_value CreatePoint(napi_env env, napi_callback_info info) {
    napi_value result;
    int32_t x, y;

    // get arguments (x and y coordinates)
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);
    napi_get_value_int32(env, args[0], &x);
    napi_get_value_int32(env, args[1], &y);

    // Create Point Structure
    Point *point = (Point *)malloc(sizeof(Point));
    *point = create_point(x, y);

    // Return the point as a pointer
    napi_create_external(env, point, NULL, NULL, &result);
    return result;
}

/** Move the point */
napi_value MovePoint(napi_env env, napi_callback_info info) {
    napi_value result;
    Point *point;
    int32_t dx, dy;

    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    napi_get_value_external(env, args[0], (void **)&point);
    napi_get_value_int32(env, args[1], &dx);
    napi_get_value_int32(env, args[2], &dy);

    move_point(point, dx, dy);
    napi_get_undefined(env, &result);

    return result;
}

/** Get X Coordinate */
napi_value GetX(napi_env env, napi_callback_info info) {
    Point *point;
    napi_value x;

    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);
    napi_get_value_external(env, args[0], (void **)&point);

    napi_create_int32(env, get_x(point), &x);
    return x;
}

/** Get Y Coordinate */
napi_value GetY(napi_env env, napi_callback_info info) {
    Point *point;
    napi_value y;

    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);
    napi_get_value_external(env, args[0], (void **)&point);

    napi_create_int32(env, get_y(point), &y);
    return y;
}