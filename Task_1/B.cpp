#include <iostream>

using namespace std;

const int max_len = 1000;

void fill_array(long* array, int& len)
{
	long tmp;

	for (int i = 0; i < len; ++i)
	{
		cin >> tmp;
		array[i] = tmp;
	}

	return;
}

bool is_prime(long& input)
{
	long d = 2;

	while (d * d <= input)
	{
		if (input % d == 0)
			return false;
		++d;
	}

	return true;
}

int find_new_pos(long* array, int& length, long& number) // first greater or -1 if already found
{
	for (int i = 0; i < length; ++i)
	{
		if(array[i] == number)
			return -1;
		if (array[i] > number)
			return i;
	}
	
	return length; // if there are no greater elements, insert in the end
}

void insert_before(long* array, int& length, int before_element, long& new_element)
{
	if (before_element == -1) // if we are not inserting any element
		return;


	for (int i = length; i >= before_element; --i) // move elements [before_element;length) to right
	{
		array[i] = array[i - 1];
	}

	array[before_element] = new_element;

	++length; // increase length

	return;
}

void print_array(long* array, int& length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << array[i];
		
		if (i != length - 1)
			cout << ' ';
	}
	
	cout << endl;

	return;
}

void delete_first_element(long* array, int& length)
{
	for (int i = 0; i < length - 1; ++i) // move all elements to the left on 1 position
		array[i] = array[i + 1];

	--length;
}

bool is_more_than_three_dividers(long& input)
{
	int number_of_dividers = 2; // 1 and input are always dividers of input

	for (int d = 2; d < input; ++d)
	{
		if (input % d == 0) // if it divides by d
			++number_of_dividers;

		if (number_of_dividers > 3)
			return true;
	}

	return false;
}


int main1()
{
	long a = 6;
	cout << is_more_than_three_dividers(a);

	return 0;
}

int main()
{
	long list[max_len];
	int n;

	cout << "Please, enter size of input array: ";
	cin >> n;

	if (n > max_len)
	{
		cout << "That size is way bigger than max allowed size... Please, change max_len constant.";
		return 0;
	}

	cout << "Please, enter elements of input array:" << endl;

	fill_array(list, n);

	cout << "Creating second array..." << endl;

	long new_list[max_len];
	int new_n = 0;

	for (int i = 0; i < n; ++i)
	{
		if (is_prime(list[i]))
		{
			if (new_n == 0) // no elements yet
			{
				new_list[0] = list[i];
				new_n = 1;
			}
			else
			{
				insert_before(new_list, new_n, find_new_pos(new_list, new_n, list[i]), list[i]);
			}
		}
	}

	cout << "Sucessful! Second array is:" << endl;
	print_array(new_list, new_n);

	string start_string = "So, what are you gonna do?\n1 - Delete smaller element of second array\n2 - Count how many numbers in first array have more than three dividers?";

	while (true)
	{
		cout << start_string << endl;

		char tmp;

		cin >> tmp;

		if (tmp == '1')
		{
			delete_first_element(new_list, new_n);
			cout << "Successful! Now second array is:" << endl;
			print_array(new_list, new_n);
			cout << "Please, press enter to continue..." << endl;
		}
		
		if (tmp == '2')
		{
			int counter = 0;

			for (int i = 0; i < n; ++i)
			{
				if (is_more_than_three_dividers(list[i]))
					++counter;
			}
			
			cout << "Done! There are " << counter << " of them! Please, press enter to continue..." << endl;
		}

		cin.get();
		cin.get();
	}


	return 0;
}