for i in range(int(input().strip())):
    n = bin(int(input().strip()))[2:]
    print('Case #' + str(i + 1), end = ': ')
    print('YES' if n.count('1') % 2 == 0 else 'NO')
    
#for i in range(int(input().strip())): print('Case #' + str(i + 1) + ': ' + ('YES' if bin(int(input()))[2:].count('1') % 2 == 0 else 'NO'))
