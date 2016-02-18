#!/usr/bin/nodejs

var net = require('net');
var port = 1337;

var server = net.createServer(function (socket) {
	socket.pipe(socket);
});

server.listen(port, '127.0.0.1');
console.log("Port: " + port);
