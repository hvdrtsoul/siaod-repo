#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

/*
Дан текст, содержащий слова, которые разделены пробелами. 
Сформировать массив слов. Найти самое длинное слово, в котором все буквы различны. 
Например, лейкопластырь, неряшливость, четырёхдюймовка.
*/

int is_special(string word) // returns len
{
    set<char> letters;

    for(int i = 0;i < word.length();++i)
    {
        if(letters.find(word[i]) == letters.end()) // there are no such letter in leters
            letters.insert(word[i]);
        else
            return -1;
    }

    return word.length();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string line;
    vector<string> lines;
    
    cin >> line;

    string tmp_line = "";

    string coolest_word;

    for(int i = 0;line[i] != '\0';++i)
    {
        if(line[i] == ' ' || line[i+1] == '\0')
        {
            lines.push_back(tmp_line);
            tmp_line = "";

            int special_len = is_special(lines.back());

            if(special_len != -1 && special_len > coolest_word.length())
            {
                //printf("FOUND COOL WORD %s", lines[current_word]);
                coolest_word = lines.back();
            }
        }
        else
        {
            tmp_line += line[i];
        }
    }
    
    cout << "THE COOLEST WORD IS: " << coolest_word;

    return 0;
}