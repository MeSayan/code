import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import getpass

def sendEmail(frm, to, subject, message):
  user_pwd = getpass.getpass('Password:')
  
  ## Preparing the message
  
  msg = MIMEMultipart()
  msg['From'] = frm
  msg['To'] = to
  msg['Subject'] = subject
  msg.attach(MIMEText(message,'plain'))
  msg_text = msg.as_string();
  
  
 