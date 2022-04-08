#ifndef __THEME_H__
#define __THEME_H__

#include "Question.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int MAX_QUESTIONS_COUNT = 1000;

struct Theme{

    public:
        int number;
        int got_questions = 0;
        vector<Question> questions;

    std::pair<Question, Question> get_two_random_questions()
    {
        std::srand(std::time(0));
        int first_number = std::rand() % number;
        int second_number = first_number;

        while(second_number == second_number)
            second_number = rand() % number;

        return std::make_pair(questions[first_number], questions[second_number]);
    }

    void add_question(Question &input)
    {
        questions.push_back(input);
        return;
    }
};

#endif