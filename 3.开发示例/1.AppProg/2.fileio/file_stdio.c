/* file_stdio.c */
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc ,char **argv)
{
	FILE *fp;
	char *buf = "hello,I'm Webee,This is  file standard io test!";
	char buf_r[20];
	int len = strlen(buf);	

	/* ����fopen�����������ǰĿ¼��û��hello.c�򴴽����Կɶ���д��ʽ���ļ�*/
	if((fp = fopen("./hello.c","w+")) != NULL)
	{
		printf("fopen success\n");
	}

	/* ����fwrite��������buf�е�����д��hello.c */
 	if((fwrite(buf,sizeof(char),len,fp) > 0))
 	{
 		printf("fwrite: %s\n",buf);
 	}

	/* ����fseek�������ļ�ָ���Ƶ��ļ���ʼλ�ã��������ļ��е�15���ֽ� */
	fseek(fp,0,SEEK_SET);
	if((fread(buf_r,sizeof(char),15,fp)) <0)
	{
		printf("fread fail\n");
		exit(1);
	}
	else
	{
		buf_r[15] = '\0';
		printf("fread from hello.c and the content is %s\n",buf_r);
	}

	/* ������close�����رմ򿪵��ļ� */
	if(fclose(fp) < 0)
	{
		printf("fclose fail\n");
		exit(1);
	}
	else
		printf("fclose hello.c\n");

	return 0;	
}

