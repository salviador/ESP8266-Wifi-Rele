
extern WebSocketsServer webSocket;
void Rele_Init(void);
String Get_All_Status_rele_JSON(void);
void Set_Status_Relay(uint8_t nRelay, uint8_t stato);
void switch_update(void);

//https://techtutorialsx.com/2017/04/02/esp8266-nodemcu-pin-mappings/

struct _rele {
  unsigned char rele1;
  unsigned char rele2;
  unsigned char rele3;
  unsigned char rele4;
  unsigned char rele5;
  unsigned char rele6;
  unsigned char rele7;
  unsigned char rele8;  
}RELE;


void Rele_Init(void){
  RELE.rele1 = 0;
  RELE.rele2 = 0;
  RELE.rele3 = 0;
  RELE.rele4 = 0;
  RELE.rele5 = 0;
  RELE.rele6 = 0;
  RELE.rele7 = 0;
  RELE.rele8 = 0;
  pinMode(D0, OUTPUT); 
  pinMode(D4, OUTPUT); 
  pinMode(D2, OUTPUT); 
  pinMode(D3, OUTPUT); 
  digitalWrite(D0, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  
}

ButtonDebounce buttonRELE_1(D7, 200);  


String Get_All_Status_rele_JSON(void){
  String s = "{\"r1\":\"" + String(RELE.rele1) + "\"," +
              "\"r2\":\"" + String(RELE.rele2) + "\"," +
              "\"r3\":\"" + String(RELE.rele3) + "\"," +
              "\"r4\":\"" + String(RELE.rele4) + "\"," +
              "\"r5\":\"" + String(RELE.rele5) + "\"," +
              "\"r6\":\"" + String(RELE.rele6) + "\"," +
              "\"r7\":\"" + String(RELE.rele7) + "\"," +
              "\"r8\":\"" + String(RELE.rele8) + "\"}";
  return s;
}


void Set_Status_Relay(uint8_t nRelay, uint8_t stato){
  switch(nRelay){
    case 1:
      RELE.rele1 = stato;
      digitalWrite(D0, stato);
    break;
    case 2:
      RELE.rele2 = stato;
      digitalWrite(D4, stato);
    break;
    case 3:
      RELE.rele3 = stato;
      digitalWrite(D2, stato);
    break;
    case 4:
      RELE.rele4 = stato;
      digitalWrite(D3, stato);
    break;
    case 5:
      RELE.rele5 = stato;
    break;
    case 6:
      RELE.rele6 = stato;
    break;
    case 7:
      RELE.rele7 = stato;
    break;
    case 8:
      RELE.rele8 = stato;
    break;
    default:
    break;
  }
} 


void switch_update(void){  
  static bool SwitchStatoRele1=false; 
  
  buttonRELE_1.update();
  if(buttonRELE_1.state() == LOW){
    if(SwitchStatoRele1==false){
      if(RELE.rele1==1){
        Set_Status_Relay(1,0);
      }else{
        Set_Status_Relay(1,1);
      }
      String s = "{\"r1\":\"" + String(RELE.rele1) + "\"}";
      webSocket.sendTXT(0,s);
      
      SwitchStatoRele1 = true;
    }
  }
  if(buttonRELE_1.state() == HIGH){
    SwitchStatoRele1 = false;
  }








  
}


