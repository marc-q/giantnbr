/* Copyright 2016 Marc Volker Dickmann */
/* Project: GiantNbr */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "giantnbr.h"

/*
	Function: gnbr_init_array_int (unsigned int* nbr_array, unsigned int nbr_array_size, int init_value);
	Description: Inits a array of integers with the specified number.
	InitVersion: 0.0.1
*/
void gnbr_init_array_int (unsigned int* nbr_array, unsigned int nbr_array_size, int init_value)
{
	int i;
	
	for (i = 0; i < nbr_array_size; i++)
	{
		nbr_array[i] = init_value;
	}
}

/*
	Function: gnbr_copy_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int nbr_array_size);
	Description: Copys a array of integers to another array.
	InitVersion: 0.0.1
*/
void gnbr_copy_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int nbr_array_size)
{
	int i;
	
	for (i = 0; i < nbr_array_size; i++)
	{
		nbr_array_a[i] = nbr_array_b[i];
	}
}

/*
	Function: gnbr_print_array_int (unsigned int* nbr_array, unsigned int nbr_array_size);
	Description: Prints the number contained in a array of integers.
	InitVersion: 0.0.1
*/
void gnbr_print_array_int (unsigned int* nbr_array, unsigned int nbr_array_size)
{
	int i;
	short state;
	
	state = 0;
	
	for (i = nbr_array_size-1; i >= 0; i--)
	{
		if (state == 0 &&
		    nbr_array[i] != 0)
		{
			state = 1;
		}
		
		if (state == 1)
		{
			if (nbr_array[i] == 0)
			{
				printf ("0000000000 ");
			}
			else
			{
				printf ("%u ", nbr_array[i]);
			}
		}
	}
	
	printf ("\n\n");
}

/*
	Function: gnbr_add_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int* nbr_array_out, unsigned int nbr_array_size);
	Description: Performs the addition with two arrays of integers.
	InitVersion: 0.0.1
*/
void gnbr_add_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int* nbr_array_out, unsigned int nbr_array_size)
{
	int i, carry;
	
	carry = 0;
	
	for (i = 0; i < nbr_array_size; i++)
	{
		if ((nbr_array_a[i] + nbr_array_b[i] + carry) >= GNBR_INT_MAX)
		{
			nbr_array_out[i] = (nbr_array_a[i] + nbr_array_b[i] + carry) - (GNBR_INT_MAX);
			carry = 1;	
		}
		else
		{
			nbr_array_out[i] = nbr_array_a[i] + nbr_array_b[i] + carry;
			carry = 0;
		}
	}
}

/*
	Function: gnbr_multiply_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_out, unsigned int nbr_array_size, unsigned int f);
	Description: Performs the multiplication with one array of integers and one unsigned int.
	InitVersion: 0.0.1
*/
void gnbr_multiply_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_out, unsigned int nbr_array_size, unsigned int f)
{
	int i;
	
	for (i = 0; i < f; i++)
	{
		gnbr_add_array_int (nbr_array_out, nbr_array_a, nbr_array_out, nbr_array_size);
	}
}

/*
	Function: gnbr_factorial_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_tmp, unsigned int nbr_array_size, unsigned int f);
	Description: Performs the factorisation with one array of integers and one unsigned int.
	InitVersion: 0.0.1
*/
void gnbr_factorial_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_tmp, unsigned int nbr_array_size, unsigned int f)
{
	unsigned int i;
	
	for (i = f; i > 1; i--)
	{
		gnbr_multiply_array_int (nbr_array_a, nbr_array_tmp, nbr_array_size, i);
		gnbr_copy_array_int (nbr_array_a, nbr_array_tmp, nbr_array_size);
		gnbr_init_array_int (nbr_array_tmp, nbr_array_size, 0);
	}
}
