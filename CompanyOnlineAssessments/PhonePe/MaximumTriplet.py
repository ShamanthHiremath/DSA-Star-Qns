def max_triplet():
    n = len(arr)
    
    if n < 3:
        print("Max triplet not possible")
    
    summ = 0
    for i in range(0, 3):
        summ += arr[i]
    
    max_sum = summ
    for i in range(3, n):
        summ -= arr[i - 3]
        summ += arr[i]
        max_sum = max(max_sum, summ)
    
    print("Max triplet sum is", max_sum)
    
n = int(input())
arr = list(map(int, input().split()))

max_triplet()