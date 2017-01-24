#include <SoftPWM.h>

void setup()
{
  SoftPWMBegin();
  
  SoftPWMSet(7, 0);

 // SoftPWMSetFadeTime(7, 1000, 1000);
}

void loop()
{
  SoftPWMSet(7, 70);
 
}
