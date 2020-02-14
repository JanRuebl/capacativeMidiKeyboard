#include <CapacitiveSensor.h>

// hier werden die korken auf digitalPins gelegt. pin 3 ist messpin.

CapacitiveSensor korken_22 = CapacitiveSensor(3, 22); // erst messpin (3), dann digitalpin 22

bool korken_22_isInUse = false;

CapacitiveSensor korken_23 = CapacitiveSensor(3, 23); // erst messpin (3), dann digitalpin 22

bool korken_23_isInUse = false;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  long korken_22_val = korken_22.capacitiveSensor(30);
  long korken_23_val = korken_23.capacitiveSensor(30);

  //if( korken_22_val > 0){
  //    Serial.print( "KORKEN22");
  //     //NoteOn(153,36,127);
  //  }
  //
  //if( korken_23_val > 0){
  //     Serial.print("xxxxxxxxxxxxxx");
  //  }

  if (korken_22_val > 0 && !korken_22_isInUse)
  {
    korken_22_isInUse = true;
    Serial.print("22 korken geht");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (korken_22_val == 0 && korken_22_isInUse)
  {
    korken_22_isInUse = false;
    Serial.print("22 korken aus");
    digitalWrite(LED_BUILTIN, LOW);
  }

  //
  //  if(korken_23_val > 0 && !korken_23_isInUse){
  //          korken_23_isInUse = true;
  //          Serial.print("23 korken geht");
  //          digitalWrite(LED_BUILTIN, HIGH);
  //    }
  //  if(korken_23_val == 0 && korken_23_isInUse){
  //          korken_23_isInUse = false;
  //          Serial.print("23 korken aus");
  //          digitalWrite(LED_BUILTIN, LOW);
  //    }
}

void NoteOn(int channel, int note, int velocity)
{
  Serial.write(channel);  // 1001 0000 = Note On/ Kanal
  Serial.write(note);     // Note C1
  Serial.write(velocity); //Schlagstärke auf max:127
}

void NoteOff(int channel, int note, int velocity)
{
  Serial.write(channel);  // 1001 0000 = Note On/ Kanal
  Serial.write(note);     // Note C1
  Serial.write(velocity); //Schlagstärke auf max:127
}
