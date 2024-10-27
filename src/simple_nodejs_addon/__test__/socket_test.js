const addon = require('../build/Release/addon')

const sockfd = addon.connectSocket('127.0.0.1', 8080)
if (sockfd < 0) {
  console.error('Failed to connect.')
} else {
  console.log('Connected:', sockfd)

  const len = addon.sendMessage(sockfd, 'Hello, Server!')
  console.log('Send Message Length:', len)

  // Close the socket
  addon.closeSocket(sockfd)
  console.log('Connection closed.')
}
