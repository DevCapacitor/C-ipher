#ifndef _AFFINE_H
#include "affine.h"
#endif

affine::affine(string &input, int &a, int &b)
{
    this->input = input;
    this->temp = this->input;
    for (size_t i = 0;i < this->input.size();++i)
        if ( isalpha(this->input[i]) )
        {
            if ( islower(this->input[i]) )
                this->input[i] = toupper(this->temp[i]);
        }
        else
            continue;
    this->temp = this->input;
    this->a = a;
    this->b = b;
}

void
affine::encrypt()
{
    int &a = this->a;
    int &b = this->b;
    std::string &input = this->input;
    std::string &temp = this->input;

    for (size_t i = 0;i < input.size();++i)
        if ( isalpha(input[i]) )
            input[i] = ((a * (temp[i] - CODE) + b) % ALPHABET) + CODE;
        else
            continue;

    for (size_t i = 0;i < input.size();++i)
        if ( isupper(input[i]) )
        {
            input[i] = tolower(input[i]);
            temp[i] = input[i];
        }
}

void
affine::decrypt()
{
    int &a = this->a;
    int &b = this->b;
    std::string &input = this->input;
    std::string &temp = this->temp;

    int flag, a_inv;

    for (int i = 0;i < ALPHABET;++i)
    {
        flag = (a * i) % ALPHABET;
        if ( flag == 1 )
            a_inv = i;
    }

    for (size_t i = 0;i < input.size();++i)
        if ( isalpha(input[i]) )
            input[i] = (a_inv * ( (temp[i] + CODE) - b ) % ALPHABET) + CODE;
        else
            continue;
    for (size_t i = 0;i < input.size();++i)
        if ( isupper(input[i]) )
        {
            input[i] = tolower(input[i]);
            temp[i] = input[i];
        }
}

std::string
affine::get_input() const
{
    return this->input;
}
