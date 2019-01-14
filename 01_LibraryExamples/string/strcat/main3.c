void mail_compose(char buff[2048])
{
	int len;
	char * token, senderOfEmail[20], recieverOfEmail[20][20], email_Sub[500], email_Body[500], *nameOfFile, *email_File;
	int count = 0 ,i,lastCount,lines;
	FILE *fpcfg;
	char *attach = malloc(2048);
	
	token = strtok(buff, "|");
	token = strtok(NULL,",");
	while(token != NULL)
	{
		strncpy(recieverOfEmail[count++], token, strlen(token)+1);
		token = strtok(NULL,",");	
	}
	lastCount = count-1;
	strncpy(senderOfEmail, recieverOfEmail[0], strlen(recieverOfEmail[0])+1);
	token = strtok(recieverOfEmail[lastCount],"|");
	strncpy(recieverOfEmail[count-1], token, strlen(token)+1);
	token= strtok(NULL,"|");
	strncpy(email_Sub, token, strlen(token)+1);
	token= strtok(NULL, "|");	
	strncpy(email_Body, token, strlen(token)+1);
	token = strtok(NULL, "|");
	strcpy(attach, token);
	printf("\n Sender is %s",senderOfEmail );
	printf("\nSubject is %s", email_Sub);
	printf("\nBody is %s", email_Body);
	printf("\nAttachment is %s", token);
	for(i=1;i<count ;i++)
	{
		printf("\nReciever is %s", recieverOfEmail[i]);
		lines = numoflines(fpcfg);
		nameOfFile = getfileName(fpcfg, recieverOfEmail[i], lines);
		printf("\nFile name is %s", nameOfFile);
		emailservice(nameOfFile);	
		email_File = emailservice(nameOfFile);	
		printf("%s", email_File);
		compose(senderOfEmail,email_Sub,email_Body,email_File,lines,attach);
	}
	
}