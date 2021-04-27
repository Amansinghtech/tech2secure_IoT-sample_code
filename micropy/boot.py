import network
import time
from machine import Pin
ssid = "HomeAP"
password = "routerkiller"

station = network.WLAN(network.STA_IF)

station.active(True)
station.connect(ssid, password)

print("Connecting")

while not (station.isconnected()):
    led = Pin(2, Pin.OUT)
    led.off()
    time.sleep(0.5)
    led.on()
    time.sleep(0.5)

print('Connected Successfully!')
led.off()
print(station.ifconfig())
