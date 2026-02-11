n = int(input("Enter a number: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []
for i in range(2,n):
    if(isPrime(i)):
        li.append(i)
print(li)
count = 0
for i in range(2,n):
    if(isPrime(i)):
        for j in range(len(li)):
            for k in range(j+1,len(li)):
                if i == li[j] + li[k]:
                    count = count + 1
                    ans = i
                    # print(i,li[j],li[k])
        for j in range(len(li)):
            for k in range(j+1,len(li)):
                if i == li[k] - li[j]:
                    count = count + 1
                    ans = i
                    # print(i,li[j],li[k])
        if count == 2: print(i)
        else: count = 0