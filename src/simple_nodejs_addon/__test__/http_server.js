const addon = require('../build/Release/addon')

function http_server() {
  addon.startServer(8080)
  console.log('Server is running on http://localhost:8080')
}

module.exports = {
  http_server,
}
