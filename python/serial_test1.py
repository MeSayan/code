import serial
import smtplib
from email.mime.multipart import MIMEMultipart 
from email.mime.text import MIMEText
import time

ser = serial.Serial('/dev/ttyUSB0',9600)

def send_email():
  gmail_user = "productions.petrichor@gmail.com"  
  gmail_pwd =  "khuchroh"
  FROM = gmail_user
  TO = "sayan.mahapatra1997@gmail.com"
  SUBJECT = "Test"
  TEXT = "Demo Message"

  # Genrating a msg with all details
  msg = MIMEMultipart()
  msg['From'] = FROM
  msg['To'] = TO
  msg['Subject'] = SUBJECT
  body = """ Hello dear friend , how are you ? 
          \n Long time no see \n 
          Look forward to meeting you this sunday"""
  msg.attach(MIMEText(body,'plain'))
  msg_text = msg.as_string(); # Obtaining String Text 



  # SMTP SSL

  # SMTP_SSL Example
  server_ssl = smtplib.SMTP_SSL("smtp.gmail.com", 465)
  server_ssl.ehlo() # optional, called by login()
  server_ssl.login(gmail_user, gmail_pwd)  
    # ssl server doesn't support or need tls, so don't call         server_ssl.starttls     () 
  server_ssl.sendmail(FROM, TO, msg_text)
    #server_ssl.quit()
  server_ssl.close()
  print('successfully sent the mail')



while True:
  message = ser.readline();
  words = []
  words = message.split();
  if words[3] == "14" :
    send_email();
    time.sleep(100);
  else:
    print(words)
