const addon = require('./build/Release/addon')
const { add_sub_test } = require('./__test__/add_subtract')
const { memory_management } = require('./__test__/memory_management')
const { point_data_structure } = require('./__test__/point_data_structure')
const { linked_list_test } = require('./__test__/linked_list')

console.log(addon.MyFunction(), '\n')

add_sub_test()
point_data_structure()
memory_management()
linked_list_test()
