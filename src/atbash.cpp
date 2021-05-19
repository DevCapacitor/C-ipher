#ifndef _ATBASH_H
#include "atbash.h"
#endif

atbash::atbash(std::string &input)
{
    this->input = input;
    this->temp = input;
}

void atbash::encrypt()
{
    std::string &input = this->input;
    std::string &temp = this->temp;
    int &code = this->code;

    for (size_t num = 0;num < input.size();++num)
    {
        if ( islower(input[num]) )
            code = 97;
        else if ( isupper(input[num]) )
            code = 65;
        else
            continue;
        input[num] = (temp[num] + ALPHABET - (temp[num] - code) - (temp[num] - code) - 1);
    }
}

void atbash::decrypt()
{
    encrypt();
    encrypt();
}

std::string atbash::get_input() const
{
    return this->input;
}
