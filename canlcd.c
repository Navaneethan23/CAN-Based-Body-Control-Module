 #include<LPC21XX.H>
#define RS 1<<17
#define RW 1<<18
#define E 1<<19
#define LCD_D 0x0f<<20
/*typedef unsigned int U32;

typedef unsigned char U8;

typedef signed char S8;

typedef float F32;*/
void delay_milli(unsigned int);
void Float_display(float );
void str(unsigned char *);
void lcd_integer(int );

void LCD_DATA(unsigned char);
void LCD_init(void);
void LCD_command(unsigned char );

void LCD_init(void){

       IODIR1 = LCD_D|RS|E|RW;
	   LCD_command(0x01);
	   LCD_command(0x02);
	   LCD_command(0x0c);
	   LCD_command(0x28);
	   LCD_command(0x80);
	 }

     void LCD_command(unsigned char cmd){
	 IOCLR1 = LCD_D;
	 IOSET1 = (cmd & (0xf0))<<16;
	 IOCLR1 = RS;
	 IOCLR1 = RW;
	 IOSET1 = E;
	 delay_milli(20);
	 IOCLR1 = E;

	 IOCLR1 = LCD_D;
	 IOSET1 = (cmd & (0x0f))<<20;
	 IOCLR1 = RS;
	 IOCLR1 = RW;
	 IOSET1 = E;
	 delay_milli(2);
	 IOCLR1 = E;
	}

	void LCD_DATA(unsigned char d){
	IOCLR1 = LCD_D;
    IOSET1 = (d & (0xf0))<<16;
	IOSET1 = RS;
	IOCLR1 = RW;
    IOSET1 = E;
	delay_milli(2);
	IOCLR1 =E;

	IOCLR1 = LCD_D;
    IOSET1 =(d & (0x0f))<<20;
	IOSET1 = RS;
	IOCLR1 = RW;								   
    IOSET1 = E;
	delay_milli(2);
	IOCLR1=E;
	}
void str (unsigned char *s)
{

	while(*s)

	LCD_DATA(*s++);

}


void lcd_integer(int n)

{
	signed char arr[5],i=0;

	if(n==0)

		LCD_DATA(0);

	else

	{

		   if(n<0)

		   {
             LCD_DATA('-');

				 n=-n;

       }

	      while(n>0)

      	{

		     arr[i++]=n%10;

		     n=n/10;

        }

        for(--i;i>=0;i--)

   	      LCD_DATA(arr[i]+48);

  }

}

void Float_display(float f_val)

{

  unsigned int number;

  number = f_val;

  lcd_integer(number);

  LCD_DATA('.');

  number=(f_val-number)*100;

  lcd_integer(number);	

}
void delay_milli(unsigned int m){
 T0PR = 15000-1;
 T0TCR = 0x01;
 while(T0TC < m);
 T0TCR = 0x03;
 T0TCR = 0x00;
 }


