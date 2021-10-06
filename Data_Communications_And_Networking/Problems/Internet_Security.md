# 1. Host A and Host B use IPSec in the transport mode. Can we say that the two hosts need to create a virtual connection-oriented service between them? Explain.
Yes, the two hosts need to create a virtual connection-oriented service between them. Two parties need to first create cryptographic secrets between themselves before exchanging secure data. 

# 3. If Alice and Bob arre continuously sending messages to each other, can they create a security association once and use it for every packet exchanged? Explain.
Although it is possible to create a SA permanently, it is strongly discouraged because of the leak of security parameters.

# 5. Why there no need for a Security Association with SSL?
Beacause SSL is over TCP and SSL has handshake protocol. TCP provide connection and handshake protocol provide security parameter exchange.

# 7. Should the handshaking in SSL occur before or after the three-way handshaking in TCP?Can they be combined? Explain.
After, they can't be combined. Handshaking in SSL provide security parameters exchange. The three-way handshaking in TCP established connection in two parties.

# 9. Assume Alice needs to send an e-mail to Bob. Explain how the integrity of the e-mail is achieved using PGP.
Alice creates a digest of the message and signs it with her private key.

# 11. Assume Alice needs to send an e-mail to Bob. Explain how the integrity of the e-mail is achieved using S/MIME.
1. A message digest is calculated from the content.
2. The message digest, the algorithm, and the content are added together to create the **digestedData** object.

# 13. Assume Alice needs to send an e-mail to Bob. Expain how the confidentiality of e-mail is achieved using S/MIME.
1. A pseudorandom session key is created for the symmetric-key algorithms to be used .
2. For each recipient, a copy of the session key is encrypted with the public key of that recipient.
3. The content is encrypted using the defined algorithm and created session key.
4. The encrypted contents, encrypted session keys, algorithm used, and certificates are encoded using Radix-64.

# 15. When we talk about authentication in PGP (or S/MIME), do we mean message authentication or entity authentication? Exaplin.
Message authentication. PGP (or S/MIME) is one-direction.
