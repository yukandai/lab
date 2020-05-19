import os
import time
import signal

class Señal():
    def __init__(self):
        self.time = 1
        self.number = 0
        self.pid = os.getpid()
        self.signal10 = False
        self.signal12 = False

    def signals(self, signalNumber, frame):
        if signalNumber == 10:
            if self.signal10 == True:
                self.time = self.time * 2

            self.signal10 = True
            self.printNumber()

        if signalNumber == 12:
            if self.signal12 == False:
                self.time = 1
                self.signal12 = True
                signal.pause()
            else:
                self.signal12 = False
                self.printNumber()

    def printNumber(self):
        print("Pid del proceso:", self.pid)

        while True:
            self.number += 1
            print(self.number)
            time.sleep(self.time)

if __name__ == "__main__":
    señal = Señal()

    def receiveSignal(signalNumber, frame):
        señal.signals(signalNumber, frame)

    #Codigo de señal: -10
    signal.signal(signal.SIGUSR1, receiveSignal)
    #Codigo de señal: -12
    signal.signal(signal.SIGUSR2, receiveSignal)

    print('El PID es:', os.getpid())
    signal.pause()