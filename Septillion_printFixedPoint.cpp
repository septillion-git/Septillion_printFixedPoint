/*
	Septillion_PrintFixedPoint.h v1 - Library to print fixed point values
	Created by Timo Engelgeer (Septillion), December 10, 2015
*/

#include "Arduino.h"
#include "Print.h"
#include "Septillion_printFixedPoint.h"

void printFixedPoint(Print &out, unsigned int value, byte decimalLocation){
  //Just pass it on without crop
  printFixedPoint(out, value, decimalLocation, decimalLocation);
}

void printFixedPoint(Print &out, unsigned int value, byte decimalLocation, byte decimalCrop){
  //Check if there is a decimal point, otherwise we can skip the hassle
  if(decimalLocation){
    unsigned int decimalDivider = 1;
    
    //Calculate the value we need to devide the value with
    //Also divide the value if it need to be cropped
    for(; decimalLocation != 0; decimalLocation--){
      //If we wnat to crop it (decimal place location > crop size)
      if(decimalCrop == 0){
        if(decimalLocation == 1){ //Fix the rounding
          value += 5; 
        }
        value /= 10;  //devide to crop a digit
      }
      else{
        decimalDivider *= 10; //Otherwise, make the divider bigger
        decimalCrop--;        //go on to the next
      }
    }
    
    //Time to acually print everything
    out.print(value / decimalDivider);
    out.print(",");
    out.print(value % decimalDivider);
  }
  else{
    out.print(value);
  }
}

void printFixedPoint(Print &out, int value, byte decimalLocation){
  //just pass it on without crop
  printFixedPoint(out, value, decimalLocation, decimalLocation);
}

void printFixedPoint(Print &out, int value, byte decimalLocation, byte decimalCrop){
  //if it negative, print a - sign, make the value positive
  if(value < 0){
    out.print('-');
    value = -1 * value;
  }
  //Just pass it on as a unsigned type, it is now positive anyway
  printFixedPoint(out, (unsigned int) value, decimalLocation, decimalCrop);
}

void printRightAllignment(Print &out, unsigned int &value, byte places, byte &decimalLocation, byte &decimalCrop){
  //we don't want to edit the value unless it's to big. Work on a copy
  unsigned int valueTemp = value;
  
  byte valueLength = 0; //How long is the value (including decimal point)
  
  //Add to the length as long as we can divide it
  for(; valueTemp; valueLength++){
    valueTemp /= 10;
  }
  valueLength += 1; //for the decimal
  
  //If we want to crop it, take it into account
  if(decimalCrop < decimalLocation){
    valueLength -= decimalLocation - decimalCrop;
  }
  
  //if the value fits the number of places
  if(valueLength <= places){
    //Now we know the value leng we can fill the remaining places befor the value with spaces
    for(; places > valueLength; places--){
      out.print(' ');
    }
  }
  //if it does not fit, show it as ++++1
  else{
    for(places -= 1; places; places--){
      out.print('+');
    }
    value = 1;
    decimalLocation = 0;
  }
}

void printFixedPointRight(Print &out, unsigned int value, byte places, byte decimalLocation){
  //Just pass it on without crop
  printFixedPointRight(out, value, places, decimalLocation, decimalLocation);
}

void printFixedPointRight(Print &out, unsigned int value, byte places, byte decimalLocation, byte decimalCrop){
  //Print the right amount of spaces in front
  printRightAllignment(out, value, places, decimalLocation, decimalCrop);
  //and now print the fixed point number
  printFixedPoint(out, value, decimalLocation, decimalCrop);
}

void printFixedPointRight(Print &out, int value, byte places, byte decimalLocation){
  //Just pass it on without crop
  printFixedPointRight(out, value, places, decimalLocation, decimalLocation);
}

void printFixedPointRight(Print &out, int value, byte places, byte decimalLocation, byte decimalCrop){
  //If the value is negative, print a - sign and make the value positive
  if(value < 0){
    out.print('-');
    value = -1 * value;
    places--;
  }
  
  //Just pass it on as unsigned type, it's now positive anyways
  printFixedPointRight(out, (unsigned int) value, places, decimalLocation, decimalCrop);
}