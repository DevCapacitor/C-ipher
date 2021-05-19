#ifndef _SCYTALE_H
#include "scytale.h"
#endif

scytale::scytale(std::string &input, int &diameter)
{
    this->input = input;
    this->temp = this->input;
    this->d = diameter;
}

void scytale::calculate_lines()
{
    std::string &input = this->input;
    int counter = 0;
    int counter2 = 0;
    for (size_t x = 0;x < input.size();++x)
    {
        if (counter == (this->d))
        {
            counter = 0;
            ++counter2;
        }
        counter++;
    }
    ++counter2;
    this->lines = counter2;
}

void scytale::encrypt()
{
    size_t angka = 0;
    int &lines = this->lines;
    int &d = this->d;
    std::string &input = this->input;
    std::string &temp = this->temp;
    std::vector<int> vecc;
    vecc.reserve(input.size());
    for (size_t y = 0;y < input.size();++y)
    {
        angka =  y;
        vecc.push_back(angka);
        angka = y + d;
        vecc.push_back(angka);
        for (int x = 0;x < (lines - 2);++x)
        {
            angka = angka + d;
            vecc.push_back(angka);
        }
        if (angka == input.size())
            break;
    }
    for (size_t i = 0;i < input.size();++i)
        input[i] = temp[vecc[i]];
    vecc.clear();
}

void scytale::decrypt()
{
    size_t angka = 0;
    int &d = this->lines;
    int &lines = this->d;
    std::string &input = this->input;
    std::string &temp = this->temp;
    std::vector<int> vec;
    vec.reserve(input.size());
    for (size_t y = 0;y < input.size();++y)
    {
        angka =  y;
        vec.push_back(angka);
        angka = y + d;
        vec.push_back(angka);
        for (int x = 0;x < (lines - 2);++x)
        {
            angka = angka + d;
            vec.push_back(angka);
        }
        if (angka == input.size())
            break;
    }
    for (size_t i = 0;i < input.size();++i)
        input[i] = temp[vec[i]];
    vec.clear();
}


std::string scytale::get_input() const
{
    return this->input;
}
