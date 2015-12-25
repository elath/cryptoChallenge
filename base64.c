#include "stdio.h"
#include "stdint.h"

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	char* encode = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	int count = 0;
	int i = 0;
	int j = 0;
	unsigned int mod = 0;
	uint32_t temp = 0;

	/*printf("There are %c arguments\n", argv[1][0]);*/
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

	mod = count % 3;

	i = 0;
	while(count >= 3)
	{
		temp = 0;
		temp |= argv[1][i];
		temp = temp << 8;
		i++;
		temp |= argv[1][i];
		temp = temp << 8;
		i++;
		temp |= argv[1][i];
		i++;
		count -= 3;

		/*printf("%X\n", temp);*/

		printf("%c", encode[(temp & 0x00FC0000)>>18]);
		printf("%c", encode[(temp & 0x0003F000)>>12]);
		printf("%c", encode[(temp & 0x00000FC0)>>6]);
		printf("%c", encode[(temp & 0x0000003F)]);
	}

	if(count == 2)
	{
		temp = 0;
		temp |= argv[1][i];
                temp = temp << 8;
                i++;
                temp |= argv[1][i];
                temp = temp << 8;
                i++;
                temp |= 0x00;
                i++;
                count -= 3;

                /*printf("%X\n", temp);*/

                printf("%c", encode[(temp & 0x00FC0000)>>18]);
                printf("%c", encode[(temp & 0x0003F000)>>12]);
                printf("%c", encode[(temp & 0x00000FC0)>>6]);
                printf("%c", encode[64]);
	}

       if(count == 1)
        {
                temp = 0;
                temp |= argv[1][i];
                temp = temp << 8;
                i++;
                temp |= 0x00;
                temp = temp << 8;
                i++;
                temp |= 0x00;
                i++;
                count -= 3;

                /*printf("%X\n", temp);*/

                printf("%c", encode[(temp & 0x00FC0000)>>18]);
                printf("%c", encode[(temp & 0x0003F000)>>12]);
                printf("%c", encode[64]);
                printf("%c", encode[64]);
        }


	return(0);
}
