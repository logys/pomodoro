EESchema Schematic File Version 4
EELAYER 30 0
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
L Pomodoro-rescue:R_US-Device R2
U 1 1 5C80C382
P 7000 1500
F 0 "R2" V 6795 1500 50  0000 C CNN
F 1 "1k" V 6886 1500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7040 1490 50  0001 C CNN
F 3 "~" H 7000 1500 50  0001 C CNN
	1    7000 1500
	0    1    1    0   
$EndComp
$Comp
L Pomodoro-rescue:R_US-Device R1
U 1 1 5C80C507
P 4950 1250
F 0 "R1" V 4745 1250 50  0000 C CNN
F 1 "1k" V 4836 1250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4990 1240 50  0001 C CNN
F 3 "~" H 4950 1250 50  0001 C CNN
	1    4950 1250
	0    1    1    0   
$EndComp
$Comp
L Pomodoro-rescue:SW_Push-Switch SW1
U 1 1 5C80C66D
P 9500 1250
F 0 "SW1" H 9500 1535 50  0000 C CNN
F 1 "SW_Push" H 9500 1444 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 9500 1450 50  0001 C CNN
F 3 "" H 9500 1450 50  0001 C CNN
	1    9500 1250
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:VCC-power #PWR0101
U 1 1 5C80C75E
P 3050 2200
F 0 "#PWR0101" H 3050 2050 50  0001 C CNN
F 1 "VCC" H 3067 2373 50  0000 C CNN
F 2 "" H 3050 2200 50  0001 C CNN
F 3 "" H 3050 2200 50  0001 C CNN
	1    3050 2200
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:GND-power #PWR0102
U 1 1 5C80C7D2
P 3050 3400
F 0 "#PWR0102" H 3050 3150 50  0001 C CNN
F 1 "GND" H 3055 3227 50  0000 C CNN
F 2 "" H 3050 3400 50  0001 C CNN
F 3 "" H 3050 3400 50  0001 C CNN
	1    3050 3400
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:LED-Device D1
U 1 1 5C80CA67
P 5450 1250
F 0 "D1" H 5442 995 50  0000 C CNN
F 1 "LED" H 5442 1086 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5450 1250 50  0001 C CNN
F 3 "~" H 5450 1250 50  0001 C CNN
	1    5450 1250
	-1   0    0    1   
$EndComp
$Comp
L Pomodoro-rescue:Q_NPN_CBE-Device Q1
U 1 1 5C80CC17
P 7350 1500
F 0 "Q1" H 7541 1546 50  0000 L CNN
F 1 "Q_NPN_CBE" H 7541 1455 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92" H 7550 1600 50  0001 C CNN
F 3 "~" H 7350 1500 50  0001 C CNN
	1    7350 1500
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:Buzzer-Device BZ1
U 1 1 5C80CCEA
P 7700 1100
F 0 "BZ1" H 7853 1129 50  0000 L CNN
F 1 "Buzzer" H 7853 1038 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" V 7675 1200 50  0001 C CNN
F 3 "~" V 7675 1200 50  0001 C CNN
	1    7700 1100
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:DIODE-pspice D2
U 1 1 5C80CDA4
P 7450 1100
F 0 "D2" V 7496 972 50  0000 R CNN
F 1 "DIODE" V 7405 972 50  0000 R CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 7450 1100 50  0001 C CNN
F 3 "~" H 7450 1100 50  0001 C CNN
	1    7450 1100
	0    -1   -1   0   
$EndComp
$Comp
L Pomodoro-rescue:VCC-power #PWR0104
U 1 1 5C80CF4D
P 7450 750
F 0 "#PWR0104" H 7450 600 50  0001 C CNN
F 1 "VCC" H 7467 923 50  0000 C CNN
F 2 "" H 7450 750 50  0001 C CNN
F 3 "" H 7450 750 50  0001 C CNN
	1    7450 750 
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:GND-power #PWR0105
U 1 1 5C80CFB4
P 5600 1350
F 0 "#PWR0105" H 5600 1100 50  0001 C CNN
F 1 "GND" H 5605 1177 50  0000 C CNN
F 2 "" H 5600 1350 50  0001 C CNN
F 3 "" H 5600 1350 50  0001 C CNN
	1    5600 1350
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:GND-power #PWR0106
U 1 1 5C80D0DC
P 7450 1850
F 0 "#PWR0106" H 7450 1600 50  0001 C CNN
F 1 "GND" H 7455 1677 50  0000 C CNN
F 2 "" H 7450 1850 50  0001 C CNN
F 3 "" H 7450 1850 50  0001 C CNN
	1    7450 1850
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:GND-power #PWR0107
U 1 1 5C80D262
P 5650 3850
F 0 "#PWR0107" H 5650 3600 50  0001 C CNN
F 1 "GND" H 5655 3677 50  0000 C CNN
F 2 "" H 5650 3850 50  0001 C CNN
F 3 "" H 5650 3850 50  0001 C CNN
	1    5650 3850
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:VCC-power #PWR0108
U 1 1 5C80D2EB
P 5400 3550
F 0 "#PWR0108" H 5400 3400 50  0001 C CNN
F 1 "VCC" H 5417 3723 50  0000 C CNN
F 2 "" H 5400 3550 50  0001 C CNN
F 3 "" H 5400 3550 50  0001 C CNN
	1    5400 3550
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:CP-Device C1
U 1 1 5C80D404
P 5400 3700
F 0 "C1" H 5518 3746 50  0000 L CNN
F 1 "CP" H 5518 3655 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 5438 3550 50  0001 C CNN
F 3 "~" H 5400 3700 50  0001 C CNN
	1    5400 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3850 5650 3850
