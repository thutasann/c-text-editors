#include <node_api.h>

/** Sample MyFunction to return a string */
napi_value MyFunction(napi_env env, napi_callback_info info) {
    napi_value result;
    napi_create_string_utf8(env, "Hello From C!", NAPI_AUTO_LENGTH, &result);
    return result;
}

/** Function to add two numbers */
napi_value Add(napi_env env, napi_callback_info info) {
    size_t argc = 2; // expect 2 argument
    napi_value args[2];
    napi_value result;

    // get the arguments passed from Javascript
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    // convert arguments from napi_value to double
    double value1, value2;
    napi_get_value_double(env, args[0], &value1);
    napi_get_value_double(env, args[1], &value2);

    // perform addition
    double sum = value1 + value2;

    // convert the result back to napi_value and return
    napi_create_double(env, sum, &result);
    return result;
}

/** Module Initialization */
napi_value Init(napi_env env, napi_value exports) {
    napi_value fn;

    // Define the function `MyFunction` in Javascript
    napi_create_function(env, NULL, 0, MyFunction, NULL, &fn);
    napi_set_named_property(env, exports, "MyFunction", fn);

    // Define the function `Add` in Javascript
    napi_create_function(env, NULL, 0, Add, NULL, &fn);
    napi_set_named_property(env, exports, "add", fn);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);