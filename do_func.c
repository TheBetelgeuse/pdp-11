#include "pdp-11.h"
#include <stdio.h>
#include <stdlib.h>


Command cmd[] = {
        {0170000, 0010000, "mov", HAS_DD | HAS_SS, do_mov},
        {0170000, 0060000, "add", HAS_DD | HAS_SS, do_add},
        {0177000, 0077000, "sob", HAS_R | HAS_NN, do_sob},
        {0077700, 0005000, "clr", HAS_DD, do_clr},
        {0177777, 0000257, "ccc", 0, do_ccc},
        {0177777, 0000277, "scc", 0, do_scc},
        {0177777, 0000270, "sen", 0, do_sen},
        {0177777, 0000250, "cln", 0, do_cln},
        {0177777, 0000244, "clz", 0, do_clz},
        {0177777, 0000242, "clv", 0, do_clv},
        {0177777, 0000241, "clc", 0, do_clc},
        {0177777, 0000250, "cln", 0, do_cln},
        {0177777, 0000264, "sez", 0, do_sez},
        {0177777, 0000262, "sev", 0, do_sev},
        {0177777, 0000261, "sec", 0, do_sec},
        {0177400, 0000400, "br", HAS_XX, do_br},
        {0177400, 0001400, "beq", HAS_XX, do_beq},
        {0177777, 000000,  "halt", 0, do_halt},
        {0000000, 000000,  "unknown command", 0, do_nothing}
};

void do_halt() {
    trace("\n----------halted------------\n");
    exit(0);
}
void do_add() {
    trace("ADD");
}
void do_nothing(){
    trace("unknown");
    exit(10);
}

void do_mov(){
    ;
}
void do_sob(void){
    ;
}
void do_clr(void){
    ;
}
void do_ccc(void){
    ;
}
void do_scc(void){
    ;
}
void do_tst(void){
    ;
}
void do_cmp(void){
    ;
}
void do_cln(void){
    ;
}
void do_clz(void){
    ;
}
void do_clv(void){
    ;
}
void do_clc(void){
    ;
}
void do_sen(void){
    ;
}
void do_sez(void){
    ;
}
void do_sev(void){
    ;
}
void do_sec(void){
    ;
}
void do_br(void){
    ;
}
void do_beq(void){
    ;
}
