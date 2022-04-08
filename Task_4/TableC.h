#ifndef __TABLEA_H__
#define __TABLEA_H__

#include "ThemeA.h"
#include <set>
#include <vector>

const int MAX_THEMES_COUNT = 1000;

struct Table{

    public:
        set<int> theme_numbers;
        vector<Theme> themes;

    int find_theme_number(int &theme_number)
        {
            for(int i = 0;i < themes.size();++i)
            {
                if(themes[i].number == theme_number)
                    return i;
            }

            return -1;
        }

        void delete_element(int &number)
        {
            themes.erase(themes.begin() + find_theme_number(number));

            return;
        }

    void add_question(Question &input)
    {
        if(theme_numbers.find(input.theme_number) != theme_numbers.end())
        {
            themes[find_theme_number(input.theme_number)].add_question(input);
        }
        else
        {
            theme_numbers.insert(input.theme_number);
            themes.push_back(*new Theme());
            themes[themes.size()-1].number = input.theme_number;
            themes[themes.size()-1].add_question(input);
        }

        return;
    }

    vector<Question> create_test()
    {
        vector<Question> result;

        for(int i = 0;i < themes.size();++i)
        {
            pair<Question, Question> two_questions = themes[i].get_two_random_questions();

            result.push_back(two_questions.first);
            result.push_back(two_questions.second);
        }

        return result;
    }

    void delete_theme(int &theme_number)
    {
        int theme_id = find_theme_number(theme_number);
        delete_element(theme_id);
        
        return;
    }
        
    

     
};

#endif