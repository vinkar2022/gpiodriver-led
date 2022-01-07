

#include"header.h"

#define WR_DATA _IOW('a','a',int32_t*);
#define RD_DATA _IOR('a'.'b',int32_t*);

int main()
{
	int fd;

	int32_t val;
	printf("\n IOCTL based character device driver operation from user space ...\n");

	fd = open("/dev/char_device,O_RDWR");
	if(fd < 0)
	{	
		printf("cannot open the device file\n");
	return 0;
	}
	
	printf("Nter the data to send..\n");
	scanf("%d",&num);
	printf("Writing value to the driver ..\n");
	ioctl(fd,WR_DATA,(int32_t*)&num);
	printf("reading value from the driver ...\n");
	ioctl(fd,RD_DATA,(int32_t*)&val);
	printf("closing driver \n");
	close(fd);
	
}
