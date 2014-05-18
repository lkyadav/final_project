//lat=1,lot=2,lang=3,lrita=4
char pass_root[30];
char pass_meaning[50];
#include "functions.h"
#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
int lakar1(char[],int,verbs *,int *);


int lakar1(char a[100],int len,verbs *verb_ar,int *verb_l)
{
int i,j,k,retn=0;
string sub,sub1,sub2,sub3,sub4,roota,show_out;
char subs[15],subs1[7],subs2[4],subs3[4],subs4[10],roots[30];
std::string str(a);
if(len>11) sub=str.substr(len-4*3,len-1);
if(len>5) sub1=str.substr(len-2*3,len-1);
if(len>=3)sub2=str.substr(len-3,len-1);
if(len>=9)sub4=str.substr(len-3*3,len-1);
strcpy(subs,sub.c_str());
strcpy(subs1,sub1.c_str());
strcpy(subs2,sub2.c_str());
strcpy(subs4,sub4.c_str());
/*initialization completes here:
1. subs> a character array that stores last four characters.
2. subs1> a character array that stores last two  characters.
3. subs2> a character array that stores last one character.
3. subs3> a character array that will be used further as required (for making new substrings)
4. subs4> a character array that stores last three characters.
*/


if(strcmp(subs,"न्ति")==0)
{
       if(len>=21){
             if(len>=21)sub3=str.substr(len-7*3,9);
             strcpy(subs3,sub3.c_str());

       }
        if(strcmp(subs3,"ष्य")==0){
             show_out= "future-tense first-person,plural\n";
             verb_ar->tense=4;
             verb_ar->row=1;
             verb_ar->col=3;
             if(len>=24)
                  roota=str.substr(0,len-8*3);
             strcpy(roots,roota.c_str());

       }else if(strcmp(subs3,"स्य")==0){
             show_out= "future-tense first-person,plural\n";
             verb_ar->tense=4;
             verb_ar->row=1;
             verb_ar->col=3;
             if(len>=21)
                   roota=str.substr(0,len-7*3);
             strcpy(roots,roota.c_str());

       }else if(strcmp(subs3,"छ्य")==0){
             show_out= "future-tense first-person,plural\n";
             verb_ar->tense=4;
             verb_ar->row=1;
             verb_ar->col=3;
             if(len>=21)
                  roota=str.substr(0,len-7*3);
             strcpy(roots,roota.c_str());

       } else {
             show_out= "present-tense,first-person,plural\n";
             verb_ar->tense=1;
             verb_ar->row=1;
             verb_ar->col=3;
             if(len>=12)
                  roota=str.substr(0,len-4*3);
             strcpy(roots,roota.c_str());

       }retn=check_verb_database(roots);
        if(retn==1){
                   cout<< show_out<<"\n";
                   strcpy(verb_ar->root,pass_root);
                   strcpy(verb_ar->meaning,pass_meaning);
                   (* verb_l)++;
                   return 1;
                   }
                   else
                      return 0;

}



else if(strcmp(subs1,"ति")==0)
{
       if(len>=15){
               if(len>=15)sub3=str.substr(len-5*3,9);
               strcpy(subs3,sub3.c_str());

       }if(strcmp(subs3,"ष्य")==0){
                show_out= "future-tense first-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=1;
                verb_ar->col=1;
                if(len>=18)
                     roota=str.substr(0,len-6*3);
                strcpy(roots,roota.c_str());

       }else if(strcmp(subs3,"स्य")==0){
                show_out= "future-tense first-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=1;
                verb_ar->col=1;
                if(len>=15)
                     roota=str.substr(0,len-5*3);
                strcpy(roots,roota.c_str());}
        else if(strcmp(subs3,"छ्य")==0){
                show_out= "future-tense first-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=1;
                verb_ar->col=1;
                if(len>=15)
                    roota=str.substr(0,len-5*3);
                strcpy(roots,roota.c_str());

        }else {
                show_out= "present-tense,first-person,singular";
                verb_ar->tense=1;
                verb_ar->row=1;
                verb_ar->col=1;
                if(len>=6)
                     roota=str.substr(0,len-2*3);
                strcpy(roots,roota.c_str());
        }retn=check_verb_database(roots);
        if(retn==1){
                  cout<< show_out<<"\n";
                  strcpy(verb_ar->root,pass_root);
                  strcpy(verb_ar->meaning,pass_meaning);
                  (* verb_l)++;
                  return 1;
                   }
                   else
                   return 0;
}



else if(strcmp(subs1,"सि")==0)
{       if(len>=15){
               if(len>=15)
                    sub3=str.substr(len-5*3,9);
                strcpy(subs3,sub3.c_str());
        }if(strcmp(subs3,"ष्य")==0){
                show_out= "future-tense second-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=2;
                verb_ar->col=1;
                if(len>=18)
                     roota=str.substr(len-len,len-6*3);
                strcpy(roots,roota.c_str());

        }else if(strcmp(subs3,"स्य")==0){
                show_out= "future-tense second-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=2;
                verb_ar->col=1;
                if(len>=15)
                     roota=str.substr(0,len-5*3);
                strcpy(roots,roota.c_str());

        }else if(strcmp(subs3,"छ्य")==0){
                show_out= "future-tense second-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=2;
                verb_ar->col=1;
                if(len>=15)
                     roota=str.substr(0,len-5*3);
                strcpy(roots,roota.c_str());

        }else{
                show_out= "present-tense,second-person,singular";
                verb_ar->tense=1;
                verb_ar->row=2;
                verb_ar->col=1;
                if(len>=6)
                      roota=str.substr(0,len-2*3);
                strcpy(roots,roota.c_str());

         }retn=check_verb_database(roots);
          if(retn==1){
                    cout<< show_out<<"\n";
                    strcpy(verb_ar->root,pass_root);
                    strcpy(verb_ar->meaning,pass_meaning);
                    (* verb_l)++;
                    return 1;
                    }
               else return 0;
}

else if(strcmp(subs1,"मि")==0)
{       if(len>=18){
                sub3=str.substr(len-6*3,9);
                strcpy(subs3,sub3.c_str());

        }if(strcmp(subs3,"ष्य")==0){
                show_out= "future-tense third-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=3;
                verb_ar->col=1;
                if(len>=21)
                     roota=str.substr(0,len-7*3);
                strcpy(roots,roota.c_str());

        }else if(strcmp(subs3,"स्य")==0){
                show_out= "future-tense third-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=3;
                verb_ar->col=1;
                if(len>=18)
                    roota=str.substr(0,len-6*3);
                strcpy(roots,roota.c_str());
        }else if(strcmp(subs3,"छ्य")==0){
                show_out= "future-tense third-person,singular\n";
                verb_ar->tense=4;
                verb_ar->row=3;
                verb_ar->col=1;
                if(len>=18)
                     roota=str.substr(0,len-6*3);
                strcpy(roots,roota.c_str());

        }else {
                show_out= "present-tense,third-person,singular";
                verb_ar->tense=1;
                verb_ar->row=3;
                verb_ar->col=1;
                if(len>=9)
                     roota=str.substr(0,len-3*3);
                strcpy(roots,roota.c_str());

        }retn=check_verb_database(roots);
         if(retn==1){
                  cout<< show_out<<"\n";
                  strcpy(verb_ar->root,pass_root);
                  strcpy(verb_ar->meaning,pass_meaning);
                  (* verb_l)++;
                  return 1;
                    }
            else
                  return 0;
}

else if(strcmp(subs2,"थ")==0)
{      if(len>=12){
                sub3=str.substr(len-4*3,9);
                strcpy(subs3,sub3.c_str());

       }if(strcmp(subs3,"ष्य")==0){
                show_out= "future-tense second-person,plural\n";
                verb_ar->tense=4;
                verb_ar->row=2;
                verb_ar->col=3;
                if(len>=15)
                    roota=str.substr(0,len-5*3);
                strcpy(roots,roota.c_str());

       }else if(strcmp(subs3,"स्य")==0){
                show_out= "future-tense ,second-person ,plural\n";
                verb_ar->tense=4;
                verb_ar->row=2;
                verb_ar->col=3;
                if(len>=12)
                     roota=str.substr(0,len-4*3);
                strcpy(roots,roota.c_str());

       }else if(strcmp(subs3,"छ्य")==0){
                show_out= "future-tense ,second-person ,plural\n";
                verb_ar->tense=4;
                verb_ar->row=2;
                verb_ar->col=3;
                if(len>=12)
                      roota=str.substr(0,len-4*3);
                      strcpy(roots,roota.c_str());
       }else{
                show_out= "present-tense, second-person ,plural";
                verb_ar->tense=1;
                verb_ar->row=2;
                verb_ar->col=3;
                if(len>=3)
                    roota=str.substr(0,len-1*3);
                    strcpy(roots,roota.c_str());

       }retn=check_verb_database(roots);
       if(retn==1){
                   cout<< show_out<<"\n";
                   strcpy(verb_ar->root,pass_root);
                   strcpy(verb_ar->meaning,pass_meaning);
                   (* verb_l)++;
                   return 1;
                  }
           else
                 return 0;
}



else if(strcmp(subs,"न्तु")==0)
{
	       show_out= "command, first-person, plural";
	       verb_ar->tense=2;
	       verb_ar->row=1;
	       verb_ar->col=3;
	       if(len>=12)
	            roota=str.substr(0,len-4*3);
	       strcpy(roots,roota.c_str());
	       retn=check_verb_database(roots);
	       if(retn==1)
	              {
	               cout<< show_out<<"\n";
	               strcpy(verb_ar->root,pass_root);
	               strcpy(verb_ar->meaning,pass_meaning);
	               (* verb_l)++;
	               return 1;
	              }
	        else
	            return 0;
}

else if(strcmp(subs1,"तु")==0)
{              show_out= "command, first-person, singular";
               verb_ar->tense=2;
               verb_ar->row=1;
               verb_ar->col=1;
               if(len>=6)
                   roota=str.substr(0,len-2*3);
               strcpy(roots,roota.c_str());
               retn=check_verb_database(roots);
               if(retn==1)
                    {
                     cout<< show_out<<"\n";
                     strcpy(verb_ar->root,pass_root);
                     strcpy(verb_ar->meaning,pass_meaning);
                     (* verb_l)++;
                     return 1;
                    }
               else
                   return 0;
 }

else if(strcmp(subs1,"नि")==0)
{              show_out= "command, third-person, singular"; verb_ar->tense=2; verb_ar->row=3; verb_ar->col=1;
               if(len>=3)roota=str.substr(0,len-3*3);
               strcpy(roots,roota.c_str());
               retn=check_verb_database(roots); if(retn==1){cout<< show_out<<"\n"; strcpy(verb_ar->root,pass_root); strcpy(verb_ar->meaning,pass_meaning); (* verb_l)++; return 1;} else return 0;
}

else if(strcmp(subs4,"ाम्")==0)
{
                sub3=str.substr(0,3);
                strcpy(subs3,sub3.c_str());
                if(strcmp(subs3,"आ")==0) {
                                          show_out="past-tense, first-person, dual";
                                          verb_ar->tense=3;
                                          verb_ar->row=1;
                                          verb_ar->col=2;
                                          }

             else if(strcmp(subs3,"अ")==0){
                                         if((len-15)>=6){
                                                        show_out= "past-tense, first-person, dual";
                                                        verb_ar->tense=3;
                                                        verb_ar->row=1;
                                                        verb_ar->col=2;
                                                        }

                                                  else {
                                                        show_out= "command, first-person, dual";
                                                        verb_ar->tense=2;
                                                        verb_ar->row=1;
                                                        verb_ar->col=2;
                                                        }

                                        }

                                   else {
                                        show_out="command, first-person, dwiwachan";
                                        verb_ar->tense=2;
                                        verb_ar->row=1;
                                        verb_ar->col=2;
                                        }

                if(len>=12)roota=str.substr(0,len-4*3);
                strcpy(roots,roota.c_str());
                retn=check_verb_database(roots);
                if(retn==1)
                      {
                       cout<< show_out<<"\n";
                       strcpy(verb_ar->root,pass_root);
                       strcpy(verb_ar->meaning,pass_meaning);
                       (* verb_l)++;
                       return 1;
                      }
                      else
                        return 0;

}

else if(strcmp(subs4,"तम्")==0)
{              sub3=str.substr(0,3);
               strcpy(subs3,sub3.c_str());
               if(strcmp(subs3,"आ")==0) {
                                           show_out="past-tense, second-person, dual";
                                           verb_ar->tense=3;
                                           verb_ar->row=2;
                                           verb_ar->col=2;
                                        }

           else if(strcmp(subs3,"अ")==0){
                                          if((len-12)>=6)
                                                     {show_out= "past-tense, second-person, dual";
                                                      verb_ar->tense=3;
                                                      verb_ar->row=2;
                                                      verb_ar->col=2;
                                                     }

                                                 else{
                                                      show_out="command, second-person, dual";
                                                      verb_ar->tense=2;
                                                      verb_ar->row=2;
                                                      verb_ar->col=2;
                                                      }

                                       }

                                 else {
                                         show_out="command, second-person, dwiwachan";
                                         verb_ar->tense=2;
                                         verb_ar->row=2;
                                         verb_ar->col=2;
                                      }

               if(len>=9)
                   roota=str.substr(0,len-3*3);
               strcpy(roots,roota.c_str());
               retn=check_verb_database(roots);
               if(retn==1)
                    {
                      cout<< show_out<<"\n";
                      strcpy(verb_ar->root,pass_root);
                      strcpy(verb_ar->meaning,pass_meaning);
                      (* verb_l)++;
                      return 1;
                    }
               else
                  return 0;

}

else if(strcmp(subs2,"व")==0)
{              sub3=str.substr(0,3);
               strcpy(subs3,sub3.c_str());
               if(strcmp(subs3,"आ")==0)
                                       {show_out="past-tense, third-person, dual";
                                        verb_ar->tense=3;
                                        verb_ar->row=3;
                                        verb_ar->col=2;
                                        }

           else if(strcmp(subs3,"अ")==0){
                                        if((len-9)>=6)
                                                   {show_out= "past-tense, third-person, dual";
                                                    verb_ar->tense=3;
                                                    verb_ar->row=3;
                                                    verb_ar->col=2;
                                                    }
                                        else
                                                    {show_out= "command, third-person, dual";
                                                     verb_ar->tense=2;
                                                     verb_ar->row=3;
                                                     verb_ar->col=2;
                                                    }

                                        }

                                   else {
                                       show_out="command, third-person, dual";
                                       verb_ar->tense=2;
                                       verb_ar->row=3;
                                       verb_ar->col=2;
                                       }

               if(len>=6)roota=str.substr(0,len-2*3);
               strcpy(roots,roota.c_str());
               retn=check_verb_database(roots);
               if(retn==1)
                    {cout<< show_out<<"\n";
                     strcpy(verb_ar->root,pass_root);
                     strcpy(verb_ar->meaning,pass_meaning);
                     (* verb_l)++;
                     return 1;
                     }
                     else
                     return 0;

}

else if(strcmp(subs2,"म")==0)
{              sub3=str.substr(0,3);
               strcpy(subs3,sub3.c_str());
               if(strcmp(subs3,"आ")==0){
                                     show_out="past-tense, third-person, plural";
                                     verb_ar->tense=3;
                                     verb_ar->row=3;
                                     verb_ar->col=3;
                                        }

           else if(strcmp(subs3,"अ")==0){
                                    if((len-9)>=6){
                                               show_out= "past-tense, third-person, plural";
                                               verb_ar->tense=3; verb_ar->row=3;
                                               verb_ar->col=3;
                                                  }

                                             else {

                                              show_out="command, third-person, plural";
                                              verb_ar->tense=2;
                                              verb_ar->row=3;
                                              verb_ar->col=3;
                                                  }

            }else            {
                                  show_out= "command, third-person, plural";
                                  verb_ar->tense=2;
                                  verb_ar->row=3;
                                  verb_ar->col=3;
                             }

               if(len>=6)roota=str.substr(0,len-2*3);
               strcpy(roots,roota.c_str());
               retn=check_verb_database(roots);

               if(retn==1){
                        cout<< show_out<<"\n";
                        strcpy(verb_ar->root,pass_root);
                        strcpy(verb_ar->meaning,pass_meaning);
                        (* verb_l)++;
                        return 1;
                          }
               else return 0;

}

else if(strcmp(subs2,"त")==0)
{              sub3=str.substr(0,3);
               strcpy(subs3,sub3.c_str());
               if(strcmp(subs3,"आ")==0){
                                         show_out="past-tense, second-person, plural";
                                         verb_ar->tense=3;
                                         verb_ar->row=2;
                                         verb_ar->col=3;
                                       }

          else if(strcmp(subs3,"अ")==0){
                                        if((len-6)>=6){
                                                        show_out= "past-tense, second-person, plural";
                                                        verb_ar->tense=3;
                                                        verb_ar->row=2;
                                                        verb_ar->col=3;
                                                      }

                                                 else {
                                                        show_out= "command, second-person, plural";
                                                        verb_ar->tense=2;
                                                        verb_ar->row=2;
                                                        verb_ar->col=3;
                                                      }

                                        }

                                  else {
                                          show_out="command, second-person, plural";
                                          verb_ar->tense=2;
                                          verb_ar->row=2;
                                          verb_ar->col=3;
                                       }

               if(len>=3)
                  roota=str.substr(0,len-3);
              strcpy(roots,roota.c_str());
              retn=check_verb_database(roots);
              if(retn==1)
                 {
                    cout<< show_out<<"\n";
                    strcpy(verb_ar->root,pass_root);
                    strcpy(verb_ar->meaning,pass_meaning);
                    (* verb_l)++;
                    return 1;
                 }
              else
                   return 0;
}/*ambiguity exists here between lang and lot*/

else if(strcmp(subs2,"ः")==0)
{

if(strcmp(subs1,"तः")==0){
      if(len>=15){
                if(len>=15)sub3=str.substr(len-5*3,9);
                strcpy(subs3,sub3.c_str());
       } if(strcmp(subs3,"ष्य")==0){
                show_out= "future-tense first-person,dual\n";
                verb_ar->tense=4;
                verb_ar->row=1;
                verb_ar->col=2;
                if(len>=18)
                    roota=str.substr(0,len-6*3);
                    strcpy(roots,roota.c_str());
        } else if(strcmp(subs3,"स्य")==0){
                show_out= "future-tense first-person,dual\n";
                verb_ar->tense=4;
                verb_ar->row=1;
                verb_ar->col=2;
                if(len>=15)
                     roota=str.substr(0,len-5*3);
                strcpy(roots,roota.c_str());
        }
          else if(strcmp(subs3,"छ्य")==0){
                show_out= "future-tense first-person,dual\n";
                verb_ar->tense=4;
                verb_ar->row=1;
                verb_ar->col=2;
                if(len>=15)
                    roota=str.substr(0,len-5*3);
                strcpy(roots,roota.c_str());
        }
           else {
                 sub3=str.substr(0,3);
                 strcpy(subs3,sub3.c_str());
                          if(strcmp(subs3,"आ")==0) {
                                                show_out="past-tense, second-person, first-person-wachan";
                                                verb_ar->tense=3;
                                                verb_ar->row=2;
                                                verb_ar->col=1;
                                                if(len>=3)
                                                     roota=str.substr(0,len-3);
                                                     strcpy(roots,roota.c_str());
                                                   }

                      else if(strcmp(subs3,"अ")==0){
                                                show_out="present-tense, first-person, dual";
                                                verb_ar->tense=1;
                                                verb_ar->row=1;
                                                verb_ar->col=2;
                                                if(len>=6)
                                                     roota=str.substr(0,len-2*3);
                                                strcpy(roots,roota.c_str());
                                                   }

                                               else{
                                                show_out= "present-tense,first-person,dual";
                                                verb_ar->tense=1;
                                                verb_ar->row=1;
                                                verb_ar->col=2;
                                                if(len>=6)
                                                     roota=str.substr(0,len-2*3);
                                                     strcpy(roots,roota.c_str());
                                                   }
                 }
       retn=check_verb_database(roots);
       if(retn==1)
            {
              cout<< show_out<<"\n";
              strcpy(verb_ar->root,pass_root);
              strcpy(verb_ar->meaning,pass_meaning);
              (* verb_l)++; return 1;
            }
       else
            return 0;

  }// tah completes here


else if(strcmp(subs1,"थः")==0){
       if(len>=15){
                if(len>=15)sub3=str.substr(len-5*3,9);
                strcpy(subs3,sub3.c_str());
       }
       if(strcmp(subs3,"ष्य")==0){
               show_out= "future-tense second-person,dual\n";
               verb_ar->tense=4;
               verb_ar->row=2;
               verb_ar->col=2;
               if(len>=18)
                    roota=str.substr(0,len-6*3);
                    strcpy(roots,roota.c_str());
        } else if(strcmp(subs3,"स्य")==0){
                 show_out= "future-tense second-person,dual\n";
                 verb_ar->tense=4;
                 verb_ar->row=2;
                 verb_ar->col=2;
                 if(len>=15)
                     roota=str.substr(0,len-5*3);
                 strcpy(roots,roota.c_str());
        } else if(strcmp(subs3,"छ्य")==0){
                 show_out= "future-tense, second-person ,dual\n";
                 verb_ar->tense=4;
                 verb_ar->row=2;
                 verb_ar->col=2;
                 if(len>=15)
                     roota=str.substr(0,len-5*3);
                 strcpy(roots,roota.c_str());
        } else {
                show_out= "present-tense, second-person , dual";
                verb_ar->tense=1;
                verb_ar->row=2;
                verb_ar->col=2;
                if(len>=6)roota=str.substr(0,len-2*3);
                strcpy(roots,roota.c_str());
                }
       retn=check_verb_database(roots);
       if(retn==1)
           {
              cout<< show_out<<"\n";
              strcpy(verb_ar->root,pass_root);
              strcpy(verb_ar->meaning,pass_meaning);
              (* verb_l)++;
              return 1;
           }
       else
              return 0;

       }//thah completes here

/**/
else if(strcmp(subs1,"वः")==0){
	if(len>=15){
		if(len>=18)sub3=str.substr(len-6*3,3*3);
		strcpy(subs3,sub3.c_str());
	}

	if(strcmp(subs3,"ष्य")==0){
		show_out= "future-tense third-person, dual\n";
		verb_ar->tense=4;
		verb_ar->row=3;
		verb_ar->col=2;
		if(len>=21)
		     roota=str.substr(0,len-7*3);
		strcpy(roots,roota.c_str());

	} else if(strcmp(subs3,"स्य")==0){
		show_out= "future-tense third-person ,dual\n";
		verb_ar->tense=4;
	        verb_ar->row=3;
	        verb_ar->col=2;
		if(len>=18)
		     roota=str.substr(0,len-6*3);
		strcpy(roots,roota.c_str());

	} else if(strcmp(subs3,"छ्य")==0){
		show_out= "future-tense third-person ,dual\n";
		verb_ar->tense=4;
		verb_ar->row=3;
		verb_ar->col=2;
		if(len>=18)
		    roota=str.substr(0,len-6*3);
		strcpy(roots,roota.c_str());

	} else {
		show_out= "present-tense , third-person ,dual";
	        verb_ar->tense=1;
	        verb_ar->row=3;
	        verb_ar->col=2;
		if(len>=9)
		     roota=str.substr(0,len-3*3);
		strcpy(roots,roota.c_str());
	}
	retn=check_verb_database(roots);
	if(retn==1)
	    {
	      cout<< show_out<<"\n";
	      strcpy(verb_ar->root,pass_root);
	      strcpy(verb_ar->meaning,pass_meaning);
	      (* verb_l)++;
	      return 1;
	    }
	 else
	     return 0;

   }//wah completes here




else if(strcmp(subs1,"मः")==0){
	if(len>=18){
		if(len>=18)sub3=str.substr(len-6*3,9);
		strcpy(subs3,sub3.c_str());
	}
	if(strcmp(subs3,"ष्य")==0){
		show_out= "future-tense third-person, plural\n"; verb_ar->tense=4; verb_ar->row=3; verb_ar->col=3;
		if(len>=21)roota=str.substr(0,len-7*3);
		strcpy(roots,roota.c_str());
	} else if(strcmp(subs3,"स्य")==0){
		show_out= "future-tense third-person ,plural\n"; verb_ar->tense=4; verb_ar->row=3; verb_ar->col=3;
		if(len>=18)roota=str.substr(0,len-6*3);
		strcpy(roots,roota.c_str());
	} else if(strcmp(subs3,"छ्य")==0){
		show_out= "future-tense third-person ,plural\n";verb_ar->tense=4; verb_ar->row=3; verb_ar->col=3;
		if(len>=18)roota=str.substr(0,len-6*3);
		strcpy(roots,roota.c_str());
	} else {
		show_out= "present-tense , third-person ,plural";
		verb_ar->tense=1;
		verb_ar->row=3;
		verb_ar->col=3;
		if(len>=9)
		    roota=str.substr(0,len-3*3);
		strcpy(roots,roota.c_str());

	}//if ends here

    retn=check_verb_database(roots);
    if(retn==1)
       {
          cout<< show_out<<"\n";
          strcpy(verb_ar->root,pass_root);
          strcpy(verb_ar->meaning,pass_meaning);
          (* verb_l)++;
          return 1;
       }
    else
          return 0;

   }//mah completes here


else {
        sub3=str.substr(0,3);
        strcpy(subs3,sub3.c_str());
        if(strcmp(subs3,"अ")==0)
           {
              show_out= "past-tense, second-person, singular";
              verb_ar->tense=3;
              verb_ar->row=2;
              verb_ar->col=1;
           }

        if(len>=3)roota=str.substr(0,len-3);
        strcpy(roots,roota.c_str());
        retn=check_verb_database(roots); if(retn==1){cout<< show_out<<"\n"; strcpy(verb_ar->root,pass_root); strcpy(verb_ar->meaning,pass_meaning); (* verb_l)++; return 1;} else return 0;
  }


}/*ah completes here within this block we handled   tah, thah , mah*/


else if(strcmp(subs1,"त्")==0)
{       show_out= "past-tense, first-person, singular";
        verb_ar->tense=3;
        verb_ar->row=1;
        verb_ar->col=1;
        if(len>=6)
             roota=str.substr(0,len-2*3);
        strcpy(roots,roota.c_str());
        retn=check_verb_database(roots);
        if(retn==1)
           {
             cout<< show_out<<"\n";
             strcpy(verb_ar->root,pass_root);
             strcpy(verb_ar->meaning,pass_meaning);
             (* verb_l)++;
             return 1;
           }
        else
           return 0;
}

else if(strcmp(subs1,"न्")==0)
{       show_out= "past-tense, first-person, plural";
        verb_ar->tense=3;
        verb_ar->row=1;
        verb_ar->col=3;
        if(len>=6)
             roota=str.substr(0,len-2*3);
        strcpy(roots,roota.c_str());
        retn=check_verb_database(roots);

        if(retn==1)
           {
             cout<< show_out<<"\n";
             strcpy(verb_ar->root,pass_root);
             strcpy(verb_ar->meaning,pass_meaning);
             (* verb_l)++;
             return 1;
          }
       else
          return 0;
}


else if(strcmp(subs1,"म्")==0)
{       show_out= "past-tense, third-person, singular";
        verb_ar->tense=3;
        verb_ar->row=3;
        verb_ar->col=1;
        if(len>=6)
             {
               roota=str.substr(0,len-2*3);
             }

        strcpy(roots,roota.c_str());
        retn=check_verb_database(roots);

        if(retn==1)
            {
              cout<< show_out<<"\n";
              strcpy(verb_ar->root,pass_root);
              strcpy(verb_ar->meaning,pass_meaning);
              (* verb_l)++; return 1;
            }
        else
          return 0;
 }

else {return 0;}

}

/*function lakar1 ends here*/


int check_verb_database(char roots[30]){

char x[100];
FILE *f;
char the_path[256];
getcwd(the_path, 255);
strcat(the_path, "/data/verbs");
f = fopen(the_path, "r");

while(fscanf(f,"%s",x)!=EOF)
    {
	if(strcmp(x,roots)==0)
	     {
	       fscanf(f,"%s",x);
	       printf("\n The root is: %s\n",x);
	       strcpy(pass_root,x);
	       fscanf(f,"%s",x);
	       printf("the meaning is: %s\n",x);
	       strcpy(pass_meaning,x);
	       return 1;
	       break;
	     }
       else
             {
               fscanf(f,"%s",x);
               fscanf(f,"%s",x);
             }
    }//while ends here

return 0;

}//function ends here

/*mdash and tamdash ko mix karna hai...*/

