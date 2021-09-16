balance = 0

while True:
    try:
        op, amount = input().split()
        amount = int(amount) if op == 'D' else -int(amount)
        balance += amount
    except:
        break

print(balance)