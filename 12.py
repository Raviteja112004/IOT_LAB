import paho.mqtt.client as mqtt
from random import randrange
import time

mqtt_broker = "broker.hivemq.com"
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, "number-out")
client.connect(mqtt_broker)

while True:
    num = randrange(1, 11)
    client.publish("random number", num)
    print(f"The number {num} is published as random number")
    time.sleep(1)