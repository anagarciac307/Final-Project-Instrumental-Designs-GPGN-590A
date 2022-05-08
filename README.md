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
    - Utilized python to find compare fourier transforms and spectrograms of shake table and accelerometer   
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

#### Baseline Data
<details><summary>Graphs</summary>
    <p align="middle">
        <img src="/../main/baseline/x_baseline_Input_time_history.bmp"width="32%" />
        <img src="/../main/baseline/y_baseline_time.bmp"width="32%" />
        <img src="/../main/baseline/z_baseline_time.bmp"width="32%" />
    </p>
    <p align="middle">
        <img src="/../main/baseline/x_baseline_waterfall.bmp"width="32%" />
        <img src="/../main/baseline/y_baseline_waterfall.bmp"width="32%" />
        <img src="/../main/baseline/z_baseline_waterfall.bmp"width="32%" />
    </p>
    <p align="middle">
        <img src="/../main/baseline/x_base_spectro.bmp"width="32%" />
        <img src="/../main/baseline/y_base_spectro.bmp"width="32%" />
        <img src="/../main/baseline/z_base_spectro.bmp"width="32%" />
    </p>
    </details>
    
We then changed the sensitivity and sampling rates of both accelerometers and cycled through several different validation tests:

### Test 1
-  Accelerometer: 2g sensitivity, 1hz sampling rate
-  Shake Table: 1hz vibration, 1mm amplitude

   - #### Accelerometer no ADC:
    <details><summary>Graphs</summary>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Agraphs/x_2_time.png" width="32%" />
            <img src="/../main/images/test_graphs/Agraphs/y_2_time.png" width="32%" />
            <img src="/../main/images/test_graphs/Agraphs/z_2_time.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Agraphs/x_2_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/Agraphs/y_2_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/Agraphs/z_2_waterfall.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Agraphs/x_2_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/Agraphs/y_2_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/Agraphs/z_2_spectro.png" width="32%" />
            </p>
        </details>
    
    
   - #### Accelerometer with ADC:
    <details><summary>Graphs</summary>      
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_2_time.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_2_time.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_2_time.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_2_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_2_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_2_waterfall.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_2_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_2_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_2_spectro.png" width="32%" />
            </p>
        </details>
    
   - #### Shake Table Data
    <details><summary>Graphs</summary>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_2_time.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_2_time.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_2_time.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_2_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_2_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_2_waterfall.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_2_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_2_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_2_spectro.png" width="32%" />
            </p>
        </details>
    
    
    
### Test 2
- Accelerometer: 4g sensitivity, 1hz sampling rate
- Shake Table: 1hz vibration, 1mm amplitude

   - #### Accelerometer with ADC:
    <details><summary>Graphs</summary>      
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_3_time.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_3_time.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_3_time.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_3_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_3_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_3_waterfall.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_3_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_3_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_3_spectro.png" width="32%" />
            </p>
        </details>
    
   - #### Shake Table Data
    <details><summary>Graphs</summary>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_3_time.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_3_time.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_3_time.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_3_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_3_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_3_waterfall.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_3_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_3_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_3_spectro.png" width="32%" />
            </p>
        </details>
    
    
    
### Test 3
- Accelerometer: 4g sensitivity, 1hz sampling rate
- Shake Table: 10hz vibration, 1mm amplitude

   - #### Accelerometer with ADC:
    <details><summary>Graphs</summary>      
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_4_time.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_4_time.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_4_time.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_4_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_4_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_4_waterfall.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/Dgraphs/x_4_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/y_4_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/Dgraphs/z_4_spectro.png" width="32%" />
            </p>
        </details>
    
   - #### Shake Table Data
    <details><summary>Graphs</summary>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_4_time.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_4_time.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_4_time.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_4_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_4_waterfall.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_4_waterfall.png" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/images/test_graphs/STgraphs/x_4_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/y_4_spectro.png" width="32%" />
            <img src="/../main/images/test_graphs/STgraphs/z_4_spectro.png" width="32%" />
            </p>
        </details>
    
    
    
### Test 4
- Accelerometer: 4g sensitivity, 10hz sampling rate
- Shake Table: 10hz vibration, 1mm amplitude

   - #### Accelerometer no ADC
    <details><summary>Graphs</summary>
        <p align="middle">   
            <img src="/../main/Accelerometer (no adc)/4g/x_4g_time.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/4g/y_4g_time.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/4g/z_4g_time.bmp" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/Accelerometer (no adc)/4g/x_4g_waterfall.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/4g/y_4g_waterfall.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/4g/z_4g_waterfall.bmp" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/Accelerometer (no adc)/4g/x_4g_spectro.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/4g/y_4g_spectro.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/4g/z_4g_spectro.bmp" width="32%" />
            </p>
    </details>
 

    - #### Accelerometer with ADC:
    <details><summary>Graphs</summary>
       <p align="middle">
            <img src="/../main/Accelerometer (with adc)/4g_D/x_4g_10hz_time.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/4g_D/y_4g_10hz_time.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/4g_D/z_4g_10hz_time.bmp" width="32%" />
       <p align="middle">
            <img src="/../main/Accelerometer (with adc)/4g_D/x_4g_10hz_waterfall.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/4g_D/y_4g_10hz_waterfall.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/4g_D/z_4g_10hz_waterfall.bmp" width="32%" />
            </p>
       <p align="middle">
            <img src="/../main/Accelerometer (with adc)/4g_D/x_4g_10hz_spectro.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/4g_D/y_4g_10hz_spectro.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/4g_D/z_4g_10hz_spectro.bmp" width="32%" />
            </p>
        </details>
    
   - #### Shake Table Data
    <details><summary>Graphs</summary>
        <p align="middle">
            <img src="/../main/Shake Table/x_time_4g.bmp"width="32%" />
            <img src="/../main/Shake Table/y_time_4g.bmp"width="32%" />
            <img src="/../main/Shake Table/z_time_4g.bmp"width="32%" />
        </p>
        <p align="middle">
            <img src="/../main/Shake Table/x_waterfall_4g.bmp"width="32%" />
            <img src="/../main/Shake Table/y_waterfall_4g.bmp"width="32%" />
            <img src="/../main/Shake Table/z_waterfall_4g.bmp"width="32%" />
        </p>
        <p align="middle">
            <img src="/../main/Shake Table/x_spectro_4g.bmp"width="32%" />
            <img src="/../main/Shake Table/y_spectro_4g.bmp"width="32%" />
            <img src="/../main/Shake Table/z_spectro_4g.bmp"width="32%" />
        </p>
        </details>



