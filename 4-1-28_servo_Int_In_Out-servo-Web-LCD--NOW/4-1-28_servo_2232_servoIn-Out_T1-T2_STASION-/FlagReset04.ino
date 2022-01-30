void FlagReset04(){
 // if(Train1==3 || Train2==3 || Train3==3 || Train4==3){
   // Data7=0;
  //}
   if(Train1==3 || Train2==3 || Train3==3 || Train4==3){
     Data7=3;
    if(T1SS==1 && digitalRead(S_Timer_set)==HIGH){
      T1SS = 0;
    }
    if(T1MS==1 && digitalRead(M_Timer_set)==HIGH){
      T1MS = 0;
    }
    if(T2SS==1 && digitalRead(S_Timer_set)==HIGH){
      T2SS = 0;
    }
    if(T2MS==1 && digitalRead(M_Timer_set)==HIGH){
      T2MS = 0;
    }
    if(T3SS==1 && digitalRead(S_Timer_set)==HIGH){
      T3SS = 0;
    }
    if(T3MS==1 && digitalRead(M_Timer_set)==HIGH){
      T3MS = 0;
    }
    if(T4SS==1 && digitalRead(S_Timer_set)==HIGH){
      T4SS = 0;
    }
    if(T4MS==1 && digitalRead(M_Timer_set)==HIGH){
      T4MS = 0;
    }
   
    Poji22=0;
    Poji32=0;
    Train1TimeSetFlag1=0; 
    Train2TimeSetFlag2=0;
    Train3TimeSetFlag3=0;
    Train4TimeSetFlag4=0;
  }
}
