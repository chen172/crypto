# 1. Answer the following questions about Figure 2.2 when the communication is from Maria to Ann:
a. What is the service provided by layer 1 to layer 2 at Maria's site?
b. What is the service provided by layer 1 to layer 2 at Ann's site?

a. layer 2 encrypt plaintext to ciphertext. layer 1 send mail.
b. layer 1 receive mail. layer 2 decrypt ciphertext.

# 2. Answer the following questions about Figure 2.2 when the communication if from Maria to Ann:
a. What is the service provided by layer 2 to layer 3 at Maris's site?
b. What is the service provided by layer 2 to layer 3 at Ann's site?

# 3. Assume that the number of hosts connected to the Internet at year 2010 is five hundred million. If the number of hosts increases only 20 percent per year. What is the number of hosts in 2020?
(5*10^8)*(1.2)^10

# 4. Assume a system uses five protocol layers. If the application program creates a message of 100 bytes and each layer (including the fifth and the first) adds a header of 10 bytes to the data unit, what is the efficiency (the ratio of appliction layer bytes to the number of bytes transmitted) of the system?
100/150 = 2/3

# 5. Assume we have created a packet-switched internet. Using the TCP/IP protocol suite, we need to transfer a huge file. What are the advantage and disadvantage of sending large packets?
Advantage: Can use full capicity of the link.
Disadvantage: packets too large.

# 6. Match the following to one or more layers of the TCP/IP protocol suite:
a. route determination
b. connection to transmission media
c. providing services for the end user

a. network layer
b. data-link layer and physical layer
c. application layer

# 7. Match the following to one or more layers of the TCP/IP protocol suite:
a. creating user datagram
b. responsibility for handling frames between adjacent nodes
c. transforming bits to electronmagnetic signals

a. transport layer
b. data-link layer
c. physical layer

# 8. In figure 2.10, when the IP protocol decapsulates the transport-layer packet, how does it know to which uppper-layer protocol (UDP or TCP) the packet should be delivered?
It has a filed contains the protocol.

# 9. Assume a private internet uses three different protocols at the data-link layer (L1, L2, L3). Redraw Figure 2.10 with this assumption. Can we say that, in the data-link layer, we have demultiplexing at the source node and multiplexing at the destination node?


# 10. Assume that a private internet requires that the messages at the application layer be encrypted and decrypted for security purposes. If we need to add some information about the encryption/decryption process (such as the algorithms used in the process), does it mean that we are adding one layer to the TCP/IP protocol suite? Redraw the TCP/IP layers (Figure 2.4 part b) if you think so.
No.

# 11. Protocol layering can be found in many aspects of our lives such as air traveling. Imageine you make a round-trip to spend some time on vacation at a resort. You need to go through some processes at your city airport before flying. You also need to go through some processes when you arrive at the resort airport. Show the protocol layering for the round trip using some layers such as baggage checking/claiming, boarding/unboarding, takeoff/landing.

# 12. The presentation of data is becoming more and more important in today's Internet. Some people argue that the TCP/IP protocol suite needs to add a new layer to take care of the presentation of data. If this new layer is added in the future, where should its position be in the suite?
Between the transport layer and the application layer.

# 13. In an internet, we change the LAN technology to a new one. Which layers in the TCP/IP protocol suite need to be changed?
data-link layer and physcical layer.

# 14. Assume that an application-layer protocol is written to use the services of UDP. Can the application-layer protocol uses the services of TCP without change?
No.

# 15. Using the internet in Figure 1.11 in the text, show the layers of the TCP/IP protocol suite and the flow of data when two hosts, one on the west coast and the other on the east coast, exchange message.

