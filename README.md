# IoT-BASED-WATER-LEVEL-MONITORING-SYSTEM-USING-NODEMCU-ESP8266-ESPWEBSERVER-ULTRASONIC-SENSOR



----------


## About This Project
- Water is very precious and needed for many and every day activity.
Conservation of water is similarly, important and has adverse effects
otherwise.
- At the household level, some people turn-on the electric water-pumps and
set off to work or even go to sleep, neglect to turn-off the mains when the
water container is full. This ends in wastage of water and often flood.
- As the technology grows observing the behaviours and the yearning
demands, there is a need for ingenious replacements, for the difficulties
prevailing in the present world. By using IoT based water monitoring
system, we avoid the water wastage, power consumption, can easily prevail
the water for our generation.
- This system monitors the water level of the reservoir and automatically
switches ON/OFF when the tank or container is Partially Empty or Full.
Here the waterline of the water storage tanks is reflected on the website.
- By emphasizing on the mentioned issues, our prototype develops an
economical set-up while monitoring the water level of multiple reservoirs at
different locations in real time, certainly with automatic water level
detection and refilling of water storage system in an IoT environment.


----------

## Getting Started

### Prerequisites

 

 - Software and Hardware required:
			 - **Arduino IDE**
			 - **NodeMCU ESP8266 development board**
			 - **ESP8266Webserver Library**
			 - **Newping Library**

- Knowledge about IOT protocol,Webserver,HTML5,CSS,NodeMCU ESP8266 architecture.


### Background

 1.  What is Internet of Things (IoT)?
 
The ​Internet of things​ (​IoT​) describes the network of physical objects—
“things”—that are embedded with sensors, software, and other technologies for the
purpose of connecting and exchanging data with other devices and systems over
the ​Internet​.

![IOT Building Blocks](https://drive.google.com/uc?export=view&id=1uA5eOJuuZGnGvATM_MA9H1R-Y0kxUiw0)

2. What is NODEMCU ESP8266 and it’s role in the project?

NodeMCU is an open-source Lua based firmware and ​development board
specially targeted for IoT based Applications. It includes firmware that runs on the
ESP8266 Wi-Fi SoC from Espressif Systems, and hardware which is based on the
ESP-12 module.

![Pinout diagram of ESP8266](https://drive.google.com/uc?export=view&id=1pM26tWKtpAv9ou5FpMF9hUYiOYkxwKES)

>  NodeMCU ESP8266 Specifications & Features
● Microcontroller: Tensilica 32-bit RISC CPU Xtensa LX106
● Operating Voltage: 3.3V
● Input Voltage: 7-12V
● Digital I/O Pins (DIO): 16
● Analog Input Pins (ADC): 1
● UARTs: 1
● SPIs: 1
● I2Cs: 1
● Flash Memory: 4 MB
● SRAM: 64 KB
● Clock Speed: 80 MHz
● USB-TTL based on CP2102 is included onboard, Enabling Plug n Play
● PCB Antenna

3. What is ESPWebserver and its role in the project?

ESPWebserver is a library that helps in setting a webserver on esp8266
microcontroller. In this project this library used for IoT application it helps us
visualize the water level in the tank. HTML,CSS,Javascript based text are uploaded
in the microcontroller and this library help to send these file’s to user mobile/PC
when there is HTTP request from client

![General working of webserver](https://drive.google.com/uc?export=view&id=1cQZU4zyQHMmOXwVEhHKLcETetX3tgNwF)

4. What is Ultrasonic sensor and its role in the project?

An ultrasonic sensor is an electronic device that measures the distance of a target
object by emitting ultrasonic sound waves, and converts the reflected sound into an
electrical signal. The data from the sensor is processed by microcontroller to
analyze the amount of water in the tank and take appropriate decision i.e. If water
level is low, it turn’s on the motor and vice versa

## Circuit Diagram

![Circuit  Diagram](https://drive.google.com/uc?export=view&id=1W1s1R1l_T7p8JenuA50skKPP995jG74f)

## Flowchart 

![Flowchart](https://drive.google.com/uc?export=view&id=1MA95bQdtelT91EExSqkyLMZJVBx7iEHx)

## Configuring the Tank Info Through Website
**Input the Height of the Tank**

![Tank details](https://drive.google.com/uc?export=view&id=1kb3ltVjoPUHD6wBEmkUzPaxhPz6A0lqp)

**Status Feedback about the waterline**

![waterline](https://drive.google.com/uc?export=view&id=1Kmgzw_ZCLkEaoeA_CmyJhiW3wHCC27sI)

## Customize Your Website 

I have stored the HTML and CSS stylesheet in the program memory of ESP8266.You can customize the HTML and CSS style by editing this variable in Water-Level-Monitor.ino file

    const char index_html[] PROGMEM = {"Your HTML code"};
    const char css[] PROGMEM={"Your CSS code"};




