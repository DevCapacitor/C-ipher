#ifndef _RAILFENCE_H
#include "railfence.h"
#endif

fence::fence(std::string &input, int &rail)
{
    this->input = input;
    this->temp = input;
    this->rail = rail;
}

void
fence::encrypt()
{
    int &rail = this->rail;
    std::string &input = this->input;
    std::string &temp = this->temp;

    std::vector<int> vec;
    int beda1 = 0, beda2 = 0, beda = 0;
    int counter = 1;
    bool do_one = true;
    vec.reserve(static_cast<int>(this->input.size()));
    for (int var = 0;var < rail;++var)
    {
        if ( (var == (rail - 1)) || (var == 0) )
        {
            beda1 = (rail + (rail - 2));
            beda2 = beda1;
        }
        else if ( do_one )
        {
            beda1 = ((rail + (rail - 2)) - 2);
            beda2 = (beda1 - (beda1 - 2));
            do_one = false;
        }
        else
        {
            beda1 -= 2;
            beda2 += 2;
        }
        if ( beda1 == beda2 )
            beda = beda1;
        counter = 1;
        for (size_t i = var;i < this->input.size();i += beda)
        {
            if ( counter == 1 )
            {
                beda = beda1;
                ++counter;
            }
            else
            {
                beda = beda2;
                counter = 1;
            }
            vec.push_back(i);
        }
    }
    for (size_t i = 0;i < this->input.size(); ++i)
        input[i] = temp[vec[i]];
    vec.clear();
}

void
fence::decrypt()
{
    /* decryption from :
     * https://www.geeksforgeeks.org/rail-fence-cipher-encryption-decryption/
     * with modification and optimization by Kuroyasha512 */

    std::string &cipher = this->input;
    std::string &result = this->temp;
    int &key = this->rail;

    bool dir_down = false;
    char rail[key][static_cast<int>(this->input.size())];
    int row = 0, col = 0;
    int index = 0;

    for (int i = 0; i < key; i++)
        for (size_t j = 0; j < this->input.size(); j++)
            rail[i][j] = '\n';

    row = 0;
    col = 0;

    for (size_t i = 0; i < this->input.size(); i++)
    {
        if ( row == 0 )
            dir_down = true;
        else if ( row == (key - 1) )
            dir_down = false;

        rail[row][col++] = '*';

        if ( dir_down )
            row++;
        else
            row--;
    }

    for (int i = 0; i < key; i++)
        for (size_t j = 0; j < this->input.size(); j++)
            if ( (rail[i][j] == '*') && (index < static_cast<int>(this->input.size())) )
                rail[i][j] = cipher[index++];

    row = 0;
    col = 0;
    result.clear();

    for (size_t i = 0; i < this->input.size(); i++)
    {
        if ( row == 0 )
            dir_down = true;
        else if ( row == key-1 )
            dir_down = false;

        if ( rail[row][col] != '*' )
            result.push_back(rail[row][col++]);

        if ( dir_down )
            row++;
        else
            row--;
    }
    this->input = result;
}

std::string
fence::get_input() const
{
    return this->input;
}
