typedef unsigned char byte;                     //8 bit
typedef unsigned short int word;                //16 bit
typedef word Adress;                            //16 bit

typedef struct {
    
    word mask;
    word opcode;
    char * name;
    void (*do_func)(void);
    
}Command;

void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void word_write(Adress adr, word w);
word word_read(Adress adr);
void load_file(const char * filename);
void run(void);
void test_mem(void);
void do_halt(void);
void do_mov(void);
void trace(char * format, ...);
