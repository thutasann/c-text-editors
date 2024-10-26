#include "src/add.h"
#include "src/point.h"
#include "src/subtract.h"
#include <node_api.h>
#include <stdlib.h>

/** Sample MyFunction to return a string */
napi_value MyFunction(napi_env env, napi_callback_info info) {
    napi_value result;
    napi_create_string_utf8(env, "Hello From C!", NAPI_AUTO_LENGTH, &result);
    return result;
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

/** 🚀 Module Initialization */
napi_value Init(napi_env env, napi_value exports) {
    napi_value fn;
    napi_value add_fn;
    napi_value subtract_fn;
    napi_value create_point_fn, move_point_fn, get_x_fn, get_y_fn;

    // Define the function `MyFunction` in Javascript
    napi_create_function(env, NULL, 0, MyFunction, NULL, &fn);
    napi_set_named_property(env, exports, "MyFunction", fn);

    // Define the function `Add` in Javascript
    napi_create_function(env, NULL, 0, Add, NULL, &add_fn);
    napi_set_named_property(env, exports, "add", add_fn);

    // Define the function `Subtract` in Javascript
    napi_create_function(env, NULL, 0, Subtract, NULL, &subtract_fn);
    napi_set_named_property(env, exports, "subtract", subtract_fn);

    // Point Data Structure
    napi_create_function(env, NULL, 0, CreatePoint, NULL, &create_point_fn);
    napi_set_named_property(env, exports, "createPoint", create_point_fn);

    napi_create_function(env, NULL, 0, MovePoint, NULL, &move_point_fn);
    napi_set_named_property(env, exports, "movePoint", move_point_fn);

    napi_create_function(env, NULL, 0, GetX, NULL, &get_x_fn);
    napi_set_named_property(env, exports, "getX", get_x_fn);

    napi_create_function(env, NULL, 0, GetY, NULL, &get_y_fn);
    napi_set_named_property(env, exports, "getY", get_y_fn);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);