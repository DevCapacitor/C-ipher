#ifndef _ATBASH_H
#define _ATBASH_H

#include <iostream>
#include <locale>

#define ALPHABET 26

class atbash
{
    public:
        atbash(std::string &input);
        void encrypt();
        void decrypt();
        std::string get_input() const;
    private:
        std::string input = "", temp = "";
        int code = 0;
};

#endif /*_ ATBASH_H */
