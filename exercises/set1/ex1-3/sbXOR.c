#include "stdio.h"
#include "stdint.h"
#include "hextools.h"
#include "statstools.h"

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	char cypherText[100];
	char trialText[100];
	int count = 0;
	int counth = 0;
	int i = 0;
	int j = 0;
	unsigned int mod = 0;
	int8_t tempC = 0;
	double keyscore[256];

	if(argc != 2) /* Check that there are exactly 2 argument passed*/
	{
		printf("Must pass ASCII encoded hex text and key to convert\n");
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
	j = 0;

	while(count >= 2)
	{
		tempC = 0;

		tempC |= ascii2hex(argv[1][i], argv[1][i+1]);
		//printf("%c\n", tempC);
		//printf("%x", tempM ^ tempK);
		cypherText[j] = tempC;
		j++;
		i += 2;
		count -= 2;

	}

	counth = j;

	cypherText[j] = 0; /*null terminate the cypherText string*/

	for(i = 0; i < 256; i++)
	{
		for(j = 0; j < count; j++)
		{
			trialText[j] = cypherText[j] ^= i;
		}
			keyscore[i] = isEnglish(&(trialText));
	}

	//Need to printout result of using highest scoring key.

	//printf("cypher text: %s\n", cypherText);

	return(0);
}
