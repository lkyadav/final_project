/*
nouns,verbs,indeclined are struct defined in file functins.h

A:::

all nouns in the sentence (that user gives as input) are stored in noun_ar array(which is array of structures)
similarly verbs in the sentence are stored in verb_ar
          avyaya                           in indecl_ar
and their size is stored in noun_l,verb_l,indecl_l respectively.. actually(their value will be one more then size)
eg: if noun_l=3, that means noun_ar[0],noun_ar[1],noun_ar[2], three nouns have been recorded yet

:::

B:::
convention if I will take some array >x
then to track its length i will take a variable > x_l, eg: noun_l, tracks noun_ar
                                                           verb_l, tracks verb_ar
                                                           indecl_l, tracks indecl_ar
:::

C::: path_trace traces the path, which will be used in parser later
:::                                                      

*/

#define NOUN 2 
#define VERB 1
#define AVYAYA 3
#define PRONOUN 4
#include "functions.h"
#include<iostream> 
#include<string.h>
#include<string>
#include<stdio.h>
extern int check_avyaya_database(char[],indeclined *,int *);                             
extern int lakar1(char[],int,verbs *,int *);
extern int noun(char[],int,nouns *,int *);

//he[3][7]={"सः","तौ","ते"};
//you[3][20]={"त्वम्","युवाम्","यूयम्"};
//I[3][15]={"अहम्","आवाम्","वयम्"};
FILE *f;

nouns noun_ar[4];
verbs verb_ar[4];
indeclined indecl_ar[4];
int noun_l=0,verb_l=0,indecl_l=0;

char path_trace[50][3]; 
short path_trace_l=0;
void parser();
int club(int, char []);
using namespace std;

int main(){

f = fopen("temp", "a+");
fprintf(f,"\n");
string show_out;
verb_ar[0].row=1;
char input[300];
short i=0,j=0,k=0;
char *token;
for(i=0;i<4;i++){noun_ar[i].row_l=0;}

cout<< "enter the string\n";
cin.getline(input,300);
cout<< "lexer running...\n";

strcat(input," end");  //end in the end of input so that we could know where input ends             
token = strtok(input," "); //this function tokenize the input 
cout << token<<":::  ";
i=check_avyaya_database(token,&indecl_ar[indecl_l],&indecl_l); // check avyaya database this function is in avyaya.cpp

	if(i==0){ //if token is not in avyaya
	        j=lakar1(token,strlen(token),&verb_ar[verb_l],&verb_l);  //check for whether it is a verb?? this function is in proxy1.cpp
	          if(j==0) {//not a verb
	                     k=noun(token,strlen(token),&noun_ar[noun_l],&noun_l);//check for whether it is a noun?? this function is in proxynoun.cpp
	                          if(k==0) {cout<<"Not in database. please Add it manually\n";  //nowhere found you have to add it in database
	                                    fprintf(f,"%s ",token);
	                                    path_trace_l++;
	                                    } else     {//yes, token is a noun
	                                               path_trace[path_trace_l][0]=NOUN;  
	                                               path_trace[path_trace_l][1]=noun_ar[noun_l-1].row; 
	                                               path_trace[path_trace_l][2]=verb_ar[verb_l-1].col;                    
	                                               path_trace_l++;
	                                               }
	                        }else{//yes, token is a verb
	                             path_trace[path_trace_l][0]=VERB;  
	                             path_trace[path_trace_l][1]=verb_ar[verb_l-1].row; 
	                             path_trace[path_trace_l][2]=verb_ar[verb_l-1].col;                    
	                             path_trace_l++;
	                             }
	        }else{//yes token is a indeclined or avyaya
	        
	                if(!club(indecl_ar[indecl_l-1].type,indecl_ar[indecl_l-1].meaning))
	                 {
	                   path_trace[path_trace_l][0]=AVYAYA;   
	                   path_trace[path_trace_l][1]=indecl_ar[indecl_l-1].type;
	                   path_trace_l++;
	                 }
	               else{indecl_l--;}
	            
	            }
	      
	      //same thing as above will be repeated again in a while loop this time 

while(strcmp(token=strtok(NULL," "),"end")!=0)
	{ cout << token<<"::: ";
i=check_avyaya_database(token,&indecl_ar[indecl_l],&indecl_l);

	if(i==0){ 
	        j=lakar1(token,strlen(token),&verb_ar[verb_l],&verb_l); 
	               if(j==0) {
	                         k=noun(token,strlen(token),&noun_ar[noun_l],&noun_l);
	                                if(k==0) {cout<<"Not in database. please Add it manually\n"; 
	                                
	                                fprintf(f,"%s ",token);
	                                         path_trace_l++;
	                                         } else{
	                                             //if(noun_ar[noun_l-1].n_p==5)
	                                               path_trace[path_trace_l][0]=NOUN;  
	                                              // else 
	                                               //path_trace[path_trace_l][0]=PRONOUN;
	                                               path_trace[path_trace_l][1]=noun_ar[noun_l-1].row; 
	                                               path_trace[path_trace_l][2]=verb_ar[verb_l-1].col;                    
	                                               path_trace_l++;
	                                               }
	                        }else{
	                             path_trace[path_trace_l][0]=VERB;  
	                             path_trace[path_trace_l][1]=verb_ar[verb_l-1].row; 
	                             path_trace[path_trace_l][2]=verb_ar[verb_l-1].col;                    
	                             path_trace_l++;
	                             }
	        }else{
	        if(!club(indecl_ar[indecl_l-1].type,indecl_ar[indecl_l-1].meaning)){path_trace[path_trace_l][0]=AVYAYA;   
	                                                          path_trace[path_trace_l][1]=indecl_ar[indecl_l-1].type;
	                                                          path_trace_l++;}
	            else{indecl_l--;}

	             }
       
	}//while ends
	
	
	//lexing part is now complete.. and we have also done path_tracing part
	//and some of the avyaya's been hadled. when we call function (club()) in this file
	
	cout<<"________________________________________________________________________________";
	cout<<"parser output is in temp file...\n";
	parser();
	
printf("\n");


return 0;
	
}//function ends

