def search(l, x):
    low, high = 0, len(l) - 1
    
    while low <= high:
        mid = (low + high) // 2
        if l[mid] < x:
            low = mid + 1
        elif l[mid] > x:
            high = mid - 1
        else:
            return mid
    
    return -1