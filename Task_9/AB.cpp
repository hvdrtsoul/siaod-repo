// 29 линейный поиск и поиск с барьером
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

bool linearSearch(vector<Node> input, Node toFind){
    for(Node candidate : input){
        if(candidate.accountNumber == toFind.accountNumber &&
            candidate.adress == toFind.adress &&
            candidate.name == toFind.name)
            return true;
    }
    return false; // if nothing found
}

bool barrierSearch(vector<Node> input, Node toFind){
    Node errorNode;
    errorNode.accountNumber = -1;
    errorNode.name = "ERROR";
    errorNode.adress = "ERROR";

    input.push_back(errorNode);
    int i = 0;

    while(input[i].accountNumber != -1  && (input[i].accountNumber != toFind.accountNumber &&
        input[i].adress != toFind.adress && input[i].name != toFind.name))
        ++i;

    if(input[i].accountNumber == toFind.accountNumber &&
        input[i].adress == toFind.adress && input[i].name == toFind.name)
        return true;
    else
        return false;
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
    vector<Node> nodes;
    int n;
    cout << "Hi. How many accounts you wish to add?" << endl;
    cin >> n;

    cout << "#\tName\tAdress" << endl;
    for(int i = 0;i < n;++i){
        Node toAdd;
        toAdd.accountNumber = rand() % 9999;
        toAdd.adress = generateRandomAdress();
        toAdd.name = generateRandomName();

        cout << toAdd.accountNumber << '\t' << toAdd.name << '\t' << toAdd.adress << endl;
        
        nodes.push_back(toAdd);
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

    if(linearSearch(nodes, toFind))
        cout << "Found by linear search..." << endl;
    else
        cout << "Not found by linear search..." << endl;

    if(barrierSearch(nodes, toFind))
        cout << "Found by barrier search...";
    else
        cout << "Not found by barrier search...";
}