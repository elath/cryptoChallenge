#include "stdio.h"
#include "stdint.h"

int main(int argc, char** argv);

uint8_t ascii2hex(char ascii1, char ascii2);

int main(int argc, char** argv)
{
	char* encode = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	int count = 0;
	int i = 0;
	int j = 0;
	unsigned int mod = 0;
	uint32_t temp = 0;
	int padding = 0;

	if(argc != 2) /* Check that there are exactly 1 argument passed*/
	{
		printf("Must pass hex text to convert\n");
		return(64);
	}

	while(argv[1][i] != 0) /*count the length of the message to encode*/
	{
		i++;
		count++;
	}

	printf("Count = %d\n",count);

	mod = count % 2;

	if(mod != 0)
	{
		printf("Must pass 2 characters per byte.\n");
		return(64);
	}

	i = 0;

	while(count >= 2)
	{
		padding = 0;
		temp = 0;

		temp |= ascii2hex(argv[1][i], argv[1][i+1]);
		//printf("debug3: %x\n", temp);
		temp = temp << 8;
		i += 2;
		count -= 2;

		if(count >= 2)
		{
			temp |= ascii2hex(argv[1][i], argv[1][i+1]);
			//printf("debug4: %x\n", temp);
			temp = temp << 8;
			i += 2;
			count -= 2;
		}

		else
		{
			temp = temp << 8;
			padding = 2;
		}

                if(count >= 2)
                {
			temp |= ascii2hex(argv[1][i], argv[1][i+1]);
                        i += 2;
                        count -= 2;
                }

                else if(padding == 0)
                {
			padding = 1;
                }

		//printf("debug3: %x\n", temp);

		printf("%c", encode[(temp & 0x00FC0000)>>18]);
		printf("%c", encode[(temp & 0x0003F000)>>12]);

		if(padding == 0)
		{
			printf("%c", encode[(temp & 0x00000FC0)>>6]);
			printf("%c", encode[(temp & 0x0000003F)]);
		}

		else if(padding == 1)
		{
			printf("%c", encode[(temp & 0x00000FC0)>>6]);
			printf("%c", encode[64]);
		}

		else if(padding == 2)
		{
			printf("%c", encode[64]);
			printf("%c", encode[64]);
		}

	}

	return(0);
}


uint8_t ascii2hex(char ascii1, char ascii2)
{
	uint8_t hex;
	uint8_t i;

	hex = 0;

	//printf("debug1 %d %d\n", ascii1, ascii2);

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

	//printf("debug2: %x\n", hex);

	return hex;
}
