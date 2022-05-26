#include <iostream>
#include <vector>

using namespace std;


/*
    Вариант: 17
    Постфиксная-Массив-Вычислить значение выражения
*/

/*
Алгоритм вычисления постфиксной формы записи из инфиксной:
К формуле на входе (в конец записи) и на вершину стека добавляем остановочный оператор – %;
Поэлементно слева направо идем по формуле;
Операнды переходят в результат;
Левые круглые скобки толкаем(push) в стек;
Встретив правую круглую скобку, выталкиваем(pop) из стека все операторы пока не встретим левую скобку;
Если оператор имеет более высокий приоритет вычисления, чем оператор на вершине стека, то оператор толкаем в стек;
Если оператор имеет равный или меньший приоритет вычисления, чем оператор на вершине стека, то выталкиваем оператор из стека в результат, и толкаем в стек новый оператор;
Достигнув на входе % – остановочный оператор, выталкиваем все из стека, пока не дойдем до %.
*/

class Stack{
public:
    vector<int> values;
    
    void push(int x){
        values.push_back(x);
    }

    int pop(){
        int to_return = values[values.size()-1];
        values.pop_back();
        return to_return;
    }
};

int main() {
    string input;
    Stack num;
    cout << "Input:";
    cin >> input;
    for (int i = 0; i < input.length(); ++i) {
        if (string("0123456789").find(input[i]) != string::npos)
            num.push(input[i] - '0');
        else {
            int a = num.pop();
            int b = num.pop();
            switch (input[i]) {
                case ('*'):
                    num.push(a * b);
                    break;
                case ('/'):
                    num.push(b / a);
                    break;
                case ('+'):
                    num.push(a + b);
                    break;
                case ('-'):
                    num.push(b - a);
                    break;
                default:
                    break;
            }
        }
        for (auto elem: num.values)
            cout << elem << ' ';
        cout << endl;
    }
    cout << "Result: " << num.pop();
}