#!/usr/bin/nodejs

console.log(process.argv.length + " arguments");

for (var i = 0; i < process.argv.length; i++) {
	console.log(i + ": " + process.argv[i]);
}
