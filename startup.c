#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include "workspace/etc/func.h"


int main(){
	int i=0;
	
login:
	//用户登录 ok
	if(rootLogin() == -1){
		return;
	}

	while(1){
	
	init:init();

		//pwd ok
		if(!strcmp(command,"pwd")){
			printf("%s\n",location);
			goto init;
		}

	
		//cd ok
		if('c'==command[0] && 'd'==command[1] && ' '==command[2] && '.'!=command[3] &&'.'!=command[4]){
			char furi[50] = "";
			getCmdAftStr(3, command);
			
			strcat(location,cmdAftStr);
			
			goto init;
		}
		//cd ..  ok
		if(!strcmp("cd ..",command)){
			char local[50] = "";
			char temp[50] = "";
			int len=0;
		
			strcpy(local,location);	
			len = strlen(local);
			len -= 2;
	
			for(;len>0;len--){
			
				if('/' == local[len]){
					//	printf("len:%d\n",len);
					//	strcpy(location,"");
					//	printf("-->%s\n",location);
					for(i=0;i<=len;i++){					
						temp[i] = local[i];
					}

					strcpy(location,temp);
				//	printf("-->%s\n",location);
					break;
				}
			}

			goto init;
		}
		

		//touch ok
		if(strStartWith(command,"touch ")){
			char furi[50] = "";
			getCmdAftStr(6, command);
			
			strcpy(furi,location);
			strcat(furi,cmdAftStr);
			touch(furi);
			goto init;
		}

		//mkdir ok
		if(strStartWith(command,"mkdir ")){
			char furi[50] = "";
		
			getCmdAftStr(6, command);
			
			strcpy(furi,location);
			strcat(furi,cmdAftStr);
			mkdir(furi);
		
			goto init;
		}
		//rmdir ok
		if(strStartWith(command,"rmdir ")){
			char furi[50] = "";
		
			getCmdAftStr(6, command);
			
			strcpy(furi,location);
			strcat(furi,cmdAftStr);
			rmdir(furi);
		
			goto init;
		}

		//rm ok
		if(strStartWith(command,"rm ")){
			
			
			char myfilename[50];	
			getCmdAftStr(3,command);
			strcpy(myfilename,cmdAftStr);
		
			if(rm(myfilename)!=0){
				printf("remove file %s fail!!\n",myfilename);
			}
			goto init;
			
		}

		//  > filename string  ok
		if('>'==command[0] && ' '==command[1]){
			inserTextToFile(command,"w");
			goto init;
		}

		//  >> filename string
		if('>'==command[0] && '>'==command[1] && ' '==command[2]){
			
			inserTextToFile(command,"a");
			goto init;
		}

		//cat  ok
		if(strStartWith(command,"cat ")){
			char filename[10] = "";
			getCmdAftStr(4,command);
			strcpy(filename,location);
			strcat(filename,cmdAftStr);
			cat(filename);
		
			goto init;
		}

		// grep 
		if(strStartWith(command,"grep ")){
			char str[]={'\0'};
			int slen = 0;
			int i = 0;
			char grepVal[]={'\0'};
			char fName[]={'\0'};
			int j,jj = 0;

			strcpy(str,command);
			slen = strlen(str);
			for(i=0;i<slen;i++){
				if(' ' == str[i]){
					for(j=i+1;' ' != str[j];j++){
						grepVal[jj++] = str[j];
					}
					break;			
				}
			}
			
			printf("grepVal=%s\n",grepVal);
			printf("fName=%s\n",fName);
			goto init;
		}
		//ll
		if(strcmp("ll",command)==0){
			
			char d[50]="dir ";
				system(d);
			/*
			int len = 0;
			strcat(d,location);
			len = strlen(d);
			d[len-1] = "";
			printf("ddd: %s",d);//dos是不能列出多级目录的？？？
			system(d); 
			getch(); 

*/

			goto init;
		}
		//passwd  ok
		if(strcmp("passwd",command)==0){
			FILE *fp = NULL;
			char passwd[10]="";
			gets(passwd);
			fp = fopen("workspace/etc/root.dll","w");
			fprintf(fp,"%s",passwd);
		//	fscanf(fp,"%s",fileContext);
			fclose(fp);
			goto init;
		
		}
		//reboot ok
		if(strcmp("reboot",command)==0){
			system("cls");
			goto login;
		}

		// clear ok
		if(strcmp("clear",command)==0){	
			system("cls");
			goto init;
		}

		//win:api   ok
		if(strStartWith(command,"win:")){
			char myfilename[50]="";
			
			getCmdAftStr(4,command);
			strcpy(myfilename,cmdAftStr);

			system(myfilename);
			goto init;
		}
		
		// 闪瞎眼  ok
		if(!strcmp(command,"bgrand")){
			int i=0,j=0;
			int r;
			
			char color[10] = "color ";
			r = rand()%100+1;
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					color[6] = i+48;
					color[7] = j+48;
					system(color);
					if(r < i*10+j){
						goto init;
					}	
				}
			}
		

			
		}
		//setcolor ok
		if(strStartWith(command,"setcolor")){
			char color[10] = "color ";
			getCmdAftStr(9,command);
			strcat(color,cmdAftStr);
		//	printf("-%s-",color);
			system(color);
			goto init;
			/*
			颜色属性由两个十六进制数字指定 --
			第一个为背景，第二个则为文字。
			每个数字可以为以下任何值之一：
			0 = 黑色 8 = 灰色
			1 = 蓝色 9 = 淡蓝色
			2 = 绿色 A = 淡绿色
			3 = 浅绿色 B = 淡浅绿色
			4 = 红色 C = 淡红色
			5 = 紫色 D = 淡紫色
			6 = 黄色 E = 淡黄色
			7 = 白色 F = 亮白色
			*/
		}
	
		//

	
		//shutdown ok
		if(strcmp("shutdown",command)==0){
			break;
		
		}

		//help ok
		if(strcmp("help",command)==0){
			system("cls");
			printf("help	\n");
			printf("shutdown	\n");
			printf("reboot	\n");
			printf("window [api]	\n");
			printf("clear	\n");
			printf("pwd	\n");
			printf("ll	\n");

			printf("cd [dirName]	\n");
			printf("cd ..	\n");

			printf("touch [fname]	\n");
			printf("> [fname] string	\n");
			printf(">> [fname] string	\n");
			printf("rm [fname]	\n");
			printf("mkdir [dirName]	\n");
			printf("rmdir [dirName]	\n");
			printf("passwd	\n");
			
			printf("cat [fname]	\n");

			printf("setcolor a1	\n"); 
		
			goto init;
		}
		// cmd not matching
		printf("error: not find this command!!\n");
	}

//shutdown:
	return 0;
}


