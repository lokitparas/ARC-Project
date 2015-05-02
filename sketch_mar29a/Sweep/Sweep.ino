 // Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo                 
// a maximum of eight servo objects can be created 
int i = 0; 
int pos1 = 75;    // variable to store the servo position 
int count = 0;
const int trigPin = 2;
const int echoPin = 4;
boolean stat = false;
void setup() 
{ 
  Serial.begin(9600);
  myservo1.attach(9);   
  myservo1.write(75);
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);  
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);  

} 

 
void loop() 
{ delay(100);
  long duration, inches, cm;
  
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
    inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
   
  //if(i==1) delay(10000);
    if(inches <=1 && inches > 0){
        //myservo1.write(75);
        //delay(1000);
        if(stat == false){  
            for(int i=0;i<37;i++){
              delay(50);
              pos1 = pos1 - 2;
              myservo1.write(pos1);
             }
             
            stat = true;
        }
        
        else{
          for(int i=0;i<37;i++){
            delay(50);
            pos1 = pos1 + 2;
            myservo1.write(pos1);
          }
           stat = false;
         }
   
    }
  if(stat == true){ count = count +1;
                  if(count == 100){
                            count = 0;
                            for(int i=0;i<37;i++){
                            delay(50);
                            pos1 = pos1 + 2;
                            myservo1.write(pos1);
                          }
                           stat = false;
                  }
  }
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}


long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
