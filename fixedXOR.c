#include "stdio.h"
#include "stdint.h"
#include "hextools.h"

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	int count = 0;
	int i = 0;
	int j = 0;
	unsigned int mod = 0;
	uint8_t tempM = 0;
	uint8_t tempK = 0;

	if(argc != 3) /* Check that there are exactly 2 argument passed*/
	{
		printf("Must pass hex text and key to convert\n");
		return(64);
	}

	while(argv[1][i] != 0) /*count the length of the message to encode*/
	{
		i++;
		count++;
	}

        while(argv[2][j] != 0) /*count the length of the key*/
        {
                j++;
        }

	printf("i:%d\tj:%d\n", i, j);

	if(i != j)
	{
		printf("Message and key must be same length\n");
		return(64);
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
		tempM = 0;
		tempK = 0;

		tempM |= ascii2hex(argv[1][i], argv[1][i+1]);
		tempK |= ascii2hex(argv[2][i], argv[2][i+1]);
		printf("%x", tempM ^ tempK);

		i += 2;
		count -= 2;

	}
	printf("\n");

	return(0);
}
