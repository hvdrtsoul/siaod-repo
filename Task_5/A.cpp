/*
13	int	Дан массив из n указателей на вершины списков. Структура узла списка содержит ключ (информационная часть узла) и ссылку на следующий узел.
1)	Разработать функцию, которая вставляет переданный в качестве параметра ключ в i-ый список массива. Индекс i определяется по правилу: i=key%n. Некоторые элементы массива могут остаться nullptr.
2)	Разработать функцию, которая удаляет значение ключа из списка.
3)	Разработать функцию, которая находит узел со значением ключа и возвращает указатель на найденный узел.
*/

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

struct Node{
    int key;
    Node* next = nullptr;

    Node(int key){
        this->key = key;
    }

};

struct List{
    Node* head=nullptr;

    void push_back(int input){
        
        Node *current_node = head;

        while(current_node->next != nullptr){ // while it's not the last element in list
            current_node = current_node->next;
        } 

        current_node->next = new Node(input);


        return;
    }

    Node* find_node_by_key(int key){
        Node *current_node = head;

        while(current_node != nullptr && current_node->key != key){
            current_node = current_node->next;
        }

        return current_node; // it's nullptr if node by key is not found
    }

    void remove_all_nodes_with_key(int key){
        
        while(head->key == key){
            Node *to_delete = head;
            head = head->next;
            delete to_delete;
        }

        // from there head is DEFINETELY not key

        for(Node* current_node = head;current_node != nullptr;current_node = current_node->next){
            while(current_node->next->key == key){
                Node *to_delete = current_node->next;
                current_node->next = current_node->next->next;
                delete to_delete;
            }            
        }

        return;
    }
};

void insert_key_to_array(int key, vector<List> &array){
    array[key%array.size()].push_back(key);
    return;
}

int main()
{
    vector<List> lists;

    for(int i = 0;i < 10;++i) // creating 10 lists
        lists.push_back(*new List());


    for(int i = 1;i < 810;i += ((int)pow(i, 3))%3){
        cout << i << endl;
        cout << "INSERTING " << i << endl;
        insert_key_to_array(i, lists);
    }


    // delete 505 key from each list:

    for(int i = 0;i < lists.size();++i){
        lists[i].remove_all_nodes_with_key(505);
    }

    // find all nodes adresses with key 404:

    for(int i = 0;i < lists.size();++i){
        cout << "ADRESS FOUND: " << lists[i].find_node_by_key(404) << endl;
    }

    return 0;
}