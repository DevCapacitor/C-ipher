#ifndef _CAESAR_H
#define _CAESAR_H

#include <iostream>
#include <locale>

class caesar
{
    public:
        caesar(std::string &input, int &shift);
        void encrypt();
        void decrypt();
        std::string get_input() const;
    private:
        std::string input = "", temp = "";
        int shift_count = 0;
};

#endif //CAESAR_H
