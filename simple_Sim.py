# Import Libraries
import time

def Sensing(delay_time):
	print("Performing Sensor Tasks")
	time.sleep(delay_time)

def Movement(delay_time):
	print("Performing Movement Tasks")
	time.sleep(delay_time)

def Safety(delay_time):
	print ("Performing Safety Tasks")
	time.sleep(delay_time)
	
if __name__ == "__main__":
    delay_time = 1  # Change this value to see how increasing the robot tasking delays the counter from incrementing.
    i = 0  # initiate the counter
    print('starting')
    # Main loop that will run the tasks.
    while True:
        Sensing(delay_time)
        Movement(delay_time)
        Safety(delay_time)

        print(i)
        i = i + 1  # increment the counter
        print("")  # for readability