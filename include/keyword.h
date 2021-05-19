#ifndef _KEYWORD_H
#define _KEYWORD_H

#include <iostream>
#include <array>
#include <cstdlib>
#include <string>
#include <locale>

#define ALPHABET 26

class keyword
{
    public:
        keyword(std::string &input, std::string &key);
        void encrypt();
        void decrypt();
        void abcrypt();
        void abcplain();
        void strip_double_char(std::string &input);
        std::string get_input() const;
    private:
        int code = 0, base_upper_code = 65, base_lower_code = 97;
        std::string input = "", temp = "", key = "";
        std::string upper_encrypting = "", lower_encrypting = "";
        std::string upper_plain = "", lower_plain = "";
};

#endif
