#include "pcpy.h"

int check_arg(const char *SFile,int arg_num,int pronum)
{
	if(access(SFile,F_OK) != 0)
	{
		perror("Check_arg Error");
		exit(-1);
	}

	if(arg_num < 3)
	{
		printf("check_arg Error :参数异常\n");
		exit(-1);
	}

	if(pronum <= 0 || pronum >= 100)
	{
		printf("check_arg error : 进程数量应在0到100以内\n");
		exit(-1);
	}

	return 0;
}
