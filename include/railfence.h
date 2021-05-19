#ifndef _RAILFENCE_H
#define _RAILFENCE_H

#include <iostream>
#include <vector>

class fence
{
    public:
        fence(std::string &input, int &rail);
        void encrypt();
        void decrypt();
        std::string get_input() const;
    private:
        int rail = 0;
        std::string input = "", temp = "";
};

#endif /* _RAILFENCE_H */
