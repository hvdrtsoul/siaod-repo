#include "stdio.h"
#include <string>
#include <cstring>
#include <set>
using namespace std;

/*
Дан текст, содержащий слова, которые разделены пробелами. 
Сформировать массив слов. Найти самое длинное слово, в котором все буквы различны. 
Например, лейкопластырь, неряшливость, четырёхдюймовка.
*/

const int MAX_STR_LEN = 1024;
const int MAX_ARRAY_SIZE = 100;

int is_special(char *word) // returns len
{
    set<char> letters;
    int i = 0;

    for(i = 0;word[i] != '\0';++i)
    {
        if(letters.find(word[i]) == letters.end()) // there are no such letter in leters
            letters.insert(word[i]);
        else
            return -1;
    }

    return i+1;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char line[MAX_STR_LEN];
    
    char lines[MAX_ARRAY_SIZE][MAX_STR_LEN];
    fgets(line, MAX_STR_LEN, stdin);

    int current_word = 0;
    int current_tmp_pos = 0;
    char tmp_line[MAX_STR_LEN];

    char coolest_word[MAX_STR_LEN];
    int coolest_word_len = 0;

    for(int i = 0;line[i] != '\0';++i)
    {
        if(line[i] == ' ' || line[i+1] == '\0')
        {
            strcpy(lines[current_word], tmp_line);
            memset(tmp_line,' ', current_tmp_pos+1);

            int special_len = is_special(lines[current_word]);

            if(special_len != -1 && special_len > coolest_word_len)
            {
                //printf("FOUND COOL WORD %s", lines[current_word]);
                strcpy(coolest_word, lines[current_word]);
                coolest_word_len = special_len;
            }
            ++current_word;
            current_tmp_pos = 0;


        }
        else
        {
            tmp_line[current_tmp_pos] = line[i];
            ++current_tmp_pos;
        }
    }

    printf("THE COOLEST WORD IS: %s", coolest_word);

    return 0;
}