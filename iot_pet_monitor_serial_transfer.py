from firebase import firebase
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
firebase = firebase.FirebaseApplication('Firebase URL', None)

while True:
    direction = firebase.get('/iot-pet-monitoring-system', 'data')
    print direction
    ser.write(str(direction))
    
