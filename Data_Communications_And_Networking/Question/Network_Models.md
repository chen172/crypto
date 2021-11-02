# 1. What is the first principle we discussed in this chapter for protocol layering that needs to be followed to make the communication bidirectional?
We need to make each layer so that it is able to perform two opposite tasks.

# 2. Which layers of the TCP/IP protocol suite are involoved in a link-layer switch?
physical layer and data-link layer.

# 3. A router connects three links(networlks). How many of each of the following layers can the router be involoved with?
a. physical layer b. data-link layer c. network layer 
3

# 4. In the TCP/IP protocol suite, what are the identical objects at the sender and the receiver sites when we think about the logical connection at the application layer?
message.

# 5. A host communicates with another host using the TCP/IP protocol suite. What in the unit of data sent or received at each of the following layer?
a. application layer: message
b. network layer: datagram
c. data-link layer: frame

# 6. Which of the following data units is encapsulated in a frame?
a datagram

# 7. Which of the following data units is decapsulated from a user datagram?
a datagram

# 8. Which of the following data units has an application-layer message plus the header from layer 4?
a user datagram

# 9. List some applicationn-layer protocols mentioned in this chapter.
HTTP, SMTP, FTP, TELNET, SSH, SNMP, DNS.

# 10. If a port number is 16 bits (2 bytes), what is the minimum header size at the transport layer of the TCP/IP protocol suite?
4 bytes.

# 11. What are the types of addresses (identifies) used in each of the following layers?
a. application layer: name
b. network layer: ip
c. data-link layer: MAC

# 12. When we say that the transport layer multiplexes and demultiplexes applcation layer messages, do we mean that a transport-layer protocol can combine several messages from the application layer in one packet? Explain.
No, a protocol needs tot have a field in its header to identify to which protocol the encapsulated packets belong.

# 13. Can you explain why we did not mention multiplexing/demultiplexing services for the application layer?
It does not provide services to any layer.

# 14. Assume we want to connect two isolated hosts together to let each host communicate with the other. Do we need a link-layer switch between the two?Explain.
No.

# 15. If there is a single path between the source host and the destination host, do we need a router between the two hosts?
No, router is used for choosen path.
