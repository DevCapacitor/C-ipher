#ifndef _MANAGER_H
#include "manager.h"
#endif

void
strip_space(std::string &input);

int
main (int argc, char *argv[])
{
    /* common variable */
    std::string cipher = "";
    std::string input = "";

    bool have_cipher = false;
    bool have_input = false;
    bool have_shift_count = false;
    bool have_diameter = false;
    bool have_var_A = false;
    bool have_var_B = false;
    bool have_rail = false;
    bool have_key = false;

    bool is_encryption = false;
    bool is_decryption = false;
    bool is_scytale = false;
    bool is_caesar = false;
    bool is_affine = false;
    bool is_atbash = false;
    bool is_rail_fence = false;
    bool is_keyword = false;
    bool is_redirect = false;

    bool need_help = false;
    bool argument_missing = true;
    bool version = false;

    /* getopt variable */
    int opt = 0, option_index = 0;

    /* scytale variable */
    int diameter = 0;

    /* caesar variable */
    int shift_count = 0;

    /* affine variable */
    int varA = 0, varB = 0;

    /* rail fence variable */
    int rail = 0;

    /* keyword variable */
    std::string key = "";

    while ( true )
    {
        option_index = 0;
        static struct
            option long_options[] =
            {
                {"cipher",      required_argument, 0, 'c'},
                {"input",       required_argument, 0, 'i'},
                {"shift-count", required_argument, 0, 's'},
                {"diameter",    required_argument, 0, 'D'},
                {"var-A",       required_argument, 0, 'A'},
                {"var-B",       required_argument, 0, 'B'},
                {"rail",        required_argument, 0, 'r'},
                {"key",          required_argument, 0, 'k'},
                {"encryption",  no_argument, 0, 'e'},
                {"decryption",  no_argument, 0, 'd'},
                {"help",        no_argument, 0, 'h'},
                {"version",     no_argument, 0, 'v'},
                {"redirect",    no_argument, 0, 'R'}
            };
        opt = getopt_long(argc, argv, "c:i:s:D:A:B:r:k:edhvR", long_options, &option_index);
        if ( opt == -1 )
            break;
        switch ( opt )
        {
            case 'c':
                if ( optarg )
                {
                    cipher = optarg;
                    have_cipher = true;
                }
                break;
            case 'e':
                is_encryption = true;
                break;
            case 'd':
                is_decryption = true;
                break;
            case 'i':
                if ( optarg )
                {
                    input = optarg;
                    strip_space(input);
                    have_input = true;
                }
                break;
            case 's':
                if ( optarg )
                {
                    shift_count = std::atoi(optarg);
                    have_shift_count = true;
                }
                break;
            case 'D':
                if ( optarg )
                {
                    diameter = std::atoi(optarg);
                    have_diameter = true;
                }
                break;
            case 'A':
                if ( optarg )
                {
                    varA = std::atoi(optarg);
                    if ((varA % 2) == 0)
                    {
                        std::cerr << "Valid input A is 1,3,5,7,9,11,15,17,19,21,23,25" << std::endl;
                        exit(EXIT_SUCCESS);
                    }
                    else
                        have_var_A = true;
                }
                break;
            case 'B':
                if ( optarg )
                {
                    varB = std::atoi(optarg);
                    have_var_B = true;
                }
                break;
            case 'r':
                if ( optarg )
                {
                    rail = std::atoi(optarg);
                    if (rail == 1)
                    {
                        std::cerr << "rail must be higher than 1" << std::endl;
                        exit(EXIT_SUCCESS);
                    }
                    have_rail = true;
                }
                break;
            case 'k':
                if ( optarg )
                {
                    key = optarg;
                    have_key = true;
                }
                break;
            case 'h':
                need_help = true;
                break;
            case 'v':
                version = true;
                break;
            case 'R':
                is_redirect = true;
                break;
        } /* switch (opt) */
    } /* while(true) */

    /* logic for encryption */
    if      (
            (cipher == "scytale") ||
            (cipher == "SCYTALE") ||
            (cipher == "Scytale")
            )
        is_scytale = true;
    else if (
            (cipher == "caesar") ||
            (cipher == "CAESAR") ||
            (cipher == "Caesar")
            )
        is_caesar = true;
    else if (
            (cipher == "atbash") ||
            (cipher == "ATBASH") ||
            (cipher == "Atbash")
            )
        is_atbash = true;
    else if (
            (cipher == "affine") ||
            (cipher == "AFFINE") ||
            (cipher == "Affine")
            )
        is_affine = true;
    else if (
            (cipher == "rail")        ||
            (cipher == "fence")       ||
            (cipher == "rail_fence")  ||
            (cipher == "RAIL_FENCE")  ||
            (cipher == "Rail_fence")  ||
            (cipher == "Rail-fence")
            )
        is_rail_fence = true;
    else if (
            (cipher == "keyword")  ||
            (cipher == "KEYWORD")  ||
            (cipher == "Keyword")
            )
        is_keyword = true;
    else
        argument_missing = true;

    if ( have_cipher && is_encryption && have_input && have_diameter && is_scytale )
    {
        scytale *scycrypt = new scytale(input, diameter);
        scycrypt->calculate_lines();
        scycrypt->encrypt();
        if ( !is_redirect )
            std::cout << "Encrypted : ";
        std::cout << scycrypt->get_input() << std::endl;
        delete scycrypt;
        argument_missing = false;
    }
    else if ( have_cipher && is_encryption && have_input && is_atbash )
    {
        atbash *atbcrypt = new atbash(input);
        atbcrypt->encrypt();
        if ( !is_redirect )
            std::cout << "Encrypted : ";
        std::cout << atbcrypt->get_input() << std::endl;
        delete atbcrypt;
        argument_missing = false;
    }
    else if ( have_cipher && is_encryption && have_input && have_shift_count && is_caesar )
    {
        caesar *caecrypt = new caesar(input, shift_count);
        caecrypt->encrypt();
        if ( !is_redirect )
            std::cout << "Encrypted : ";
        std::cout << caecrypt->get_input() << std::endl;
        delete caecrypt;
        argument_missing = false;
    }
    else if ( have_cipher && is_encryption && have_input && have_var_A && have_var_B && is_affine )
    {
        affine *affcrypt = new affine(input, varA, varB);
        affcrypt->encrypt();
        if ( !is_redirect )
            std::cout << "Encrypted : ";
        std::cout << affcrypt->get_input() << std::endl;
        delete affcrypt;
        argument_missing = false;
    }
    else if (have_cipher && is_encryption && have_input && have_rail && is_rail_fence)
    {
        fence *fencrypt = new fence(input, rail);
        fencrypt->encrypt();
        if ( !is_redirect )
            std::cout << "Encrypted : ";
        std::cout << fencrypt->get_input() << std::endl;
        delete fencrypt;
        argument_missing = false;
    }
    else if (have_cipher && is_encryption && have_input && have_key && is_keyword)
    {
        keyword *keycrypt = new keyword(input, key);
        keycrypt->abcrypt();
        keycrypt->encrypt();
        if ( !is_redirect )
            std::cout << "Encrypted : ";
        std::cout << keycrypt->get_input() << std::endl;
        delete keycrypt;
        argument_missing = false;
    }


    if ( have_cipher && is_decryption && have_input && have_diameter && is_scytale )
    {
        scytale *scycrypt = new scytale(input, diameter);
        scycrypt->calculate_lines();
        scycrypt->decrypt();
        if ( !is_redirect )
            std::cout << "Decrypted : ";
        std::cout << scycrypt->get_input() << std::endl;
        delete scycrypt;
        argument_missing = false;
    }
    else if ( have_cipher && is_decryption && have_input && is_atbash )
    {
        atbash *atbcrypt = new atbash(input);
        atbcrypt->decrypt();
        if ( !is_redirect )
            std::cout << "Decrypted : ";
        std::cout << atbcrypt->get_input() << std::endl;
        delete atbcrypt;
        argument_missing = false;
    }
    else if ( have_cipher && is_decryption && have_input && have_shift_count && is_caesar )
    {
        caesar *caecrypt = new caesar(input, shift_count);
        caecrypt->decrypt();
        if ( !is_redirect )
            std::cout << "Decrypted : ";
        std::cout << caecrypt->get_input() << std::endl;
        delete caecrypt;
        argument_missing = false;
    }
    else if ( have_cipher && is_decryption && have_input && have_var_A && have_var_B && is_affine )
    {
        affine *affcrypt = new affine(input, varA, varB);
        affcrypt->decrypt();
        if ( !is_redirect )
            std::cout << "Decrypted : ";
        std::cout << affcrypt->get_input() << std::endl;
        delete affcrypt;
        argument_missing = false;
    }
    else if (have_cipher && is_decryption && have_input && have_rail && is_rail_fence)
    {
        fence *fencrypt = new fence(input, rail);
        fencrypt->decrypt();
        if ( !is_redirect )
            std::cout << "Decrypted : ";
        std::cout << fencrypt->get_input() << std::endl;
        delete fencrypt;
        argument_missing = false;
    }
    else if (have_cipher && is_decryption && have_input && have_key && is_keyword)
    {
        keyword *keycrypt = new keyword(input, key);
        keycrypt->abcplain();
        keycrypt->abcrypt();
        keycrypt->decrypt();
        if ( !is_redirect )
            std::cout << "Decrypted : ";
        std::cout << keycrypt->get_input() << std::endl;
        delete keycrypt;
        argument_missing = false;
    }

    if ( version )
    {
        std::cout << "Crypted v1.7 (c) 2019 by Kuroyasha512" << std::endl;
        argument_missing = false;
    }
    if ( need_help )
    {
        std::cout << "Usage : Crypted [OPTIONS]" << std::endl << std::endl
                  << "Option\t\tGNU long option\t\tMeaning" << std::endl
                  << "-c\t\t--cipher\t\tSet type of cipher eg. scytale, caesar, etc" << std::endl
                  << "-i\t\t--input\t\t\tSet input to process en/decrypting" << std::endl
                  << "-s\t\t--shift-count\t\tSpecial options for caesar" << std::endl
                  << "-D\t\t--diameter\t\tSpecial options for scytale cipher" << std::endl
                  << "-e\t\t--encryption\t\tArgument for encryption" << std::endl
                  << "-d\t\t--decryption\t\tArgument for decryption" << std::endl
                  << "-h\t\t--help\t\t\tShow a summary of the available command-line options and exit." << std::endl
                  << "-v\t\t--version\t\tShow the current version number and exit." << std::endl
                  << "-R\t\t--redirect\t\tOption for Redirecting output" << std::endl
                  << "-A\t\t--var-A\t\t\tSpecial options for affine cipher" << std::endl
                  << "-B\t\t--var-B\t\t\tSpecial options for affine cipher" << std::endl
                  << "-r\t\t--rail\t\t\tSpecial option for rail fence cipher" << std::endl
                  << "-k\t\t--key\t\t\tSpecial options for keyword cipher" << std::endl;
        argument_missing = false;
    }

    if ( argument_missing )
        std::cout << "Try `Crypted --help/-h' for more information." << std::endl;

    exit(EXIT_SUCCESS); /* function from cstdlib */
}

void
strip_space(std::string &input)
{
    int j = 0;
    for(int s = 0;input[s] != '\0';++s)
        if ( input[s] != ' ' )
            input[j++] = input[s];
    input[j] = '\0';
}