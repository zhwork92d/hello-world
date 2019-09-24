#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define DEV_NAME "/dev/CHARDEV"

int main()
{
 int fd, num;
 fd =open(DEV_NAME,O_RDWR,S_IRUSR | S_IWUSR);
  if(fd<0)
  { printf("open device failed!!! \n");
  return -1;
  }
  read(fd,&num,sizeof(int));
  printf("The globalchar is %d \n",num);

  printf("please input a number written to dev :\n");

  scanf("%d",&num);
  write(fd,&num,sizeof(int));

  read(fd,&num,sizeof(int));
  printf("the global is %d \n",num);
  close(fd);
  return 0;


}

