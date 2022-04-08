#ifndef __TABLEB_H__
#define __TABLEB_H__

#include "ThemeA.h"
#include <set>

const int START_THEMES_COUNT = 1000;

struct Table{

    public:
        set<int> theme_numbers;
        Theme *themes;
        int got_themes = 0;

    Table()
    {
        themes = new Theme[START_THEMES_COUNT];
    }

    int find_theme_number(int &theme_number)
        {
            for(int i = 0;i < got_themes;++i)
            {
                if(themes[i].number == theme_number)
                    return i;
            }

            return -1;
        }

        void delete_element(int &number)
        {
            for(int i = number; i < got_themes-1;++i)
            {
                themes[i] = themes[i+1];
            }

            --got_themes;

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
            themes[got_themes] = *new Theme();
            themes[got_themes].number = input.theme_number;
            themes[got_themes].add_question(input);
            ++got_themes;
        }

        return;
    }

    vector<Question> create_test()
    {
        vector<Question> result;

        for(int i = 0;i < got_themes;++i)
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