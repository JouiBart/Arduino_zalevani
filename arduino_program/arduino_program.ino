int hladinaPin3 = A3; // analogovy PIN 3 - složí pro určení hladiny vody 
int vlhkostPin5 = A5; // analogovy PIN 5 - složí pro určení vlhkosti
int vodni_pumpa = 3; // digitalni PIN 3

int minimalni_vlhkost = 30; // minimalni vlhkost pro zapnuti vodniho cerpadla

void setup() {
  Serial.begin(9600);          
  pinMode(vodni_pumpa, OUTPUT);
}

void loop() {
  int hladina_vody = analogRead(hladinaPin3);  
  int vlhkostRaw = analogRead(vlhkostPin5); 
  int vlhkost = map(vlhkostRaw, 1023,0,0,100); // převede analogový vstup na vlhkost
  Serial.println(vlhkost); 
  if(hladina_vody < 1000)       // Pokud dochazi voda
  {
    Serial.println("Dochazi voda!!!!!"); 
  }

  if(vlhkost < minimalni_vlhkost)
  {
    Serial.println("zapni"); 
    digitalWrite(vodni_pumpa, HIGH);
  }
  else
  {
    Serial.println("vypni"); 
    digitalWrite(vodni_pumpa, LOW);
  }

   delay(500); // prodleva
}
