/**
 *	Program array-missing-value.c
 *
 *	This problem was posed to me at an interview
 *	in Toronto, October 2017.
 *
 *	## The problem:
 *
 *	Write a program to find a random missing value in an
 *	array with an arbitrary length.
 *
 *	## Application:
 *
 *	Two arrays are declared with a length of 100 for 
 *	populating with integers between 1 and 100, inclusive.
 *	A random integer between 0 and 99 is generated based on
 *	the time. The random number is used to set a value in
 *	the modified array to 0.
 *
 *	## Solution
 *
 *	Resolve the sums of both arrays, check and return the
 *	difference and print to stdout.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LIMIT 100

time_t seed;

void populate_arrays (int array_initial[], int array_modified[])
{
	int i;

	for (i = 0; i < ARRAY_LIMIT; ++i)
	{
		array_initial[i]  = i + 1;
		array_modified[i] = i + 1;
	}
}

void modify_array (int array_new[], int rand)
{
	array_new[rand] = 0;
}

int sum_array (int array[])
{
	int i, sum;
	sum = 0;

	for (i = 0; i < ARRAY_LIMIT; ++i)
		sum = sum + array[i];

	return sum;
}

int check_difference (int array_initial[], int array_modified[])
{
	int sum_initial, sum_modified, difference;

	sum_initial  = sum_array(array_initial);
	sum_modified = sum_array(array_modified);
	difference   = sum_initial - sum_modified;

	return difference;
}

int main (void)
{
	int random_int, answer, i;
	int array_one[ARRAY_LIMIT], array_two[ARRAY_LIMIT];

	srand(42 * 12345 + (unsigned int) &seed);
	random_int = rand() % ARRAY_LIMIT;

	populate_arrays(array_one, array_two);
	modify_array(array_two, random_int);

	answer = check_difference(array_one, array_two);

	printf(
		"\r\nFIND THE RANDOM MISSING VALUE\n\n"
		"=================================\n"
		);

	printf(
		"Array One\t|\tArray Two\n"
		"----------------+----------------\n"
		);

	for (i = 0; i < ARRAY_LIMIT; ++i) {
		if (i < 10) {
			printf(" %i : %i\t\t|\t %i : %i\n", i, array_one[i], i, array_two[i]);
		}
		else if (i < 99) {
			printf("%i : %i\t\t|\t%i : %i\n", i, array_one[i], i, array_two[i]);
		}
		else {
			printf("%i : %i\t|\t%i : %i\n", i, array_one[i], i, array_two[i]);
		}
	}

	printf("----------------+----------------\n");

	printf(
		"The random value is: %i\n"
		"And the missing value from the modified array is: %i\r\n\n",
		random_int, answer
		);

	return 0;
}
