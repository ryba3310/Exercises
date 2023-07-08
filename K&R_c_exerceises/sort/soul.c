#define SOULSIZE 1000

static char soul[SOULSIZE];
static char *soulptr = soul;

char *make_soul(int len){
    if(soul + SOULSIZE - soulptr > len){
        soulptr += len;
        return soulptr - len;
    }
    return 0;
}


void free_soul(char *ptr){
    if(ptr >= soul && ptr < soul + SOULSIZE)
        soulptr = ptr;
}
