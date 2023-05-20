#include <Wire.h> 
#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#define disparo   22 
#define receptor  23 
#define BUZZER 11 
#define col 4
#define fil 4
#define servo     45
#define direccion_lcd 0x27


char keys[fil][col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pines_filas[fil] = {5,4,3,2};
byte pines_columnas[col] = {9,8,7,6};

LiquidCrystal_I2C pantalla_grupo(direccion_lcd, fil, col);
Keypad teclado_grupo = Keypad( makeKeymap(keys), pines_filas, pines_columnas,fil,col);
Servo Servo_grupo; 

float d;
float capacidad; 
float medicion();
int lectura_teclado();
long sensor, distancia;
void barra_led();


  void setup() {
  Serial.begin(9600); 
  Wire.begin(); 
  pantalla_grupo.init();
  pantalla_grupo.backlight();
  pinMode(disparo, OUTPUT);
  pinMode(receptor,INPUT);
  Servo_grupo.attach(servo); 
  Servo_grupo.write(0);
  for(int i = 30; i <=39; i++){
  pinMode(i,OUTPUT);
  pinMode(11,OUTPUT);
}
}
  
void loop() {
  void barra_led();
   lectura_teclado(); 
   capacidad = 110 - medicion();
   Serial.println(capacidad);
   if (capacidad <= 100){
    pantalla_grupo.setCursor(0,0); 
     pantalla_grupo.print("Almacenado:");  
   pantalla_grupo.setCursor(11,0); 
   pantalla_grupo.print(capacidad);
   pantalla_grupo.print("%  ");
   pantalla_grupo.setCursor(0,1);
pantalla_grupo.print("Desea servir?   ");
   }
   else {
    pantalla_grupo.setCursor(0,0);
    pantalla_grupo.print(" Cierre la Tapa ");
    pantalla_grupo.setCursor(0,1);
    pantalla_grupo.print("                ");
   }
 
   if(capacidad < 2){ 
    tone(BUZZER, 1000);
     digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(36, LOW);
    digitalWrite(37, LOW);
    digitalWrite(38, LOW);
    digitalWrite(39, LOW);
    
    }
    else if(capacidad >= 3 && capacidad < 6){
  digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(36, LOW);
    digitalWrite(37, LOW);
    digitalWrite(38, LOW);
    digitalWrite(39, HIGH);
    noTone(BUZZER);
    }
    else if(capacidad >= 10 && capacidad < 15){  
      digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(36, LOW);
    digitalWrite(37, LOW);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    noTone(BUZZER);
    }
    else if(capacidad >= 20 && capacidad < 25){ 
  digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    noTone(BUZZER);
    }
    else if(capacidad >= 30 && capacidad < 35){  
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    noTone(BUZZER);
    }
    else if(capacidad >= 40  && capacidad < 45){  
      digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    noTone(BUZZER);
    }
    else if(capacidad >= 50 && capacidad < 55){  
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    noTone(BUZZER);
    }
    else if(capacidad >= 60 && capacidad < 65){  
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    noTone(BUZZER);

    }
    else if(capacidad >= 70 && capacidad < 75){  
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    noTone(BUZZER);

    }
    else if(capacidad >= 80 && capacidad < 85){   
    digitalWrite(30, LOW);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);

    }
    else if(capacidad >= 90){   
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    noTone(BUZZER);
    }
    
}

   float medicion(){
   long t; 
   digitalWrite(disparo, HIGH);
   delayMicroseconds(10);
   digitalWrite(disparo, LOW);
   t = pulseIn(receptor, HIGH);
   d= t / 59;
   int porcentaje = ((d)/20)*100;
  delay(100);
  return porcentaje;
   }
  int lectura_teclado(){
  char tecla = teclado_grupo.getKey();
  if(tecla){
switch(tecla){
  
   case '1':
   if(capacidad >= 5){ 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("   1 onza   ");
      Serial.println(capacidad);
      Servo_grupo.write(60);
      delay(2000);
      Servo_grupo.write(0);
      delay(500);
     
      break;
   } else{    
    for(int i = 0; i < 3; i++){
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("      producto     ");
     delay(500);
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("  escaso   ");
     delay(500);
    }
    break;
  }

  case '2': 
   if(capacidad >= 10){ 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("   2 onzas   ");
      Serial.println(capacidad);
      Servo_grupo.write(60);
      delay(5000);
      Servo_grupo.write(0);
      delay(500);
      
      break;
   } else{    
    for(int i = 0; i < 3; i++){
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("      producto     ");
     delay(500);
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("  escaso   ");
     delay(500);
    } 
    break;
  }

  case '3': 
   if(capacidad >= 20){ 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("   3 onzas    ");
      Serial.println(capacidad);
      Servo_grupo.write(60);
      delay(10000);
      Servo_grupo.write(0);
      delay(500);
      
      break;
   } else{    
    for(int i = 0; i < 3; i++){
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("      producto     ");
     delay(500);
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("  escaso   ");
     delay(500);
    }
    break;
  }

  case '4': 
   if(capacidad >= 30){
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  4 onzas   ");
      Serial.println(capacidad);
      Servo_grupo.write(60);
      delay(15000);
      Servo_grupo.write(0);
      delay(500);
      
      break;
   } else{   
    for(int i = 0; i < 3; i++){
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("      producto     ");
     delay(500);
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("  escaso   ");
     delay(500);
    }
    break;
  }
  case '5': 
   if(capacidad >= 40){ 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  5 onzas   ");
      Serial.println(capacidad);
      Servo_grupo.write(60);
      delay(20000);
      Servo_grupo.write(0);
      delay(500);
       
      break;
   } else{   
    for(int i = 0; i < 3; i++){
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("      producto     ");
     delay(500);
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("  escaso   ");
     delay(500);
    }
    break;
  }

  case '6': 
   if(capacidad >= 50){ 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("6 onzas ");
      Serial.println(capacidad);
      Servo_grupo.write(60);
      delay(30000);
      Servo_grupo.write(0);
      delay(500);
     
      break;
   } else{   
    for(int i = 0; i < 3; i++){
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("      producto     ");
     delay(500);
     pantalla_grupo.setCursor(0,1);
     pantalla_grupo.print("  escaso   ");
     delay(500);
    }
    break;
  }
  case '7': 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  sirvete :  )");
   delay(900);
    break;
    case '8': // boton invalido
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  sirvete :)  ");
   delay(900);
    break;
    case '9': 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  sirvete :)  ");
   delay(900);
    break;
    case '0':
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  sirvete :)  ");
   delay(900);
    break;
    case 'A': 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  sirvete :)  ");
   delay(900);
    break;
    case 'B': 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  sirvete :)  ");
   delay(900);
    break;
    case 'C':
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  sirvete :)  ");
   delay(900);
    break;
    case 'D': 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print("  sirvete :)  ");
   delay(900);
    break;
    case '*': 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print(  "sirvete :)"  );
   delay(900);
    break;
    case '#': 
   pantalla_grupo.setCursor(0,1);
   pantalla_grupo.print(  "sirvete :)"  );
   delay(900);
    break;
  }
} 
  }
