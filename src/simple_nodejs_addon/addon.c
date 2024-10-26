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

    // Define the function `MyFunction` in Javascript
    napi_create_function(env, NULL, 0, MyFunction, NULL, &fn);
    napi_set_named_property(env, exports, "MyFunction", fn);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);