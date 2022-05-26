// 29 Поиск с применением цепного хеширования 
// Счет в банке: номер счета - 7 разрядное число, ФИО, Адрес

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct Node{
    int accountNumber;
    string name;
    string adress;
};

class HashTable{

public:
    HashTable();
    void insertNode(Node toInsert);
    bool findNode(Node toFind);
    vector<vector<Node>> table;

private:
    const int tableSize = 1000;
    const int hashPrime = 17;
    long long hash(Node toHash);
    
};

HashTable::HashTable(){
    table = vector<vector<Node> >(tableSize, *new vector<Node>);
}

long long HashTable::hash(Node toHash){
    string stringToHash = toHash.name + toHash.adress; // concatenate
    
    long long result = 0;
    long long nowPrime = hashPrime;

    for(char symbol : stringToHash){
        result += (nowPrime * (int)symbol) % tableSize;
        nowPrime *= hashPrime;
    }

    result += (toHash.accountNumber * hashPrime) % tableSize;

    result = result % tableSize;

    return result;
}

void HashTable::insertNode(Node toInsert){
    table[hash(toInsert)].push_back(toInsert);
}

bool HashTable::findNode(Node toFind){
    for(Node candidate : table[hash(toFind)]){
        if(candidate.accountNumber == toFind.accountNumber &&
            candidate.adress == toFind.adress &&
            candidate.name == toFind.name)
            return true;
    }
    return false; // if nothing found
}


string generateRandomName(){
    //srand(time(NULL));
    string result = "";
    int nameLength = rand() % 10 + 5;

    result += char('A' + rand()%26);

    for(int i = 0;i < nameLength;++i){
        result += char('a' + rand()%26);
    }

    return result;
}

string generateRandomAdress(){
    //srand(time(NULL));
    string result = "";
    int streetLength = rand() % 10 + 5;

    result += char('A' + rand()%26);

    for(int i = 0;i < streetLength;++i){
        result += char('a' + rand()%26);
    }

    result += " st. ";
    result += to_string(rand()%99);

    return result;
}

int main(){
    srand(time(NULL));
    HashTable hashTable;
    int n;
    cout << "Hi. How many accounts you wish to add?" << endl;
    cin >> n;

    Node toRemember;

    cout << "#\tName\tAdress" << endl;
    for(int i = 0;i < n;++i){
        Node toAdd;
        toAdd.accountNumber = rand() % 9999;
        toAdd.adress = generateRandomAdress();
        toAdd.name = generateRandomName();

        cout << toAdd.accountNumber << '\t' << toAdd.name << '\t' << toAdd.adress << endl;
        
        hashTable.insertNode(toAdd);

        if(i == n-1)
            toRemember = toAdd;
    }

    int number;
    string name, adress;
    cout << "Please enter account number, name for the account you wish to find:" << endl;
    cin >> number >> name;
    getline(cin, adress);
    cout << "Okay. Now input the adress:" << endl;
    getline(cin, adress);

    Node toFind;
    toFind.accountNumber = number;
    toFind.name = name;
    toFind.adress = adress;

    if(hashTable.findNode(toFind))
        cout << "Found...";
    else
        cout << "Not found...";
}

