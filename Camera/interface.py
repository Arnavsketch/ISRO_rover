import socket

# IP address and port of the target device
target_ip = '172.20.10.8'   #Example IP address
target_port = USB0 # Example port number

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the target device
target_address = (target_ip, target_port)
client_socket.connect(target_address)
