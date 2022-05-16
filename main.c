#include <stdio.h>
#include <assert.h>

typedef unsigned char byte;                     //8 bit
typedef unsigned short int word;                //16 bit
typedef word Adress;                            //16 bit



#define MEMSIZE (64*1024)


byte mem[MEMSIZE];

void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void word_write(Adress adr, word w);
word word_read(Adress adr);






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

int main() {
    test_mem();
    return 0;
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
    printf("w = 0%x\n", w);
    
    return w;
        
}

void word_write(Adress adr, word w)
{
    mem[adr+1] = (byte) (w >> 8);
    mem[adr] = (byte) (w);
}
