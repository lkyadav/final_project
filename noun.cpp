//little information
//when it opens a file
   /*x-> first row of the file (bhyam vagairah)
     y-> second row of the file (integer how many outputs)
     z-> all output strings
     sex=1 masculine
     sex=2 feminine
     sex=3 neuter
     sex=4 N/A
     n_p=5 NOUN
     n_p=6 pronoun
     
     
     
   */
#include "functions.h"
#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include <unistd.h>

int sex,n_p;
char pass_root1[30],pass_meaning1[100];


using namespace std;
int noun(char[],int,nouns *,int *);
void show_output(int );
void show_output1(char);
int noun(char a[100],int len,nouns *noun_ar, int *noun_l){

char x[100],subs[100];
int y,z,done=0;
FILE *ds,*except; 
string sub;
int len1,ged=0;

std::string str(a);

char the_path[256];

    getcwd(the_path, 255);
    strcat(the_path, "/data/exceptions");
  

except=fopen(the_path,"r");

//first check in exception database.
noun_ar->row_l=0;
while(fscanf(except,"%s",x)!=EOF)
{
   fscanf(except,"%d",&y);
   if(strcmp(a,x)==0)
       { 
          for(int index=0;index<y;index++) 
              { fscanf(except,"%d",&z); 
                if(index>=1)cout<<"\t    "; 
                show_output(z);  
                noun_ar->row=z/10; 
                noun_ar->col=z%10; 
                noun_ar->row1[noun_ar->row_l]=z/10; 
                (noun_ar->row_l)++; 
              } 

         fscanf(except,"%s",x); 
         check_noun_database(x); 
         done=1; 
         noun_ar->sex=sex; noun_ar->n_p=n_p;  
         strcpy(noun_ar->root,pass_root1); 
         strcpy(noun_ar->meaning,pass_meaning1);
         (*noun_l)++; 
         return 1; 
         break;  
       }
       
   else 
       {
           for(int index=0;index<y;index++) 
                {
                fscanf(except,"%d",&z);
                } 
           fscanf(except,"%s",x);
          
        }
        
}//while ends here


//now exceptions are checked, let's use some intelligence of the language 
//we will check suffixes as given in rule database and remove suffix then check it in root words database
if(done==0)
{
   getcwd(the_path, 256);
   strcat(the_path, "/data/rules");
   ds = fopen(the_path, "r");
   
   while(fscanf(ds,"%s",x)!=EOF)
   {
      len1=strlen(x);
      if(len>=len1)sub=str.substr(len-len1,len1);
      strcpy(subs,sub.c_str());
      fscanf(ds,"%d",&y);
      
      if(strcmp(subs,x)==0)
            { 
              for(int index=0;index<y;index++) 
                    {
                      fscanf(ds,"%d",&z); 
                      if(index>=1)cout<<"\t    ";
                      show_output(z); 
                      noun_ar->row=z/10; 
                      noun_ar->col=z%10;
                      noun_ar->row1[noun_ar->row_l]=z/10; 
                      (noun_ar->row_l)++; 
                    } 
               sub=str.substr(0,len-len1); 
               strcpy(subs,sub.c_str());
               ged=check_noun_database(subs); 
               if(ged==1)
                    {
                      noun_ar->sex=sex; 
                      noun_ar->n_p=n_p; 
                      strcpy(noun_ar->root,pass_root1); 
                      (*noun_l)++; 
                      strcpy(noun_ar->meaning,pass_meaning1);
                      return 1; 
                    }  
               else 
                   break; 
                   
            }//if(strcmp (subs,x)==0)ends here


  }//while ends here

return 0;
}//if done ends here

} //main function ends here

//below is the function to check the roots in database

int check_noun_database(char roots[100])
{
char x[30],the_path[256];
FILE *f;
int y;
getcwd(the_path, 255);
strcat(the_path, "/data/root_words");
f = fopen(the_path, "r");
while(fscanf(f,"%s",x)!=EOF)
     {
       if(strcmp(x,roots)==0) 
            {
              fscanf(f,"%d",&y);
              show_output1(y);
              fscanf(f,"%d",&y);
              show_output1(y); 
              fscanf(f,"%s",x); 
              printf("\t    and the root is: %s\n",x); 
              fscanf(f,"%s",pass_meaning1);
              printf("\t    and the meaning is %s\n",pass_meaning1);
              strcpy(pass_root1,x); 
              return 1;
            }
            
       else 
            {
              fscanf(f,"%d",&y); 
              fscanf(f,"%d",&y); 
              fscanf(f,"%s",x); 
              fscanf(f,"%s",x);
            }
            
     }//while loop ends here

return 0;
}//check_verb_database function ends here

//below is a program for displaying information about individual lexer

void show_output(int z)
{
int f,s;
f=z/10;
s=z%10;
switch(f)
   {
     	case 1:cout<<"Nominative"; 
     	  break;
 	case 2:cout<<"Accusative"; 
 	  break;
	case 3:cout<<"Instrumental"; 
	  break;
	case 4:cout<<"Dative"; 
	  break;
	case 5:cout<<"Ablative"; 
	  break;
	case 6:cout<<"Genitive"; 
	  break;
	case 7:cout<<"Locative"; 
	  break;
   
  }//switch ends

switch(s)
  {
	case 1: cout<<",Singular\n"; 
	  break;
	case 2: cout<<",Dual\n";  
	  break;
	case 3: cout<<",Plural\n"; 
	  break;
  }//switch ends

}//function show_output ends here

void show_output1(char y)
{
switch(y)
  {
	case 1: cout<<"\t    "<<"Gender-Masculine"; sex=1;
	  break;
	case 2: cout<<"\t    "<<"Gender-Feminine"; sex=2; 
	  break;
	case 3: cout<<"\t    "<<"Gender-Neuter"; sex=3; 
	  break;
	case 4: cout<<"\t    "<<"Gender-N/A"; sex=4; 
	  break;
	case 5: cout<<" ,noun\n"; n_p=5; 
	  break;
	case 6: cout<<" ,pronoun\n"; n_p=6; 
	  break;
  
  } //switch ends here

}//show_output1 function ends here

//a problem may arise in this problem> let say it prints out about the form of the word but it doesn't exist in the database in that case it might not be right form
//hence interpreted as a noun.. that would cause problem...... 
