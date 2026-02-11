ans = []
for j in range(1, 20):
    def fact(n):
        if n == 0: return 1
        ans = n*fact(n-1)
        return ans

    val = fact(j) + 1
    # print(val)

    def isPrime(n):
        for i in range(2,n):
            if n%i == 0: return False
        return True

    li = []
    for i in range(2,2000):
        if(isPrime(i)):
            li.append(i)

    for i in li:
        if val%i == 0:
            print("Smallest prime factor for the value of n as ",j, "is: ", i)
            ans.append(i)
            break


print(ans)