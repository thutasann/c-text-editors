const MyAddon = require('./build/Release/addon')

console.log('MyAddon', MyAddon.MyFunction())

const result = MyAddon.add(3, 5)
console.log('sum result : ', result)
