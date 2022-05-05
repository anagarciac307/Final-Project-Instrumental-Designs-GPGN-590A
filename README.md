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
- [X] Obtain accelerometers and other required sensors
- [X] Connect the smart board, ADC and LCD screen to a breadboard
- [X] Set up the receiver/main station with a single accelerometer attached
- [X] Add the necessary libraries to run the accelerometer, ADC and LCD 
- [X] Define axis on accelerometer and build code to run the receiver and transmitter
- [X] Perform a simple test to verify that the accelerometer is transmitting data
- [X] Test precision with Shake Table 
- [X] Include code to  processes signal
    - Utilized third-party software to process transforms and spectrograms   
- [X] Observe the data on the serial monitor and see if it matches what is displayed on the LCD 
- [ ] Expand the array to include 2 accelerometers connected 

## Possible additional elements: 
- [X] External SD storage for extended recording
- [X] Set-up secondary station to record data independently from main station
- [ ] Develop wireless capability by utilizing either RF/wireless receiver and  MMS – 10-Axis IMU
- [ ] Expand array to multiple in-line transmitters that communicate with the single receiver
- [ ] Develop array to have in-line transmitters with connected transmitters that transfer data from other and relay to the main receiver
- [X] Expanded LCD capability to larger screens that can show multiple lines of data at once

## Validation/Data collection:
We validated our accelerometer and station set-ups (with/without external ADC attached) on a shake table. For the validation tests, we evaluated both stations at variable frequencies and sensitivities. We began by obtaining a baseline measurement where our accelerometer was on a flat, unmoving surface to observe the accelerometers behavior and variability. Our settings for our accelerometer were set to 4g sensitivity with a 10hz sampling rate. Our shake table had a limited vibrational frequency ranging from 1-10hz so we could fully test the capabilities of the accelerometers we had. We wound up sticking with the 4g and 8g data at 10hz as they proved to be a good sensistivity for testing on the shake table. We noticed some irregularities and aliasing when utilizing 2g sensitivity and variable sampling rates between sensor and shake table. Each of our tests include an amplitude through time, spectrogram and FFT graph.

### Baseline
![baseline](/../main/baseline/baseline_1.png)

We then changed the sensitivity and sampling rates of both accelerometers and cycled through several different validation tests:

### Test 1
-  Accelerometer: 2g sensitivity, 1hz sampling rate
-  Shake Table: 1hz vibration, 1mm amplitude


### Test 2
- Accelerometer: 4g sensitivity, 1hz sampling rate
- Shake Table: 1hz vibration, 1mm amplitude

### Test 3
- Accelerometer: 4g sensitivity, 1hz sampling rate
- Shake Table: 10hz vibration, 1mm amplitude

<details><summary>Graphs</summary>
    
Accelerometer with no ADC:
    <p>x-axis <img src="/../main/Accelerometer (no adc)/8g/x_8g_spectro.bmp" alt="pic" title="title" /></p>
    <p>y-axis <img src="/../main/Accelerometer (no adc)/8g/y_8g_spectro.bmp" alt="pic" title="title" /></p>
    <p>z-axis <img src="/../main/Accelerometer (no adc)/8g/z_8g_spectro.bmp" alt="pic" title="title" /></p>
    
  
Accelerometer with ADC:
    <p>x-axis <img src="/../main/Accelerometer (with adc)/8g_D/x_8g_10hz_spectro.bmp" alt="pic" title="title" /></p>
    <p>y-axis <img src="/../main/Accelerometer (with adc)/8g_D/y_8g_10hz_spectro.bmp" alt="pic" title="title" /></p>
    <p>z-axis <img src="/../main/Accelerometer (with adc)/8g_D/z_8g_10hz_spectro.bmp" alt="pic" title="title" /></p>

</details>

### Test 4
- Accelerometer: 4g sensitivity, 10hz sampling rate
- Shake Table: 10hz vibration, 1mm amplitude

<details><summary>Graphs</summary>
    
