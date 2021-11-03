# 1. Given the frequencies listed below, calculate the corresponding periods.
a. 24 Hz
b. 8 MHz
c. 140 KHz

a. 1/24
b. 1/(8 * 10^6)
c. 1/(140 * 10^3)

# 2. Given the following periods, calculate the corresponding frequencies.
a. 5 s
b. 12 us
c. 220 ns

a. 1/5
b. 1/(12 * 10^6)
c. 1/(220 * 10^8)

# 3. What is the phase shift for the following?
a. A sine wave with the maximum amplitude at time zero
b. A sine wave with the maximum amplitude after 1/4 cycle
c. A sine wave with zero amplitude after 3/4 cycle and increasing

a. 0
b. 1/4 * pi
c. 3/4 * pi

# 4. What is the bandwidth of a signal that can be decomposed into five sine waves with frequencies at 0, 20, 50, 100, and 200 Hz? All peak amplitudes are the same. Draw the bandwidth.
200 Hz.

# 5. A periodic composite signal with a bandwidth of 2000 Hz is composed of two sine waves. The first one has a frequency of 100 Hz with a maximum amplitude of 20V; the second one has a maximum amplitude of 5V.Draw the bandwith.

# 6. Which signal has a wider bandwith, a sine wave with a frequency of 100 Hz or a sine wave with a frequency of 200 Hz?

# 7. What is the bit rate for each of the following signals?
a. A signal in which 1 bit lasts 0.001s
b. A signal in which 1 bit lasts 2ms
c. A signal in which 1 bit lasts 20us

a. 1000 bps
b. 500 bps
c. 50000 bps

# 8. A device is sending out data at the rate of 1000 bps
a. How long does it take to send out 10 bits?
b. How long does it take to send out a signal character (8 bits)?
c. How long does it take to send a file of 100,000 characters?

a. 0.01 s
b. 8 / 1000 s
c. 800 s

# 12. A periodic composite signal contains frequencies from 10 to 30 KHz, each with an amplitude of 10 V. Draw the frequency spectrum.

# 14. A TV channel 

# 15. A signal travels from point A to point B. At point A, the signal power is 100 W. At point B, the power is 90 W. What is the attenuation in decibels?
10 * log10(9/10)

# 16. The attenuation of a signal is -10dB. What is the final signal power if it was originally 5 W?
0.5 W.

# 17. A signal has passed through three cascaded amplifiers, each with a 4dB gain. What is the total gain? How much is the signal amplified?
12dB gain. 10^(1.2)

# 18. In the bandwidth of the channel is 5 Kbps, how long does it take to send a frame of 100,000 bits out of this devices?
20 s.

# 19. The light of the sun take approximately eight minutes to reach the earth. What is the distance between the sun and the earth?
3 * 10^8 * 8 * 60 = 1.44 * 10^11 m

# 20. A signal has a wavelength of 1 um in air. How far can the front of the wave travel during 1000 periods?
1 mm

# 21. A line has a signal-to-noise ratio of 1000 and a bandwidth of 4000 KHz. What is the maximum data rate supported by this line?
4000000 * log2(1001) = 40Mbps

# 22. We measure the performance of a telephone line (4 KHz of bandwidth). When the signal is 10 V, the noise is 5 mV. What is the maximum data rate supported by this telephone line?
SNR = 100 / 5 = 20, 4 * log2(20+1) = 16 Kbps.

# 23. A file contains 2 million bytes. How long does it take to download this file using a 56-Kbps channel? 1-Mbps channel?
2000000 * 8 / 56000, 16s

# 24. A computer monitor has a resolution of 1200 by 1000 pixels. If each pixel uses 1024 colors, how many bits are needed to send the complete contents of a screen?
1200 * 1000 * 10 = 1.2 * 10^7 bit

# 25. A signal with 200 milliwatts power passes through 10 devices, each with an average noise of 2 microwatts. What is the SNR? What is the SNRdB?
200 * 10^3 / 2 / 10 = 10000, 10 * 4 = 40dB.

# 26. If the peak voltage value of a signal is 20 times the peak voltage value of the noise, what is the SNR? What is the SNRdB?
SNR = 20, SNRdB = 10 * log10(20)

# 27. What is the theoretical capacity of a channel in each of the following cases?
a. Bandwidth: 20 KHz SNRdB = 40
b. Bandwidth: 200 KHz SNRdB = 4
c. Bandwidth: 1 MHz SNRdB = 20

a. SNR = 1000, C = 20 * log2(1001) = 200 kbps
b. SNR = 10^(0.4), C = 200 * log2(10^(0.4)+1) = 400 kbps
c. SNR = 100, C = 1 * log2(101) = 7 Mbps

# 28. We need to upgrade a channel to a higher bandwidth. Answer the following questions:
a. How is the rate improved if we double the bandwidth?
b. How is the rate improved if we double the SNR?

a. the rate is doubled
b. the rate is log2(2SNR+1) / log2(SNR+1)

# 29. We have a channel with 4 KHz bandwidth. If we want to send data at 100 Kbps, what is the minimum SNRdB? What is the SNR?
SNR = 2^25 - 1, SNRdB = 10 * log10(SNR)

# 30. What is the transmission time of a packet sent by a station if the length of the packet is 1 million bytes and the bandwidth of the channel is 200 Kbps?
1000000 * 8 / 200000 = 40s

# 31. What is the length of a bit in a channel with a propagation speed of 2 * 10^8 m/s if the channel bandwidth is
a. 1Mbps: 200m
b. 10Mbps: 20m
c. 100Mbps: 2m

# 32. How many bits can fit on a link with a 2 ms delay if the bandwidth of the link is 
a. 1Mbps: 2000 bit
b. 10Mbps: 20000 bit
c. 100Mbps: 200000 bit

# 33. What is the total delay (latency) for a frame of size 5 million bits that is being sent on a link with 10 routers each having a queuing time of 2us and a processing time of 1us. The length of the link is 2000 Km. The speed of light inside the link is 2 * 10^8 m/s. The link has a bandwidth of 5 Mbps. Which compoent of the total delay is dominant?Which one is negligible?
Total delay is 1.01s. Transmission time is dominant, is 1s. propagation time, 10ms. processing time and queuing time. 
