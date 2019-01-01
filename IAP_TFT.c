#include<stc15.h>
sbit RS = P2^5;
sbit WR = P2^4;
sbit RD = P2^3;
sbit CS = P3^5;
sbit REST = P3^3;
#define DB_LOW P0 
#define LCD_W 480
#define LCD_H 800
sbit DB_8 =P2^2;
sbit DB_9 =P2^1;
sbit DB_10 =P2^0;
sbit DB_11 =P4^4;
sbit DB_12 =P4^2;
sbit DB_13 =P4^1;
sbit DB_14 =P3^7;
sbit DB_15 =P3^6;
void delayms(unsigned int c)  ;
void lcd_init(void);
void WR_REG(int A);
void WR_DATA(int A);
void address_set(int x1,int y1,int x2,int y2 );
void lcd_clear(int color) ;

	void main(void)
	{
	 lcd_init();
	 lcd_clear(0x38);
	}
	/*******************************************/
	void lcd_init(void)
	{
	CS =0;
	RD =1;
	WR =1;
	REST =0;
	delayms(200);
	REST =1;

	WR_REG(0X01);
	WR_DATA(16);
	}
 /***************************************/
 void delayms(unsigned int c)  
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=38;b>0;b--)
            for(a=130;a>0;a--);
}
/***********************************/
	void WR_REG(int A)
	{
	 CS =0;
	 RS =0;
	 DB_LOW =0Xff&A;
	 DB_8 =(A>>7)&0X01;
	 DB_9 =(A>>8)&0X01;
	 DB_10 =(A>>9)&0X01;
	 DB_11 =(A>>10)&0X01;
	 DB_12 =(A>>11)&0X01;
	 DB_13 =(A>>12)&0X01;
	 DB_14 =(A>>13)&0X01;
	 DB_15 =(A>>14)&0X01;
	 WR =0;
	 RD =1;
	 WR =1;

	}
	/*******************************/
		void WR_DATA(int A)
		{
		 CS =0;
		 RS =1;
		 DB_LOW =0Xff&A;
		 DB_8 =(A>>7)&0X01;
		 DB_9 =(A>>8)&0X01;
		 DB_10 =(A>>9)&0X01;
		 DB_11 =(A>>10)&0X01;
		 DB_12 =(A>>11)&0X01;
		 DB_13 =(A>>12)&0X01;
		 DB_14 =(A>>13)&0X01;
		 DB_15 =(A>>14)&0X01;
		 WR =0;
		 RD =1;
		 WR =1;
		}	
/*****************************/
void lcd_clear(int color)
{
int i,j;
address_set(0,0,LCD_W-1,LCD_H-1);
 for(i=0;i<LCD_W;i++)
 {
	 for(j=0;j<LCD_H;j++)
	 {
	 WR_DATA (color);
	 }
 }

}
/*******************************************/
    void address_set(int x1,int y1,int x2,int y2 )
	{
	WR_REG(2);
	WR_DATA(x1);
	WR_REG(3);
	WR_DATA(y1);
	WR_REG(6);
	WR_DATA(x2);
	WR_REG(7);
	WR_DATA(y2);
	WR_REG(0X0F);
	}											 