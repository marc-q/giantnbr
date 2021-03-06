/* Copyright 2016 - 2017 Marc Volker Dickmann */
/* Project: GiantNbr */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../lib/dutils.h"
#include "../giantnbr.h"

#define TESTS_AMOUNT 3
#define TESTS_FAIL 0
#define TESTS_PASS 1

/* |--------------------------------------------|
   |			Utils			|
   |--------------------------------------------| */

/*
	Function: tst_print_success (char* tstname);
	Description: Prints the test success message.
	InitVersion: 0.0.1
*/
static void tst_print_success (char* tstname)
{
	printf ("%s:", tstname);
	
	if (strlen (tstname) < 15)
	{
		printf ("\t\t\t");
	}
	else if (strlen (tstname) < 23)
	{
		printf ("\t\t");
	}
	else
	{
		printf ("\t");
	}
	
	printf ("%sSUCCESS%s\n", BC_BLD_GREEN, BC_TXT_RST);
}

/*
	Function: tst_print_fail (char* tstname);
	Description: Prints the test failure message.
	InitVersion: 0.0.1
*/
static void tst_print_fail (char* tstname)
{
	printf ("%s:", tstname);
	
	if (strlen (tstname) < 15)
	{
		printf ("\t\t\t");
	}
	else if (strlen (tstname) < 23)
	{
		printf ("\t\t");
	}
	else
	{
		printf ("\t");
	}
	
	printf ("%sFAIL%s\n", BC_BLD_RED, BC_TXT_RST);
}

/*
	Function: tst_print_summary (int points);
	Description: Prints the summary of all tests.
	InitVersion: 0.0.1
*/
static void tst_print_summary (int points)
{
	printf ("\n+=======================+\n");
	printf ("|  Summary of all tests |\n");
	printf ("+=======================+\n");
	printf ("|  Tests: \t%i\t|\n", TESTS_AMOUNT);
	printf ("+-----------------------+\n");
	printf ("|  Passed:\t%i\t|\n", points);
	printf ("|  Failed:\t%i\t|\n", TESTS_AMOUNT-points);
	printf ("+-----------------------+\n");
}

/* |--------------------------------------------|
   |		    Tests-Int			|
   |--------------------------------------------| */

/*
	Function: gnbr_test_int_addition (void);
	Description: Tests the gnbr_add_array_int function from giantnbr.c.
	InitVersion: 0.0.1
*/
static short gnbr_test_int_addition (void)
{
	unsigned int *nbr_a, *nbr_b, *nbr_c;
	short passed;
	
	/* Add positive to positive. */
	gnbr_init_array_int (&nbr_a, 10, 0);
	gnbr_init_array_int (&nbr_b, 10, 0);
	gnbr_init_array_int (&nbr_c, 10, 0);
	
	nbr_a[0] = 999999999;
	nbr_a[1] = 999999999;
	nbr_a[2] = 204242;
	
	nbr_b[0] = 1;
	
	gnbr_add_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (nbr_c[0] == 0 && nbr_c[1] == 0 && nbr_c[2] == 204243)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Add positive to negative. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 999999999;
	nbr_a[1] = 999999999;
	nbr_a[2] = 204242;
	
	nbr_b[0] = 1;
	
	gnbr_setnegative_array_int (nbr_a, 10, TRUE);
	gnbr_setnegative_array_int (nbr_b, 10, FALSE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_add_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == true &&
	    nbr_c[0] == 999999998 && nbr_c[1] == 999999999 && nbr_c[2] == 204242)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Add negative to positive. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 999999999;
	nbr_a[1] = 999999999;
	nbr_a[2] = 204242;
	
	nbr_b[0] = 1;
	
	gnbr_setnegative_array_int (nbr_a, 10, FALSE);
	gnbr_setnegative_array_int (nbr_b, 10, TRUE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_add_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == false &&
	    nbr_c[0] == 999999998 && nbr_c[1] == 999999999 && nbr_c[2] == 204242)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Add negative to negative. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 999999999;
	nbr_a[1] = 999999999;
	nbr_a[2] = 204242;
	
	nbr_b[0] = 1;
	
	gnbr_setnegative_array_int (nbr_a, 10, TRUE);
	gnbr_setnegative_array_int (nbr_b, 10, TRUE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_add_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == true &&
	    nbr_c[0] == 0 && nbr_c[1] == 0 && nbr_c[2] == 204243)
	{
		tst_print_success ("INT_Addition");
		passed = TESTS_PASS;
	}
	else
	{
		tst_print_fail ("INT_Addition");
		passed = TESTS_FAIL;
	}
	
	gnbr_free_array_int (nbr_a);
	gnbr_free_array_int (nbr_b);
	gnbr_free_array_int (nbr_c);
	return passed;
}

