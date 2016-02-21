/* Copyright 2016 Marc Volker Dickmann */
/* Project: GiantNbr */
#include <stdio.h>
#include <stdlib.h>
#include "../lib/dutils.h"
#include "../giantnbr.h"

#define GNBR_TEST_ASIZE 1000

static void gnbr_test (void)
{
	unsigned int *nbr_a, *nbr_b, *nbr_c, *nbr_tmp;
	char a;
	
	gnbr_init_array_int (&nbr_a, GNBR_TEST_ASIZE, 0);
	gnbr_init_array_int (&nbr_b, GNBR_TEST_ASIZE, 0);
	gnbr_init_array_int (&nbr_c, GNBR_TEST_ASIZE, 0);
	gnbr_init_array_int (&nbr_tmp, GNBR_TEST_ASIZE, 0);
	
	/* A < B */
	nbr_a[0] = 10;
	nbr_a[1] = 0;
	nbr_b[0] = 3;
	nbr_b[1] = 10;
	
	/*gnbr_print_array_int (nbr_a, GNBR_TEST_ASIZE);
	
	printf ("-\n");
	
	gnbr_print_array_int (nbr_b, GNBR_TEST_ASIZE);*/
	
	gnbr_subtract_array_int (nbr_a, nbr_b, nbr_c, GNBR_TEST_ASIZE);
	gnbr_print_array_int (nbr_c, GNBR_TEST_ASIZE);
	
	gnbr_setnegative_array_int (nbr_b, GNBR_TEST_ASIZE, TRUE);
	
	/*gnbr_print_array_int (nbr_c, GNBR_TEST_ASIZE);
	
	printf ("+\n");
	
	gnbr_print_array_int (nbr_b, GNBR_TEST_ASIZE);*/
	
	gnbr_add_array_int (nbr_c, nbr_b, nbr_tmp, GNBR_TEST_ASIZE);
	gnbr_print_array_int (nbr_tmp, GNBR_TEST_ASIZE);
	
	/* A > B */
	nbr_a[0] = 10;
	nbr_a[1] = 20;
	nbr_b[0] = 3;
	nbr_b[1] = 1;
	
	/*gnbr_print_array_int (nbr_a, GNBR_TEST_ASIZE);
	
	printf ("-\n");
	
	gnbr_print_array_int (nbr_b, GNBR_TEST_ASIZE);*/
	
	gnbr_subtract_array_int (nbr_a, nbr_b, nbr_c, GNBR_TEST_ASIZE);
	gnbr_print_array_int (nbr_c, GNBR_TEST_ASIZE);
	
	gnbr_setnegative_array_int (nbr_b, GNBR_TEST_ASIZE, TRUE);
	
	/*gnbr_print_array_int (nbr_c, GNBR_TEST_ASIZE);
	
	printf ("+\n");
	
	gnbr_print_array_int (nbr_b, GNBR_TEST_ASIZE);*/
	
	gnbr_add_array_int (nbr_c, nbr_b, nbr_tmp, GNBR_TEST_ASIZE);
	gnbr_print_array_int (nbr_tmp, GNBR_TEST_ASIZE);
	
	/* A * B */
	gnbr_fill_array_int (nbr_a, GNBR_TEST_ASIZE, 0);
	gnbr_fill_array_int (nbr_b, GNBR_TEST_ASIZE, 0);
	gnbr_fill_array_int (nbr_c, GNBR_TEST_ASIZE, 0);
	gnbr_fill_array_int (nbr_tmp, GNBR_TEST_ASIZE, 0);
	
	nbr_a[0] = 5;
	nbr_b[0] = 10;
	
	gnbr_multiply_array_int (nbr_a, nbr_b, nbr_c, nbr_tmp, GNBR_TEST_ASIZE);
	gnbr_print_array_int (nbr_c, GNBR_TEST_ASIZE);
	
	/* FACTORIAL */
	gnbr_fill_array_int (nbr_a, GNBR_TEST_ASIZE, 0);
	gnbr_fill_array_int (nbr_c, GNBR_TEST_ASIZE, 0);
	
	nbr_a[0] = 1;
	
	gnbr_factorial_array_int (nbr_a, nbr_c, GNBR_TEST_ASIZE, 10);
	gnbr_print_array_int (nbr_a, GNBR_TEST_ASIZE);
	
	/* SQUARE */
	gnbr_fill_array_int (nbr_a, GNBR_TEST_ASIZE, 0);
	gnbr_fill_array_int (nbr_c, GNBR_TEST_ASIZE, 0);
	
	nbr_a[0] = 5;
	
	gnbr_square_array_int (nbr_a, nbr_c, GNBR_TEST_ASIZE, 5);
	gnbr_print_array_int (nbr_a, GNBR_TEST_ASIZE);
	
	gnbr_free_array_int (nbr_a);
	gnbr_free_array_int (nbr_b);
	gnbr_free_array_int (nbr_c);
	gnbr_free_array_int (nbr_tmp);
}

int main (int argc, char* argv[])
{	
	printf ("GiantNbr v. 0.0.1 A (c) 2016 Marc Volker Dickmann\n\n");
	
	gnbr_test ();
	
	return 0;
}
