// ** MEGA Receive ******************************
void Receive(){
    if (Serial2.available() > 0) {
        Train = Serial2.readStringUntil('\n');
        
       //Train=Train.toInt();
       //Serial.println(Train);
      // Serial.println(Train1,Train2,Train3,Train4); //28ms
    }
      mc = Train.length();                            
    Hedder = Train.substring(0,2);                  
    Termination = Train.substring(17,18);           
    //Serial.print(" length :  ");
    //Serial.print(mc);
    //Serial.print("  Hedder:  ");
    //Serial.print(Hedder);
    //Serial.print("  Termination  :  ");
    //Serial.println(Termination);
   
    if(Hedder=="99" && mc==19 && Termination=="F"){
      Train1s = Train.substring(3,5);
      if(Train1s>="00" && Train1s<="99"){
      Train1=Train1s.toInt();
      }
      
      Train2s = Train.substring(6,8);
      if(Train2s>="00" && Train2s<="99"){
      Train2=Train2s.toInt();
      }
      
      Train3s = Train.substring(9,11);
      if(Train3s>="00" && Train3s<="99"){
      Train3=Train3s.toInt();
      }
      
      Train4s = Train.substring(12,14);
       if(Train4s>="00" && Train4s<="99"){ 
      Train4=Train4s.toInt();
       }
      
      SInPoji = Train.substring(15,17);
      
         //Data5=SInPoji.toInt(); 
        // Data5=abs(data5);
      
     //Serial.print("SInPoji==");
    // Serial.println(SInPoji);
    // Serial.print("Train1-4==");
     // Serial.print(Train1);
      Data1=Train1;
     // Serial.print(Train2);
       Data2=Train2;
     // Serial.print(Train3);
       Data3=Train3;
      //Serial.println(Train4);
       Data4=Train4;
     }
  
}
// ** MEGA Receive end **************************
