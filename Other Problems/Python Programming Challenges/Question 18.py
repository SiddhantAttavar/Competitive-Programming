res = []
for password in input().split(','):
    lowerLetter = False
    upperLetter = False
    digit = False
    special = False

    for c in password:
        lowerLetter = lowerLetter or c.islower()
        upperLetter = upperLetter or c.isupper()
        digit = digit or c.isdigit()
        special = special or (not c.isalnum())
    
    if (
        lowerLetter and
        upperLetter and
        digit and
        special and
        6 <= len(password) <= 12
    ):
        res.append(password)
        
print(*res, sep = ',')