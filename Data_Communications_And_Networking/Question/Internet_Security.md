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
 
