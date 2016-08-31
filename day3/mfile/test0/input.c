#include "di_io.h"

DI_ERR_CODE DI_IO_Input()
{
	char temp[256];

	scanf("%s", temp);
	printf("Input String is [%s]\n", temp);
	return DI_ERR_OK;
}
