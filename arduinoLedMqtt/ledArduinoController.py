import serial

if __name__ == '__main__':
    ser = serial.Serial('COM3',9600)
    print('Test')
