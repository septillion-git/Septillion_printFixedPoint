/*
	Septillion_PrintFixedPoint.h v1 - Library to print fixed point values
	Created by Timo Engelgeer (Septillion), December 10, 2015
*/

/*
  Some functions you can use to print fixed point values. Works with all instances that are dirived from the Print class (like Serial or LiquidCrystal)
*/

#ifndef Septillion_PrintFixedPoint_h
#define Septillion_PrintFixedPoint_h

#include "Arduino.h"
#include "Print.h"

/* 
printFixedPoint()
  Prints the fixed point value with decimal point

  out - The instance to use the print on like Serial
  value - the value with a fixed point
  decimalLocation - How many decimal places the value has
  decimalCrop - At how many decimal places do we need to crop? Rounding included
*/

void printFixedPoint(Print &out, unsigned int value, byte decimalLocation);

void printFixedPoint(Print &out, unsigned int value, byte decimalLocation, byte decimalCrop);

void printFixedPoint(Print &out, int value, byte decimalLocation);

void printFixedPoint(Print &out, int value, byte decimalLocation, byte decimalCrop);

void printRightAllignment(Print &out, unsigned int &value, byte places, byte &decimalLocation, byte &decimalCrop);

/*
printRightAllignment()
  Prints the fixed point value but aligns it to the right (aka, fills left with spaces)

  out - The instance to use the print on like Serial
  value - the value with a fixed point
  places - the number of places the whole number is allowd to take. +++1 is printed when it does not fit
  decimalLocation - How many decimal places the value has
  decimalCrop - At how many decimal places do we need to crop? Rounding included
*/

void printFixedPointRight(Print &out, unsigned int value, byte places, byte decimalLocation);

void printFixedPointRight(Print &out, unsigned int value, byte places, byte decimalLocation, byte decimalCrop);

void printFixedPointRight(Print &out, int value, byte places, byte decimalLocation);

void printFixedPointRight(Print &out, int value, byte places, byte decimalLocation, byte decimalCrop);

#endif