#include <stdio.h>
#define MAX_LINE 65

typedef enum DI_ERR_CODE{
	DI_ERR_OK = 0,
	DI_ERR_ERROR,
	DI_ERR_MAX
} DI_ERR_CODE;

DI_ERR_CODE DI_IO_Output(char* str);
DI_ERR_CODE DI_IO_Input();

