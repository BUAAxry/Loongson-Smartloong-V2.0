#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc ,char **argv)
{
	int fd,size;
	char *buf = "hello,I'm Webee,This is  file io test!";
	char buf_r[20];
	int len = strlen(buf);

	/* ���ȵ���open�����������ǰĿ¼��û��hello.c�򴴽�
	 * �Զ�д��ʽ���ļ�����ָ��Ȩ��Ϊ�ɶ���д
	 */
	if((fd = open("./hello.c",O_CREAT | O_TRUNC | O_RDWR,0666))<0)
	{
		/* ������ */
		printf("open fail\n");
		exit(1);
	}
	else
		printf("open file:hello.c fd = %d\n",fd);

	/* ����write��������buf�е�����д��hello.c */
	if((size = write(fd,buf,len) ) < 0)
	{
		printf("write fail\n");
		exit(1);
	}
	else
		printf("write: %s\n",buf);

	/* ����lseek�������ļ�ָ���Ƶ��ļ���ʼλ�ã��������ļ��е�15���ֽ� */
	lseek(fd,0,SEEK_SET);
	if((size = read(fd,buf_r,15)) <0)
	{
		printf("read fail\n");
		exit(1);
	}
	else
	{
		buf_r[15] = '\0';
		printf("read from hello.c and the content is %s\n",buf_r);
	}

	/* ������close�����رմ򿪵��ļ� */
	if(close(fd) < 0)
	{
		printf("close fail\n");
		exit(1);
	}
	else
		printf("close hello.c\n");

	return 0;	
}

