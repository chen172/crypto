# 1. Why does IPSec need a security association?
Because IPSec requires a logical relationship between two hosts. The security association changes the connectionless service provided by IP to a connection-oriented service upon which we can apply security.

# 3. What are the two protocols defined by IPSec?
1. AH: Authentication Header protocol.
2. ESP: Encapsulating Security Payload.

# 5. What does ESP add to the IP packet?
ESP adds a header and trailer. ESP's authentication data are added at the end of the packet.
The fields for the header and trailer are as follows:

**Security Paramter Index**

**Sequence Number**

**Padding**

**Pad Length**

**Next Header**

**Authentication Data**

# 7. What are the two protocols discussed in this chapter that provided security at the transport layer?
1. SSL: Secure Sockets Layer protocol.
2. TSL: Transport Layer Security protocol.

# 9. What is the difference between a session and a connection in SSL?
A session is an association between a client and a server. For two entities to exchange data, the establishment of a session is necessary, but not sufficient, they need to create a connection between themselves. A session can consist of many connections. A connection between two parties can be terminated and reestablished within the same session.

# 11. What are the names of the protocols, that provide security for e-mail?
1. PGP: Pretty Good Privacy.
2. S/MIME: Secure/Multipurpose Internet Mail Extension.

# 13. What is the purpose of the Handshake Protocol in SSL?
The **Handshake Protocol** uses messages to negotitate the cipher suite, to authenticate the server to the client and the client to the server if needed, and exchange information for building the cryptograpic secret.

# 15. What is the purpose of a firewall?
Prevent Eve from sending a harmful message to a system. It is designed to forward some packet and filter others.

# 17. What is a VPN and why is it needed?
1. VPN is a network that is private but virtual. It is private because it guarantees privacy inside the organization. It is virtual because it does not use real private WANs, the network is physically public but virtually private.
2. For large organizations that use the global Internet for both intra- and interorganization communication, but require privacy in their intraorganization commmunication.
