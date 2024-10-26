const MyAddon = require('./build/Release/addon')

console.log('MyAddon', MyAddon.MyFunction())

const result = MyAddon.add(7, 3)
console.log('sum result : ', result)
