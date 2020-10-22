#ifndef kraussserial_h
#define kraussserial_h

#include "Arduino.h"

char get_char();

int get_int();

int get_positive_int();

float get_float();

float get_positive_float();

int read_one_byte();

int get_valid_byte();

void get_int_with_message(char * var_name, int * var_dest);

int get_int_with_message_no_pointer(char * var_name);

void get_float_with_message(char * var_name, float * var_dest);

float get_float_with_message_no_pointer(char * var_name);

void mynewline();

void print_int_with_label(char * label, int val);

void print_float_with_label(char * label, float val);

void print_comma_then_int(int val);

void print_comma_then_float(float val);

int reassemblebytes(unsigned char msb, unsigned char lsb);

#endif
