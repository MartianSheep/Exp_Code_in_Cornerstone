import time
import sys

import msvcrt # for kb
import serial # for bt
# bt is only single-way, no need threading

class bluetooth:
    def __init__(self, port: str, baudrate: int=9600):
        """ Initialize an BT object, and auto-connect it. """
        # The port name is the name shown in control panel
        # And the baudrate is the communication setting, default value of HC-05 is 9600.
        try:
            self.ser = serial.Serial(port, baudrate=baudrate)
        except:
            print("Port not opened !!!")
            sys.exit()
        
        
    def is_open(self) -> bool:
        return self.ser.is_open

    def waiting(self) -> bool:
        return self.ser.in_waiting

    def do_connect(self, port: str, baudrate: int=9600) -> bool:
        """ Connect to the specify port with particular baudrate """
        # Connection function. Disconnect the previous communication, specify a new one.
        self.disconnect()

        try:
            self.ser = serial.Serial(port, baudrate=baudrate)
            return True
        except:
            return False

    def disconnect(self):
        """ Close the connection. """
        self.ser.close()

    def write(self, output: bytes):
        # Write the byte to the output buffer, encoded by utf-8.
        self.ser.write(output)

if __name__ == "__main__":
	# Please modify the port name.
	bt = bluetooth("COM18")
	while not bt.is_open(): pass
	print("BT Connected!")

	while True:
		try:
			if msvcrt.kbhit():
				key = msvcrt.getch()
				bt.write(key)
		except:
			print("msvcrt skipping out")
			break


# known problem: after pressing 'Ctrl+,', 'Ctrl+C' will print out '\x03' instead of terminating
# known problem: no known exit except Ctrl+C
# known problem: Ctrl+C combination key leads to a wasd before skipping out