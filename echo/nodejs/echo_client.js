#!/usr/bin/nodejs

var net = require('net');

if (process.argv.length < 3) {
	console.log("usage: " + process.argv[1] + " <port>");
	process.exit(1);
}
var port = Number(process.argv[2]);

var client = net.connect({port: port});

client.on("data", function(data) {
	console.log(String.fromCharCode.apply(String, data).trim());
});

process.stdin.resume();
process.stdin.setEncoding("ascii");
process.stdin.on("data", function (data) {
	client.write(data);
});
