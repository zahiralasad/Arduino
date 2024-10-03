import serial

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0',9600, timeout=1)
    ser.flush()

while True:
        user_input = input("Enter command to send to Arduino: ")  # Ask user for input
        if user_input:
            ser.write(user_input.encode('utf-8'))  # Send the input as a byte string
        if ser.in_waiting > 0:
            response = ser.readline().decode('utf-8').rstrip()  # Read Arduino's response
            print(f"{response}")

                    
