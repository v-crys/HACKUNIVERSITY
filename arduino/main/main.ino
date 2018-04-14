#include <Servo.h> 

#define LEFT_R( speed )   servo.write( 90 + (speed) );
#define RIGHT_R( speed )  servo.write( 90 - (speed) );
#define STOP()            servo.write( 90 );

Servo servo; 

#define DEF_SPEED   20
#define NUMBER_PIN  10

#define FLAG_DIRECTION  0 ///<  Флаг направления движения (в какую сторону спрятан\вытащен)




class Pen
{
    public:
        Pen() : position( 0 ), flag_enabled( 0 ) {};
    
        void write_0();
        void write_1();
        
        void write_bit( unsigned char b );
        void write_byte( unsigned char b );

    private:
        int position;   ///< Сдвиг относительно начального положения
        int flag_enabled; ///< Флаг последнего символа (по умолчанию спрятан - 0)
  
};

void Pen::write_0()
{
    if ( !flag_enabled )
      return;

    flag_enabled = !flag_enabled;

    if ( FLAG_DIRECTION )
        LEFT_R( DEF_SPEED );
    else
        RIGHT_R( DEF_SPEED );
}

void Pen::write_1()
{
    if ( !flag_enabled )
      return;

    flag_enabled = !flag_enabled;

    if ( FLAG_DIRECTION )
        RIGHT_R( DEF_SPEED );
    else
        LEFT_R( DEF_SPEED );
}

void write_bit( unsigned char b )
{
    if ( b )
      write_1();
    else 
      write_0();
}

void Pen::write_byte( unsigned char b )
{
    int i;

    for ( i = 0; i < 8; i++ )
    {
        
    }
}


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
