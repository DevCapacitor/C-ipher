#ifndef _CAESAR_H
#include "caesar.h"
#endif

caesar::caesar(std::string &input, int &shift)
{
    this->input = input;
    this->temp = input;
    this->shift_count = shift;
}

void caesar::encrypt()
{
    std::string &input = this->input;
    std::string &temp = this->temp;
    int &shift_count = this->shift_count;

    for (size_t var = 0;var < input.size();++var)
        if ( isalpha(input[var]) )
            if ( (temp[var] + shift_count) > 122 )
                input[var] = ((temp[var] - 25) + (shift_count - 1));
            else
                input[var] = ((temp[var] + shift_count));
        else
            continue;
}

void caesar::decrypt()
{
    std::string &input = this->input;
    std::string &temp = this->temp;
    int &shift_count = this->shift_count;

    for (size_t var = 0;var < input.size();++var)
        if ( isalpha(input[var]) )
            if ( (temp[var] - shift_count) < 97 )
                input[var] = ((temp[var] + 25) - (shift_count + 1) + 2);
            else
                input[var] = ((temp[var] - shift_count));
        else
            continue;
}

std::string caesar::get_input() const
{
    return this->input;
}
