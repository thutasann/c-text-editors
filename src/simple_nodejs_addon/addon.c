#include "src/include/add.h"
#include "src/include/linked_list.h"
#include "src/include/memory.h"
#include "src/include/point.h"
#include "src/include/server.h"
#include "src/include/socket.h"
#include "src/include/subtract.h"
#include <node_api.h>
#include <stdlib.h>

/** Sample MyFunction to return a string */
napi_value MyFunction(napi_env env, napi_callback_info info) {
    napi_value result;
    napi_create_string_utf8(env, "Hello From C Addons!", NAPI_AUTO_LENGTH, &result);
    return result;
}

// Point Data Structure Methods
napi_value CreatePoint(napi_env env, napi_callback_info info);
napi_value MovePoint(napi_env env, napi_callback_info info);
napi_value GetX(napi_env env, napi_callback_info info);
napi_value GetY(napi_env env, napi_callback_info info);

// Socket
napi_value js_connect_socket(napi_env env, napi_callback_info args);
napi_value js_send_message(napi_env env, napi_callback_info args);
napi_value js_close_socket(napi_env env, napi_callback_info args);

// HTTP Server
napi_value js_start_server(napi_env env, napi_callback_info args);

// Memory Management
napi_value AllocateMemory(napi_env env, napi_callback_info info);
napi_value ReallocateMemory(napi_env env, napi_callback_info info);
napi_value FreeMemory(napi_env env, napi_callback_info info);
napi_value GetMemoryUsage(napi_env env, napi_callback_info info);

// Linked List
napi_value Insert(napi_env env, napi_callback_info info);
napi_value Delete(napi_env env, napi_callback_info info);
napi_value Display(napi_env env, napi_callback_info info);

/** 🚀 Module Initialization */
napi_value Init(napi_env env, napi_value exports) {
    napi_value fn;
    napi_value add_fn;
    napi_value subtract_fn;
    napi_value create_point_fn, move_point_fn, get_x_fn, get_y_fn;
    napi_value socket_fn;
    napi_value server_fn;
    napi_value alloc_fn, realloc_fn, free_fn, usage_fn;
    napi_value insert_fn, delete_fn, display_fn;

    // Define the function `MyFunction` in Javascript ⭐️
    napi_create_function(env, NULL, 0, MyFunction, NULL, &fn);
    napi_set_named_property(env, exports, "MyFunction", fn);

    // Define the function `Add` in Javascript ⭐️
    napi_create_function(env, NULL, 0, Add, NULL, &add_fn);
    napi_set_named_property(env, exports, "add", add_fn);

    // Define the function `Subtract` in Javascript ⭐️
    napi_create_function(env, NULL, 0, Subtract, NULL, &subtract_fn);
    napi_set_named_property(env, exports, "subtract", subtract_fn);

    // Point Data Structure ⭐️
    napi_create_function(env, NULL, 0, CreatePoint, NULL, &create_point_fn);
    napi_set_named_property(env, exports, "createPoint", create_point_fn);

    napi_create_function(env, NULL, 0, MovePoint, NULL, &move_point_fn);
    napi_set_named_property(env, exports, "movePoint", move_point_fn);

    napi_create_function(env, NULL, 0, GetX, NULL, &get_x_fn);
    napi_set_named_property(env, exports, "getX", get_x_fn);

    napi_create_function(env, NULL, 0, GetY, NULL, &get_y_fn);
    napi_set_named_property(env, exports, "getY", get_y_fn);

    // Socket ⭐️
    napi_create_function(env, NULL, 0, js_connect_socket, NULL, &socket_fn);
    napi_set_named_property(env, exports, "connectSocket", socket_fn);

    napi_create_function(env, NULL, 0, js_send_message, NULL, &socket_fn);
    napi_set_named_property(env, exports, "sendMessage", socket_fn);

    napi_create_function(env, NULL, 0, js_close_socket, NULL, &socket_fn);
    napi_set_named_property(env, exports, "closeSocket", socket_fn);

    // HTTP Server ⭐️
    napi_create_function(env, NULL, 0, js_start_server, NULL, &server_fn);
    napi_set_named_property(env, exports, "startServer", server_fn);

    // Memory Management ⭐️
    napi_create_function(env, NULL, 0, AllocateMemory, NULL, &alloc_fn);
    napi_create_function(env, NULL, 0, ReallocateMemory, NULL, &realloc_fn);
    napi_create_function(env, NULL, 0, FreeMemory, NULL, &free_fn);
    napi_create_function(env, NULL, 0, GetMemoryUsage, NULL, &usage_fn);

    napi_set_named_property(env, exports, "allocateMemory", alloc_fn);
    napi_set_named_property(env, exports, "reallocateMemory", realloc_fn);
    napi_set_named_property(env, exports, "freeMemory", free_fn);
    napi_set_named_property(env, exports, "getMemoryUsage", usage_fn);

    // Linked List ⭐️
    napi_create_function(env, NULL, 0, Insert, NULL, &insert_fn);
    napi_set_named_property(env, exports, "insert", insert_fn);

    napi_create_function(env, NULL, 0, Delete, NULL, &delete_fn);
    napi_set_named_property(env, exports, "delete", delete_fn);

    napi_create_function(env, NULL, 0, Display, NULL, &display_fn);
    napi_set_named_property(env, exports, "display", display_fn);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);