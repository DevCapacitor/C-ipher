#include "keyword.h"

keyword::keyword(std::string &input, std::string &key)
{
    this->input = input;
    this->temp = input;
    this->key = key;
}

void keyword::strip_double_char(std::string &input)
{
    for (size_t i = 0;i < input.size();++i)
        for (size_t x = (i+1);x < input.size();++x)
            if (input[i] == input[x])
                for (size_t y = i;y < input.size();++y)
                    input[x] = input[x+1];
}

void keyword::abcrypt()
{
    std::string &lower_key = this->key;
    std::string &upper_encrypting = this->upper_encrypting;
    std::string &lower_encrypting = this->lower_encrypting;
    std::string upper_key = "";
    int &base_upper_code = this->base_upper_code;
    int &base_lower_code = this->base_lower_code;
    for (size_t i = 0;i < lower_key.size();++i)
        if (islower(lower_key[i]))
            upper_key.push_back(toupper(lower_key[i]));
    for (size_t i = 0;i < ALPHABET;++i)
        upper_encrypting.push_back(static_cast<char>(base_upper_code + i));
    for (size_t i = 0;i < ALPHABET;++i)
        lower_encrypting.push_back(static_cast<char>(base_lower_code + i));
    strip_double_char(key);

    for (size_t i = 0;i < upper_encrypting.size();++i)
        for (size_t x = 0;x < upper_key.size();++x)
            if (upper_encrypting[i] == upper_key[x])
                for (size_t y = i;y < upper_encrypting.size();++y)
                    upper_encrypting[y] = upper_encrypting[y+1];
    upper_encrypting.insert(0, upper_key);
    for (size_t i = 0;i < upper_encrypting.size();++i)
        if (upper_encrypting[i] == '\0')
            for (size_t x = i;x < upper_encrypting.size();++x)
                upper_encrypting[x] = upper_encrypting[x+1];
    strip_double_char(upper_encrypting);

    for (size_t i = 0;i < lower_encrypting.size();++i)
        for (size_t x = 0; x < lower_key.size(); ++x)
            if (lower_encrypting[i] == lower_key[x])
                for (size_t y = i;y < lower_encrypting.size();++y)
                    lower_encrypting[y] = lower_encrypting[y+1];
    lower_encrypting.insert(0, lower_key);
    for (size_t i = 0;i < lower_encrypting.size();++i)
        if (lower_encrypting[i] == '\0')
            for (size_t x = i;x < lower_encrypting.size();++x)
                lower_encrypting[x] = lower_encrypting[x+1];
    strip_double_char(lower_encrypting);
}

void keyword::abcplain()
{
    std::string &upper_plain = this->upper_plain;
    std::string &lower_plain = this->lower_plain;
    int &base_upper_code = this->base_upper_code;
    int &base_lower_code = this->base_lower_code;
    for (size_t i = 0;i < ALPHABET;++i)
        upper_plain.push_back(static_cast<char>(base_upper_code + i));
    for (size_t i = 0;i < ALPHABET;++i)
        lower_plain.push_back(static_cast<char>(base_lower_code + i));
}

void keyword::encrypt()
{
    std::string &input = this->input;
    std::string &temp = this->temp;
    std::string &upper_encrypting = this->upper_encrypting;
    std::string &lower_encrypting = this->lower_encrypting;
    int &code = this->code;
    for (size_t i = 0;i < input.size();++i)
    {
        if ( isupper(input[i]) )
            code = 65;
        else if ( islower(input[i]) )
            code = 97;
        else
            continue;
        temp[i] = temp[i] - code;
    }
    for (size_t i = 0;i < input.size();++i)
        if ( isupper(input[i]) )
            input[i] = upper_encrypting[temp[i]];
        else if ( islower(input[i]) )
            input[i] = lower_encrypting[temp[i]];
        else
            continue;
}

void keyword::decrypt()
{
    std::string &input = this->input;
    std::string &temp = this->temp;
    std::string &upper_plain = this->upper_plain;
    std::string &lower_plain = this->lower_plain;
    std::string &upper_encrypting = this->upper_encrypting;
    std::string &lower_encrypting = this->lower_encrypting;
    for (size_t i = 0;i < input.size();++i)
        if ( isupper(input[i]) )
            input[i] = upper_plain[upper_encrypting.find(temp[i])];
        else if ( islower(input[i]) )
            input[i] = lower_plain[lower_encrypting.find(temp[i])];
        else
            continue;
}

std::string
keyword::get_input() const
{
    return this->input;
}