void parser(){

char x[100];


//if(noun_l==0 && verb_l==0)
//{fprintf(f," ");  return;}


int one[6],i,j,s,two[6],six[6],elses[6],one_l=0,two_l=0,six_l=0,else_l=0,colision_one_two[4],colision_l=0;
//array one stores all nominative two stores accusative six stores genetive and elses store all other vibhaktis

        for(i=0;i<indecl_l;i++)
        {
         if(indecl_ar[i].type==10){fprintf(f,"%s ",indecl_ar[i].meaning);}
         else if(indecl_ar[i].type==14){
                                         //this is a bad way of handeling verbs unscalable.. needs to be implemented more efficiently
                                         char adverb[50]=" ";
                                         strcat(adverb,indecl_ar[i].meaning);
                                         strcat(verb_ar[0].meaning,adverb);
                       
                                       }
         else if(indecl_ar[i].type>2) {}//club(indecl_ar[i].type,indecl_ar[i].meaning);}
        }

	for(i=0;i<noun_l;i++)
	{for(j=0;j<noun_ar[i].row_l;j++){
	                           if(noun_ar[i].row1[j]==1){one[one_l]=i;  one_l++;}      
	                           else if(noun_ar[i].row1[j]==2){two[two_l]=i; two_l++;}
	                                 }
	                           if(noun_ar[i].row==6){six[six_l]=i; six_l++;}
			           else if((noun_ar[i].row!=1) && (noun_ar[i].row!=2) && (noun_ar[i].row!=6)){elses[else_l]=i; else_l++;}
	                                
	
	}
	
	if(one_l>0)
	{    if(six_l>0)
	        {fprintf(f,"%s ",noun_ar[six[0]].meaning); 
	         for(i=0;i<one_l;i++) 
	             {
	             if((verb_ar[0].row==1) && (verb_ar[0].col==noun_ar[one[i]].col))
	               {fprintf(f,"%s ",noun_ar[one[i]].meaning); 
	                colision_one_two[colision_l]=one[i];
	                colision_l++;
	               }
	          
	             }
	         fprintf(f,"%s ",verb_ar[0].meaning); 
	         for(i=0;i<two_l;i++) {s=0; for(j=0;j<colision_l;j++){if(two[i]==colision_one_two[j]){s=1; break;}} if(s!=1)fprintf(f,"%s ",noun_ar[two[i]].meaning); }
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==7) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==5) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==4) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==3) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         
	         
	
		 fprintf(f,"\n                       or\n");
		
		 
		 for(i=0;i<one_l;i++) 
	            {
	              if((verb_ar[0].row==1) && (verb_ar[0].col==noun_ar[one[i]].col))
	               {fprintf(f,"%s ",noun_ar[one[i]].meaning); 
	                colision_one_two[colision_l]=one[i];
	                colision_l++;
	               }
	          
	            }
		 
		 
		 fprintf(f,"%s ",verb_ar[0].meaning); 
	         fprintf(f,"%s ",noun_ar[six[0]].meaning); 
	       
	         
	         for(i=0;i<two_l;i++) {s=0; for(j=0;j<colision_l;j++){if(two[i]==colision_one_two[j]){s=1; break;}} if(s!=1)fprintf(f,"%s ",noun_ar[two[i]].meaning); }
	         
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==7) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==5) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==4) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==3) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         
	         
	        
	         }
	    
	    else//if row six is not present
	        {
	         
	          for(i=0;i<one_l;i++) 
	            {
	              if((verb_ar[0].row==1) && (verb_ar[0].col==noun_ar[one[i]].col))
	               {fprintf(f,"%s ",noun_ar[one[i]].meaning); 
	                colision_one_two[colision_l]=one[i];
	                colision_l++;
	               }
	          
	            }
	         
	         fprintf(f,"%s ",verb_ar[0].meaning); 
	         
	          for(i=0;i<two_l;i++) {s=0; for(j=0;j<colision_l;j++){if(two[i]==colision_one_two[j]){s=1; break;}} if(s!=1)fprintf(f,"%s ",noun_ar[two[i]].meaning); }
	         
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==7) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==5) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==4) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==3) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         
	         
	        
	         }
      }
      else//row one is not present
	{fprintf(f,"%s ",verb_ar[0].meaning); 
	for(i=0;i<two_l;i++) fprintf(f,"%s ",noun_ar[two[i]].root); 
	for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==7) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==5) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==4) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	for(i=0;i<else_l;i++){if(noun_ar[elses[i]].row==3) fprintf(f,"%s ",noun_ar[elses[i]].meaning);}
	         
	         
	
	}
	
}





