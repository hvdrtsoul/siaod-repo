//	29 Быстрая сортировка
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

void swap(vector<int> &input, int i, int j){
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

int partition(vector<int> &input, int left, int right){
    int x = input[left];
    int i = left;

    for(int j=left+1;j <= right;++j){
        if(input[j] <= x){
            ++i;
            swap(input, i, j);
        }
    }
    swap(input, i, left);

    return i;
}

void quick_sort(vector<int> &input, int i, int j){
    if(i < j){
        int r = partition(input, i, j);
        quick_sort(input, i, r-1);
        quick_sort(input, r+1, j);

        return;
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

    quick_sort(new_array, 0, new_array.size()-1);

    cout << "Done, sorted array is:" << endl;

    for(int value : new_array){
        cout << value << ' ';
    }
}