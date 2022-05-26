#include <iostream>
#include <vector>

using namespace std;

vector<int> countPrefixFunction(string input){
    int n = input.length();
    vector<int> result(n);

    for(int i = 1;i < n;++i){
        int j = result[i-1];
        while(j > 0 && input[i] != input[j])
            j = result[j-1];
        if(input[i] == input[j])
            ++j;
        result[i] = j;
    }

    return result;
}

vector<int> countAppears(string text, string candidate, char delimiter){
    string buffer = candidate + delimiter + text;
    vector<int> prefixFunction = countPrefixFunction(buffer);

    int n = candidate.length();
    vector<int> result;

    for(int i = 0;i < buffer.length();++i){
        if(prefixFunction[i] == n)
            result.push_back(i-2*n);
    }

    return result;
}

int main(){
    cout << "Please, input error log:" << endl;
    string errorLog;
    getline(cin,errorLog);

    cout << "Please, input cash register number" << endl;
    string cashNumber;
    cin >> cashNumber;

    vector<int> appearances = countAppears(errorLog, cashNumber, '!');
    
    cout << "This cash register did " << appearances.size() << " operations";
}