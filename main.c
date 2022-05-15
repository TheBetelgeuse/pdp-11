#include <stdio.h>

typedef unsigned char byte;                     //8 bit
typedef unsigned short int word;                //16 bit
typedef word Adress;                            //16 bit



#define MEMSIZE (64*1024)


byte mem[MEMSIZE];

void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void word_write(Adress adr, word w);
word word_read(Adress adr);






int main() {

    byte b0 = 0x0a;
    b_write(2, b0);
    byte bres = b_read(2);
    printf("%02hhx = %02hhx\n", b0, bres);
    return 0;
}

void b_write(Adress adr, byte b) {
    
    mem[adr] = b;
}
byte b_read(Adress adr) {
    
    return mem[adr];
    
}
