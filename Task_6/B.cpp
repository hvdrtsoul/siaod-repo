/*
Дан линейный однонаправленный список.
Сформировать новый список из нечетных значений исходного.
Порядок следования значений в узлах нового списка соответствует порядку следования значений в исходном списке.
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;


class Node{
public:    
    int value;
    Node* next;

    Node(int new_value){
        this->value = new_value;
    }

};


void generate_list(vector<int> &values, int current_pos, Node* last_node){

    if(current_pos == values.size()){
        last_node->next = nullptr;
        return;
    }

    Node* new_node = new Node(values[current_pos]);
    last_node->next = new_node;

    generate_list(values, current_pos + 1, new_node);
    
    return;
}

int get(list<int> &input, int index){

    list<int>::iterator result = input.begin();

    for(int i = 0;i < index;++i)
        ++result;

    return *result;
}



int main()
{
    int seed;
    list<int> first_list;
    vector<int> good_list;

    cout << "ENTER SEED: ";
    cin >> seed;
    srand(seed);

    for(int i = 0;i < 20;++i){
        first_list.push_back(rand()%500);
    }

    cout << "FIRST LIST: " << endl;

    for(int v: first_list)
    {
        cout << v << ' ';
    
        if(v % 2 == 0)
            good_list.push_back(v);
    }

    cout << endl;

    if(good_list.size() == 0){
        cout << "NO EVEN VALUES, GOODBYE";
        return 0;
    }

    Node* head = new Node(good_list[0]);

    generate_list(good_list, 1, head);

    Node* current_node = head;

    cout << "NEW LIST IS HERE:" << endl;

    while(current_node != nullptr){
        cout << current_node->value << ' ';
        current_node = current_node->next;
    }
    

    return 0;
}