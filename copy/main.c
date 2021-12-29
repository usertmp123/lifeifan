#include "pcpy.h"

int main(int argc,char** argv)
{
	int blocksize;
	int pronum;
	if(argv[3])
	{
		pronum = atoi(argv[3]);
	}
	else
	{
		pronum = 5;
	}
	check_arg(argv[1],argc,pronum);
	blocksize = block(argv[1],pronum);
	procreate(argv[1],argv[2],pronum,blocksize);

	return 0;
}
