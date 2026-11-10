#include <iostream> // include the input output stream library for cin and cout
#include <string>   // include string library for string data type and operations
#include <iomanip>  // include iomanip library for formatted console output like setw
#include <fstream>  // include fstream library for file input and output operations like ifstream

using namespace std; // use the standard namespace to avoid writing std constantly

int main()
{

	// -------------------------------------------------------------------------------
	// --- 1 FIRST FILE PASS COUNTING DATA POINTS ---
	// -------------------------------------------------------------------------------

	// set up input file stream to open and read data from the text file
	ifstream reader("szigetek.txt");

	// check if the file was successfully opened
	if (!reader.is_open())
	{
		// print error message if file opening fails
		cout << "error opening file. " << endl;

		// pause the system console to let the user read the error before closing
		system("pause");

		// exit program with error code 1 indicating failure
		return 1;
	}

	// declare and initialize a counter variable to track the total number of data points
	int count = 0;

	// declare and initialize a temporary variable to hold each number read from the file
	int data = 0;

	// loop continuously until the end of the file is reached
	while (!reader.eof())
	{
		// read the next integer from the file into the temporary data variable
		reader >> data;

		// increment the counter for each successfully read integer
		count++;
	}

	// close the first input file stream since counting is finished
	reader.close();

	// display the total number of measurements counted in the file
	cout << count << " measurements were conducted. " << endl;

	// -------------------------------------------------------------------------------
	// --- 2 DYNAMIC MEMORY ALLOCATION AND SECOND FILE PASS ---
	// -------------------------------------------------------------------------------

	// declare an integer pointer for dynamic array allocation
	int* measurements;

	// dynamically allocate an array of integers based on the counted size
	measurements = new int[count];

	// open a second input file stream to read the actual data into the array
	ifstream in("szigetek.txt");

	// check if the second file stream was successfully opened
	if (!in.is_open())
	{
		// print error message if file opening fails
		cout << "error opening file. " << endl;

		// pause the system console to let the user read the error
		system("pause");

		// exit program with error code 1 indicating failure
		return 1;
	}

	// declare and initialize an index variable for the array
	int i = 0;

	// loop continuously until the end of the file is reached again
	while (!in.eof())
	{
		// read the next integer directly into the dynamically allocated array at the current index
		in >> measurements[i];

		// increment the array index variable
		i++;
	}

	// -------------------------------------------------------------------------------
	// --- 3 FORMATTED DISPLAY OF MEASUREMENT DATA ---
	// -------------------------------------------------------------------------------

	// print header for the data display section with tabs and newlines
	cout << "\n\tHeight data: \n\n" << endl;

	// iterate through the dynamically allocated array to display all measurements
	for (int i = 0; i < count; i++)
	{
		// check if the current element is the first one in a new row of eight using modulo arithmetic
		if ((i + 1) % 8 == 1)
		{
			// print the starting index of the new row
			cout << "\t" << i + 1 << "." << endl;
		}

		// check if the current element is not the last one in the row of eight
		if ((i + 1) % 8 != 0)
		{
			// print the measurement value with a fixed width of four characters
			cout << "\t" << setw(4) << measurements[i];
		}
		else
		{
			// print the last measurement value in the row with a fixed width and add a newline character
			cout << "\t" << setw(4) << measurements[i] << endl;
		}
	}

	// -------------------------------------------------------------------------------
	// --- 4 FINDING THE MAXIMUM MEASUREMENT VALUE ---
	// -------------------------------------------------------------------------------

	// declare and initialize a variable to track the index of the highest measurement starting with the first element
	int maxIndex = 0;

	// iterate through the array to find the maximum value
	for (int i = 0; i < count; i++)
	{
		// check if the current measurement is strictly greater than the currently stored maximum
		if (measurements[i] > measurements[maxIndex])
		{
			// update the maximum index to the current index
			maxIndex = i;
		}
	}

	// display the highest measurement value and its one based position in the dataset
	cout << "\n\n" << "The heighest measurement value is " << measurements[maxIndex] << " at index " << maxIndex + 1 << "." << endl;

	// -------------------------------------------------------------------------------
	// --- 5 COUNTING MEASUREMENTS EXACTLY AT SEA LEVEL ZERO ---
	// -------------------------------------------------------------------------------

	// declare and initialize a counter variable for measurements that equal zero
	int aboveSea = 0;

	// iterate through the array to check each measurement value
	for (int i = 0; i < count; ++i)
	{
		// check if the current measurement is exactly zero
		if (measurements[i] == 0)
		{
			// increment the counter when a zero measurement is found
			aboveSea++;
		}
	}

	// display the total count of measurements that equal zero
	cout << "There are " << aboveSea << " measurements above sea." << endl;

	// return zero to indicate that the program executed successfully
	return 0;

}