Connection ~ 5650 3850
Wire Wire Line
	7450 1850 7450 1700
$Comp
L Pomodoro-rescue:GND-power #PWR0110
U 1 1 5C80D7A8
P 9900 1250
F 0 "#PWR0110" H 9900 1000 50  0001 C CNN
F 1 "GND" H 9905 1077 50  0000 C CNN
F 2 "" H 9900 1250 50  0001 C CNN
F 3 "" H 9900 1250 50  0001 C CNN
	1    9900 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 1250 9700 1250
Wire Wire Line
	5100 1250 5300 1250
Wire Wire Line
	5600 1250 5600 1350
Wire Wire Line
	3750 2600 3650 2600
Wire Wire Line
	7450 900  7450 750 
Wire Wire Line
	7450 750  7600 750 
Wire Wire Line
	7600 750  7600 1000
Connection ~ 7450 750 
Wire Wire Line
	7600 1200 7500 1200
Wire Wire Line
	7500 1200 7500 1300
Wire Wire Line
	7500 1300 7450 1300
Connection ~ 7450 1300
$Comp
L Pomodoro-rescue:ATtiny85V-10PU-MCU_Microchip_ATtiny U1
U 1 1 5C80F1C5
P 3050 2800
F 0 "U1" H 2520 2846 50  0000 R CNN
F 1 "ATtiny85V-10PU" H 2520 2755 50  0000 R CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 3050 2800 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf" H 3050 2800 50  0001 C CNN
	1    3050 2800
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:R_US-Device R3
U 1 1 5C9B6E91
P 3650 3150
F 0 "R3" H 3718 3196 50  0000 L CNN
F 1 "10k" H 3718 3105 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3690 3140 50  0001 C CNN
F 3 "~" H 3650 3150 50  0001 C CNN
	1    3650 3150
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:Battery_Cell-Device BT1
U 1 1 5C9B90B6
P 5100 3750
F 0 "BT1" H 5218 3846 50  0000 L CNN
F 1 "Battery_Cell" H 5218 3755 50  0000 L CNN
F 2 "Battery:BatteryHolder_Keystone_105_1x2430" V 5100 3810 50  0001 C CNN
F 3 "~" V 5100 3810 50  0001 C CNN
	1    5100 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3850 5900 3850
$Comp
L Pomodoro-rescue:AVR-ISP-6-Connector J1
U 1 1 5DD849F3
P 2800 4300
F 0 "J1" H 2521 4396 50  0000 R CNN
F 1 "AVR-ISP-6" H 2521 4305 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" V 2550 4350 50  0001 C CNN
F 3 " ~" H 1525 3750 50  0001 C CNN
	1    2800 4300
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:GND-power #PWR0109
U 1 1 5DD85794
P 2700 4900
F 0 "#PWR0109" H 2700 4650 50  0001 C CNN
F 1 "GND" H 2705 4727 50  0000 C CNN
F 2 "" H 2700 4900 50  0001 C CNN
F 3 "" H 2700 4900 50  0001 C CNN
	1    2700 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3800 2700 3750
Wire Wire Line
	2700 4700 2700 4900
Wire Wire Line
	3200 4100 3400 4100
Text GLabel 3400 4200 2    50   Input ~ 0
PB0
Text GLabel 3400 4100 2    50   Input ~ 0
PB1
Text GLabel 3400 4300 2    50   Input ~ 0
PB2
Text GLabel 3400 4400 2    50   Input ~ 0
RESET
Wire Wire Line
	3400 4200 3200 4200
Wire Wire Line
	3200 4300 3400 4300
Wire Wire Line
	3400 4400 3200 4400
