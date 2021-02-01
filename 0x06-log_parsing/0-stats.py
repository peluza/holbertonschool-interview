#!/usr/bin/python3

import sys
import signal


def log_parsing(function_size, status_code):
    """Write a script that reads stdin line by line and computes metrics:

    Args:
        function_size (int): size the funtion
        status_code (int): status code
    """
    print('File size: {}'.format(function_size))
    for key, value in sorted(status_code.items()):
        if value != 0:
            print('{}: {}'.format(key, value))

status_code = {"200": 0, "301": 0, "400": 0, "401": 0,
               "403": 0, "404": 0, "405": 0, "500": 0}

count = 1
function_size = 0

# split the line in the stdin
try:
    for line in sys.stdin:
        split1 = line.split()

        if len(split1) > 2:
            file_size = split1[-1]
            status = split1[-2]
            function_size = function_size + int(file_size)

# verify if the status sent is in the diccionary created and sum to the status
            if status in status_code:
                status_code[status] = status_code[status] + 1


# Every 10 iteractions, prints the value
        if count % 10 == 0:
            print('File size: {}'.format(function_size))
            for key, value in sorted(status_code.items()):
                if value != 0:
                    print('{}: {}'.format(key, value))

        count = count + 1

except KeyboardInterrupt:
    pass

finally:
    log_parsing(function_size, status_code)
