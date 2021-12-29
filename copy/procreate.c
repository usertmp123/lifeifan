#include "pcpy.h"


int procreate(const char *SFile,const char *DFile,int pronum,int block)
{
	int flag;
	pid_t pid;

	int pos;
	char cblock[10];
	char cpos[10];
	bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cpos));


	for(flag = 0;flag < pronum;flag++)
	{
		pid = fork();
		if(pid == 0)
			break;

	}
	if(pid > 0)
	{
		printf("Parent Pro pid[%d] 非阻塞回收...\n",getpid() );
		pid_t zpid;
		while((zpid = waitpid(-1,NULL,WNOHANG)) != -1)
		{
			if(zpid > 0)
			{
				printf("Parent wait Success :zombie pid [%d]\n",zpid);
			}
		}
	}
	else if(pid == 0)
	{
		pos = flag * block;
		sprintf(cblock,"%d",block);
		sprintf(cpos,"%d",pos);

		execl("/home/colin/12.28/COPY","./COPY",SFile,DFile,cblock,cpos,NULL);
	}
	else
	{
		perror("fork call failed");
		exit(-1);
	}
}
