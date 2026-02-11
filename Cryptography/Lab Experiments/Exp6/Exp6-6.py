# autokey cipher

text = (input("Enter the text : "))
k = (input("Enter the key of size 1: "))

arr = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}

for i in range(len(text)):
    k = k + text[i]

cipher = ""

for i in range(len(text)):
    value1 = arr[text[i]]
    value2 = arr[k[i]]
    a = (value1 + value2)%26
    for key, value in arr.items():
        if value == a:
            b = key
            cipher = cipher + b
print("Encoding-------------------")
print(cipher)

plaintext = ""
for i in range(len(cipher)):
    value1 = arr[cipher[i]]
    value2 = arr[k[i]]
    a = (value1 - value2)%26
    for key, value in arr.items():
        if value == a:
            b = key
            plaintext = plaintext + b
print("Decoding-------------------")
print(plaintext)