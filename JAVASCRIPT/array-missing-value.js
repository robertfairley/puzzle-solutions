const ARRAY_LIMIT = 100;
const SEED        = new Date();

function main() {
	const arrayOne = new Array(ARRAY_LIMIT);
	const arrayTwo = new Array(ARRAY_LIMIT);
	
	let randomInteger, answer, i;

	randomInteger = Math.floor(
		(SEED * 12345 + Math.random()) % ARRAY_LIMIT
		);

	populateArrays(arrayOne, arrayTwo);
	modifyArray(arrayTwo, randomInteger);

	answer = checkDifference(arrayOne, arrayTwo);

	console.log(`
\r\nFIND THE RANDOM MISSING VALUE\n
=============================\n
Array 1 | Array 2`);
	console.log(`--------+--------`);


	for (i = 0; i < ARRAY_LIMIT; ++i) {
		console.log(`${arrayOne[i]}\t|\t${arrayTwo[i]}`);
	}

	console.log(`--------+--------\n`);
	console.log(`The random missing value is ${randomInteger}`);
	console.log(`And the missing vlaue from the modified array is ${answer}`);
}

function populateArrays(arrayInitial = [], arrayModified = []) {
	let i;

	for (i = 0; i < ARRAY_LIMIT; ++i) {
		arrayInitial[i] = i + 1;
		arrayModified[i] = i + 1;
	}
}

function modifyArray(arrayNew = [], random = 0) {
	arrayNew[random] = 0;
}

function sumArray(array = []) {
	let i, sum;
	sum = 0;

	for (i = 0; i < ARRAY_LIMIT; ++i)
		sum += array[i];

	return sum;
}

function checkDifference(arrayInitial = [], arrayModified = []) {
	let sumInitial, sumModified, difference;

	sumInitial  = sumArray(arrayInitial);
	sumModified = sumArray(arrayModified);
	difference  = sumInitial - sumModified;

	return difference;
}

module.exports = main;