/**
 *	TODO: Document.
 */
import std.stdio;
import std.random;

/** Constants */
enum ARRAY_LIMIT = 100;

void main ()
{
	/** Locals */
	size_t i;
	int    random_int;
	int    answer;
	auto   set_rand = MinstdRand0(1);

	/** Arrays */
	int[ARRAY_LIMIT] array_one;
	int[ARRAY_LIMIT] array_two;

	/** Get a random integer */
	set_rand.seed(unpredictableSeed);
	random_int = set_rand.front % 100;

	/** Populate te arrays and modify the second */
	populate_arrays(array_one, array_two);
	modify_array(array_two, random_int);

	/** Get the difference between the two arrays */
	answer = check_difference(array_one, array_two);

	/** Print the results to stdout */
	writeln("\r\nFIND THE RANDOM MISSING VALUE");
	writeln("==================================\n");
	writeln("Array One\t|\tArray Two");
	writeln("----------------+-----------------");

	for (i = 0; i < ARRAY_LIMIT; ++i) {
		if (i == 99)
			writefln("%d : %d\t|\t%d : %d", i, array_one[i], i, array_two[i]);
		else
			writefln("%d : %d\t\t|\t%d : %d", i, array_one[i], i, array_two[i]);
	}

	writeln("---------------------------------\n");

	writefln("The random value is: %d", random_int);
	writefln("And the missing value from the modified array is: %d\r\n", answer);
}

void populate_arrays (int[] array_initial, int[] array_modified)
{
	size_t i;

	for (i = 0; i < ARRAY_LIMIT; ++i) {
		array_initial[i]  = cast(int)i + 1;
		array_modified[i] = cast(int)i + 1;
	}
}

void modify_array(int[] array_new, int rand)
{
	array_new[rand] = 0;
}

int sum_array (int[] array)
{
	size_t i;
	int    sum;

	sum = 0;

	for (i = 0; i < ARRAY_LIMIT; ++i)
		sum += array[i];

	return sum;
}

int check_difference (int[] array_initial, int[] array_modified)
{
	int sum_initial, sum_modified, difference;

	sum_initial  = sum_array(array_initial);
	sum_modified = sum_array(array_modified);
	difference   = sum_initial - sum_modified;

	return difference;
}