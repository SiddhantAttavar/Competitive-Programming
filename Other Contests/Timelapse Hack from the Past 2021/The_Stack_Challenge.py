def solve(n, a, b, c):
    if n == 1:
        print(f'{n} : {a} --> {c}')
        return
    
    solve(n - 1, a, c, b)
    print(f'{n} : {a} --> {c}')
    solve(n - 1, b, a, c)

solve(int(input()), 'A', 'B', 'C')