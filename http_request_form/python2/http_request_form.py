#!/usr/bin/env python2

import requests

url = 'http://pgp.mit.edu/pks/lookup'
vals = {
    'search': 'jmmahler@gmail.com',
    'op': 'index',
}

res = requests.get(url, params=vals)

if 'Jeremiah Mahler' in res.text:
    print("OK")
else:
    print(res.url)
    print(res.text)
    print("ERROR Unexpected response")
