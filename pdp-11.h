typedef unsigned char byte;                     //8 bit
typedef unsigned short int word;                //16 bit
typedef word Adress;                            //16 bit


typedef struct {
    word mask;
    word opcode;
    char * name;
    word params;
    void (*do_func)(void);
} Command;

typedef struct {
    word val;
    Adress adr;
}ss,dd;


#define LEN_DD 6
#define LEN_SS 6
#define LEN_NN 6
#define LEN_R 3
#define LEN_XX 8
#define HAS_SS (1<<1)
#define HAS_DD (1)
#define HAS_R (1<<3)
#define HAS_NN (1<<2)
#define HAS_XX (1<<4)
#define POSITION_B 15
#define LEN_BYTE 8
#define LEN_WORD 16
#define LEN_BYTE 8
#define LEN_WORD 16



void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void word_write(Adress adr, word w);
word word_read(Adress adr);
void load_file(const char * filename);
void run(void);
void test_mem(void);
void trace(char * format, ...);
void do_halt(void);
void do_mov(void);
void do_add(void);
void do_nothing(void);
void do_sob(void);
void do_clr(void);
void do_ccc(void);
void do_scc(void);
void do_tst(void);
void do_cmp(void);
void do_cln(void);
void do_clz(void);
void do_clv(void);
void do_clc(void);
void do_sen(void);
void do_sez(void);
void do_sev(void);
void do_sec(void);

void set_C(int val);
void set_NZ(word val);

void do_br(void);
void do_beq(void);


