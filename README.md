# CAN-Based-Body-Control-Module
Designed and developed a prototype Body Control Module (BCM) for automotive applications using the LPC2129 microcontroller and Embedded C. The system facilitates control of key vehicle functions, including lighting, door locks, and wipers, leveraging the Controller Area Network (CAN) protocol for efficient and reliable in-vehicle communication.
Features
Control of vehicle body functions such as:
Lighting systems
Door locks
Wiper systems
Communication via the CAN protocol for robust data transfer.
Modular and scalable design suitable for automotive applications.

Setup Instructions :
Hardware Assembly
Connect the LPC2129 microcontroller to the necessary peripherals (e.g., LEDs for lighting simulation).
Interface the CAN transceiver for communication.
Software Configuration

Clone the project repository.
Open the project in Keil µVision.
Configure CAN settings (e.g., baud rate, message IDs) in the source code

Sample Output :
    CAN Message Sent: ID=0x100, Data=0x01 (LED ON)
    CAN Message Sent: ID=0x100, Data=0x00 (LED OFF)
    
