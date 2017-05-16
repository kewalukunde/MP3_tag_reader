#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
#include "mp3_func.c"
#include "view_edit.c"
#else
#include "test.c"
#endif

#include "be_le.c"

int find_tag(FILE *fp1,int size,char *tag,char *data);
int edit_tag(FILE *fp1,char *argv_3,int size);
int view(char *argv_2);
int edit(char *argv_2,char *argv_3);
