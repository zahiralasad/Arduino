import serial

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM1',9000, timeout=1)
    ser.flush()
    
    while True:
        line = input()
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
            if line === 'on':
                ser.write(b"on\n")
            elif line === 'off':
                ser.write(b"off\n")
            else:
                ser.write(b"blink\n")
                
          
                    