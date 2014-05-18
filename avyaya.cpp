#include "functions.h"
#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
int check_avyaya_database(char[],indeclined *,int *);
using namespace std;
int check_avyaya_database(char indeclinables[100],indeclined *indecl_ar,int *indecl_l)
{

FILE *f;
char x[100],the_path[256];
getcwd(the_path, 255);
strcat(the_path, "/data/connectors");
f = fopen(the_path, "r");

while(fscanf(f,"%s",x)!=EOF)
      {
                            if(strcmp(x,indeclinables)==0)
                            {
                                int temp;
                                cout<< "this is a avyaya..\n";
                                strcpy(indecl_ar->value,indeclinables);
                                fscanf(f,"%d",&temp);
                                indecl_ar->type=temp;
                                fscanf(f,"%s",x);
                                cout<< "and the meaning is:  "<<x<<"\n";
                                strcpy(indecl_ar->meaning,x);
                                (*indecl_l)++; return 1;

                           }//if ends here
     }//while ends here


getcwd(the_path, 255);
strcat(the_path, "/data/avyaya");
f = fopen(the_path, "r");

while(fscanf(f,"%s",x)!=EOF)
      {
                            if(strcmp(x,indeclinables)==0)
                            {
                                int temp;
                                cout<< "this is a avyaya..\n";
                                strcpy(indecl_ar->value,indeclinables);
                                fscanf(f,"%d",&temp);
                                indecl_ar->type=temp;
                                fscanf(f,"%s",x);
                                cout<< "and the meaning is:  "<<x<<"\n";
                                strcpy(indecl_ar->meaning,x);
                                (*indecl_l)++; return 1;

                           }//if ends here
     }//while ends here

return 0;

}

