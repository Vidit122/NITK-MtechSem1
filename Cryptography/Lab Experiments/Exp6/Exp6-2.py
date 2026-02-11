#y
#monoalphabetic cipher - affine cipher

arr = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}

k1 = int(input("Enter the key 1 that is prime to 26: "))
k2 = int(input("Enter the key 2: "))

text = input("Enter the plaintext or message: ")

cipher = ""
for i in range(len(text)):
    value = arr[text[i]]
    a = (value*k1 + k2)%26
    for key, value in arr.items():
        if value == a:
            b = key
            cipher = cipher + b

print("Encryption--------------------------")
print(cipher)


c = pow(k1, -1, 26)

plaintext = ""
for i in range(len(cipher)):
    value = arr[cipher[i]]
    a = ((value-k2)*c)%26
    for key, value in arr.items():
        if value == a:
            b = key
            plaintext = plaintext + b

print("Decryption--------------------------")
print(plaintext)