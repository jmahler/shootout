package main

import (
	"net/http"
	"fmt"
)

func http_request_handler(w http.ResponseWriter, req *http.Request) {
	w.Header().Set("Content-Type", "text/plain")
	w.Write([]byte("Hello, World!\n"))
}

func main() {
	port := "10443"

	http.HandleFunc("/", http_request_handler)
	fmt.Printf("Listening on port: %v\n", port)
	fmt.Printf(" to test, run: curl -k https://localhost:10443\n")
	err := http.ListenAndServeTLS(":" + "10443", "cert.pem", "key.pem", nil)
	if err != nil {
		fmt.Println("Something is wrong, is the cert/key corrupt?")
		panic(err)
	}
	// To generate these .pem keys run:
	// go run $(go env GOROOT)/src/crypto/tls/generate_cert.go --host=localhost
}
