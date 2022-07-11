#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "source.h"

int  main(void) //main function begins
{
 
//Uniform random numbers
//uniform("uni.dat", 1000000);

//Gaussian random numbers
gaussian("../data/gau1.dat", 1000000,1,1);


return 0;
}