### Test 5
- Accelerometer: 8g sensitivity, 10hz sampling rate
- Shake Table: 10hz vibration, 1mm amplitude

   - #### Accelerometer no ADC
    <details><summary>Graphs</summary>
        <p align="middle">   
            <img src="/../main/Accelerometer (no adc)/8g/x_8g_time.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/8g/y_8g_time.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/8g/z_8g_time.bmp" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/Accelerometer (no adc)/8g/x_8g_waterfall.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/8g/y_8g_waterfall.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/8g/z_8g_waterfall.bmp" width="32%" />
            </p>
        <p align="middle">   
            <img src="/../main/Accelerometer (no adc)/8g/x_8g_spectro.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/8g/y_8g_spectro.bmp" width="32%" />
            <img src="/../main/Accelerometer (no adc)/8g/z_8g_spectro.bmp" width="32%" />
        </p>
    </details>


   - #### Accelerometer with ADC:
    <details><summary>Graphs</summary>
       <p align="middle">
            <img src="/../main/Accelerometer (with adc)/8g_D/x_8g_10z_time.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/8g_D/y_8g_10hz_time.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/8g_D/z_8g_10hz_time.bmp" width="32%" />
       <p align="middle">
            <img src="/../main/Accelerometer (with adc)/8g_D/x_8g_10hz_waterfall.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/8g_D/y_8g_10hz_waterfall.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/8g_D/z_8g_10hz_waterfall.bmp" width="32%" />
            </p>
       <p align="middle">
            <img src="/../main/Accelerometer (with adc)/8g_D/x_8g_10hz_spectro.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/8g_D/y_8g_10hz_spectro.bmp" width="32%" />
            <img src="/../main/Accelerometer (with adc)/8g_D/z_8g_10hz_spectro.bmp" width="32%" />
            </p>
        </details>
    
   - #### Shake Table Data
    <details><summary>Graphs</summary>
        <p align="middle">
            <img src="/../main/Shake Table/x_time_8g.bmp"width="32%" />
            <img src="/../main/Shake Table/y_time_8g.bmp"width="32%" />
            <img src="/../main/Shake Table/z_time_8g.bmp"width="32%" />
        </p>
        <p align="middle">
            <img src="/../main/Shake Table/x_waterfall_8g.bmp"width="32%" />
            <img src="/../main/Shake Table/y_waterfall_8g.bmp"width="32%" />
            <img src="/../main/Shake Table/z_waterfall_8g.bmp"width="32%" />
        </p>
        <p align="middle">
            <img src="/../main/Shake Table/x_spectro_8g.bmp"width="32%" />
            <img src="/../main/Shake Table/y_spectro_8g.bmp"width="32%" />
            <img src="/../main/Shake Table/z_spectro_8g.bmp"width="32%" />
        </p>
        </details>
    
    
    

https://user-images.githubusercontent.com/44856601/167182180-25f0c089-e98c-4e4a-8d9a-762d265ea3ed.mov



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


## Codes:
For this project C++ was used to communicate with the Arduino. The code is saved as a .ion file. Various libraries are leveraged to communicate with the different components including accelerometer, A/D converter, and touchscreen (remote station):

- Adafruit_LIS3DH.h

- Adafruit_ADS1X15.h

- TouchScreen.h

I2C was used as the communication protocol using, scl and sda ports to communicate with the LIS3DH  to ADS115, and ADS115 with Arduino Uno. The Adafruit_LIS3DH.h library includes functions that allow to adjust frequency, level of accuracy using g's, and transform raw data to m/$s^2$ by normalizing data. Data can be read into an SD file, printed to the serial monitor, or displayed on a touchscreen using.

Real-time data can be displayed on the touchscreen using tft functions for the remote station code/remote_station.ino. The main station uses an API interface for python and Arduino using the corresponding COM port. As data is read into a jupyter notebook it is decoded and split into arrays code/Accelerometer_datafile.ipynb.

For a better interpretation of the results, data was analyzed in the frequency domain by taking the Fourier transform of the time series data code/Graphs_ShakeTable_Accelerometer_.ipynb. 



## Future directions:
This project can be further developed to include a second accelerometer wired together by using a different I2C address or increment the number of a wireless station that delivers data to a webpage in real-time using XBee or internet shields. Furthermore, refining data collection and processing is still needed. Our validation tests used clamps to couple the accelerometer to the shake table, however, using the 3D printed box could yield better results. A step further to reduce noise from poor coupling would be to use a flexible printed circuit with 3 micro-electrical mechanical systems (MEMS) and fit the exact geometry of the pipeline or structure to monitor. While the Arduino has antialiasing filtering, further refinement is needed. Lastly, quasi-real-time spectrograms could be a nice feature to add and make this device more comparable to how the Terra15 interface displays data.



## References:
[1] Mateeva, A. et al. Distributed Acoustic Sensing for reservoir monitoring with vertical seismic profiling. Geophysical Prospecting 62, 679–692 (2014). 
