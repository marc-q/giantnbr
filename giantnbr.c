/* Copyright 2016 - 2017 Marc Volker Dickmann */
/* Project: GiantNbr */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include "lib/dutils.h"
#include "giantnbr.h"

/* |--------------------------------------------|
   |			Core			|
   |--------------------------------------------| */

/*
	Function: gnbr_fill_array_int (unsigned int* nbr_array, int nbr_array_size, int init_value);
	Description: Fills a array of integers with the specified number.
	InitVersion: 0.0.1
*/
void gnbr_fill_array_int (unsigned int* nbr_array, int nbr_array_size, int init_value)
{
	int i;
	
	for (i = nbr_array_size-2; i >= 0; i--)
	{
		nbr_array[i] = init_value;
	}
}

/*
	Function: gnbr_init_array_int (unsigned int* nbr_array, int nbr_array_size, int init_value);
	Description: Inits a array of integers with the specified number.
	InitVersion: 0.0.1
*/
void gnbr_init_array_int (unsigned int** nbr_array, int nbr_array_size, int init_value)
{
	unsigned int *newarray;
	
	newarray = (unsigned int*) malloc (sizeof (unsigned int) * nbr_array_size);
	
	/* Flags */
	newarray[nbr_array_size-1] = 0;
	
	gnbr_fill_array_int (newarray, nbr_array_size, init_value);
	
	*nbr_array = newarray;
}

/*
	Function: gnbr_free_array_int (unsigned int* nbr_array);
	Description: Frees a array of integers.
	InitVersion: 0.0.1
*/
void gnbr_free_array_int (unsigned int* nbr_array)
{
	free (nbr_array);
}

/*
	Function: gnbr_copy_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, int nbr_array_size);
	Description: Copys a array of integers to another array.
	InitVersion: 0.0.1
*/
void gnbr_copy_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, int nbr_array_size)
{
	for (nbr_array_size--; nbr_array_size >= 0; nbr_array_size--)
	{
		nbr_array_a[nbr_array_size] = nbr_array_b[nbr_array_size];
	}
}

/* |--------------------------------------------|
   |			Flags			|
   |--------------------------------------------| */

/*
	Function: gnbr_setnegative_array_int (unsigned int* nbr_array, int nbr_array_size, short value);
	Description: Sets the negative flag of an array of integers.
	InitVersion: 0.0.1
*/
void gnbr_setnegative_array_int (unsigned int* nbr_array, int nbr_array_size, short value)
{
	nbr_array[nbr_array_size-1] ^= BITCOPY (value, 0, nbr_array[nbr_array_size-1], GNBR_INT_FLAG_NEGATIVE);
}

/*
	Function: gnbr_isnegative_array_int (unsigned int* nbr_array, int nbr_array_size);
	Description: Returns the negative flag of an array of integers.
	InitVersion: 0.0.1
*/
bool gnbr_isnegative_array_int (unsigned int* nbr_array, int nbr_array_size)
{
	return (BITGET (nbr_array[nbr_array_size-1], GNBR_INT_FLAG_NEGATIVE) == 1 ? true : false);
}

/* |--------------------------------------------|
   |			Utils			|
   |--------------------------------------------| */

/*
	Function: gnbr_lastpos_array_int (unsigned int* nbr_array, int nbr_array_size);
	Description: Returns the last position of an valid value in a array of integers.
	InitVersion: 0.0.1
*/
unsigned int gnbr_lastpos_array_int (unsigned int* nbr_array, int nbr_array_size)
{	
	for (nbr_array_size -= 2; nbr_array_size >= 0; nbr_array_size--)
	{
		if (nbr_array[nbr_array_size] != 0)
		{
			return nbr_array_size;
		}
	}
	
	return 0;
}

