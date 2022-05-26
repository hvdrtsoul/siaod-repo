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
    setlocale(LC_ALL, "Russian");
    cout << "Please input text with groups:" << endl;
    string text;
    getline(cin, text);

    vector<int> appearances1 = countAppears(text, "ИКБО", '|');
    vector<int> appearances2 = countAppears(text, "ИНБО", '|');
    vector<int> appearances3 = countAppears(text, "ИВБО", '|');

    for(int appearancePos : appearances1)
        cout << appearancePos << endl;

    for(int appearancePos : appearances1)
        text[appearancePos+1] = 'И';

    for(int appearancePos : appearances2)
        text[appearancePos+1] = 'И';

    for(int appearancePos : appearances3)
        text[appearancePos+1] = 'И';

    cout << "So, after renaming the text is:" << endl;
    cout << text;

    return 0;
}