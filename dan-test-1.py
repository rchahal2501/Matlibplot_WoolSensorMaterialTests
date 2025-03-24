#   Reese Chahal - Material Testing Variable Resistors_Sensors
#   2024 Conductive Wool (E-Textile) _Studio Art Thesis Work

#pip3 install matplotlib
#https://www.youtube.com/watch?v=PhDPnjF3_tA

import serial
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import csv

# Constants
SERIAL_PORT = '/dev/tty.usbmodem101'
BAUD_RATE = 9600

# Initialize serial connection
ser = serial.Serial(SERIAL_PORT, BAUD_RATE)

# Initialize empty lists to store data
x_vals = []
sensorValue1_data = []

# Create a function to read and process data from Arduino
def read_and_process_data() :
    line = ser.readline().decode('utf-8').strip()
    sensorValues = line.split(', ')
    
    x_vals.append(float(sensorValues[0]))
    sensorValue1_data.append(float(sensorValues[1]))
    print(f'Time: {sensorValues[0]}, Voltage Output: {sensorValues[1]}')


# Create a function to update the plot
def update_plot(frame):
    read_and_process_data()
    ax.cla()
    ax.plot(x_vals, sensorValue1_data)
    ax.set_xlabel("Time")
    ax.set_ylabel('Voltage Output (v)')
    ax.legend(loc="upper right")

#save data into CSV fxn:
#if u dont 'cd /Documents' --> CSV file auto saves to '/Users/rchahal' directory
def on_close(event):
    #with open('arduino_data.csv', 'w', newline='') as csvfile:
    with open('/Users/rchahal/Documents/csv-tests-dan/arduino_data.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Time', 'Voltage Out'])
        for x, s1 in zip(x_vals, sensorValue1_data):
            writer.writerow([x, s1])

# Register the callback function for when the plot window is closed
fig, ax = plt.subplots()
fig.canvas.mpl_connect('close_event', on_close)
ani = FuncAnimation(fig, update_plot, interval=10)
plt.show()
