#include <iostream>
#include <vector>

using namespace std;

void fill_array(vector<long>& array, int& len)
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

int find_new_pos(vector<long>& array, int length, long& number) // first greater or -1 if already found
{
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == number)
			return -1;
		if (array[i] > number)
			return i;
	}

	return length; // if there are no greater elements, insert in the end
}

void print_array(vector<long>& array, int length)
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

void delete_first_element(vector<long>& array, int length)
{
	if (length <= 0)
		return;

	array.erase(array.begin());

	return;
}

void insert_before(vector<long>& array, int length, int before_element, long& new_element)
{
	if (before_element == -1) // if we are not inserting any element
		return;

	array.insert(array.begin() + before_element, new_element);

	return;
}

int main()
{
	int n;

	cout << "Please, enter size of input array: ";
	cin >> n;

	vector<long> list(n);

	cout << "Please, enter elements of input array:" << endl;

	fill_array(list, n);

	print_array(list, n);

	cout << "Creating second array..." << endl;

	vector<long> new_list;

	for (int i = 0; i < n; ++i)
	{
		if (is_prime(list[i]))
		{
			if (new_list.size() == 0) // no elements yet
			{
				new_list.push_back(list[i]);
			}
			else
			{
				insert_before(new_list, new_list.size(), find_new_pos(new_list, new_list.size(), list[i]), list[i]);
			}
		}
	}

	cout << "Sucessful! Second array is:" << endl;
	print_array(new_list, new_list.size());

	string start_string = "So, what are you gonna do?\n1 - Delete smaller element of second array\n2 - Count how many numbers in first array have more than three dividers?";

	while (true)
	{
		system("cls");
		cout << start_string << endl;

		char tmp;

		cin >> tmp;

		if (tmp == '1')
		{
			delete_first_element(new_list, new_list.size());
			cout << "Successful! Now second array is:" << endl;
			print_array(new_list, new_list.size());
			cout << "Please, press enter to continue..." << endl;
		}

		if (tmp == '2')
		{
			int counter = 0;

			for (int i = 0; i < list.size(); ++i)
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