/*
	Function: gnbr_bigger_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, int nbr_array_size);
	Description: Returns if nbr_array_a is bigger than nbr_array_b.
	InitVersion: 0.0.1
*/
bool gnbr_bigger_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, int nbr_array_size)
{
	if (gnbr_isnegative_array_int (nbr_array_a, nbr_array_size) == true &&
	    gnbr_isnegative_array_int (nbr_array_b, nbr_array_size) == false)
	{
		return false;
	}
	else if (gnbr_isnegative_array_int (nbr_array_a, nbr_array_size) == false &&
		 gnbr_isnegative_array_int (nbr_array_b, nbr_array_size) == true)
	{
		return true;
	}
	
	for (nbr_array_size -= 2; nbr_array_size >= 0; nbr_array_size--)
	{
		if (nbr_array_a[nbr_array_size] != 0 || nbr_array_b[nbr_array_size] != 0)
		{
			return (nbr_array_a[nbr_array_size] > nbr_array_b[nbr_array_size] ? true : false);
		}
	}
	
	return false;
}

/*
	Function: gnbr_isnull_array_int (unsigned int* nbr_array, int nbr_array_size);
	Description: Returns if nbr_array equals 0.
	InitVersion: 0.0.1
*/
bool gnbr_isnull_array_int (unsigned int* nbr_array, int nbr_array_size)
{
	nbr_array_size = gnbr_lastpos_array_int (nbr_array, nbr_array_size);
	
	if (nbr_array_size == 0 && nbr_array[0] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Function: gnbr_print_array_int (unsigned int* nbr_array, int nbr_array_size);
	Description: Prints the number contained in a array of integers.
	InitVersion: 0.0.1
*/
void gnbr_print_array_int (unsigned int* nbr_array, int nbr_array_size)
{
	int i, pos;
	
	pos = gnbr_lastpos_array_int (nbr_array, nbr_array_size);
	
	/* Negative OR Positive */
	if (gnbr_isnegative_array_int (nbr_array, nbr_array_size) == true)
	{
		printf ("-");
	}
	
	/* The actual number */
	for (i = pos; i >= 0; i--)
	{
		if (i != pos)
		{
			printf ("%.9u ", nbr_array[i]);
		}
		else
		{
			printf ("%u ", nbr_array[i]);
		}
	}
	
	printf ("\n\n");
}

/* |--------------------------------------------|
   |		    Arithmetics			|
   |--------------------------------------------| */

/*
	Function: gnbr_add_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int* nbr_array_out, int nbr_array_size);
	Description: Performs the addition with two arrays of integers.
	InitVersion: 0.0.1
*/
void gnbr_add_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int* nbr_array_out, int nbr_array_size)
{
	int i, mtmp;
	short carry;
	bool state_a, state_b;
	
	carry = 0;
	
	state_a = gnbr_isnegative_array_int (nbr_array_a, nbr_array_size);
	state_b = gnbr_isnegative_array_int (nbr_array_b, nbr_array_size);
	
	gnbr_setnegative_array_int (nbr_array_out, nbr_array_size, state_a);
	
	for (i = 0; i < nbr_array_size-1; i++)
	{
		mtmp = nbr_array_a[i] + (state_a ^ state_b ? (-nbr_array_b[i]) : nbr_array_b[i]) + carry;
		
		if (mtmp < 0)
		{
			nbr_array_out[i] = (unsigned int) (GNBR_INT_MAX + mtmp);
			carry = -1;
		}
		else if (mtmp >= GNBR_INT_MAX)
		{
			nbr_array_out[i] = (unsigned int) (mtmp - GNBR_INT_MAX);
			carry = 1;
		}
		else
		{
			nbr_array_out[i] = (unsigned int) mtmp;
			carry = 0;
		}
	}
}

/*
	Function: gnbr_subtract_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int* nbr_array_out, int nbr_array_size);
	Description: Performs the subtraction with two arrays of integers.
	InitVersion: 0.0.1
*/
void gnbr_subtract_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int* nbr_array_out, int nbr_array_size)
{
	bool state_a, state_b;
	
	state_a = gnbr_isnegative_array_int (nbr_array_a, nbr_array_size);
	state_b = gnbr_isnegative_array_int (nbr_array_b, nbr_array_size);
	
	if (!state_a && !state_b)
	{
		gnbr_setnegative_array_int (nbr_array_b, nbr_array_size, TRUE);
		gnbr_add_array_int (nbr_array_a, nbr_array_b, nbr_array_out, nbr_array_size);
		gnbr_setnegative_array_int (nbr_array_b, nbr_array_size, FALSE);
	}
	else if (state_b)
	{
		gnbr_setnegative_array_int (nbr_array_b, nbr_array_size, FALSE);
		gnbr_add_array_int (nbr_array_a, nbr_array_b, nbr_array_out, nbr_array_size);
		gnbr_setnegative_array_int (nbr_array_b, nbr_array_size, TRUE);
	}
	else if (state_a)
	{
		gnbr_setnegative_array_int (nbr_array_a, nbr_array_size, FALSE);
		gnbr_add_array_int (nbr_array_a, nbr_array_b, nbr_array_out, nbr_array_size);
		
		gnbr_setnegative_array_int (nbr_array_a, nbr_array_size, TRUE);
		gnbr_setnegative_array_int (nbr_array_out, nbr_array_size, TRUE);
	}
}

