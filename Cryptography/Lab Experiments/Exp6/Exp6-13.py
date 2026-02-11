# 2 transpositions

arr = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}

text = (input("Enter the text : "))

t1 = ""
t2 = ""
for i in range(len(text)):
    if i%2==0:
        t1 = t1 + text[i]
    else:
        t2 = t2 + text[i]


cipher = t1 + t2
print("Encoding-------------------")
print(cipher)


k = (input("Enter the key as per no.of columns required: "))

a = []
for i in range(len(k)):
    temp = []
    temp.append(arr[k[i]])
    temp.append(i)
    a.append(temp)
print(a)
count = 0
cip = []
while(True):
    if count >= len(cipher): break
    temp = []
    for i in range(len(k)):
        if count >= len(cipher):
            count = count + 1
            temp.append('x')
        else: 
            temp.append(cipher[count])
            count = count + 1
    cip.append(temp)

print(cip)

    
a.sort()
print(a)

cipher2 = ""

count = 0
k = 0
while(True):
    if(count == len(cip)*len(cip[0])): break
    for i in range(len(cip)):
        cipher2 = cipher2 + cip[i][a[k][1]]
        count = count + 1
    k = k+1
print("Encryption-----------------------")    
print(cipher2)


plain = []
for i in range(int(len(cipher2)/len(a))):
    temp = []
    for j in range(len(a)):
        temp.append(0)
    plain.append(temp)
        
plaintext = ""        
count = 0
k = 0
for i in range(len(a)):
    m = a[i][1]
    for j in range(int(len(cipher2)/len(a))):
        plain[j][m] = cipher2[count]
        count = count + 1
        
        
print("Decryption-----------------------")    
print(plain)
for i in range(len(plain)):
    for j in range(len(plain[0])):
        plaintext = plaintext + plain[i][j]
print(plaintext)




plaintext1 = ""
n = len(plaintext)
n1 = ""
n2 = ""
if(n%2 !=0):
    for i in range(n):
        if(i >= int(n/2 + 1)):
            n2 = n2 + plaintext[i]
        else:
            n1 = n1 + plaintext[i]
            
    j = 0
    k = 0
    for i in range(n):
        if(i%2 == 0):
            plaintext1 = plaintext1 + n1[j]
            j = j+1
        else:
            plaintext1 = plaintext1 + n2[k]
            k = k + 1
    print("Decoding-------------------")
    print(plaintext)
else:
    for i in range(n):
        if(i >= int(n/2)):
            n2 = n2 + plaintext[i]
        else:
            n1 = n1 + plaintext[i]
            
    j = 0
    k = 0
    for i in range(n):
        if(i%2 == 0):
            plaintext1 = plaintext1 + n1[j]
            j = j+1
        else:
            plaintext1 = plaintext1 + n2[k]
            k = k + 1
    print("Decoding-------------------")
    print(plaintext1)
