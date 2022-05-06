/*
Организовать ввод-вывод последовательности n целых чисел, с применением рекурсии.
Числа должны выводится с порядковыми номерами и в том же порядке, в каком производился их ввод.
Использование массивов не разрешается.
*/
#include <iostream>
#include <string>

using namespace std;

string in_out(string current_string, int current_depth, int max_depth)
{
    if(current_depth > max_depth)
        return current_string;
    else
    {
        string current_number;

        cin >> current_number;

        current_string += to_string(current_depth) + ' ';

        current_string += current_number;

        if(current_depth != max_depth)
            current_string += '\n';

        return in_out(current_string, current_depth + 1,max_depth);
    }
}


int main()
{

    int n;

    cin >> n;

    cout << in_out("", 1, n);

    return 0;
}