#include <Servo.h> 

#define  testbit(var, bit)   ((var) & (1 <<(bit)))
#define  setbit(var, bit)    ((var) |= (1 << (bit)))
#define  clrbit(var, bit)    ((var) &= ~(1 << (bit)))

#define LEFT_R( speed )   servo.write( 90 + (speed) )
#define RIGHT_R( speed )  servo.write( 90 - (speed) )
#define STOP()            servo.write( 90 );

Servo servo; 

#define DEF_DELAY_DIF 0

#define DEF_SPEED   90
#define DEF_DELAY   100
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
    {
      delay( 2 * DEF_DELAY );  
    
      return;
    }

    flag_enabled = !flag_enabled;

    if ( FLAG_DIRECTION )
    {
        LEFT_R( DEF_SPEED );
        delay( DEF_DELAY + DEF_DELAY_DIF );
    }
    else
    {
        RIGHT_R( DEF_SPEED );
        delay( DEF_DELAY );
    }
   

    
    STOP();
    delay( DEF_DELAY );
}

void Pen::write_1()
{
    if ( flag_enabled )
    {
      delay( 2 * DEF_DELAY );  
    
      return;
    }

    
    flag_enabled = !flag_enabled;

    if ( FLAG_DIRECTION ) 
    {
        RIGHT_R( DEF_SPEED );
        delay( DEF_DELAY );
    }
    else
    {
        LEFT_R( DEF_SPEED );
        delay( DEF_DELAY + DEF_DELAY_DIF );
    }
 

    //delay( DEF_DELAY );
    STOP();
    delay( DEF_DELAY );
}

void Pen::write_bit( unsigned char b )
{
    if ( b )
      write_1();
    else 
      write_0();
}

void Pen::write_byte( unsigned char b )
{
    int i;

    for ( i = 7; i >=0; i-- )
      write_bit( testbit( b, i ) );
}


void setup() 
{
servo.attach( NUMBER_PIN ); 

pinMode( 13, OUTPUT );
digitalWrite( 13, HIGH );
}

void loop()
{
  Pen my_pen;

  /*my_pen.write_0();
  my_pen.write_0();
  my_pen.write_0();
  my_pen.write_1();
  my_pen.write_1();
  my_pen.write_1();
  my_pen.write_1();
  my_pen.write_1();
  my_pen.write_0();
  delay(50000);
  */



  my_pen.write_byte( 32 );
  my_pen.write_byte( 15 );
  my_pen.write_byte( 0 );
  my_pen.write_byte( 95 );
  my_pen.write_byte( 16 );

digitalWrite( 13, LOW );
/*
  my_pen.write_0();
  my_pen.write_1();
  my_pen.write_0();
  my_pen.write_1();
  my_pen.write_0();
  my_pen.write_1();
  my_pen.write_0();*/

  delay( 50000 );
  
  /*
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
  */
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
