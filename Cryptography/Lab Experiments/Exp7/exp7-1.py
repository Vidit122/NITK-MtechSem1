# diffie hellman key 

pubA = int(input("Alice enter your public key: "))
privA = int(input("Alice enter your private key: "))
pubB = int(input("Bob enter your public key: "))
privB = int(input("Bob enter your private key: "))

temp1 = pow(pubB, privA)%pubA
temp2 = pow(pubB, privB)%pubA
print(temp1, temp2)

keyA = temp2
keyB = temp1

Ka = pow(keyA, privA)%pubA

Kb = pow(keyB, privB)%pubA

if(Ka == Kb): print("Encryption has been successfully implemented")
print(Ka, "is the shared secret key")