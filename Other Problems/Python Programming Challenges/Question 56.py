def throwException():
    return 5 / 0

try:
    throwException()
except ZeroDivisionError as e:
    print(e)