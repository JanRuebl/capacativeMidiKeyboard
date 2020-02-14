#include <CapacitiveSensor.h>

// hier werden die korken auf digitalPins gelegt. pin 3 ist messpin.

CapacitiveSensor korken_22 = CapacitiveSensor(3, 22); // erst messpin (3), dann digitalpin 22

bool korken_22_isInUse = false;

// bla

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  long korken_22_val = korken_22.capacitiveSensor(30);

  if (korken_22_val > 0)
  {
    Serial.print(korken_22_val);
  }

  //  if(korken_22_val > 0 && !korken_22_isInUse){
  //          korken_22_isInUse = true;
  //          Serial.print("22 korken geht");
  //    }
  //  if(korken_22_val == 0 && korken_22_isInUse){
  //          korken_22_isInUse = false;
  //          Serial.print("22 korken aus");
  //    }
}

void NoteOn(int channel, int note, int velocity)
{
}
