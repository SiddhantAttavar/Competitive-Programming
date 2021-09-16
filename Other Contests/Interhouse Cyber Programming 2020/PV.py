n=int(input())

if 1<=n<=100000:      
    arr=[]
    for i in range(n):
        if 1<=arr[i]<=100000:
            arr.append(int(input()))

    val=[1]

    for i in range(len(arr)-1):
        c=1
        for j in range(i,len(arr)-1):
            if arr[j]<arr[j+1]:
                c+=1
            else:
                break
        val.append(c)

    print(sum(val))
    

