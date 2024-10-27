const addon = require('../build/Release/addon')

function add_sub_test() {
  console.log('==> Add Subtract')
  const sum = addon.add(7, 3)
  console.log('sum result: ', sum)
  const subtract = addon.subtract(5, 4)
  console.log('subtract result: ', subtract)
}

module.exports = { add_sub_test }
