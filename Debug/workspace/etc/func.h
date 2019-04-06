
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


int rootLogin(){
	char passwd[10]; 
	char rootPasswd[10]="";
	FILE *fp = NULL;
	int result;
	char fname[500]="";

	printf("[root@127.0.0.1]# ");
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

int rm(char *v[]){
	int ret;
	char fname[20]="";
	strcpy(fname,location);
	strcat(fname,v);
//	printf("rm : %s\n",fname);
	ret = remove(fname);
	return ret;

}