/* Author 86kanth@gmail.com
 * Code For Maker Nano / Uno
 * V1.0
 */


#define PIEZO 8
int octo = 2;                // to optocoupler ANODE
int upstair_pir = 3;         //From PIR upstairs
int downstair_pir = 4;      //From PIR downstairs
int led_on_time = 60000;    //1minute    //How long light stays ON


//Dont change anything here
int upstair = 0;                   // PIR status
int downstair = 0;
int toggle = 0;
int start_trigger = 0;

void setup() {
 pinMode(octo, OUTPUT);       
 pinMode(upstair_pir, INPUT); 
 pinMode(downstair_pir, INPUT); 
 pinMode(PIEZO, OUTPUT);    
 Serial.begin(115200);
     tone(PIEZO,350);
  delay(150);
       tone(PIEZO,400);
  delay(150);
         tone(PIEZO,500);
  delay(150);
  tone(PIEZO,600);
 delay(500);
   tone(PIEZO,800);
 delay(500);
   noTone(PIEZO);
 
}


void check_pir(){
  upstair = digitalRead(upstair_pir); 
  downstair = digitalRead(downstair_pir); 
  
 if (upstair == HIGH || downstair == HIGH ) {   // if motion detected
   
  Serial.println("Motion detected");
  digitalWrite(octo, HIGH);
  
  if (upstair == HIGH){Serial.println("Upstairs Motion");}
  if (downstair == HIGH){Serial.println("Downstairs Motion");}
  
 }else{
  digitalWrite(octo, LOW);
 }
}


void loop(){

 check_pir();
  
} 
