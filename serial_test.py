import serial


ser = serial.Serial('/dev/ttyUSB0',9600)



while True:
  message = ser.readline();
  words = []
  words = message.split();
  print(message)

