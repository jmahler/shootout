#!/usr/bin/env python3

import sys
import json

def die_usage():
    print("usage: cat file.json | {}".format(sys.argv[0]), file=sys.stderr)
    print("       {} file.json".format(sys.argv[0]), file=sys.stderr)
    sys.exit(1)

def main():
    
    try:
        fd = sys.stdin
        if len(sys.argv) > 1:
            fd = open(sys.argv[1])

        data = fd.read()
        json_data = json.loads(data)

        print(json.dumps(json_data, indent=4, sort_keys=True))
    except json.JSONDecodeError as e:
        print("Error decoding JSON, is it malformed?", file=sys.stderr)
        die_usage()
    except Exception as e:
        print(e, file=sys.stderr)
        die_usage()

if __name__ == '__main__':
    main()
