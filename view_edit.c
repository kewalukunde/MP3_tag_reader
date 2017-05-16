
char *tags[20] = {"TIT2","TALB","TYER","TRCK","TOPE","TEXT","COMM","TLAN","TCON","TPE1","TLEN","APIC","TSIZ"};
char *Names[20] = {"Title","Album","Year","Track number","Artist","lyrist","Composer","Language","Content type","lead performer","Length","Picture","Size"};

int view(char *argv_2)
{
    FILE *fp1;
    char arr[20],data[3000];
    char ch[10];
    int i,j,size_meta,count,read,flag;

    if( (fp1 = fopen(argv_2,"r")) == NULL)
    {
	printf("Pass source file\n");
	return 0;
    }
    fread(arr,1,3,fp1);
    if (strncmp(arr,"ID3",3))
    {
   	printf("This is not ID3 file !!\n");
	return 0;
    }

    printf("\n============================================================================\n");
    printf("%-s : %s\n","File name",argv_2);
    printf("%s %s\n",arr,"2.3");
    printf("============================================================================\n");

    fseek(fp1,3,SEEK_CUR);
    fread(arr,1,4,fp1);
    size_meta = be_to_le(arr);

    for(i=0;i<13;i++)
    {
	*data = '\0';
	find_tag(fp1,size_meta,tags[i],data);

	fseek(fp1,0,SEEK_SET);

	if(*data != '\0')	
	    printf("%-15s : %s\n",Names[i],data);
    }
    printf("============================================================================\n\n");

    fclose(fp1);
    return 0;

}

int edit(char *argv_2,char *argv_3)
{
    FILE *fp1;
    char arr[4];
    int size_meta;
    if( (fp1 = fopen(argv_2,"r+")) == NULL)
    {
	printf("Pass source file\n");
	return 0;
    }

    fseek(fp1,6,SEEK_SET);
    fread(arr,1,4,fp1);
    size_meta = be_to_le(arr);

    edit_tag(fp1,argv_3,size_meta);

    fclose(fp1);
    return 0;

}

int print_help()
{
    printf("\n============================================================================\n");
    printf("# MP3 TAG --help menu info\n");
    printf("============================================================================\n");
    printf("-t  Modifies a tital tag\n");
    printf("-A  Modifies a Artist tag\n");
    printf("-y  Modifies a Year tag\n");
    printf("-n  Modifies a Track number tag\n");
    printf("-a  Modifies a Album tag\n");
    printf("-l  Modifies a lyrist tag\n");
    printf("-c  Modifies a composre tag\n");
    printf("-L  Modifies a language tag\n");
    printf("-co  Modifies a content type tag\n");
    printf("-le  Modifies a lead performer tag\n");
    printf("============================================================================\n\n");
    return 0;
}
