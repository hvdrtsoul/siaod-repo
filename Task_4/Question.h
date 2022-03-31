#ifndef __QUESTION_H__
#define __QUESTION_H__

#include <string>
#include <vector>

/*
Разработка тестовых вопросов. Структура записи вопроса: номер темы, текст вопроса, балл за правильный ответ, список вариантов ответов, номер правильного ответа.
По каждой теме вопросов 10 (это условно). 
Операции
1)	Заполнить запись по одному вопросу с клавиатуры.
2)	Вставить запись в таблицу, упорядочивая по номеру темы (сортировку не использовать).
3)	Сформировать тест, включая в него по два вопроса из каждой темы, выбранных случайно.
4)	Удалить вопросы по одной теме.
*/

struct Question{
    
    public:
        int theme_number;
        int reward;
        int right_answer;
        std::string question;
        std::vector<std::string> answers;

    Question()
    {
        return;
    }

    Question(int theme_number, int reward, int right_answer, std::string question, std::vector<std::string> answers)
    {
        this->theme_number = theme_number;
        this->reward = reward;
        this->right_answer = right_answer;
        this->question = question;
        this->answers = answers;

        return;
    }
    
};
#endif