Text GLabel 3750 2500 2    50   Input ~ 0
PB0
Text GLabel 3750 2600 2    50   Input ~ 0
PB1
Text GLabel 3750 2700 2    50   Input ~ 0
PB2
Text GLabel 3750 3000 2    50   Input ~ 0
RESET
$Comp
L Pomodoro-rescue:VCC-power #PWR0111
U 1 1 5DDA19C0
P 3950 3300
F 0 "#PWR0111" H 3950 3150 50  0001 C CNN
F 1 "VCC" H 3967 3473 50  0000 C CNN
F 2 "" H 3950 3300 50  0001 C CNN
F 3 "" H 3950 3300 50  0001 C CNN
	1    3950 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3300 3950 3300
Wire Wire Line
	3750 2500 3650 2500
Text GLabel 4600 1250 0    50   Input ~ 0
PB0
Wire Wire Line
	4800 1250 4600 1250
Text GLabel 6750 1500 0    50   Input ~ 0
PB1
Wire Wire Line
	6850 1500 6750 1500
Wire Wire Line
	3650 2700 3750 2700
Text GLabel 3750 2800 2    50   Input ~ 0
Button1
Wire Wire Line
	3750 2800 3650 2800
Text GLabel 9150 1250 0    50   Input ~ 0
Button1
Wire Wire Line
	9300 1250 9150 1250
Wire Wire Line
	3750 3000 3650 3000
Connection ~ 3650 3000
$Comp
L Pomodoro-rescue:Jumper_3_Bridged12-Jumper JP1
U 1 1 5DDCB870
P 5600 3250
F 0 "JP1" H 5600 3454 50  0000 C CNN
F 1 "Vcc select" H 5600 3363 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 5600 3250 50  0001 C CNN
F 3 "~" H 5600 3250 50  0001 C CNN
	1    5600 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3550 5600 3550
Wire Wire Line
	5600 3550 5600 3400
Connection ~ 5400 3550
Text GLabel 3750 2900 2    50   Input ~ 0
Button2
Wire Wire Line
	3750 2900 3650 2900
$Comp
L Pomodoro-rescue:SW_Push-Switch SW2
U 1 1 5F005701
P 9500 1750
F 0 "SW2" H 9500 2035 50  0000 C CNN
F 1 "SW_Push" H 9500 1944 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 9500 1950 50  0001 C CNN
F 3 "" H 9500 1950 50  0001 C CNN
	1    9500 1750
	1    0    0    -1  
$EndComp
$Comp
L Pomodoro-rescue:GND-power #PWR02
U 1 1 5F005707
P 9900 1750
F 0 "#PWR02" H 9900 1500 50  0001 C CNN
F 1 "GND" H 9905 1577 50  0000 C CNN
F 2 "" H 9900 1750 50  0001 C CNN
F 3 "" H 9900 1750 50  0001 C CNN
	1    9900 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 1750 9700 1750
Text GLabel 9150 1750 0    50   Input ~ 0
Button2
Wire Wire Line
	9300 1750 9150 1750
$Comp
L Pomodoro-rescue:R_US-Device R4
U 1 1 5F007E48
P 4900 1850
F 0 "R4" V 4695 1850 50  0000 C CNN
F 1 "1k" V 4786 1850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4940 1840 50  0001 C CNN
F 3 "~" H 4900 1850 50  0001 C CNN
	1    4900 1850
	0    1    1    0   
$EndComp
$Comp
L Pomodoro-rescue:LED-Device D3
U 1 1 5F007E4E
P 5400 1850
F 0 "D3" H 5392 1595 50  0000 C CNN
F 1 "LED" H 5392 1686 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5400 1850 50  0001 C CNN
F 3 "~" H 5400 1850 50  0001 C CNN
	1    5400 1850
	-1   0    0    1   
$EndComp
$Comp
L Pomodoro-rescue:GND-power #PWR01
U 1 1 5F007E54
P 5550 1950
F 0 "#PWR01" H 5550 1700 50  0001 C CNN
F 1 "GND" H 5555 1777 50  0000 C CNN
F 2 "" H 5550 1950 50  0001 C CNN
F 3 "" H 5550 1950 50  0001 C CNN
	1    5550 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 1850 5250 1850
Wire Wire Line
	5550 1850 5550 1950
Text GLabel 4550 1850 0    50   Input ~ 0
PB2
Wire Wire Line
	4750 1850 4550 1850
Text GLabel 2550 3750 0    50   Input ~ 0
Vcc_prog
Text GLabel 6000 3250 2    50   Input ~ 0
Vcc_prog
Wire Wire Line
	2550 3750 2700 3750
Wire Wire Line
	5850 3250 6000 3250
Wire Wire Line
	5100 3550 5100 3250
Wire Wire Line
	5100 3250 5350 3250
Wire Wire Line
	5100 3850 5400 3850
Connection ~ 5400 3850
$EndSCHEMATC
