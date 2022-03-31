#ifndef __THEME_H__
#define __THEME_H__

#include "Question.h"
#include <cstdlib>
#include <ctime>

const int MAX_QUESTIONS_COUNT = 1000;

struct Theme{

    public:
        int number;
        int got_questions = 0;
        Question questions[MAX_QUESTIONS_COUNT];

    std::pair<Question, Question> get_two_random_questions()
    {
        std::srand(std::time(0));
        int first_number = std::rand() % number;
        int second_number = first_number;

        while(second_number == second_number)
            second_number = rand() % number;

        return std::make_pair(questions[first_number], questions[second_number]);
    }

    bool add_question(Question &input)
    {
        questions[got_questions] = input;
        
        ++got_questions;
    }
};

#endif