Accelerometer with no ADC:
    <p>x-axis <img src="/../main/Accelerometer (no adc)/4g/x_4g_spectro.bmp" alt="pic" title="title" /></p>
    <p>y-axis <img src="/../main/Accelerometer (no adc)/4g/y_4g_spectro.bmp" alt="pic" title="title" /></p>
    <p>z-axis <img src="/../main/Accelerometer (no adc)/4g/z_4g_spectro.bmp" alt="pic" title="title" /></p>
    
  
Accelerometer with ADC:
    <p>x-axis <img src="/../main/Accelerometer (with adc)/4g_D/x_4g_10hz_spectro.bmp" alt="pic" title="title" /></p>
    <p>y-axis <img src="/../main/Accelerometer (with adc)/4g_D/y_4g_10hz_spectro.bmp" alt="pic" title="title" /></p>
    <p>z-axis <img src="/../main/Accelerometer (with adc)/4g_D/z_4g_10hz_spectro.bmp" alt="pic" title="title" /></p>

</details>

### Test 5
- Accelerometer: 8g sensitivity, 10hz sampling rate
- Shake Table: 10hz vibration, 1mm amplitude
    <p align="middle">
        <img src="/../main/Accelerometer (with adc)/8g_D/x_8g_10hz_spectro.bmp" width="32%" />
        <img src="/../main/Accelerometer (with adc)/8g_D/x_8g_10hz_spectro.bmp" width="32%" />
        <img src="/../main/Accelerometer (with adc)/8g_D/x_8g_10hz_spectro.bmp" width="32%" />
    </p>
    
<details><summary>Graphs</summary>
    
Accelerometer with no ADC:
    <p>x-axis <img src="/../main/Accelerometer (no adc)/8g/x_8g_spectro.bmp" alt="pic" title="title" /></p>
    <p>y-axis <img src="/../main/Accelerometer (no adc)/8g/y_8g_spectro.bmp" alt="pic" title="title" /></p>
    <p>z-axis <img src="/../main/Accelerometer (no adc)/8g/z_8g_spectro.bmp" alt="pic" title="title" /></p>
    
  
Accelerometer with ADC:
    <p>x-axis <img src="/../main/Accelerometer (with adc)/8g_D/x_8g_10hz_spectro.bmp" alt="pic" title="title" /></p>
    <p>y-axis <img src="/../main/Accelerometer (with adc)/8g_D/y_8g_10hz_spectro.bmp" alt="pic" title="title" /></p>
    <p>z-axis <img src="/../main/Accelerometer (with adc)/8g_D/z_8g_10hz_spectro.bmp" alt="pic" title="title" /></p>
    
    
</details>

## Hardware Wiring Diagram:
Various existing designs are available online for accelerometers with different types of accelerometers. In this project, each of the different proposed accelerometers will be wired to communicate with analog-to-digital converter and send data to Arduino, as depicted above. As data is recorded it will be displayed on the LCD screen.

![Main station](/../main/images/main.png)
Main data station
![remote station](/../main/images/remote.png)
Remote data station

## Materials list:
- LIS3DH accelerometer (2) - $ 4.99/ea
![accel](/../main/images/lis.jpeg) 
- LCD screen – $ 34.99​
![LCD](/../main/images/TFTLCD.jpg)
- Arduino UNO - $ 24.99
![UNO](/../main/images/UNO.jpeg)
- Arduino Mega 2560 - $ 39.99
![Mega](/../main/images/Mega.jpg)
- ADS1115(2) - $ 4.99/ea
![ADS](/../main/images/adc.jpg)
- Arduino W5100 ethernet shield - $ 20.99
![w5100](/../main/images/w5100.jpg)
- 32 GB microSD card - $ 9.99
![SD](/../main/images/SD.jpg)

## References:
[1] Mateeva, A. et al. Distributed Acoustic Sensing for reservoir monitoring with vertical seismic profiling. Geophysical Prospecting 62, 679–692 (2014). 
