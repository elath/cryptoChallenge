#ifndef _statstools_h
#define _statstools_h

#include "stdint.h"

/* This function takes a null terminated string and returns the chi sqared fit against the
distribution of characters in English*/
double isEnglish(char** sample);

#endif
