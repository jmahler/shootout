#!/usr/bin/env python3

import sys
import json

def die_usage():
    print("usage: cat file.json | {}".format(sys.argv[0]), file=sys.stderr)
    print("       {} file.json".format(sys.argv[0]), file=sys.stderr)
    sys.exit(1)

def main():
    
    try:
        json_data = None
        if len(sys.argv) > 1:
            with open(sys.argv[1]) as fd:
                json_data = json.loads(fd.read())
        else:
            json_data = json.load(sys.stdin)

        print(json.dumps(json_data, indent=4, sort_keys=True))
    except json.JSONDecodeError as e:
        print("Error decoding JSON, is it malformed?", file=sys.stderr)
        die_usage()
    except Exception as e:
        print(e, file=sys.stderr)
        die_usage()

if __name__ == '__main__':
    main()
