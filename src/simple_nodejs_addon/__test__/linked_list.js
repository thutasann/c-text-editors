const linkedList = require('../build/Release/addon')

function linked_list_test() {
  console.log('\n==> Linked List')

  // Insert elements
  linkedList.insert(10)
  linkedList.insert(20)
  linkedList.insert(30)

  // Display the list
  console.log('Linked List:')
  linkedList.display() // Output: 30 -> 20 -> 10 -> NULL

  // Delete an element
  linkedList.delete(20)

  // Display again
  console.log('After Deletion:')
  linkedList.display() // Output: 30 -> 10 -> NULL
}

module.exports = { linked_list_test }
