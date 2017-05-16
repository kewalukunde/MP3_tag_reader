#include "mp3.h"

int main(int argc,char *argv[])
{
    char *tag_pass[10] = {"-t","-a","-y","-n","-A","-l","-c","-L","-co","-le"};
    int i;

    switch(argc)
    {
	case 2: if(!strcmp(argv[1],"--help"))
		    print_help();
		else
		{
		    printf("%-20s : %s\n","# for help","Pass ./a.out --help");
		    printf("%-20s : %s\n","# for view tags","Pass ./a.out -v  <FILE NAME>");
		    printf("%-20s : %s","# for edit tags data","Pass ./a.out -e  <FILE NAME> <tag> ,  ");
		    printf("for tag info go to ./a.out --help\n");
		}
		break;

	case 3: if(!strcmp(argv[1],"-v"))
		{
		    view(argv[2]);
		}
		else
		{
		    printf("%-20s : %s\n","# for help","Pass ./a.out --help");
		    printf("%-20s : %s\n","# for view tags","Pass ./a.out -v  <FILE NAME>");
		    printf("%-20s : %s","# for edit tags data","Pass ./a.out -e  <FILE NAME> <tag> ,  ");
		    printf("for tag info go to ./a.out --help\n");
		}
		break;

	case 4: if(!strcmp(argv[1], "-e"))
		{
		    for(i=0;i<10;i++)
		    {
			if(!strcmp(argv[3],tag_pass[i]))
			{
			    edit(argv[2],tags[i]);
			    break;
			}
		    }
		}
		else
		{
		    printf("%-20s : %s\n","# for help","Pass ./a.out --help");
		    printf("%-20s : %s\n","# for view tags","Pass ./a.out -v  <FILE NAME>");
		    printf("%-20s : %s","# for edit tags data","Pass ./a.out -e  <FILE NAME> <tag> ,  ");
		    printf("for tag info go to ./a.out --help\n");
		}
		break;

	default: printf("Not enought argument passed\n");
		 break;
    }
    return 0;
}

