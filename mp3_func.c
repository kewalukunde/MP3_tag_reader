
int find_tag(FILE *fp1,int size,char *tag,char *data)
{
    char arr[20];
    char ch[4];
    int i,j,count,read,flag,f_size;

    while((count += fread(arr,1,4,fp1)) && (count <= size))
    {
	if(!strncmp(tag,arr,4))
	{
	    fread(arr,1,4,fp1);
	    
	    fseek(fp1,+3L,SEEK_CUR);
	  
	    for (j=0;j<be_to_le(arr);j++)
	    {
		data[j] = fgetc(fp1);
	    }
	    data[j-1] = '\0';
	    break;
	}
	fseek(fp1,-3L,SEEK_CUR);
    }
//	fseek(fp1,10L,SEEK_SET);
    return 0;
}

int edit_tag(FILE *fp1,char *argv_3,int m_size)
{
    char arr[4],data[3000];
    int j,size,read,count,flag = 1;

    while((count += fread(arr,1,4,fp1)) && (count <= m_size))
    {
	if(!strncmp(argv_3,arr,4))
	{
	    fread(arr,1,4,fp1);
	    read = fgetc(fp1);
	    if (read & (1<<5))
	    {
		printf("File is read only\n");
		return 0;
	    }
//	    printf("\nread  file : %d\n",read);
	    size = be_to_le(arr);
	    printf("Enter new containt of length %d: ",size);
	    scanf("%[A_Z a-z 0-9 '']",data);

	    fseek(fp1,2L,SEEK_CUR);
		for (j=0;j<(size-1);j++)
	    {
		if ((data[j] != '\0') && (flag != 0))
		{
		    fputc(data[j],fp1);
		}
		else
		{
		    flag = 0;
		    fputc('\0',fp1);
		}
	    }
	    fputc('\0',fp1);;
	    break;
	}
	fseek(fp1,-3L,SEEK_CUR);
    }

    return 0;
}
