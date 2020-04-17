import keyboard as kb
import time
import sys
import msvcrt

if __name__ == '__main__':

	while True:
		
		try:
			if msvcrt.kbhit():
				ts = time.time()
				key = msvcrt.getch()
				# known problem: after pressing 'Ctrl+,', 'Ctrl+C' will print out '\x03' instead of terminating
				print(key)
				'''
				print(key, end = "")
				
				try:
					key = key.decode()
				except:
					print(", and it's not decodable now", end = "")
				else:
					if key.isprintable():
						print(", char = ", end = "")
						print(key, end = "")
				finally:
					print()
					'''
				te = time.time()
				print('Ruun Time: {:.5f}s'.format(te-ts))
		except:
			print("msvcrt skipping out")
			break

'''	
	while True:
		try:

			if kb.is_pressed('p'): # kb.read_key()
				print("Pressed p")
				time.sleep(0.5)

			if kb.read_key() == 'p':
				print("Pressed p")
				sys.stdin.flush()
				time.sleep(0.2)
		except:
			break
'''