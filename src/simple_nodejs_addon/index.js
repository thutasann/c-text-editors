const MyAddon = require('./build/Release/addon')

console.log('MyAddon', MyAddon.MyFunction())

const sum = MyAddon.add(7, 3)
console.log('sum result: ', sum)

const subtract = MyAddon.subtract(5, 4)
console.log('subtract result: ', subtract)
