#include <iostream>
#include <regex>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Please input text with groups:" << endl;
    string text;
    getline(cin, text);

    const regex r("И[К,Н,В]БО");

    cout << "So, after renaming the text is:" << endl;
    cout << regex_replace(text, r, "ИИБО");

    return 0;
}