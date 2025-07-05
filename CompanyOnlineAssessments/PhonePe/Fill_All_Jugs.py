# 

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        h = list(map(int, input().split()))
        max_h = max(h)
        ans = float('inf')

        for target in range(max_h, max_h + 101):
            one, two = 0, 0
            for hi in h:
                diff = target - hi
                two += diff // 2
                one += diff % 2

            # If 2x+1y = hours: Each pair of (even+odd) = 2 hours
            low, high = 0, 2 * (one + two)
            while low < high:
                mid = (low + high) // 2
                # Max odd hours = ceil(mid/2), even = mid//2
                odd = (mid + 1) // 2
                even = mid // 2
                if odd >= one and (odd + 2 * even) >= (one + 2 * two):
                    high = mid
                else:
                    low = mid + 1
            ans = min(ans, low)

        print(ans)
solve()