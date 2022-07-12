#include <stdio.h>
#include <stdlib.h>
#include "./func.h"

int main(){
    ber_gen("./ber.dat",1000000);
    max_lik_gen("./max_lik.dat",1000000);
    return 0;
}