int check_noun_database(char[]);
int check_verb_database(char[]);
typedef struct{
int n_p;
int sex;
short row;
short row1[3];
short row_l;
short col;
char root[100];
char meaning[100];
}nouns;

typedef struct{
short tense;
short row;
short col;
char root[30];
char meaning[20];
}verbs;

typedef struct{
char value[50];
int type;
char meaning[20];
}indeclined;

//sex assumptions: 1-masculine 2-feminine 3-neuter 4-n/a 5-noun hai 6-pronoun hai//// 
//n_p shows whether its a noun or pronoun
//indeclined types:
//.unknown
//8.ek word connector 
//9. 2 word connector
//10. question
//11. 2 word connector.
//12. 1675 lines of project total

