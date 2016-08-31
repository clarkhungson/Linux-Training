#include "di_io.h"

DI_ERR_CODE DI_IO_Output(char* str)
{
	printf("%s\n", str);
	
	return DI_ERR_OK;
}
