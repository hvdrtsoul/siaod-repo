// 29	Простой вставки
#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_random_list(int seed, int size){
    srand(seed);
    vector<int> result;

    for(int i = 0;i < size;++i){
        result.push_back(rand()%500);
    }

    return result;
}

void simple_insertion_sort(vector<int> &input){
    for(int i = 0;i < input.size();++i){
        int key = input[i];
        int j = i-1;
        for(;input[j] > key && j >= 0;--j){
            input[j+1] = input[j];
        }
        input[j+1] = key;
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

    simple_insertion_sort(new_array);

    cout << "Done, sorted array is:" << endl;

    for(int value : new_array){
        cout << value << ' ';
    }
}