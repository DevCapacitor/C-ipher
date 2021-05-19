#ifndef _AFFINE_H
#define _AFFINE_H

#include <iostream>
#include <locale>
#include <cctype>

#define CODE 65
#define ALPHABET 26

class affine
{
    public:
        affine(std::string &input, int &a, int &b);
        void encrypt();
        void decrypt();
        std::string get_input() const;
    private:
        int a = 0, b = 0;
        std::string input = "", temp = "";
};

#endif /* _ALFFINE_H */
