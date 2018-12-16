/*

Shutter time evaluation
*/
#define SENSOR A0
#define TRIGGER 10

int ReferenceValue  = 0;
int ActualTime      = 0;
int MsCounter       = 0;
int sensorValue     = 0;
bool OkToPrint      = false;
int count           = 0;

int GetReferenceValue(void){
  return analogRead(SENSOR);
}

// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Wait in order to avoid problems for flash a new program:
  while (millis() <5000) {};
  
  ReferenceValue = GetReferenceValue();
  Serial.println("OK to start");
}



// the loop routine runs over and over again forever:
void loop() {
  
  ActualTime = millis();
  int sensorValue = analogRead(SENSOR);

  if (sensorValue > ReferenceValue + TRIGGER) {
    MsCounter += millis()-ActualTime;
    OkToPrint = true;
    count++;
  }
  if (sensorValue <= ReferenceValue+5 && OkToPrint == true) {
    Serial.println(MsCounter);
    MsCounter = 0;
    OkToPrint = false;
  }

}
