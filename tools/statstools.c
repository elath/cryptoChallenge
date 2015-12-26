#include "statstools.h"
#include "math.h"
#include "stdint.h"
#include "stdio.h"

double isEnglish(char** sample)
{
	double english[26] = {8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77,\
			     4.02, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06, 2.76, 0.98,\
			     2.36, 0.15, 1.974, 0.07};
	double chisquared = 0.0;
	double expected[26];
	uint32_t test[26];
	uint32_t i = 0;
	uint32_t count = 0;

	for(i = 0; i < 26; i++)
	{
		test[i] = 0;
	}

	i = 0;
	while((*sample)[i] != 0) /*Find the number of occourences of each character*/
	{
		if((*sample)[i] >= 0x41 && (*sample)[i] <= 0x5a)
		{
			test[(*sample)[i]-65]++;
			count++;
		}
		if((*sample)[i] >= 0x61 && (*sample)[i] <= 0x7a)
		{
			test[(*sample)[i]-97]++;
			count++;
		}
		i++;
	}

	printf("count: %d\n", count);

	for(i = 0; i < 26; i++) /*Calculate the expected number for each character.*/
	{
		expected[i] = (english[i]/100) * count;
		printf("Expected[%d]: %f\n", i, expected[i]);
	}

	for(i = 0; i < 26; i++) /*Calculate the chi squared score of this sample.*/
	{
		chisquared += (pow((test[i]-expected[i]),2))/expected[i];
	}

	return(chisquared);
}