int club(int type,char value[50]){
int i,j=0,k=0;
int checker;char copy[50]="";
switch(type){
case 2:
  strcat(value," ");
  strcpy(copy,value);
  i=path_trace_l-1;
  if(path_trace[i][0]==NOUN) //&& (path_trace[i][1]==2))
  {
  for(i=0;i<noun_ar[noun_l-1].row_l;i++)
           {
            if(noun_ar[noun_l-1].row1[i]==2)
                 {
                  strcat(value,noun_ar[noun_l-1].root);
                  strcpy(noun_ar[noun_l-1].root,value); 
                  strcat(copy,noun_ar[noun_l-1].meaning); 
                  strcpy(noun_ar[noun_l-1].meaning,copy); 
                  k=1; 
                  return 1;
                 }
            }
  }
 
if(k==1)return 1;
else return 0;
 

break;

case 3: 
 
   strcat(value," ");
  strcpy(copy,value);
  for(i=path_trace_l-1;i>=0;i--)
         {
         if(path_trace[i][0]==NOUN)
                 {
                 for(j=0;j<noun_ar[noun_l-1].row_l;j++)
                              {
                               if(noun_ar[noun_l-1].row1[j]==3)
                                            {strcat(value,noun_ar[noun_l-1].root); 
                                            strcpy(noun_ar[noun_l-1].root,value); 
                                            strcat(copy,noun_ar[noun_l-1].meaning); 
                                            strcpy(noun_ar[noun_l-1].meaning,copy); 
                                            k=1;
                                            noun_ar[noun_l-1].row=3; 
                                            return 1; 
                                            }
                                }
                                
                  }
 
          }

if(k==1)return 1;
else return 0;
break;

 
 
if(k==1)return 1;
else return 0;
break;


case 4:

  strcat(value," ");
  strcpy(copy,value);
  for(i=path_trace_l-1;i>=0;i--)
         {
         if(path_trace[i][0]==NOUN)
                 {
                 for(j=0;j<noun_ar[noun_l-1].row_l;j++)
                              {
                               if(noun_ar[noun_l-1].row1[j]==4)
                                            {strcat(value,noun_ar[noun_l-1].root); 
                                            strcpy(noun_ar[noun_l-1].root,value); 
                                            strcat(copy,noun_ar[noun_l-1].meaning); 
                                            strcpy(noun_ar[noun_l-1].meaning,copy); 
                                            k=1;
                                            noun_ar[noun_l-1].row=4; 
                                            return 1; 
                                            }
                                }
                                
                  }
 
          }

if(k==1)return 1;
else return 0;
break;

case 5:

   strcat(value," ");
  strcpy(copy,value);
  for(i=path_trace_l-1;i>=0;i--)
         {
         if(path_trace[i][0]==NOUN)
                 {
                 for(j=0;j<noun_ar[noun_l-1].row_l;j++)
                              {
                               if(noun_ar[noun_l-1].row1[j]==5)
                                            {strcat(value,noun_ar[noun_l-1].root); 
                                            strcpy(noun_ar[noun_l-1].root,value); 
                                            strcat(copy,noun_ar[noun_l-1].meaning); 
                                            strcpy(noun_ar[noun_l-1].meaning,copy); 
                                            k=1;
                                            noun_ar[noun_l-1].row=5; 
                                            return 1; 
                                            }
                                }
                  }
 
          }

if(k==1)return 1;
else return 0;
break;


case 7:

 strcat(value," ");
  strcpy(copy,value);
  for(i=path_trace_l-1;i>=0;i--)
         {
         if(path_trace[i][0]==NOUN)
                 {
                 for(j=0;j<noun_ar[noun_l-1].row_l;j++)
                              {
                               if(noun_ar[noun_l-1].row1[j]==7)
                                            {strcat(value,noun_ar[noun_l-1].root); 
                                            strcpy(noun_ar[noun_l-1].root,value); 
                                            strcat(copy,noun_ar[noun_l-1].meaning); 
                                            strcpy(noun_ar[noun_l-1].meaning,copy); 
                                            k=1;
                                            noun_ar[noun_l-1].row=7; 
                                            return 1; 
                                            }
                                }
                  }
 
          }

if(k==1)return 1;
else return 0;
break;

case 8:
parser();
fprintf(f," %s ",value);
noun_l=0;
verb_l=0;
indecl_l=0;
return 1;
break;

case 9:
parser();
fprintf(f," %s ",value);
noun_l=0;
verb_l=0;
indecl_l=0;
return 1;
break;

case 10:
return 0;
break;

case 11:
parser();
fprintf(f," %s ",value);
noun_l=0;
verb_l=0;
indecl_l=0;
return 1;
break;

case 12:j=1; //handles or
case 13:     //handles and
if(j!=1)
      j=2;
else j=1;      

 int temps;
checker=path_trace[path_trace_l-1][0]*10 + path_trace[path_trace_l-1][1];
short checker1;
strcat(value," ");
for(i=path_trace_l-2;i>=0;i--)
        {
         checker1=path_trace[i][0]*10 + path_trace[i][1];
         if(checker==checker1)
                  {
                   k=1;
                       if(i==path_trace_l-2){
                      
                                           strcat(noun_ar[noun_l-2].root," ");
                                           strcat(noun_ar[noun_l-2].root,value); 
                                           strcat(noun_ar[noun_l-2].root,noun_ar[noun_l-1].root); 
                                           strcat(noun_ar[noun_l-2].meaning," ");
                                           strcat(noun_ar[noun_l-2].meaning,value); 
                                           strcat(noun_ar[noun_l-2].meaning,noun_ar[noun_l-1].meaning);
                                           if(j==2){temps=noun_ar[noun_l-2].col+noun_ar[noun_l-1].col ;
                                           if(temps>3)
                                           noun_ar[noun_l-2].col=3;
                                           else 
                                           noun_ar[noun_l-2].col=temps;}
                                           noun_l--;
                                           }
                       
                       else {
                             strcat(noun_ar[noun_l-2].root,","); 
                             strcat(noun_ar[noun_l-2].root,noun_ar[noun_l-1].root); 
                             strcat(noun_ar[noun_l-2].meaning,","); 
                             strcat(noun_ar[noun_l-2].meaning,noun_ar[noun_l-1].meaning); 
                             if(j==2){temps=noun_ar[noun_l-2].col+noun_ar[noun_l-1].col ;
                              if(temps>3)
                                        noun_ar[noun_l-2].col=3;
                                     else 
                                        noun_ar[noun_l-2].col=temps;}
                             noun_l--;
                             }
                 
                 }//if ends here
      
       else break;
 }//for ends
 if(k==1){return 1;}
 else return 0;

break;


}

}

