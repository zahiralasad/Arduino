import serial
import paho.mqtt.client as mqtt

# Set up the serial connection to the Arduino
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
ser.flush()

# MQTT configurations
broker = "localhost"  # Use your broker address if different
port = 1883  # Default MQTT port
topic = "arduino/led"  # Topic to subscribe to for controlling the LED

# Function to handle incoming MQTT messages
def on_message(client, userdata, message):
    command = message.payload.decode('utf-8')  # Decode the message
    print(f"Received command from MQTT: {command}")
    
    # Send the command to Arduino via serial
    if command in ["on", "off"]:
        ser.write(command.encode('utf-8'))  # Send to Arduino as byte string
        print(f"Sent command to Arduino: {command}")
    else:
        print("Invalid command received.")

# MQTT setup
def on_connect(client, userdata, flags, rc):
    print(f"Connected to MQTT broker with result code {rc}")
    client.subscribe(topic)  # Subscribe to the topic when connected

# Initialize MQTT client and connect to broker
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(broker, port, 60)  # Connect to the MQTT broker

# Start MQTT loop to process incoming messages
client.loop_start()

# Main loop to keep the script running and interact with Arduino
try:
    while True:
        # If there's a response from Arduino, print it
        if ser.in_waiting > 0:
            response = ser.readline().decode('utf-8').rstrip()  # Read Arduino's response
            print(f"Arduino response: {response}")
except KeyboardInterrupt:
    print("Disconnecting...")
    client.loop_stop()  # Stop MQTT loop
    ser.close()  # Close serial connection
