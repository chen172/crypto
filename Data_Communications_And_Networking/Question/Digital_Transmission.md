# 1. List three techniques of digital-to-digital conversion.
line coding, block coding, scrambling.

# 2. Distinguish between a signal element and a data element.
In digital data communications, a signal element carries data elements.

# 3. Distinguish between data rate and signal rate.
1. The **data rate** defines the number of data elements sent in 1s.
2. The **signal rate** is the number of signal elements sent in 1s.

# 4. Define baseline wandering and its  effect on digital transmission.
A long string of 0s and 1s can cause a drift in the baseline (**baseline wandering**) and make it difficult for the receiver to decode correctly.

# 5. Define a DC component and its effect on digital transmission.
These frequencies around zero, called DC (direct-current) components, present problems for a system that cannot pass low frequencies or a system that uses electrical coupling.

# 6. Define the characteristics of a self-synchronizing signal.
A **self-synchronizing** digtial signal includes timing information in the data being transmitted.

# 7. List five line coding schemes discussed in this book.
Unipolar, Polar, Bipolar, Multilevel, Multitransition.

# 8. Define block coding and give its purpose.
1. In general, **block coding** changes a block of m bits into a block of n bits, where n is larger than m. 
2. We need redundancy to ensure synchronization and to provide some kind of inherent error detecting. Block coding can give us this redundancy and improve the performance of line coding.

# 9. Define scrambling and give its purpose.
1. We modify part of the AMI rule to include scrambling.
2. A technique that does not increase the number of bits and does provide synchronization. A solution that substitutes long zero-level pulses with a combination of other levels to provide synchronization.

# 10. Compare and contrast PCM and DM.
1. PCM is a very complex technique. DM was developed to reduced  the complexity of PCM.
2. PCM finds the value of signal amplitude for each sample. DM finds the change from previous sample.

# 11. What are the difference between parallel and serial transmission?
1. parallel: we can send n bits at a time.
2. serial: one bit follows another.

# 12. List three different techniques in serial transmission and explain the difference.
1. Asynchronous: we send 1 start bit (0) at the beginning and 1 or more stop bits (1s) at the end of each byte.
2. Synchronous: we send bits one after another without start or stop bits or gaps. 
3. Isochronous: The isochronous transmission guarantees that the data arrive at a fixed rate.

