
#define   MAXTOKEN   1000
enum { NAME, PARENS, BRACKETS };

void dcl();

void dirdcl();

int gettoken(void);

int tokentype;            // type of last token

extern char token[MAXTOKEN];     // last token string

extern char name[MAXTOKEN];      // identifier name

extern char datatype[MAXTOKEN];  // data type * char, int, etc

extern char out[1000];           // output string of declartions


