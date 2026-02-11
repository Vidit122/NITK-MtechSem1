a = int(input("Enter a number(>2): "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []
for i in range(2,a):
    if(isPrime(i)):
        li.append(i)

print(li)
check = False
for i in range(len(li)):
    for j in range(i+1,len(li)):
        if li[i] + li[j] == a:
            check = True
            print(li[i], li[j])
            break
        else:
            check = False
    if check==True:
        break

if(check==False): print(-1)