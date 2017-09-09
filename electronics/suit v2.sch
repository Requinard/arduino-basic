EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:nodemcu
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L NodeMCU_0.9 U?
U 1 1 59B44903
P 2300 2800
F 0 "U?" H 2300 3600 50  0000 C CNN
F 1 "NodeMCU_0.9" H 2300 1950 50  0000 C CNN
F 2 "" H 2550 2800 50  0000 C CNN
F 3 "" H 2550 2800 50  0000 C CNN
	1    2300 2800
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR?
U 1 1 59B449AA
P 1000 1050
F 0 "#PWR?" H 1000 900 50  0001 C CNN
F 1 "+12V" H 1000 1190 50  0000 C CNN
F 2 "" H 1000 1050 50  0001 C CNN
F 3 "" H 1000 1050 50  0001 C CNN
	1    1000 1050
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR?
U 1 1 59B449C2
P 1000 1250
F 0 "#PWR?" H 1000 1100 50  0001 C CNN
F 1 "+5V" H 1000 1390 50  0000 C CNN
F 2 "" H 1000 1250 50  0001 C CNN
F 3 "" H 1000 1250 50  0001 C CNN
	1    1000 1250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 59B449D8
P 1000 1450
F 0 "#PWR?" H 1000 1200 50  0001 C CNN
F 1 "GND" H 1000 1300 50  0000 C CNN
F 2 "" H 1000 1450 50  0001 C CNN
F 3 "" H 1000 1450 50  0001 C CNN
	1    1000 1450
	0    1    1    0   
$EndComp
$Comp
L R 10K
U 1 1 59B44AEA
P 3200 1350
F 0 "10K" V 3280 1350 50  0000 C CNN
F 1 "R" V 3200 1350 50  0000 C CNN
F 2 "" V 3130 1350 50  0001 C CNN
F 3 "" H 3200 1350 50  0001 C CNN
	1    3200 1350
	0    -1   -1   0   
$EndComp
$Comp
L R_PHOTO 10k/1M
U 1 1 59B44B19
P 3200 1050
F 0 "10k/1M" H 3250 1100 50  0000 L CNN
F 1 "R_PHOTO" H 3250 1050 50  0000 L TNN
F 2 "" V 3250 800 50  0001 L CNN
F 3 "" H 3200 1000 50  0001 C CNN
	1    3200 1050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1000 1250 3050 1250
Wire Wire Line
	3050 1050 3050 1350
Connection ~ 3050 1250
Wire Wire Line
	3350 1350 3350 1450
Wire Wire Line
	3350 1450 1000 1450
Wire Wire Line
	3350 1050 3500 1050
Wire Wire Line
	3500 1050 3500 1550
Wire Wire Line
	3500 1550 1700 1550
Wire Wire Line
	1700 1550 1700 2100
Wire Wire Line
	1700 2100 1850 2100
$EndSCHEMATC
