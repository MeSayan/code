import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import getpass

def sendemail(frm, to, subject, message):
  user_pwd = getpass.getpass('Password:')
  
  ## Preparing the message
  
  msg = MIMEMultipart()
  msg['From'] = frm
  msg['To'] = to
  msg['Subject'] = subject
  msg.attach(MIMEText(message,'plain'))
  msg_text = msg.as_string();
  
  
  #SMTP SSL
  server_ssl = smtplib.SMTP_SSL("smtp.gmail.com",465)
  server_ssl.ehlo()
  server_ssl.login(frm,user_pwd)
  server_ssl.sendmail(frm,to,msg_text)
  server_ssl.close()
    
  print(msg_text)
  


  