/*
	Function: gnbr_multiply_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int* nbr_array_out, unsigned int* nbr_array_tmp, int nbr_array_size);
	Description: Performs the multiplication with two array of integers.
	InitVersion: 0.0.1
*/
void gnbr_multiply_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_b, unsigned int* nbr_array_out, unsigned int* nbr_array_tmp, int nbr_array_size)
{
	bool state_a, state_b;
	
	state_a = gnbr_isnegative_array_int (nbr_array_a, nbr_array_size);
	state_b = gnbr_isnegative_array_int (nbr_array_b, nbr_array_size);
	
	/* Inits a array with the value 1 */
	gnbr_fill_array_int (nbr_array_tmp, nbr_array_size, 0);
	nbr_array_tmp[0] = 1;
	
	gnbr_setnegative_array_int (nbr_array_tmp, nbr_array_size, state_b);
	gnbr_setnegative_array_int (nbr_array_out, nbr_array_size, state_a);
	
	while (gnbr_isnull_array_int (nbr_array_b, nbr_array_size) == false)
	{
		gnbr_add_array_int (nbr_array_out, nbr_array_a, nbr_array_out, nbr_array_size);
		gnbr_subtract_array_int (nbr_array_b, nbr_array_tmp, nbr_array_b, nbr_array_size);
	}
	
	gnbr_setnegative_array_int (nbr_array_out, nbr_array_size, state_a ^ state_b);
}

/*
	Function: gnbr_multiply_array_int_byint (unsigned int* nbr_array_a, unsigned int* nbr_array_out, int nbr_array_size, int f);
	Description: Performs the multiplication with one array of integers and one unsigned int.
	InitVersion: 0.0.1
*/
void gnbr_multiply_array_int_byint (unsigned int* nbr_array_a, unsigned int* nbr_array_out, int nbr_array_size, int f)
{	
	while (f > 0)
	{
		gnbr_add_array_int (nbr_array_out, nbr_array_a, nbr_array_out, nbr_array_size);
		f--;
	}
}

/*
	Function: gnbr_factorial_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_tmp, int nbr_array_size, int f);
	Description: Performs the factorisation with one array of integers and one unsigned int.
	InitVersion: 0.0.1
*/
void gnbr_factorial_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_tmp, int nbr_array_size, int f)
{	
	while (f > 1)
	{
		gnbr_multiply_array_int_byint (nbr_array_a, nbr_array_tmp, nbr_array_size, f);
		gnbr_copy_array_int (nbr_array_a, nbr_array_tmp, nbr_array_size);
		gnbr_fill_array_int (nbr_array_tmp, nbr_array_size, 0);
		f--;
	}
}

/*
	Function: gnbr_square_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_tmp, int nbr_array_size, int f);
	Description: Performs the squaring with one array of integers and one unsigned int.
	InitVersion: 0.0.1
*/
void gnbr_square_array_int (unsigned int* nbr_array_a, unsigned int* nbr_array_tmp, int nbr_array_size, int f)
{
	int i;

	i = f;
		
	while (i > 1)
	{
		gnbr_multiply_array_int_byint (nbr_array_a, nbr_array_tmp, nbr_array_size, f);
		gnbr_copy_array_int (nbr_array_a, nbr_array_tmp, nbr_array_size);
		gnbr_fill_array_int (nbr_array_tmp, nbr_array_size, 0);
		i--;
	}
}
