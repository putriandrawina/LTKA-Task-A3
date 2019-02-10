// Program ADHS
const int analogInPin = A5;  // Set MQ2 ke pin A5
#define RGBLedAnode_PIN_R 8
#define RGBLedAnode_PIN_G 6
#define RGBLedAnode_PIN_B 5 //set tiap pin untuk lampu RGB
const int buzzer = 7; // Set pin buzzer
int sensorValue = 0; //Set nilai awal
void setup() {
  Serial.begin(9600); 
  pinMode(RGBLedAnode_PIN_R, OUTPUT); 
  pinMode(RGBLedAnode_PIN_G, OUTPUT);
  pinMode(RGBLedAnode_PIN_B, OUTPUT);
  pinMode(buzzer, OUTPUT); //set pin buzzer dan lampu rgb sebagai output
  //pinMode(mh, INPUT);
}
void loop() {
  
  sensorValue = analogRead(analogInPin); //Pembacaan kondisi udara melalui MQ2          
  // menentukan kondisi udara
  if (sensorValue >= 2000) //Udara tidak sehat
  {
    digitalWrite(RGBLedAnode_PIN_R, LOW); //Set low untuk menyalakan lampu merah LED RGB Anoda
    digitalWrite(RGBLedAnode_PIN_G, HIGH) ;
    digitalWrite(RGBLedAnode_PIN_B, HIGH);
    tone(buzzer,5000); //menyalakan buzzer
                    delay(1000);
   noTone(buzzer); //mematikan buzzer                 
  }
   if ((sensorValue > 1500) && (sensorValue < 2000)) //udara kurang sehat
  {
    digitalWrite(RGBLedAnode_PIN_R, LOW); 
    digitalWrite(RGBLedAnode_PIN_B, LOW); //lampu merah dan biru menyala bersama
    digitalWrite(RGBLedAnode_PIN_G, HIGH);
                      tone(buzzer,2500); //menyalakan buzzer suara sedang
                    delay(500);
                    noTone(buzzer);} 
  if (sensorValue < 1500) //udara masih sehat
  {
      digitalWrite(RGBLedAnode_PIN_G, LOW);  //Lampu Hijau Menyala
      digitalWrite(RGBLedAnode_PIN_R, HIGH);
      digitalWrite(RGBLedAnode_PIN_B, HIGH);
  }
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);     //menampilkan pembacaan Nilai pada serial monitor
  delay(3000);  //delay tiap pembacaan                   
}
