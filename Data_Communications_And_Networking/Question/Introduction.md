# 1. Identify the five components of a data communications system.
1. Message
2. Sender
3. Receiver
4. Transmission medium
5. Protocol

# 2. What are the three criteria necessary for an effective and efficient network?
1. Performance
2. Reliability
3. Security

# 3. What are the advantages of a multipoint connection over a point-to-point one?
In a multipoint environment, the capacity of the channel is shared, either spatially or temporally.

# 4. What are the two types of line configuration?
point-to-point and multipoint.

# 5. Categorize the four basic topologies in terms of line configuration?
1. Mesh Topology 
2. Star Topology
3. Bus Topology
4. Ring Topology

# 6. What is the difference between half-duplex and full-deplex transmission modes?
1. half-duplex is one direction at a time.
2. full-deplex is both direction at all the time.

Answer for the book:
In **half-duplex mode**, each station can both transmit and receive, but not at the same time.

In **full-deplex mode**, both stations can transmit and receive simultaneously.

# 7. Name the four basic network topologies, and cite an advantages of each type.
1. Mesh topology. A mesh offers several advantages over other network topologies. 
* First, the use of dedicated links guarantees that each connection can carry its own data load, thus eliminating the traffic problems that can occur when links must be shared by multiple devices.
* Second, a mesh topology is robust. If one link becomes unusable, it does not incapacitate the entire system.
* Third, there is the advantage of privacy or security. When every message travels along a dedicated line, only the intended recipient sees it. Physical boundaries prevent other users from gaining access to messages.
* Finally, point-to-point links make fault identification and fault isolation easy. Traffic can be routed to avoid links with suspected problems.

2. Star topology. A star offers several advantages:
* A star topology is less expensive than a mesh topology.
* robustness. If one link fails, only that link is affected.

3. Bus topology. Advantages of a bus topology include ease of installation.

4. Ring topology. A ring is easy to install and reconfigure.

# 8. For n devices in a network, what is the number of cable links required for a mesh, ring, bus, and star topology?
1. mesh, n*(n-1)/2
2. ring, 1
3. bus, 1
4. star, n

# 9. What are some of the factors that determine whether a communication system is a LAN or WAN?
Size, geographical coverage, and ownership.

# 10. What is an internet? What is the Internet?
1. When two or more networks are connected, they make an **internetwork**, or **internet**.
2. The most notable internet is called the **Internet**, and is composed of thousands of interconnected networks.

# 11. Why are protocols needed?
Without a protocol, two devices may be connected but not communicating.

# 12. In a LAN with a link-layer switch, Host 1 wants to sends a message to Host 3. Since communication is through the link-layer switch, does the switch need to have an address? Explain.
The switch need to have an MAC address. Because switch has two layer, physical layer and link layer.

# 13. How many point-to-point WANs are needed to connect n LANs if each LAN should be able to directly communicate with any other LAN?
n*(n-1)/2

# 14. When we use local telephones to talk to a friend, are we using a circuit-switched network or a packet-switched network?
circuit-switched network.

# 15. When a resident uses a dial-up or DLS service to connect to the Internet, what is the role of the telephone company?

# 16. What is the first principle we discussed in this chapter for protocol layering that needs to be followed to make the communication bidirectional?

# 17. Explain the difference between an Internet draft and a proposed standard.
A proposed standard is elevated to draft standard status after at least two successful independent and interoperable implementations.

# 18. Explain the difference between a required RFC and a recommended RFC.
1. An RFC is labeled **required** if it must be implemented by all Internet systems to achieve minimum conformance.
2. An RFC is labeled **recommended** is not required for minimum conformance.

# 19. Explain the difference between the duties of the IETF and IRTF.
1. IETF is responsible for identifying operational problems and proposing solutions to these problems.
2. IRTF focuses on long-term research topics related to Interrnet protocols, applications, architecture, and technology.
