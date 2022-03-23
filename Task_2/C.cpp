#include <iostream>
#include <vector>

using namespace std;

class Line
{
public:
    int type; // 0 -> y = b; 1 -> x = b; 2 -> y = kx+b
    double k, b;

    vector<int> first_dot, second_dot;

    Line(vector<int> first_dot, vector<int> second_dot)
    {
        if(first_dot[1] == second_dot[1]) // y1 == y2
        {
            type = 0;
            b = first_dot[1];

            this->first_dot = first_dot;
            this->second_dot = second_dot;
        }
        else if(first_dot[0] == second_dot[0]) // x1 == x2
        {
            type = 1;
            b = first_dot[0];

            this->first_dot = first_dot;
            this->second_dot = second_dot;
        }
        else // there's no situation where first_dot == second_dot
        {
            type = 2;
            k = (double)(first_dot[1] - second_dot[1])/(first_dot[0] - second_dot[0]);
            b = (double)second_dot[1] - second_dot[0]*k;

            this->first_dot = first_dot;
            this->second_dot = second_dot;
        }
        
        return;
    }

    bool is_medium(vector< vector<int> > &dots)
    {
        int first_group = 0, second_group = 0;

        for(vector<int> dot : dots)
        {
            if(dot == first_dot || dot == second_dot)
                continue; // this dot creates this line

            if(type == 0) // y = b
            {
                if(dot[1] > b)
                    ++first_group;
                else
                    ++second_group;
            }
            else if(type == 1) // x = b
            {
                if(dot[0] > b)
                    ++first_group;
                else
                    ++second_group;
            }
            else // y = kx+b
            {
                if(dot[1] > k*dot[0]+b)
                    ++first_group;
                else
                    ++second_group;
            }
        }

        return first_group == second_group;
    }

};

ostream& operator<<(ostream &os, const Line &l)
    {
        if(l.type == 0) // y = b
            return os << "y = " << l.b;
        else if(l.type == 1) // x = b
            return os << "x = " << l.b;
        else
            return os << "y = " << l.k << "x + " << l.b;
    }

int main()
{
    int number;

    cout << "Please, input the number of the dots: ";
    cin >> number;

    vector< vector<int> > dots(number, vector<int>(2));

    cout << "Good! Now, enter all the dots line by line (x y):" << endl;

    for(int i = 0;i < number;++i)
    {
        cin >> dots[i][0] >> dots[i][1];
    }

    for(int i = 0;i < number;++i)
        for(int j = i+1;j < number;++j)
        {
            Line temp_line(dots[i], dots[j]);

            if(temp_line.is_medium(dots))
            {
                cout << "MEDIAN FOUND: " << temp_line << endl;
                // cout << "DOTS ARE: " << dots[i][0] << ':' << dots[i][1] << ' ' << dots[j][0] << ':' << dots[j][1];
                
                return 0;
            }
        }


    cout << "MEDIAN WASN'T FOUND";

    return 0;
}