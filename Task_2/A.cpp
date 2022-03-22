#include <iostream>

using namespace std;

/*
Дана квадратная матрица. Проверить, что в данной матрице произведение элементов, 
стоящих над побочной диагональю, равно произведению элементов, стоящих над главной диагональю
*/

const int Rows = 100;

int main()
{
    int data[Rows][Rows];
    int current_rows;

    cout << "Please, input size of the matrix: ";
    cin >> current_rows;

    cout << "Please input your matrix row by row:" << endl;

    for(int i = 0;i < current_rows;++i)
        for(int j = 0;j < current_rows;++j)
            cin >> data[i][j];

    int main_production = 1, second_production = 1;

    for(int i = 0;i < current_rows;++i)
    {
        bool reached_main = false, reached_second = false;

        for(int j = 0;j < current_rows;++j)
        {
            if(i + j == current_rows - 1) // if it's the second diag
                reached_second = true;

            if(reached_main)
                main_production *= data[i][j];
            
            if(!reached_second)
                second_production *= data[i][j];

            if(i == j) // if it's the main diag
                reached_main = true;
        }    
    }

    cout << ( (main_production == second_production)?"YES":"NO" );

    return 0;           
}