#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocptr = allocbuf;


char *allocc(int len){
    if(allocbuf + ALLOCSIZE - allocptr >= len){
        allocptr += len;
        return allocptr - len;
    } else
        return 0;
}

void free_alloc(char *ptr){
    if(ptr >= allocbuf && ptr < allocbuf + ALLOCSIZE)
        allocptr = ptr;
}
