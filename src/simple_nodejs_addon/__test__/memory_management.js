const addon = require('../build/Release/addon')

function memory_management() {
  console.log('\n==> Memory Management')

  const ptr1 = addon.allocateMemory(128) // Allocate 128 bytes
  console.log(`Allocated memory: ${addon.getMemoryUsage()} bytes`)

  const ptr2 = addon.reallocateMemory(ptr1, 256) // Reallocate to 256 bytes
  console.log(`Reallocated memory: ${addon.getMemoryUsage()} bytes`)

  addon.freeMemory(ptr2) // Free the memory
  console.log(`Memory after free: ${addon.getMemoryUsage()} bytes`)
}

module.exports = {
  memory_management,
}
