#ifndef __GIANTNBR_H__
#define __GIANTNBR_H__

#define GNBR_INT_MAX 1000000000
#define GNBR_INT_FLAG_NEGATIVE 0

#define TONEGATIVE(a) ((a > 0 ? -a : a))

/* Core */
void gnbr_fill_array_int (unsigned int*, int, int);
void gnbr_init_array_int (unsigned int**, int, int);
void gnbr_free_array_int (unsigned int*);
void gnbr_copy_array_int (unsigned int*, unsigned int*, int);

/* Flags */
void gnbr_setnegative_array_int (unsigned int*, int, short);
unsigned short gnbr_isnegative_array_int (unsigned int*, int);

/* Utils */
unsigned int gnbr_lastpos_array_int (unsigned int*, int);
unsigned short gnbr_bigger_array_int (unsigned int*, unsigned int*, int);
unsigned short gnbr_isnull_array_int (unsigned int*, int);
void gnbr_print_array_int (unsigned int*, int);

/* Arithmetics */
void gnbr_add_array_int (unsigned int*, unsigned int*, unsigned int*, int);
void gnbr_subtract_array_int (unsigned int*, unsigned int*, unsigned int*, int);
void gnbr_multiply_array_int (unsigned int*, unsigned int*, unsigned int*, unsigned int*, int);
void gnbr_multiply_array_int_byint (unsigned int*, unsigned int*, int, int);
void gnbr_factorial_array_int (unsigned int*, unsigned int*, int, int);
void gnbr_square_array_int (unsigned int*, unsigned int*, int, int);

#endif /* __GIANTNBR_H__ */

