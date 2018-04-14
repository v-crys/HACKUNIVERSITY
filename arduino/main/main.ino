#include <Servo.h> 

#define LEFT_R( speed )   servo.write( 90 + (speed) );
#define RIGHT_R( speed )  servo.write( 90 - (speed) );
#define STOP()              servo.write( 90 );

Servo servo; 

#define DEF_SPEED   20
#define NUMBER_PIN  10

void setup() 
{
servo.attach( NUMBER_PIN ); 
}

void loop()
{
  LEFT_R( DEF_SPEED ); // write 1
  delay( 50 );
  RIGHT_R( DEF_SPEED ); //write 0
  delay( 50 );
  STOP();
  delay( 50 );
  LEFT_R( DEF_SPEED );
  delay( 50 );
  STOP();
  delay( 50 );
  
  /*
  servo.write( 180 ); // write 1
  delay( 50 );
  servo.write( 0 ); // write 0
  delay( 50 );
  servo.write( 90 ); // 0
  delay( 50 );
  servo.write( 180 ); //1
  delay( 50 );
  servo.write( 90 );
  delay( 50 );
  */


    delay( 2000 );
  
//servo.write(100); //ставим вал под 0

//delay(50000); //ждем 2 секунды
//servo.write(170); //ставим вал под 180
//delay(2000); //ждем 2 секунды
}
