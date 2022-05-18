
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdarg.h>
#include "do_func.c"

#define MEMSIZE (64*1024)
#define pc reg[7]



byte mem[MEMSIZE];
word reg[8];

int trace_flag = 0;





//void trace(char * format, ...) {
//    if (trace_flag){
//        va_list ptr;
//    }
//}
void test_mem() {
    printf("%s", "\nTesting b_write\n");
    byte b0 = 0x0a;
    b_write(2, b0);
    byte bres = b_read(2);
    printf("%02hhx = %02hhx\n", b0, bres);
    assert(b0 == bres);
    
    printf("%s", "\nTesting b_write of word\n");
    Adress a = 4;
    byte b1 = 0x0b;
    b0 = 0x0a;
    word w = 0x0b0a;
    b_write(a, b0);
    b_write(a+1, b1);
    word wres = word_read(a);
    printf("ww/br \t %04hx=%02hhx%02hhx\n", wres, b1, b0);
    assert(wres == w);
    
    printf("%s", "\nTesting word_write\n");
    word m = 0x0c0b;
    word_write(8, m);
    wres = word_read(8);
    printf("%04hx\n", wres);
    assert(wres == m);
}


void b_write(Adress adr, byte b) {
    
    mem[adr] = b;
}
byte b_read(Adress adr) {
    
    return mem[adr];
    
}


word word_read(Adress a) {
    
    word w = ((word)mem[a+1]) << 8;
    w = w | mem[a];

    
    return w;
        
}

void word_write(Adress adr, word w)
{
    mem[adr+1] = (byte) (w >> 8);
    mem[adr] = (byte) (w);
}


//void load_file(const char * filename) {
//
//
//    int adress, num;
//    Adress adr, n;
//    byte a;
//    FILE *data;
//    data = fopen(filename, "r");
//    fscanf(data,"%d %d", &adress, &num);
//    adr = (Adress) adress;
//    n = (Adress) num;
//    for (Adress i = 0; i < n; i++){
//        fscanf(data, "%hhx", &a);
//        b_write(adr+i, a);
//    }
//
//}

void load_file(const char *file) {
    Adress a, n;
    byte k;

    FILE *f = fopen(file, "r");
    if (f == NULL) {
        perror(file);
        exit(1);
    }

    while (fscanf(f, "%hx%hx", &a, &n) != EOF) {
        for (Adress i = 0; i < n; i++) {
            fscanf(f, "%hhx", &k);
            b_write(a + i, k);
        }
    }
    fclose(f);
}
void run(){
    trace("----------running-----------\n");
    pc = 01000;
    while(1) {
        
        word w = word_read(pc);
        trace("%06o %06o: ", pc, w);
        pc+=2;
        int i = 0;
        while ((w & cmd[i].mask) != cmd[i].opcode) {
            i++;
        }
        trace("%s\t\n", cmd[i].name);
        cmd[i].do_func();
    }
}

void usage(const char *progname) {
    fprintf(stderr, "USAGE: %s [-t] FILE\n ", progname);
    fprintf(stderr, "\t-t - trace on\n ");
}

void trace(char * format, ...) {
    if (trace_flag) {
        va_list ptr;
        va_start(ptr, format);
        vfprintf(stderr, format, ptr);
        va_end(ptr);
    }
}
int main(int argc, char * argv[]) {
    if (argc == 1) {
        usage(argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == 't'){
                trace_flag = 1;
            }else {
                usage(argv[0]);
                return 1;
            }
        } else
            load_file(argv[i]);
    }
    trace("\n");
    run();
    return 0;
}
