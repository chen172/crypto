# 1.List two disputes that can arise in the context of message authentication.
Suppose that John sends an authenticated message to Mary.

- Mary may forge a different message and claim that it came from Jhon. Mary would simply have
to create a message and append an authentication code using the key that Jhon and Mary share.
- Jhon can deny sending the message. Because it is possible for Mary to forge a message, there 
is no way to prove that Jhon did in fact send the message.

# 2.What are the properties a digital signature should have?
- It must verify the author and the date and time of the signature.
- It must authenticate the contents at the time of the signature.
- It must be verifiable by third parties, to resolve disputes.

# 3.What requirements should a digital signature scheme satisfy?
- The signature must be a bit pattern that depends on the message being signed.
- The signature must use some information only known to the sender to prevent both forgery and denial.
- It must be relatively easy to produce the digital signature.
- It must be relatively easy to recognize and verify the digital signature.
- It must be computationally infeasible to forge a digital signature, either by constructing a new message 
for an existing digital signature or by construction a fraudulent digital signature for a given message.
- It must be practical to retain a copy of the digital signature in storage.

# 4.What is the difference between direct and arbitrate digital signature?
The term direct digital signature refers to a digital signature scheme that involves only the communicating
parties (source, destination).

# 5.In what order should the signature function and the confidentiality function be applied to a message, and why?
It is important to perform the signature function first and then an outer confidentiality function.
In case of dispute, some third party must view the message and its signature. If the signature is calculated on an 
encrypted message, then the third party also needs access to the decryption key to read the original message.

# 6.What are some threats associated with a direct digital signature scheme?
- The sender can deny sending a particular message, by claiming that the private key was lost or stolen 
and that someone else forged his or her signature.
- A private key might actually be stolen from X at time T.The opponent can then send a message signed with
X's signature and stamped with a time before or equal to T.
