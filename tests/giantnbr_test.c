/* Copyright 2016 Marc Volker Dickmann */
/* Project: GiantNbr */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/dutils.h"
#include "../giantnbr.h"

#define TESTS_AMOUNT 2
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
	unsigned int *nbr_a, *nbr_b;
	short passed;
	
	gnbr_init_array_int (&nbr_a, 10, 0);
	gnbr_init_array_int (&nbr_b, 10, 0);
	
	nbr_a[0] = 999999999;
	nbr_a[1] = 999999999;
	nbr_a[2] = 204242;
	
	nbr_b[0] = 1;
	
	gnbr_add_array_int (nbr_a, nbr_b, nbr_a, 10);
	
	if (nbr_a[0] == 0 && nbr_a[1] == 0 && nbr_a[2] == 204243)
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
	
	gnbr_init_array_int (&nbr_a, 10, 0);
	gnbr_init_array_int (&nbr_b, 10, 0);
	gnbr_init_array_int (&nbr_c, 10, 0);
	
	nbr_a[0] = 1;
	nbr_a[1] = 0;
	nbr_a[2] = 2;
	
	nbr_b[0] = 3;
	
	gnbr_subtract_array_int (nbr_a, nbr_b, nbr_c, 10);
	
	if (nbr_c[0] == 999999998 && nbr_c[1] == 999999999 && nbr_c[2] == 1)
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

int main (int argc, char* argv[])
{
	int points;
	
	points = 0;
	
	printf ("GiantNbr v. 0.0.1 A (c) 2016 Marc Volker Dickmann\n\n");
	
	points += gnbr_test_int_addition ();
	points += gnbr_test_int_subtraction ();
	
	tst_print_summary (points);
	
	return 0;
}
