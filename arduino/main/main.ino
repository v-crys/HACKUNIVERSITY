
#include <Servo.h> //используем библиотеку для работы с сервоприводом
Servo servo; //объявляем переменную servo типа Servo
void setup() //процедура setup
{
servo.attach(10); //привязываем привод к порту 10

}

void loop() //процедура loop
{
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
  


    delay( 20000 );
  
//servo.write(100); //ставим вал под 0

//delay(50000); //ждем 2 секунды
//servo.write(170); //ставим вал под 180
//delay(2000); //ждем 2 секунды
}
