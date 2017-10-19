import smtplib
from email.mime.text import MIMEText
from email.header import Header
from email.header import decode_header
_user = "1424339365@qq.com"
_pwd  = "cugialrpccfpbadd"
_to   = "huangjiamingwl@gmail.com"

# subject =
msg = MIMEText("hahaha", "plain", "utf-8").encode()
msg["Subject"] = Header('膜拜', "utf-8").encode()
msg["From"]    = _user
msg["To"]      = _to

for _ in range(5):
    try:
        s = smtplib.SMTP_SSL("smtp.qq.com", 465)
        s.login(_user, _pwd)
        s.sendmail(_user, _to, msg.as_string())
        s.quit()
        print "Success!"
    except smtplib.SMTPException as e:
        print "Falied,%s" % e