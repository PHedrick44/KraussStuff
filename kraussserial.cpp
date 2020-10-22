#include "Arduino.h"
#include "kraussserial.h"

char get_char(){
  char mybyte;
  while (Serial.available() == 0){
    delay(10);
  }
  mybyte = Serial.read();
  return(mybyte);
}

int get_int(){
  int out_int;
  out_int = 0;
  while (out_int == 0){
    while (Serial.available() == 0){
      delay(10);
    }
    out_int = Serial.parseInt();
  }
  return(out_int);
  
}

int get_positive_int(){
  int myint = get_int();
  if (myint < 0){
    myint = 0;
  }
  return(myint);
}

float get_float(){
  float out_float;

  out_float = 0;
  while (out_float == 0){
    while (Serial.available() == 0){
      delay(10);
    }
    out_float = Serial.parseFloat();
  }
  return(out_float);
  
}

float get_positive_float(){
  float myfloat = get_float();
  if (myfloat < 0){
    myfloat = 0;
  }
  return(myfloat);
}

int read_one_byte(){
  int outbyte;

  while (Serial.available() == 0){
    delay(10);
  }
  outbyte = Serial.read();

  return(outbyte);
}

int get_valid_byte(){
  int outbyte;
  outbyte = read_one_byte();
  
  if (outbyte == 10 || outbyte == 13){
    //try again
    outbyte = read_one_byte();
  }
  
  return(outbyte);
}

void get_int_with_message(char * var_name, int * var_dest){
  char msg1[30];
  sprintf(msg1, "enter %s", var_name);
  Serial.println(msg1);
  *var_dest = get_positive_int();
  char msg2[30];
  sprintf(msg2, "%s = %d", var_name, *var_dest);
  Serial.println(msg2);
}

int get_int_with_message_no_pointer(char * var_name){
  int output;
  char msg1[200];
  sprintf(msg1, "enter %s", var_name);
  Serial.println(msg1);
  output = get_positive_int();
  char msg2[200];
  sprintf(msg2, "%s = %d", var_name, output);
  Serial.println(msg2);
  return(output);
}

void get_float_with_message(char * var_name, float * var_dest){
  //float out;
  char msg1[30];
  sprintf(msg1, "enter %s", var_name);
  Serial.println(msg1);
  *var_dest = get_float();
  char msg2[30];
  sprintf(msg2, "%s = ", var_name);
  Serial.print(msg2);
  Serial.println(*var_dest,4);
  //return out;
}

float get_float_with_message_no_pointer(char * var_name){
  float output;
  char msg1[30];
  sprintf(msg1, "enter %s", var_name);
  Serial.println(msg1);
  output = get_float();
  char msg2[30];
  sprintf(msg2, "%s = ", var_name);
  Serial.print(msg2);
  Serial.println(output);
  return(output);
}

void mynewline(){
  Serial.print('\n');
}


void print_int_with_label(char * label, int val){
  Serial.print(label);
  Serial.print(val);
}


void print_float_with_label(char * label, float val){
  Serial.print(label);
  Serial.print(val);
}

void print_comma_then_int(int val){
  Serial.print(",");
  Serial.print(val);
}


void print_comma_then_float(float val){
  Serial.print(",");
  Serial.print(val);
}

int reassemblebytes(unsigned char msb, unsigned char lsb){
  int output;
  output = (int)(msb << 8);
  output += lsb;
  return output;
}

