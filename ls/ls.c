/************************************************************
 * 
 *   name:	ls.c
 *   author:	renbin.guo
 *   brief:	the first verion of ls
 *   note:
 *   		if no args,use . 
 *   history:	
 *   		2017-03-30 	renbin.guo created
 *
 ***************************************************************/
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

/*打印当前目录下的所有文件*/
void do_ls(char []);

int main(int ac,char *av[])
{
	if(ac == 1)
		do_ls(".");
	else
		while(--ac)	// 第一个参数为ls 所以要--ac,++av	
		{
			printf("%s:\n",*++av);
			do_ls(*av);
		}
	return 0;
}
/*********************************************************************
 *	 name:		do_ls
 *	 auther:	renbin.guo
 *	 breif:		printf all files in dirname
 *	 note:	
 *	 history:
 *	 		2017-03-30	renbin.guo created
 * 
 ********************************************************************/

void do_ls(char dirname[])
{
	DIR 	*dir_ptr;
	struct 	dirent *direntp;
	dir_ptr = opendir(dirname);
	if(dir_ptr == NULL)
		fprintf(stderr,"ls : cannot open %s \n",dirname);
	else
	{
		while( (direntp = readdir(dir_ptr)) != NULL)
			printf("%s\n",direntp->d_name);
		closedir(dir_ptr);
	}
}
	
	

