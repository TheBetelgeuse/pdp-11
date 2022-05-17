#include "pdp-11.h"
#include <stdio.h>
#include <stdlib.h>


Command cmd[] = {
    {0170000, 0010000, "mov", do_mov},
    {0170000, 0060000, "halt", do_halt}
};


void do_halt() {
    printf("%s","THE END!");
    exit(0);
}
void do_mov() {
    ;
}
