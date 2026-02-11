# md5

import hashlib

str = input("Enter a message: ")
res = hashlib.md5(str.encode())
print(res.hexdigest())