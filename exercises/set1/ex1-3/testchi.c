#include "statstools.h"
#include "stdio.h"

int main(void)
{
	char* sample = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
	//char* sample = "Accurate average letter frequencies can only be gleaned by analyzing a large amount of representative text. With the availability of modern computing and collections of large text corpora, such calculations are easily made. Examples can be drawn from a variety of sources (press reporting, religious texts, scientific texts and general fiction) and there are differences especially for general fiction with the position of 'h' and 'i', with H becoming more common.";
	char** address = &sample;
	double result = 0;
	result = isEnglish(address);
	printf("%f\n",result);
	return(0);
}
