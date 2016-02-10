/* Copyright 2016 Marc Volker Dickmann */
/* Project: GiantNbr */
#include <stdio.h>
#include <stdlib.h>
#include "../giantnbr.h"

#define GNBR_TEST_ASIZE 1000

static void gnbr_test (void)
{
	unsigned int nbr_a[GNBR_TEST_ASIZE], nbr_b[GNBR_TEST_ASIZE], nbr_c[GNBR_TEST_ASIZE];
	
	gnbr_init_array_int (nbr_a, GNBR_TEST_ASIZE, 0);
	gnbr_init_array_int (nbr_b, GNBR_TEST_ASIZE, 0);
	gnbr_init_array_int (nbr_c, GNBR_TEST_ASIZE, 0);
	
	nbr_a[0] = 1;
	nbr_b[0] = 1;
	
	gnbr_factorial_array_int (nbr_a, nbr_c, GNBR_TEST_ASIZE, 26);
	gnbr_print_array_int (nbr_a, GNBR_TEST_ASIZE);
}

int main (int argc, char* argv[])
{
	printf ("GiantNbr v. 0.0.1 A (c) 2016 Marc Volker Dickmann\n\n");
	
	gnbr_test ();
	
	return 0;
}
