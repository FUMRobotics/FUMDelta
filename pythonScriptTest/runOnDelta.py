# import pyautogui


# pyautogui.keyDown('alt')
# pyautogui.keyDown('tab')
# pyautogui.keyUp('tab')
# pyautogui.keyUp('alt')
# # pyautogui.press()
# pyautogui.write('10')

# # win = pyautogui.getWindows()
# # win.close()
import csv
import sysv_ipc
import numpy as np
import struct
import random
import time
import os
import subprocess
from ctypes import *

BUFF_SIZE = 16
QID = 1239



class myMsg(Structure):
    def __init__(self):
        print("created")

    def get_buffer(self):
        return bytearray(self)

    _pack_ = 1
    _fields_ = [
        ('theta1',c_double),
        ('theta2',c_double),
        ('theta3',c_double),
        ('theta4',c_double)
    ]
def sendPos(pts):
    msg = myMsg()
    msg.theta1 = pts[0]
    msg.theta2 = pts[1]
    msg.theta3 = pts[2]
    msg.theta4 = pts[3]
    print("msg created")
    try:
        mq = sysv_ipc.MessageQueue(QID, sysv_ipc.IPC_CREAT)
        print("mq created")
        # Two double transmission
        msg = msg.get_buffer()
        print(len(msg))
        mq.send(msg, False, type=1)
        # msg = myMsg.from_buffer(msg)
        # print(msg.data[1])


    except sysv_ipc.ExistentialError:
        print ("ERROR: message queue creation failed")


def turnOnVaccum():
	print(os.system("sudo ethercat download -p0 0x60fe 1 0x0f010001"))

def turnOffVaccum():
	print(os.system("sudo ethercat download -p0 0x60fe 1 0x0f000001"))


x = None
y = None
z = None
#for i in range(5000):
#    x = random.randint(0,40)
#    y = random.randint(0,40)
#    z = random.randint(60,75)
#    #y = y * -1
#    print(i)
#    print("x = "+str(x - 20)+" y = "+str(y -20) +" z = "+str(z*-1))
#    sendPos([x-20,y-20,z * -1,0])
#    time.sleep(4)

with open('Demo_Farsi_2.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        row = [float(x) for x in row]
        print(row)
        sendPos(row)
        time.sleep(4)

# for i in range(1000):
# 	sendPos([0,26,-60,0])
# 	time.sleep(5)
# 	sendPos([0,26,-74,0])
# 	time.sleep(3)
# 	turnOnVaccum()
# 	sendPos([0,26,-60,0])
# 	time.sleep(3)
# 	sendPos([0,-29,-60,0])
# 	time.sleep(5)
# 	sendPos([0,-29,-72,0])
# 	time.sleep(3)
# 	turnOffVaccum()
# 	sendPos([0, -29,-60,0])
# 	time.sleep(3)
