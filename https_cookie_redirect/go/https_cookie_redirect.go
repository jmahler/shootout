package main

import (
	"net/http"
	"fmt"
	"math/rand"
)

func rand_token() string {
	x := rand.Int()
	str := fmt.Sprintf("%05d", x)
	return str
}

var token string

func http_first_response(w http.ResponseWriter, r *http.Request) {
	token = rand_token()

	cookie := &http.Cookie{
		Name: "token",
		Value: token,
	}
	http.SetCookie(w, cookie)
	http.Redirect(w, r, "/two", 301)
}

func http_second_response(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "text/html")

	token_cookie, err := r.Cookie("token")
	if err != nil {
		w.Write([]byte("ERROR: Could not find cookie :-(\n"))
	} else {
		if token_cookie.Value == token {
			w.Write([]byte("Success!\n"))
		} else {
			w.Write([]byte("ERROR: Wrong cookie value\n"))
		}
	}
	w.Write([]byte("<br>\n"))
	w.Write([]byte("<a href=\"/\">Retry?</a>\n"))

	token = "000"
}

func main() {
	port := "10443"

	http.HandleFunc("/", http_first_response)
	http.HandleFunc("/two", http_second_response)

	fmt.Printf("Listening on port: %v\n", port)
	fmt.Printf(" to test, run: curl -k -L https://localhost:10443\n")
	fmt.Printf(" if the path is followed, you will get a message!\n")
	err := http.ListenAndServeTLS(":" + "10443", "cert.pem", "key.pem", nil)
	if err != nil {
		fmt.Println("Something is wrong, is the cert/key corrupt?")
		panic(err)
	}
	// To generate these .pem keys run:
	// go run $(go env GOROOT)/src/crypto/tls/generate_cert.go --host=localhost
}
