# 3 - n for which no prime b/w n and n+10
# 3 - m for which no prime b/w 10m and 10m + 10
n = int(input("Enter a number: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []
for i in range(2,n):
    if not any(isPrime(j) for j in range(i,i+11)):
            print(i)
            li.append(i)
            if(len(li) == 3):
                break
    if(len(li) == 3):
        break
lm = []
for i in range(2,n):
    if not any(isPrime(j) for j in range(10*i,10*i + 11)):
            print(i)
            lm.append(i)
            if(len(lm) == 3):
                break
    if(len(lm) == 3):
        break

print(li)
print(lm)