const addon = require('./build/Release/addon')

console.log('MyAddon', addon.MyFunction(), '\n')

// --- Add / Subtract
const sum = addon.add(7, 3)
console.log('sum result: ', sum, '\n')

const subtract = addon.subtract(5, 4)
console.log('subtract result: ', subtract, '\n')

// --- Point Data Structure
const point = addon.createPoint(10, 20)
console.log('X:', addon.getX(point)) // X: 10
console.log('Y:', addon.getY(point)) // Y: 20
addon.movePoint(point, 5, -5)
console.log('After move - X:', addon.getX(point)) // X: 15
console.log('After move - Y:', addon.getY(point)) // Y: 15

// --- Memory Management
const ptr1 = addon.allocateMemory(128) // Allocate 128 bytes
console.log(`Allocated memory: ${addon.getMemoryUsage()} bytes`)

const ptr2 = addon.reallocateMemory(ptr1, 256) // Reallocate to 256 bytes
console.log(`Reallocated memory: ${addon.getMemoryUsage()} bytes`)

addon.freeMemory(ptr2) // Free the memory
console.log(`Memory after free: ${addon.getMemoryUsage()} bytes`)

// addon.startServer(8080)
// console.log('Server is running on http://localhost:8080')
