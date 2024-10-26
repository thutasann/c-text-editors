const addon = require('./build/Release/addon')

console.log('MyAddon', addon.MyFunction(), '\n')

const sum = addon.add(7, 3)
console.log('sum result: ', sum, '\n')

const subtract = addon.subtract(5, 4)
console.log('subtract result: ', subtract, '\n')

// Point Data Structure
const point = addon.createPoint(10, 20)
console.log('X:', addon.getX(point)) // X: 10
console.log('Y:', addon.getY(point)) // Y: 20
addon.movePoint(point, 5, -5)
console.log('After move - X:', addon.getX(point)) // X: 15
console.log('After move - Y:', addon.getY(point)) // Y: 15

addon.startServer(8080)
console.log('Server is running on http://localhost:8080')
