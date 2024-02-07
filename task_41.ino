const int sw_L = 13;  
const int sw_R = 12;  

const int potL = A1; 
const int potR = A0;

const int DCmotor_L = 6;
const int DCmotor_R = 5;


int inDC_L;
int inDC_R;
int outDC_L;
int outDC_R;


char reading = 'x';

void setup()
{
  pinMode(sw_L, INPUT);
  pinMode(sw_R, INPUT);

  pinMode(potR, INPUT);
  pinMode(potL, INPUT);

  pinMode(DCmotor_L, OUTPUT); 
  pinMode(DCmotor_R, OUTPUT); 
  
  Serial.begin(9600); 
  

}

void loop()
{
  //Serial.println("ALLam back");
  
 inDC_L = analogRead(potL);
 inDC_R = analogRead(potR);
  
   outDC_L = map(inDC_L, 0, 1023, 0, 255);
   outDC_R = map(inDC_R, 0, 1023, 0, 255);
  
   reading=Serial.read();
  
//if(Serial.available()>0){
  if(digitalRead(sw_L) || reading == 'L' )// if(digitalRead(sw_L) || Serial.available()>0 & reading == 'L' )

  {
       analogWrite(DCmotor_L, outDC_L);
       Serial.print("outDC_L = ");
       Serial.println(outDC_L);
       delay(1000);
     
  }
 else if(digitalRead(sw_R) || reading == 'R')
  {
    analogWrite(DCmotor_R, outDC_R);
    Serial.print("outDC_R = ");
    Serial.println(outDC_R);
    delay(1000);
    while(Serial.read() == 'L');

  }
  
 else if (digitalRead(sw_L) || digitalRead(sw_R) || reading == 'S')
   {
     analogWrite(DCmotor_L, 0 );
     analogWrite(DCmotor_R, 0);
   }
 else 
   {
   Serial.println("INVALID CHARCTER || Open the switch");delay(2000);
   }
                                          
 //}  
  
}
                    
 //-------------------------------------------------------------
                    
                    
                    
// if(Serial.available()>0) 
//   {
    
//      switch(reading)
//      { 
//         case 'L':analogWrite(/*L_motor*/,HobbyValue_L );
//                  Serial.println("L_moto is on”);
//                                                  break;       
//         case 'R':analogWrite(/*R_motor*/,HobbyValue_R );
//                  Serial.println("R_moto is on”);
//                                                   break;
//         case 'S':analogWrite(/*R_motor*/,0 );
//                  analogWrite(/*L_motor*/,0);               
//                  Serial.println("R_moto & L_moto are OFF”);
//                                                   break;
                                
//         default :
//                  Serial.println("INVALID CHARCTER”);
//                                                   break;