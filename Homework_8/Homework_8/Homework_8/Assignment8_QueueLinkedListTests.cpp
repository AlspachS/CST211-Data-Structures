#define _CRTDBG_MAP_ALLOC

typedef bool(*FunctionPointer)();  // Define a funtion pointer type

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;

#include <crtdbg.h>
#include <conio.h>
#include "ListQueue.h"
#include "Exception.h"

const int TEST_DATA[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

const char * STATES[] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California",
"Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho",
"Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland",
"Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana",
"Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York",
"North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon" };

const int NUM_STATES = 36;
const int NUM_INTS = 10;  

// Test function declaration
bool test_enqueue();
bool test_queue_integrity();
bool test_copy_ctor();
bool test_op_eql();
bool test_dequeue_empty_queue();
bool test_front_empty_queue();
bool test_front_value();
bool test_front_value_change();
bool test_is_empty();
bool test_size(); 

bool test_enqueue_complex();
bool test_queue_integrity_complex();
bool test_copy_ctor_complex();
bool test_op_eql_complex();
bool test_dequeue_empty_queue_complex();
bool test_front_empty_queue_complex();
bool test_front_value_complex();
bool test_front_value_change_complex();
bool test_is_empty_complex();
bool test_size_complex();

// Array of test functions
FunctionPointer test_functions[] = { test_enqueue, test_queue_integrity, test_copy_ctor, 
									 test_op_eql, test_dequeue_empty_queue, test_front_empty_queue, 
									 test_front_value, test_front_value_change, test_is_empty, test_size,
									 test_enqueue_complex, test_queue_integrity_complex, 
									 test_copy_ctor_complex, test_op_eql_complex, test_dequeue_empty_queue_complex, 
									 test_front_empty_queue_complex, test_front_value_complex, test_front_value_change_complex, 
									 test_is_empty_complex, test_size_complex };

int main()
{
	bool tests_passed;

	// Run the test functions
	for each (FunctionPointer func in test_functions)
	{
		if (func())
		{
			cout << "passed\n";
		}
		else
		{
			cout << "***** failed *****\n";
		}
	}

	cout << "\nPress Any Key to Exit";
	cin.get();
}

bool test_enqueue()
{
	ListQueue<int> test_queue;
	bool pass = true; 

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}

	for (int i = 0; i < NUM_INTS && pass; i++)
	{
		if (test_queue.Dequeue() != TEST_DATA[i])
		{
			pass = false; 
		}
	}

	cout << "Enqueue test ";

	return pass; 
}

bool test_queue_integrity()
{
	ListQueue<int> test_queue;
	bool pass = true;
	int integrity_data[] = { 4, 5, 6, 7, 8, 9, 0, 100, 200, 300 };

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}

	test_queue.Dequeue(); 
	test_queue.Dequeue();
	test_queue.Dequeue();

	test_queue.Enqueue(100); 
	test_queue.Enqueue(200);
	test_queue.Enqueue(300);

	for (int i = 0; i < NUM_INTS && pass; i++)
	{
		if (test_queue.Dequeue() != integrity_data[i])
		{
			pass = false;
		}
	}

	cout << "Queue integrity test ";

	return pass;
}

bool test_copy_ctor()
{
	ListQueue<int> test_queue;
	bool pass = true;

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}

	ListQueue<int> copy_queue(test_queue); 

	for (int i = 0; i < NUM_INTS && pass; i++)
	{
		if (copy_queue.Dequeue() != TEST_DATA[i])
		{
			pass = false;
		}
	}

	cout << "Copy ctor test ";

	return pass;
}

bool test_op_eql()
{
	ListQueue<int> test_queue;
	ListQueue<int> op_eql_queue;
	bool pass = true;

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}	

	op_eql_queue = test_queue;

	for (int i = 0; i < NUM_INTS && pass; i++)
	{
		if (op_eql_queue.Dequeue() != TEST_DATA[i])
		{
			pass = false;
		}
	}

	cout << "Op eql test ";

	return pass;
}

bool test_dequeue_empty_queue()
{
	ListQueue<int> test_queue;
	bool pass = false;

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Dequeue();
	}

	try
	{
		test_queue.Dequeue();
	}
	catch (Exception& except)
	{
		pass = true; 
	}

	cout << "Dequeue empty queue test ";

	return pass;
}

bool test_front_empty_queue()
{
	ListQueue<int> test_queue;
	bool pass = false;

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Dequeue();
	}

	try
	{
		test_queue.Front();
	}
	catch (Exception& except)
	{
		pass = true;
	}

	cout << "Front empty queue test ";

	return pass;
}

bool test_front_value()
{
	ListQueue<int> test_queue;
	bool pass = true;

	test_queue.Enqueue(5); 

	if (test_queue.Front() != 5)
		pass = false; 

	// Exception should occur if from removed first item
	try
	{
		test_queue.Dequeue();
	}
	catch (Exception& except)
	{
		pass = false; 
	}
	cout << "Front value test ";

	return pass;
}

