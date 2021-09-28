# 1.List ways in which secret keys can be distributed to two communicating parties.
1. A can select a key and physically deliver it to B.
2. A third party can select the key and physically deliver it to A and B.
3. If A and B have previously and recently used a key, one party can transmit the new key to the other, encrypted using the old key.
4. If A and B each has an encrcypted connection to a third party C, C can deliver a key on the encrypted links to A and B.

# 2. What is the difference between a session key and a master key?
1. A temporary **session key** that will last for the duration of a logical connection, such as a TCP connection.
2. A and B each share a long-lasting **master key** with a third party that is involved in providing the session key.

# 3. What is a key distribution center?
A **key distribution center (KDC)** generates and distributes session keys.
