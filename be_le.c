#include<stdlib.h>
#include<stdio.h>

char *reverse_string(char *s);
int be_to_le(char *s);

int be_to_le(char *s)
{
    int i,num=0,mass,buf= 0;
    char *ptr;
    
	ptr = reverse_string(s);    
	
	mass = (1<<7)-1;
	for (i=0;i<4;i++)
	{
	//   printf("char = %c\n",ptr[i]);
   	   num = (int)ptr[i];
          // print_8_bits(num);
	   num = num & mass;
          // print_8_bits(num);
	   buf = buf | (num<<(7*i));
         //  print_32_bits(buf);
	}
//	printf("num = %d\n",buf);
	return buf;
}

char *reverse_string(char *s)
{
    static char ptr[4];
    int i=0,z=3;
    //printing reverce string.
    while (z >= 0 )
    {
	ptr[i] = s[z];
	z--;
	i++;
    }
    return ptr;
}
