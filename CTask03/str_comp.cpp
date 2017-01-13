#include "str_comp.h"
#include<string.h>


bool StrComp::StrTrueFalse(const char *str,const char *ans)
{
	if (strcmp(str,ans)==0) {	//==
		return true;
	}

	return false;	//!=
}
