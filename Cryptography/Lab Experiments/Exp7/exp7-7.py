# hmac

import hmac
import hashlib

str1 = input("Enter a secret key: ")
str2 = input("Enter a message: ")

secret_key = b'str1'
message = b'str2'

mac = hmac.new(secret_key, message, hashlib.sha256)
mac_digest = mac.digest()
mac_hexdigest = mac.hexdigest()

print(f"MAC digest: {mac_digest}")
print(f"MAC hexdigest: {mac_hexdigest}")

# received_mac_hexdigest = mac_hexdigest
# receiver_mac = hmac.new(secret_key, message, hashlib.sha256)

# if hmac.compare_digest(mac_digest, receiver_mac.digest()):
#     print("MAC is valid: Message is authentic and unaltered.")
# else:
#     print("MAC is invalid: Message has been tampered with or is not from the sender.")