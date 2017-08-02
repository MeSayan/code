"""The first step is to create an SMTP object, each object is used for connection 
with one server."""

import smtplib
server = smtplib.SMTP('smtp.gmail.com', 587)

#Next, log in to the server
server.login("productions.petrichor@gmail.com", "khuchroh")

#Send the mail
msg = " # The /n separates the message from the headers"
server.sendmail("productions.petrichor@gmail.com",
               "sayan.mahapatra1997@example.com", msg)