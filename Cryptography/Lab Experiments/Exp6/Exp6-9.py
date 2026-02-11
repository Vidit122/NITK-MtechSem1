# rail fence cipher

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


plaintext = ""
n = len(cipher)
n1 = ""
n2 = ""
if(n%2 !=0):
    for i in range(n):
        if(i >= int(n/2 + 1)):
            n2 = n2 + cipher[i]
        else:
            n1 = n1 + cipher[i]
            
    j = 0
    k = 0
    for i in range(n):
        if(i%2 == 0):
            plaintext = plaintext + n1[j]
            j = j+1
        else:
            plaintext = plaintext + n2[k]
            k = k + 1
    print("Decoding-------------------")
    print(plaintext)
else:
    for i in range(n):
        if(i >= int(n/2)):
            n2 = n2 + cipher[i]
        else:
            n1 = n1 + cipher[i]
            
    j = 0
    k = 0
    for i in range(n):
        if(i%2 == 0):
            plaintext = plaintext + n1[j]
            j = j+1
        else:
            plaintext = plaintext + n2[k]
            k = k + 1
    print("Decoding-------------------")
    print(plaintext)
