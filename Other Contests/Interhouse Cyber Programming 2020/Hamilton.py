n=int(input())
if 2<=n<=10000:
    a=input()
    l=a.split(' ')
    for i in range(len(l)):
        if not(1<=int(l[i])<=1000):
            list.pop(i)
        else:
            l[i]=int(l[i])
            
    s,p=0,1
    for i in range (len(l)):
        s+=l[i]
        if s % 101 == 0:
            print('+'.join(l[0:i]),end='')
            print('*'.join(l[i:-1]))
            break
    else:
        for i in range (len(l)):
            p*=l[i]
            for j in range(i+1,len(l)):
                if p+sum(l[i:j]) % 101 == 0:
                    print('*'.join(l[0:i]),end='')
                    print('+'.join(l[i:j]),end='')
                    print('*'.join(l[j:-1]))
                elif p-sum(l[i:j]) % 101 == 0:
                    print('*'.join(l[0:i]),end='')
                    print('-'.join(l[i:j]),end='')
                    print('*'.join(l[j:-1]))