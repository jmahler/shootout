
package main

import (
	"net/http"
	"net/url"
	"bytes"
	"fmt"
	"strings"
)

func main() {
	http_url := "http://pgp.mit.edu/pks/lookup"
	form := url.Values{
		"search": {"jmmahler@gmail.com"},
		"op": {"index"},
	}

	resp, err := http.Get(fmt.Sprintf("%v?%v", http_url, form.Encode()))
	if err != nil {
		fmt.Println(err)
	} else {
		defer resp.Body.Close()

		// response to a string
		buf := new(bytes.Buffer)
		buf.ReadFrom(resp.Body)
		out := buf.String()

		if strings.Contains(out, "Jeremiah Mahler") {
			fmt.Println("OK")
		} else {
			fmt.Println(out)
			fmt.Println("ERROR Unexpected response")
		}
	}
}
