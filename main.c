#include <STC8G.H>
#include "intrins.H"
#include "straight.C"


xdata unsigned char disp_num[8]={0xC3,0x66,0x2C,0x38,0x78,0x4E,0xC3,0x81};
xdata unsigned char disp_on[3]={255,255,255};
xdata unsigned char disp_off[3]={0,0,0};
xdata unsigned char disp_temp[64*3];
xdata unsigned char i;

void convert(unsigned char num)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(	(disp_num[num*i]&0x00)	==	0x80){disp_temp[i*3]=disp_on[0];	disp_temp[(i*3)+1]=disp_on[1];	disp_temp[(i*3)+2]=disp_on[2];}
		else{disp_temp[i*3]=disp_off[0];	disp_temp[(i*3)+1]=disp_off[1];	disp_temp[(i*3)+2]=disp_off[2];}	
		
		if(	(disp_num[num*i]&0x40)	==	0x40){disp_temp[i*3]=disp_on[0];	disp_temp[(i*3)+1]=disp_on[1];	disp_temp[(i*3)+2]=disp_on[2];}
		else{disp_temp[i*3]=disp_off[0];	disp_temp[(i*3)+1]=disp_off[1];	disp_temp[(i*3)+2]=disp_off[2];}
		
		if(	(disp_num[num*i]&0x20)	==	0x20){disp_temp[i*3]=disp_on[0];	disp_temp[(i*3)+1]=disp_on[1];	disp_temp[(i*3)+2]=disp_on[2];}
		else{disp_temp[i*3]=disp_off[0];	disp_temp[(i*3)+1]=disp_off[1];	disp_temp[(i*3)+2]=disp_off[2];}
		
		if(	(disp_num[num*i]&0x10)	==	0x10){disp_temp[i*3]=disp_on[0];	disp_temp[(i*3)+1]=disp_on[1];	disp_temp[(i*3)+2]=disp_on[2];}
		else{disp_temp[i*3]=disp_off[0];	disp_temp[(i*3)+1]=disp_off[1];	disp_temp[(i*3)+2]=disp_off[2];}
		
		if(	(disp_num[num*i]&0x08)	==	0x08){disp_temp[i*3]=disp_on[0];	disp_temp[(i*3)+1]=disp_on[1];	disp_temp[(i*3)+2]=disp_on[2];}
		else{disp_temp[i*3]=disp_off[0];	disp_temp[(i*3)+1]=disp_off[1];	disp_temp[(i*3)+2]=disp_off[2];}
		
		if(	(disp_num[num*i]&0x04)	==	0x04){disp_temp[i*3]=disp_on[0];	disp_temp[(i*3)+1]=disp_on[1];	disp_temp[(i*3)+2]=disp_on[2];}
		else{disp_temp[i*3]=disp_off[0];	disp_temp[(i*3)+1]=disp_off[1];	disp_temp[(i*3)+2]=disp_off[2];}
		
		if(	(disp_num[num*i]&0x02)	==	0x02){disp_temp[i*3]=disp_on[0];	disp_temp[(i*3)+1]=disp_on[1];	disp_temp[(i*3)+2]=disp_on[2];}
		else{disp_temp[i*3]=disp_off[0];	disp_temp[(i*3)+1]=disp_off[1];	disp_temp[(i*3)+2]=disp_off[2];}
		
		if(	(disp_num[num*i]&0x01)	==	0x01){disp_temp[i*3]=disp_on[0];	disp_temp[(i*3)+1]=disp_on[1];	disp_temp[(i*3)+2]=disp_on[2];}
		else{disp_temp[i*3]=disp_off[0];	disp_temp[(i*3)+1]=disp_off[1];	disp_temp[(i*3)+2]=disp_off[2];}
	}
}

void main()
{
	P1M1 = 0x00;	P1M0 = 0x00;
	P3M1=  0x00;		P3M0 = 0x00;
	P5M1 = 0x00;	P5M0 = 0x00;
	convert(1);
	while(1)
	{
		
		for(i=0;i<64;i++)
		{
			send_byte(disp_temp[i*3],disp_temp[i*3+1],disp_temp[i*3+2]);
		}
		RES();
	}
}