#include "LedControl.h"

//LedControl lc=LedControl(11din13,9clk14,10cs2,2);  // arduino pins and no of displays

LedControl lc=LedControl(13,14,2,4);  // nodemcu pins and no of displays

unsigned long delayTime=500;  // Delay between Frames

// Put values in arrays
//////////////////////////////////////////////////////



/*
 // I WANT AMAKE THIS HAPPEN!!!!!!!!!!
 **** matrix_1-4a[] =
{
B00000000000000000000000000000000,
B00000000000000000000000000000000,
B00000000000000000000000000000000,
B00011111100000000000000111111000,
B00111111110000000000001111111100,
B01100000011000000000011000000110,
B11000000001100000000110000000011,
B10000000001100000000110000000001
};


*/

byte matrix1a[] =
{
   B00000000, 
   B00000000,
   B00000000,
   B11111000,
   B11111100,
   B00000110,
   B00000011,
   B00000001
};

byte matrix2a[] =
{
   B00000000, // FIRST frame of matrix #1
   B00000000,
   B00000000,
   B00000001,
   B00000011,
   B00000110,
   B00001100,
   B00001100
};

byte matrix3a[] =
{
   B00000000,
   B00000000,
   B00000000,
   B10000000,
   B11000000,
   B01100000,
   B00110000,
   B00110000
};

byte matrix4a[] =
{
   B00000000,  // First frame of matrix #2
   B00000000,
   B00000000,
   B00011111,
   B00111111,
   B01100000,
   B11000000,
   B10000000
};

////////////////////////////////

byte matrix1b[] =
{
   B00000000,
   B10000000,
   B11000000,
   B10000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};

byte matrix2b[] =
{

   B00000000,
   B00000000,
   B00000001,
   B00000011,
   B00000111,
   B00001110,
   B00011100,
   B00011000
};

// Put values in arrays

byte matrix3b[] =
{
   B00000000,
   B00000000,
   B10000000,
   B11000000,
   B11100000,
   B01110000,
   B00111000,
   B00011000
};



byte matrix4b[] =
{
   B00000000,
   B00000001,
   B00000011,
   B00000001,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};
 
//////////////////////////////////////

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);  
  lc.shutdown(3,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.setIntensity(2,5);  
  lc.setIntensity(3,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
}


//  Take values in Arrays and Display them
void smatrix1a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,matrix1a[i]);
  }
}

void smatrix1b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,matrix1b[i]);
  }
}

void smatrix2a()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,matrix2a[i]);
  }
}

void smatrix2b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,matrix2b[i]);
  }
}

void smatrix3a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(2,i,matrix3a[i]);
  }
}

void smatrix3b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(2,i,matrix3b[i]);
  }
}

void smatrix4a()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(3,i,matrix4a[i]);
  }
}

void smatrix4b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(3,i,matrix4b[i]);
  }
}


void loop()
{
// Put #1 frame on both Display
    smatrix1a();
    smatrix2a();
    smatrix3a();
    smatrix4a();
    
    delay(delayTime);
    
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
  
    delay(delayTime);
  
    smatrix1b();
    smatrix2b();
    smatrix3b();
    smatrix4b();
    
    delay(delayTime);
    
}
