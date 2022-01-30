void In_home(){
  if(Train1 == 22 && Poji22 == 0 && T1SS == 0){
    Send1=0; 
    digitalWrite(S_Timer_set, LOW);
    T1SS = 1;                      
    Poji22 = 1;
    Train1G = 1;
  }
   if(digitalRead(S_Train_go) == HIGH && Train1G == 1 && T1SS == 1
     && (!(Train1==3 || Train2==3 || Train3==3 || Train4==3
     || Train1==4 || Train2==4 || Train3==4 || Train4==4))){
     Send1=10;
     Data6=1;
     Data7=1;
     T2MS=0;
     T3MS=0;
     T3MS=0;
                         
    digitalWrite(S_Timer_set, HIGH);           
    Train1G  = 0;                              
                             
  }
  //========
  if(Train1 == 32 && Poji32 == 0 && T1MS == 0){
    Send1=0;
    digitalWrite(M_Timer_set, LOW);
    T1MS = 1;                      
    Poji32 = 1;                    
    Train1G = 1;
  }
   if(digitalRead(M_Train_go) == HIGH && Train1G == 1 && T1MS == 1
    && (!(Train1==3 || Train2==3 || Train3==3 || Train4==3
    || Train1==4 || Train2==4 || Train3==4 || Train4==4))){
    Send1=10;
    Data6=2;
    Data7=2;
     T2SS=0;
     T3SS=0;
     T3SS=0;              
    digitalWrite(M_Timer_set, HIGH);           
    Train1G  = 0;                               
  }
  //========
    if(Train2 == 22 && Poji22 == 0 && T2SS == 0){
    Send2=0;                  
    digitalWrite(S_Timer_set, LOW);          
    T2SS = 1;                                
    Poji22 = 1;                              
    Train2G = 1;                             
  }
     if(digitalRead(S_Train_go) == HIGH && Train2G == 1 && T2SS == 1
     && (!(Train1==3 || Train2==3 || Train3==3 || Train4==3
     || Train1==4 || Train2==4 || Train3==4 || Train4==4))){
    Data6=1;
    Data7=1;
    Send2=20;
     T1MS=0;
     T3MS=0;
     T4MS=0;          
    digitalWrite(S_Timer_set, HIGH);        
    Train2G  = 0;                                                    
  }
  
  //=============
   if(Train2 == 32 && Poji32 == 0 && T2MS == 0){
    Send2=0;             
    digitalWrite(M_Timer_set, LOW);          
    T2MS = 1;                                
    Poji32 = 1;                              
    Train2G = 1;                         
  }
  
    if(digitalRead(M_Train_go) == HIGH && Train2G == 1 && T2MS == 1
    && (!(Train1==3 || Train2==3 || Train3==3 || Train4==3
    || Train1==4 || Train2==4 || Train3==4 || Train4==4))){
    Data6=2;
    Data7=2;
    Send2=20;
     T1SS=0;
     T3SS=0;
     T4SS=0;          
    digitalWrite(M_Timer_set, HIGH);                                    
    Train2G  = 0;                                                         
  }
  //===============
  if(Train3 == 22 && Poji22 == 0 && T3SS == 0){
    Send3=0;             
    digitalWrite(S_Timer_set, LOW);          
    T3SS = 1;                                
    Poji22 = 1;                              
    Train3G = 1;                             
  }
   if(digitalRead(S_Train_go) == HIGH && Train3G == 1 && T3SS == 1
    && (!(Train1==3 || Train2==3 || Train3==3 || Train4==3
    || Train1==4 || Train2==4 || Train3==4 || Train4==4))){
    Data6=1;
    Data7=1;
    Send3=20;
     T1MS=0;
     T2MS=0;
     T4MS=0;         
    digitalWrite(S_Timer_set, HIGH);        
    Train3G  = 0;                                                    
  }
  //==============
   if(Train3 == 32 && Poji32 == 0 && T3MS == 0){
    Send3=0;
    digitalWrite(M_Timer_set, LOW);
    T3MS = 1;                      
    Poji32 = 1;                    
    Train3G = 1;
  }
    if(digitalRead(M_Train_go) == HIGH && Train3G == 1 && T3MS == 1
    && (!(Train1==3 || Train2==3 || Train3==3 || Train4==3
    || Train1==4 || Train2==4 || Train3==4 || Train4==4))){
    Data6=2;
    Data7=2;
    Send3=20;
     T1SS=0;
     T2SS=0;
     T4SS=0;         
    digitalWrite(M_Timer_set, HIGH);        
    Train3G  = 0;                                             
  }
  //=================
   if(Train4 == 22 && Poji22 == 0 && T4SS == 0){
    Send4=0;            
    digitalWrite(S_Timer_set, LOW);
    T4SS = 1;                      
    Poji22 = 1;                    
    Train4G = 1;                   
  }
   if(digitalRead(S_Train_go) == HIGH && Train4G == 1 && T4SS == 1
    && (!(Train1==3 || Train2==3 || Train3==3 || Train4==3
    || Train1==4 || Train2==4 || Train3==4 || Train4==4))){
    Data6=1;
    Data7=1; 
    Send4=7;
     T1MS=0;
     T2MS=0;
     T3MS=0;          
    digitalWrite(S_Timer_set, HIGH);         
    Train4G  = 0;                                                      
  }
  //============
    if(Train4 == 32 && Poji32 == 0 && T4MS == 0){
    Send4=0;                 
    digitalWrite(M_Timer_set, LOW);          
    T4MS = 1;                                
    Poji32 = 1;                              
    Train4G = 1;                             
  }
     if(digitalRead(M_Train_go) == HIGH && Train4G == 1 && T4MS == 1
      && (!(Train1==3 || Train2==3 || Train3==3 || Train4==3
      || Train1==4 || Train2==4 || Train3==4 || Train4==4))){
     Data6=2;
     Data7=2;
     Send4=7;
     T1SS=0;
     T2SS=0;
     T3SS=0;   
    digitalWrite(M_Timer_set, HIGH);       
    Train4G  = 0;                                              
  }
  //===========
 
  
}
