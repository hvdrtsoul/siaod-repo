//	29 Поразрядная сортировка
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> generate_random_list(int seed, int size){
    srand(seed);
    vector<int> result;

    for(int i = 0;i < size;++i){
        result.push_back(rand()%500);
    }

    return result;
}


void radix_lsd_sort(vector<int> &input){ // с младшего разряда
    vector< vector<int> > digits(10, *new vector<int>);
    int current_raz = 1;
    while(true){

        for(int number : input){
            int digit = number % (int)pow(10, current_raz) / (int)pow(10, current_raz-1); // curren digit on that place
            digits[digit].push_back(number);
        }

        int current_pos = 0;
        for(int i = 0; i < 10; ++i){
            for(int number : digits[i]){
                input[current_pos] = number;
                ++current_pos;
            }
        }

        bool all_exept_zero_are_empty = true;

        for(int i = 0;i < 10;++i){
            if(!digits[i].empty() && i != 0)
                all_exept_zero_are_empty = false;
            digits[i].clear();
        }

        if(all_exept_zero_are_empty)
            break;
        
        ++current_raz;
    }

    return;
}


int main(){
    int seed, array_size;

    cout << "Please, input seed and array size:" << endl;
    cin >> seed >> array_size;

    vector<int> new_array = generate_random_list(seed, array_size);

    cout << "So, random array is:" << endl;

    for(int value : new_array){
        cout << value << ' ';
    }
    cout << endl;

    radix_lsd_sort(new_array);

    cout << "Done, sorted array is:" << endl;

    for(int value : new_array){
        cout << value << ' ';
    }
}