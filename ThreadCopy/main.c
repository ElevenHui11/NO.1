#include <threadcopy.h>


int main(int argc,char**argv)
{
	int thrno;
	if(argv[3]==0)
	{
		thrno=5;
	}
	else
	{
		thrno=atoi(argv[3]);	
	}

	pram_check(argc,argv[1],thrno);
	int blocksize;
	blocksize=file_block(argv[1],thrno);

	printf("blocksize=%d\n",blocksize);

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	thread_create(&attr,argv[1],argv[2],blocksize,thrno);
    sleep(1);
	return 0;
}
