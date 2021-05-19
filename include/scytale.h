#ifndef _SCYTALE_H
#define _SCYTALE_H

#include <iostream>
#include <vector>

class scytale
{
    public:
        scytale(std::string &input, int &diameter);
        void encrypt();
        void decrypt();
        void calculate_lines();
        std::string get_input() const;
    private:
        int d = 0, lines = 0;
        std::string input = "", temp = "";
};

#endif /* _SCYTALE_H */

