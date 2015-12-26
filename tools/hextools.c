#include "hextools.h"

uint8_t ascii2hex(char ascii1, char ascii2)
{
        uint8_t hex;

        hex = 0;

        if(ascii1 >= 48 && ascii1 <= 57) /*0-9*/
        {
                hex |= ascii1 - 48;
        }

        else if(ascii1 >= 97 && ascii1 <= 122)
        {
                hex |= ascii1 - 87;
        }

        hex = hex << 4;

        if(ascii2 >= 48 && ascii2 <= 57) /*0-9*/
        {
                hex |= ascii2 - 48;
        }

                else if(ascii2 >= 97 && ascii2 <= 122)
        {
                hex |= ascii2 - 87;
        }

        return hex;
}

