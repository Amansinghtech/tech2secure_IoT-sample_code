# https://micropython.org/
# https://docs.micropython.org/en/latest/esp8266/tutorial/intro.html#intro
from machine import Pin
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(5)
led = Pin(5, Pin.OUT)
led.off()
while True:

    try:

        conn, addr = s.accept()
        conn.settimeout(3)
        print('got connection from %s' % str(addr))

        request = conn.recv(1024)
        request = request.decode()

        print(request)
        if '/test?led=on' in request:
            response = "LED IS ON"
            led.on()
        elif '/test?led=off' in request:
            response = "LED IS OFF"
            led.off()
        else:
            with open('index.html') as file:
                response = file.read()
                file.close()

        conn.send('HTTP/1.1 200 OK\n')
        conn.send('Content-Type: text/html\n')
        conn.send('Connection: close\n\n')
        conn.sendall(response)
        conn.close()

    except Exception as e:
        print(e)
        conn.close()