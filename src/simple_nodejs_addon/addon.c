#include "src/add.h"
#include "src/subtract.h"
#include <node_api.h>

/** Sample MyFunction to return a string */
napi_value MyFunction(napi_env env, napi_callback_info info) {
    napi_value result;
    napi_create_string_utf8(env, "Hello From C!", NAPI_AUTO_LENGTH, &result);
    return result;
}

/** Module Initialization */
napi_value Init(napi_env env, napi_value exports) {
    napi_value fn;
    napi_value add_fn;
    napi_value subtract_fn;

    // Define the function `MyFunction` in Javascript
    napi_create_function(env, NULL, 0, MyFunction, NULL, &fn);
    napi_set_named_property(env, exports, "MyFunction", fn);

    // Define the function `Add` in Javascript
    napi_create_function(env, NULL, 0, Add, NULL, &add_fn);
    napi_set_named_property(env, exports, "add", add_fn);

    // Define the function `Subtract` in Javascript
    napi_create_function(env, NULL, 0, Subtract, NULL, &subtract_fn);
    napi_set_named_property(env, exports, "subtract", subtract_fn);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);