bool test_front_value_change()
{
	ListQueue<int> test_queue;
	bool pass = true;
	int changed_data[] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}

	for (int i = 0; i < NUM_INTS && pass; i++)
	{
		test_queue.Front() = i + 100; 

		if (test_queue.Dequeue() != changed_data[i])
			pass = false;
	}

	cout << "Front change value test ";

	return pass;
}

bool test_is_empty()
{
	ListQueue<int> test_queue;
	bool pass = false;

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Dequeue();
	}

	pass = test_queue.isEmpty();

	cout << "Is empty test ";

	return pass;
}

bool test_size()
{
	ListQueue<int> test_queue;
	bool pass = true;

	for (int i = 0; i < NUM_INTS; i++)
	{
		test_queue.Enqueue(TEST_DATA[i]);
	}

	if (test_queue.Size() != NUM_INTS)
		pass = false; 

	cout << "Size test ";

	return pass;
}

bool test_enqueue_complex()
{
	ListQueue<string> test_queue;
	bool pass = true;

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	for (int i = 0; i < NUM_STATES && pass; i++)
	{
		if (test_queue.Dequeue() != STATES[i])
		{
			pass = false;
		}
	}

	cout << "Enqueue test complex ";

	return pass;
}

bool test_queue_integrity_complex()
{
	ListQueue<string> test_queue;
	bool pass = true;
	string integrity_data[] = { "Arkansas", "California", "Colorado", "Connecticut", 
								"Delaware", "Florida", "Georgia", "test1", "test2", "test3" };

	for (int i = 0; i < 10; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	test_queue.Dequeue();
	test_queue.Dequeue();
	test_queue.Dequeue();

	test_queue.Enqueue("test1");
	test_queue.Enqueue("test2");
	test_queue.Enqueue("test3");

	for (int i = 0; i < 10 && pass; i++)
	{
		if (test_queue.Dequeue() != integrity_data[i])
		{
			pass = false;
		}
	}

	cout << "Queue integrity test complex ";

	return pass;
}

bool test_copy_ctor_complex()
{
	ListQueue<string> test_queue;
	bool pass = true;

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	ListQueue<string> copy_queue(test_queue);

	for (int i = 0; i < NUM_STATES && pass; i++)
	{
		if (copy_queue.Dequeue() != STATES[i])
		{
			pass = false;
		}
	}

	cout << "Copy ctor test complex ";

	return pass;
}

bool test_op_eql_complex()
{
	ListQueue<string> test_queue;
	ListQueue<string> op_eql_queue;
	bool pass = true;

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	op_eql_queue = test_queue;

	for (int i = 0; i < NUM_STATES && pass; i++)
	{
		if (op_eql_queue.Dequeue() != STATES[i])
		{
			pass = false;
		}
	}

	cout << "Op eql test complex ";

	return pass;
}

bool test_dequeue_empty_queue_complex()
{
	ListQueue<string> test_queue;
	bool pass = false;

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Dequeue();
	}

	try
	{
		test_queue.Dequeue();
	}
	catch (Exception& except)
	{
		pass = true;
	}

	cout << "Dequeue empty queue test complex ";

	return pass;
}

bool test_front_empty_queue_complex()
{
	ListQueue<string> test_queue;
	bool pass = false;

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Dequeue();
	}

	try
	{
		test_queue.Front();
	}
	catch (Exception& except)
	{
		pass = true;
	}

	cout << "Front empty queue test complex ";

	return pass;
}

bool test_front_value_complex()
{
	ListQueue<string> test_queue;
	bool pass = true;

	test_queue.Enqueue("test");

	if (test_queue.Front() != "test")
		pass = false;

	// Exception should occur if from removed first item
	try
	{
		test_queue.Dequeue();
	}
	catch (Exception& except)
	{
		pass = false;
	}
	cout << "Front value test complex ";

	return pass;
}

bool test_front_value_change_complex()
{
	ListQueue<string> test_queue;
	bool pass = true;
	char temp[30] = ""; 
	string changed_data[] = { "Alabamatest", "Alaskatest", "Arizonatest", "Arkansastest", "Californiatest",
							  "Coloradotest", "Connecticuttest" };

	for (int i = 0; i < 7; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	for (int i = 0; i < 7 && pass; i++)
	{
		strcat(temp, STATES[i]);
		strcat(temp, "test");
			
		test_queue.Front() = temp;

		strcpy(temp, ""); 

		if (test_queue.Dequeue() != changed_data[i])
			pass = false;
	}

	cout << "Front change value test complex ";

	return pass;
}

bool test_is_empty_complex()
{
	ListQueue<string> test_queue;
	bool pass = false;

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Dequeue();
	}

	pass = test_queue.isEmpty();

	cout << "Is empty test complex ";

	return pass;
}

bool test_size_complex()
{
	ListQueue<string> test_queue;
	bool pass = true;

	for (int i = 0; i < NUM_STATES; i++)
	{
		test_queue.Enqueue(STATES[i]);
	}

	if (test_queue.Size() != NUM_STATES)
		pass = false;

	cout << "Size test complex ";

	return pass;
}