const addon = require('../build/Release/addon')

function point_data_structure() {
  console.log('\n==> Point Data Structure')
  const point = addon.createPoint(10, 20)
  console.log('X:', addon.getX(point)) // X: 10
  console.log('Y:', addon.getY(point)) // Y: 20
  addon.movePoint(point, 5, -5)
  console.log('After move - X:', addon.getX(point)) // X: 15
  console.log('After move - Y:', addon.getY(point), '\n') // Y: 15
}

module.exports = {
  point_data_structure,
}