/*
	Function: gnbr_test_int_subtraction (void);
	Description: Tests the gnbr_subtract_array_int function from giantnbr.c.
	InitVersion: 0.0.1
*/
static short gnbr_test_int_subtraction (void)
{
	unsigned int *nbr_a, *nbr_b, *nbr_c;
	short passed;
	
	/* Subtract a positive from an positive number. */
	gnbr_init_array_int (&nbr_a, 10, 0);
	gnbr_init_array_int (&nbr_b, 10, 0);
	gnbr_init_array_int (&nbr_c, 10, 0);
	
	nbr_a[0] = 1;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_subtract_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (gnbr_isnegative_array_int (nbr_c, 10) == false &&
	    nbr_c[0] == 999999998 && nbr_c[1] == 999999999 && nbr_c[2] == 1)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Subtract a positive from an negative number. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 1;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_setnegative_array_int (nbr_a, 10, TRUE);
	gnbr_setnegative_array_int (nbr_b, 10, FALSE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_subtract_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == true &&
	    nbr_c[0] == 4 && nbr_c[1] == 0 && nbr_c[2] == 2)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Subtract a negative from an positive number. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 1;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_setnegative_array_int (nbr_a, 10, FALSE);
	gnbr_setnegative_array_int (nbr_b, 10, TRUE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_subtract_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == false &&
	    nbr_c[0] == 4 && nbr_c[1] == 0 && nbr_c[2] == 2)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Subtract a negative from an negative number. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 1;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_setnegative_array_int (nbr_a, 10, TRUE);
	gnbr_setnegative_array_int (nbr_b, 10, TRUE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_subtract_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == true &&
	    nbr_c[0] == 999999998 && nbr_c[1] == 999999999 && nbr_c[2] == 1)
	{
		tst_print_success ("INT_Subtraction");
		passed = TESTS_PASS;
	}
	else
	{
		tst_print_fail ("INT_Subtraction");
		passed = TESTS_FAIL;
	}
	
	gnbr_free_array_int (nbr_a);
	gnbr_free_array_int (nbr_b);
	gnbr_free_array_int (nbr_c);
	return passed;
}

/*
	Function: gnbr_test_int_multiplication (void);
	Description: Tests the gnbr_multiply_array_int function from giantnbr.c.
	InitVersion: 0.0.1
*/
static short gnbr_test_int_multiplication (void)
{
	unsigned int *nbr_a, *nbr_b, *nbr_c, *nbr_tmp;
	short passed;
	
	/* Multiply two positive numbers. */
	gnbr_init_array_int (&nbr_a, 10, 0);
	gnbr_init_array_int (&nbr_b, 10, 0);
	gnbr_init_array_int (&nbr_c, 10, 0);
	gnbr_init_array_int (&nbr_tmp, 10, 0);
	
	nbr_a[0] = 500000008;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_multiply_array_int (nbr_a, nbr_b, nbr_c, nbr_tmp, 10);
	
	if (gnbr_isnegative_array_int (nbr_c, 10) == false &&
	    nbr_c[0] == 500000024 && nbr_c[1] == 1 && nbr_c[2] == 6)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Multiply a positive with an negative number. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 500000008;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_setnegative_array_int (nbr_a, 10, FALSE);
	gnbr_setnegative_array_int (nbr_b, 10, TRUE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_multiply_array_int (nbr_a, nbr_b, nbr_c, nbr_tmp, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == true &&
	    nbr_c[0] == 500000024 && nbr_c[1] == 1 && nbr_c[2] == 6)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Multiply a negative with an positive number. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 500000008;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_setnegative_array_int (nbr_a, 10, TRUE);
	gnbr_setnegative_array_int (nbr_b, 10, FALSE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_multiply_array_int (nbr_a, nbr_b, nbr_c, nbr_tmp, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == true &&
	    nbr_c[0] == 500000024 && nbr_c[1] == 1 && nbr_c[2] == 6)
	{
		passed = TESTS_PASS;
	}
	else
	{
		passed = TESTS_FAIL;
	}
	
	/* Multiply a negative with an negative number. */
	gnbr_fill_array_int (nbr_a, 10, 0);
	gnbr_fill_array_int (nbr_b, 10, 0);
	gnbr_fill_array_int (nbr_c, 10, 0);
	
	nbr_a[0] = 500000008;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_setnegative_array_int (nbr_a, 10, TRUE);
	gnbr_setnegative_array_int (nbr_b, 10, TRUE);
	gnbr_setnegative_array_int (nbr_c, 10, FALSE);
	gnbr_multiply_array_int (nbr_a, nbr_b, nbr_c, nbr_tmp, 10);
	
	if (passed == TESTS_PASS &&
	    gnbr_isnegative_array_int (nbr_c, 10) == false &&
	    nbr_c[0] == 500000024 && nbr_c[1] == 1 && nbr_c[2] == 6)
	{
		tst_print_success ("INT_Multiplication");
		passed = TESTS_PASS;
	}
	else
	{
		tst_print_fail ("INT_Multiplication");
		passed = TESTS_FAIL;
	}
	
	gnbr_free_array_int (nbr_a);
	gnbr_free_array_int (nbr_b);
	gnbr_free_array_int (nbr_c);
	gnbr_free_array_int (nbr_tmp);
	return passed;
}

int main (int argc, char* argv[])
{
	int points;
	
	points = 0;
	
	printf ("GiantNbr v. 0.0.1 A (c) 2016 - 2017 Marc Volker Dickmann\n\n");
	
	points += gnbr_test_int_addition ();
	points += gnbr_test_int_subtraction ();
	points += gnbr_test_int_multiplication ();
	
	tst_print_summary (points);
	
	return 0;
}
