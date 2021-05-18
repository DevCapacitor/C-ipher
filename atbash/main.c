/*
* MIT License
*
* Copyright (c) 2021 Muhammad Aviv Burhanudin
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include <stdio.h>
#include <ctype.h>

#define ALPHABET 26

char input;

void
getopt_driver(int);

int
main(int argc, char const *argv[])
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

void
getopt_driver()
{

}