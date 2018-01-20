from random import *

RANDOM_INT = randint(0,99)

def main():
	array_one = [0]*100
	array_two = [0]*100

	array_one = populate_array(array_one)
	array_two = populate_array(array_two)

	array_two = modify_array(array_two)

	answer = check_difference(array_one, array_two)

	print "\r\nFIND THE RANDOM MISSING VALUE"
	print "============================="
	print " "
	print " Array One\t|\tArray Two"
	print "----------------|---------------"

	for i in range(99):
		print str(i) + " : " + str(array_one[i]) + "\t\t|\t" + str(i) + " : " + str(array_two[i])

	print "--------------------------------"

	print "\nThe random value is: ", RANDOM_INT
	print "And the missing value from the modified array is: ", answer, "\r\n"

def populate_array(array = []):
	for num in range(100):
		array[num] = num
	return array
	
def modify_array(array = []):
	array[RANDOM_INT] = 0

	return array

def sum_array(array = []):
	sum = 0

	for num in array:
		sum += num

	return sum

def check_difference(array_initial = [], array_modified = []):
	sum_initial = 0
	sum_modified = 0
	difference = 0

	sum_initial = sum_array(array_initial)
	sum_modified = sum_array(array_modified)
	difference = sum_initial - sum_modified

	return difference

if __name__ == "__main__":
	main()
