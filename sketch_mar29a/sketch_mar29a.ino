void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(2000);
Serial.println("A");
delay(10000);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println("ATD07506134635;\r");
delay(100);
Serial.println();
delay(30000);
Serial.println("ATH");
delay(10000);
}
