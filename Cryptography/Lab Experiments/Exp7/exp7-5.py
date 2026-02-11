# sha1

import hashlib

str = input("Enter a message: ")

result = hashlib.sha1(str.encode())

print("The hexadecimal equivalent of SHA1 is : ")
print(result.hexdigest())