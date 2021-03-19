#include <iostream>
#include <locale>
#include <unistd.h>
#include <string>

#define ALPHABET 26

std::string operation, input, temp;

std::string
getopt_driver(int argc, char *argv[]);

std::string
encryp(std::string input);

std::string
decrypt(std::string input);

void
pint_version();

int
main(int argc, char *argv[])
{
    int code;
    for (size_t num = 0;num < input.size();++num) {
        if ( islower(input[num]) )
            code = 97;
        else if ( isupper(input[num]) )
            code = 65;
        else
            continue;
        input[num] = (temp[num] + ALPHABET - (temp[num] - code) - (temp[num] - code) - 1);
    }
    return 0;
}

std::string
getopt_driver(int argc, char *argv[])
{
    int c;
    std::string input;
    while ((c = getopt(argc, argv, "hm:") != -1)) {
        switch (c) {
            case 'm':
                if (optarg == "encrypt") {
                } else if (optarg == "decrypt") {
                }
                break;
            default:
                break;
        }
    }
}

std::string
encrypt(std::string input)
{
}

std::string
decrypt(std::string input)
{
}

void
pint_version()
{
    std::cout << "ceureka v1.0" << std::endl;
}
