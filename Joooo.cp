#line 1 "C:/Users/Youssef Taha/Desktop/Embeded/Joooo.c"
void output(){
 adcon1 = 6;
 trisd = 0;
 trisc = 0;
 trisb.b0 = 1;
 trisb.b4 = 1;
 trisa = 0;
 portc.b1 = 1;
 GIE_BIT = 1;
 PEIE_BIT = 1;
 portd = 0;
 porta = 0b010000;
}

void pin()
{
 INTF_BIT = 0;
 INTE_BIT = 1;
 RBIF_BIT = 0;
 RBIE_BIT = 1;
}

int i;
int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 32, 33, 34, 35};

void interrupt()
{
 if(RBIF_BIT){
 porta.b0 = 1;
 porta.b4 = 1;
 porta.b5 = 1;
 for(i=23; i>=1; i--)
 {
 portd = arr[i];
 if(!portb.b0)
 i = 3;
 portd = arr[i];
 if(i == 3)
 {
 porta.b4 = 0;
 porta.b5 = 0;
 }
 delay_ms(500);
 }
 porta.B0 = 0;
 porta.B2 = 1;
 porta.B3 = 1;
 porta.B4 = 1;
 for(i=15; i>=1; i--)
 {
 portd = arr[i];
 if(!portb.b0)
 i = 3;
 portd = arr[i];
 if(i == 3)
 {
 porta.b1 = 1;
 porta.b2 = 0;
 }
 delay_ms(500);
 }
 porta = 0;
 }
}

void main() {
 output();
 pin();
 while(1)
 {
 asm sleep;
 }

}
