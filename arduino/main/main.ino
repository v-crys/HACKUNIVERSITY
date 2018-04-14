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

        void write_array( unsigned char *p, int len );

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


void Pen::write_array( unsigned char *p, int len )
{
    int i;

    for ( i = 0; i < len; i++ )
        write_byte( p[ i ] );
}


unsigned char readByteCom()
{
  while( 1 )
  {
    if ( Serial.available() > 0 )
        return Serial.read();
  }
}

///////////////////////////////////// MAIN

void setup() 
{
servo.attach( NUMBER_PIN ); 

pinMode( 13, OUTPUT );

Serial.begin( 9600 );
}

  unsigned char input_arr[ 255 ];
  int arr_i = 0;
  unsigned char len_arr = 0;

void loop()
{
  int i;

  Pen my_pen;

  digitalWrite( 13, HIGH ); ///< Светодиод горит - ожидаем приема данных
  
  while (1)
  {
      if ( readByteCom() == 'd' ) ///< 'd' is start byte
        break;
  }

  len_arr = readByteCom();

  arr_i = 0;
  for ( i = 0; i < len_arr; i++ )
      input_arr[ i ] = readByteCom();

  digitalWrite( 13, LOW ); ///< Светодиод гаснет (через 3 секунды начнет писать)

  delay( 3000 );
  my_pen.write_array( input_arr, len_arr );

  

  
  
  //Serial.write( "test" );
  //delay( 50000 );
  /*
  unsigned char arr_byte[ 10 ];
  arr_byte[ 0 ] = 32;
  arr_byte[ 1 ] = 15;
  arr_byte[ 2 ] = 0;
  arr_byte[ 3 ] = 95;
  arr_byte[ 4 ] = 16;
  arr_byte[ 5 ] = 255;
  
  Pen my_pen;

  my_pen.write_array( arr_byte, 5 );

/*
  my_pen.write_byte( 32 );
  my_pen.write_byte( 15 );
  my_pen.write_byte( 0 );
  my_pen.write_byte( 95 );
  my_pen.write_byte( 16 );
*/
//digitalWrite( 13, LOW );

  //delay( 50000 );
  
  
}
