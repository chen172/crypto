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
