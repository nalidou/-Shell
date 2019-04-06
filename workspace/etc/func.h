char cmdFlag0[50]="";
char cmdFlag1[]="[root@127.0.0.1 ";
char cmdFlag2[]="]# ";
char cmdLocaltionFlag[20]="";

char command[100]="";

int loginCount = 0;
char location[500]="./workspace/";

char cmdAftStr[50]="";


// 注意：如果两个命令开始字母相同，不要用
int strStartWith(char *str, char *with){
	int i=0;
	
	for(i=0;i<strlen(with)-1;i++){
		if(with[i] != str[i]){
				return 0;
		}	
	}
	return 1;
	
	
}

void init(){
		int i=0;
		
		//int j=0;
		for(i=0;i<19;i++){
			cmdLocaltionFlag[i] = '\0';	
		}
		for(i=strlen(location)-2;location[i] != '/';i--){	
			cmdLocaltionFlag[strlen(location)-2-i] = location[i];
		}
		for(i=0;i<(strlen(cmdLocaltionFlag))/2;i++){
			int t ;
			t = cmdLocaltionFlag[i];
			cmdLocaltionFlag[i] = cmdLocaltionFlag[strlen(cmdLocaltionFlag)-1-i];
			cmdLocaltionFlag[strlen(cmdLocaltionFlag)-1-i] = t;
		}
		strcpy(cmdFlag0,"");
		strcat(cmdFlag0,cmdFlag1);
		strcat(cmdFlag0,cmdLocaltionFlag);
		
		
		strcat(cmdFlag0,cmdFlag2);
	//	cmdLocaltionFlag


		printf(cmdFlag0);
		gets(command);
}

void getCmdAftStr(int index, char command[]){
		char str[50] = "";
		int i = 0;
		while(command[index] != 0){
			str[i++] = command[index];
			index++;
		}
	
		strcpy(cmdAftStr,str);
	//	return str;
}

void touch(char *fname[]){

		FILE *fp = NULL;
		fp = fopen(fname,"w");	
		fclose(fp);

}
void cat(char *filename){
			//char filename[10] = "";
			char fileContext[1000] = "";
			FILE *fp = NULL;
			fp = fopen(filename,"r");
			fflush(fp);
			if(fp != NULL){
				//	fprintf(fp,"%s",str);
				fscanf(fp,"%s",fileContext);
				fclose(fp);
				//printf("%s\n",fileContext);
				puts(fileContext);	
			}else{	
				puts("error: file not find!!");
			}
		
			
}
/**

http://blog.sina.com.cn/s/blog_658061060100hxb8.html


#include <stdio.h>
int
main(int argc,char **argv)
{
    printf("\033[31m The ......\n\033[0m");
    printf("\033[2;7;1mHEOO.\n\033[2;7;0m");
    printf("\033[41;36msomthe here\n\033[0m");
    return 0;
}

*/

/**

char * getStr(char * f){
	char ret[100]="tom";
	printf("len:%d\n",strlen(f));
	printf(":%s\n",f);
	strcat(ret,f);
	return ret;
}
void main(){
	char f[10]="hello";
	char *v = NULL;
	printf("------\n");

	v =	getStr(f);
	if(v != NULL){
		printf("-->%s\n",v);
	}
}

*/
/*
char ** grep(char *fname, char *value){
			char fileContext[1000] = "";
			FILE *fp = NULL;
			fp = fopen(fname,"r");
			fflush(fp);
			if(fp != NULL){
				fscanf(fp,"%s",fileContext);
				fclose(fp);
				//puts(fileContext);	
				return fileContext;
			}else{	
				puts("error: file not find!!");
				return NULL;
			}
	
	
}
*/
int rootLogin(){
	char passwd[10]; 
	char rootPasswd[10]="";
	FILE *fp = NULL;
	int result;
	char fname[500]="";

	printf("Login passwd# ");
	gets(passwd);

	strcpy(fname,location);
	strcat(fname,"etc/root.dll");
	fp = fopen(fname,"r");
	fscanf(fp,"%s",rootPasswd);
	fclose(fp);

//	puts(rootPasswd);
//	puts(passwd);
	result = strcmp(passwd,rootPasswd);
	if(result == 0){
		printf("[root@127.0.0.1]# %s","login success\n");
		return 0;
	}else{
	
		if(loginCount == 2){
			return -1;
		}
		loginCount++;
		printf("[root@127.0.0.1]# %s","login fail\n");
		rootLogin();
	}
	
}

void inserTextToFile(char *command,char type[5]){
	
			FILE *fp = NULL;
			int len = 0 ;
			int i = 0;
			int j = 0;
			char fileName[10]="";
			char str[100]="";
			char fileLocation[500]="";

			len = strlen(command);
			//printf("type--%s\n",type);	
			
			//get fileName
			if(strcmp("w",type)==0){
				//printf("11111111111111\n");
				for(i=2,j=0; command[i] != ' '; i++){
				fileName[j++]=command[i];
		
				}
				//printf("fname:%s",fileName);
			}else
			if(strcmp("a",type)==0){
				//printf("222222222222\n");
				for(i=3,j=0; command[i] != ' '; i++){
				fileName[j++]=command[i];
				//printf("fname:%s",fileName);
				}
				
			}
			//printf("--fname:%s",fileName);

			//get str
			for(i=i+1,j=0; command[i] != '\0';i++,j++){
				str[j] = command[i];
			}
			
			//printf("fileName-->%s\n",fileName);
			//printf("str-->%s\n",str);
	

			strcpy(fileLocation,location);
			strcat(fileLocation,fileName);
			
			fp = fopen(fileLocation,type);
			if(fp != NULL){
				fprintf(fp,"%s",str);
				//fscanf(fp,"%s",rootPasswd);
				fclose(fp);
			}else{
				puts("error: file not find!!");
			}
			
	
}

int rm(char *v[]){
	int ret;
	char fname[20]="";
	strcpy(fname,location);
	strcat(fname,v);
//	printf("rm : %s\n",fname);
	ret = remove(fname);
	return ret;

}

void subString(char *str, int start, int end, char *result){
	//char result[end]="";
	int len = strlen(str);
	int i = 0;
	int j = 0;
	for(j=start;j<=end;j++){
		result[i++] = str[j];
		
	}
	//return result;


}














