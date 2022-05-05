# Final-Project-Instrumental-Designs-GPGN-590A

## Project Description/Overview: 
To develop an accelerometer array to measure various flow rates in piping in Edgar mine. Can also be used in applications that measure seismic activity.

## Approach: 
We will begin by implementing an analog design and hopefully convert to a wireless array. We will first test and validate an accelerometer station with an externally wired analog-to-digital converter (ADC) that has a higher bit-rate than the on board ADC on both Arduino UNO/Mega 2560. We will then develop a remote station that can function without being connected to the "main" station. The remote station will include an SD card reader and LCD screen for real-time data viewing and capability for post-processing spectrogram/fourier transfroms.

## Critical need addressed: 
To observe the various flow rates of different fluids passing through piping in the mine. Using accelerometers the vibrations produced by acoustic vibration of the different fluids and flow can be monitored. This will allow us to determine if a pipe burst or if there's a leak somewhere in the system. 

## Geoscience Application: 
Distributed Acoustic Sensing (DAS) is a rapidly maturing fiber-optic technology with numerous applications in geophysical and in-well monitoring. DAS transforms nearly any fiber-optic cable into a distributed array of acoustic sensors. DAS is being considered as a permanent borehole seismic sensor array for Zero-Offset Walk-Away, and 3D VSPs, refraction seismic, cross-well seismic, downhole microseismic monitoring, and as a permanent surface seismic surveillance system [1]. Pipelines transport different fluids for the production of hydrocarbons and essential infrastructure uses. Using IoT to monitor the fluids within can yield critical information to potential blockages or increased turbulence that can risk the integrity of pipelines with grave environmental consequences. Monitoring systems like the one proposed here can help prevent or alert potential dangers through the characterization of fluid flow rates within a pipe.

## Benefit: 
Helps identify fluid properties and can inform on possible changes in densities and flow rates within a pipeline system

## Cost: 
$100-200

## Implementation plan:
- [ ] Obtain accelerometers and other required sensors
- [ ] Connect the smart board, ADC and LCD screen to a breadboard
- [ ] Set up the receiver with a single accelerometer attached
- [ ] Add the necessary libraries to run the accelerometer, ADC and LCD 
- [ ] Define axis on accelerometer and build code to run the receiver and transmitter
- [ ] Perform a simple test to verify that the accelerometer is transmitting data
- [ ] Test precision with Shake Table 
- [ ] Include code to  processes signal
- [ ] Observe the data on the serial monitor and see if it matches what is displayed on the LCD 
- [ ] Expand the array to include 2 accelerometers connected 

## Possible additional elements: 
- [ ] External SD storage for extended recording
- [ ] Develop wireless capability by utilizing either RF/wireless receiver and  MMS – 10-Axis IMU
- [ ] Expand array to multiple in-line transmitters that communicate with the single receiver
- [ ] Develop array to have in-line transmitters with connected transmitters that transfer data from other and relay to the main receiver
- [ ] Expanded LCD capability to larger screens that can show multiple lines of data at once

Hardware Wiring Diagram:

Various existing designs are available online for accelerometers with different types of accelerometers. In this project, each of the different proposed accelerometers will be wired to communicate with analog-to-digital converter and send data to Arduino, as depicted above. As data is recorded it will be displayed on the LCD screen.

## Materials list:
- LIS3DH accelerometer (2) - $ 4.99/ea
- LCD screen – $ 34.99​
- Arduino UNO - $ 24.99
- Arduino Mega 2560 - $ 39.99
- ADS1115(2) - $ 4.99/ea
- Arduino W5100 ethernet shield - $ 20.99

## References
[1] Mateeva, A. et al. Distributed Acoustic Sensing for reservoir monitoring with vertical seismic profiling. Geophysical Prospecting 62, 679–692 (2014). 
