
//===========control_4=====================================================

void control_4(){
    
    // *** Start Contlor **********************************
     //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
   unsigned long nowTime = millis();
   // ** "22","32" Train4 ###########################################
      //==1-0=======Train4=="21"===1-0===================Main>>>Sub
     if(Train4==21 && (Train1==22 || Train2==22 || Train3==22 )){//4
      Send4=0;   // 2号車、
        Train4Flag4=0;
        Train4TimeSetFlag4=0;
       //SubSetTime21 = nowTime +  20000;  // 経過時間+セット時間//T1
     // Train2TimeSetFlag2=0;
      }

    if(Train4 == 21 && !(Train1==22 || Train2==22 || Train3==22 )){ //Sub>>>Sub//1//T1
    Send4=7; // 1号車、前照灯、通常走行
        Train4Flag4=0;
        Train4TimeSetFlag4=0;
   }
  
  //-------------------Train4=="31"===1-0=1>>0--------------------------------------------
     if(Train4==31 && (Train1==32 || Train2==32 || Train3==32 )){//4
      Send4=0;   // 2号車、
       Train4Flag4=0;
       Train4TimeSetFlag4=0;
       //MainSetTime31 = nowTime + random(3000,10000);  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=0;
      } 
      
     if(Train4==31 && !(Train1==32 || Train2==32 || Train3==32)){ //Sub>>>Sub//1//T1
      Send4=7; // 2号車、
        Train4Flag4=0;
        Train4TimeSetFlag4=0;
     }







  
//==========="3"====1-1================================== 
      if(Train4==3 && (Train1==4 || Train2==4 || Train3==4)){//4
           Send4=0;
      }
      if(Train4==3 && !(Train1==4 || Train2==4 || Train3==4)){
           Send4=10;
      }        
//=========="4"==1-0=====================================
      if(Train4==4 && (Train1==5 || Train2==5 || Train3==5)){//4
           Send4=0;   
      }     
      if(Train4==4 && !(Train1==5 || Train2==5 || Train3==5)){
           Send4=10;
      }        
//=========="5"==0-1=====================================
     if(Train4==5 && (Train1==6 || Train2==6 || Train3==6)){//4
            Send4=0;
    }
     if(Train4 ==5 && !(Train1==6 || Train2==6 || Train3==6 )){ //Sub>>>Sub//1//T1    
           Send4=10; // 1号車、前照灯、通常走行
    }        
//=========="6"==1-0=====================================
     if(Train4==6 && (Train1==7 || Train2==7 || Train3==7)){//4
            Send4=0;
    }
     if(Train4 ==6 && !(Train1==7 || Train2==7 || Train3==7 )){ //Sub>>>Sub//1//T1    
           Send4=10; // 1号車、前照灯、通常走行
    }       
      
//=========="7"==0-1=====================================
     if(Train4==7 && (Train1==8 || Train2==8 || Train3==8)){//4
            Send4=0;
    }
     if(Train4 ==7 && !(Train1==8 || Train2==8 || Train3==8 )){ //Sub>>>Sub//1//T1    
           Send4=10; // 1号車、前照灯、通常走行
    }    
//=========="8"==1-0=====================================
     if(Train4==8 && (Train1==9 || Train2==9 || Train3==9)){//4
            Send4=0;
    }
     if(Train4 ==8 && !(Train1==9 || Train2==9 || Train3==9 )){ //Sub>>>Sub//1//T1    
           Send4=10; // 1号車、前照灯、通常走行
    }   
//=========="9"==0-1=====================================
     if(Train4==9 && (Train1==10 || Train2==10 || Train3==10)){//
            Send4=0;            
     }
     if(Train4 ==9 && !(Train1==10 || Train2==10 || Train3==10 )){ //Sub>>>Sub//1//T1    
           Send4=10; // 1号車、前照灯、通常走行
    }    
//=========="10"==1-0=====================================
      if(Train4==10 && (Train1==11 || Train2==11 || Train3==11) && Train4TimeSetFlag4==1 ){//4
            Send4=0;
            SubSetTime10 = nowTime + 5000;  // 経過時間+セット時間//T1
      Train4TimeSetFlag4=0;
    }
      if(nowTime > SubSetTime10 && Train4 == 10 && !(Train1==11 || Train2==11 || Train3==11 )){ //Sub>>>Sub//1//T1
       
            Send4=10; // 1号車、前照灯、通常走行
      Train4TimeSetFlag4=0;
   }      
//=========="11"==0-1=====================================
     if(Train4==11 && (Train1==12 || Train2==12 || Train3==12)){//
            Send4=0;            
     }
     if(Train4 ==11 && !(Train1==12 || Train2==12 || Train3==12 )){ //Sub>>>Sub//1//T1    
           Send4=10; // 1号車、前照灯、通常走行
    }    
   //=========="12"==1-0=====================================
     if(Train4==12 && (Train1==13 || Train2==13 || Train3==13)){//
            Send4=0;            
     }
     if(Train4 ==12 && !(Train1==13 || Train2==13 || Train3==13 )){ //Sub>>>Sub//1//T1    
           Send4=10; // 1号車、前照灯、通常走行
     }    
  
   //======"13"====0-1=====一旦停止========================
         if(Train4==13 && Train4Flag4==0){//3
         Send4=0;   // 1号車、消灯　停止//ターマーなし
         SubSetTime13= nowTime + random(10000,13000);
         Train4Flag4=1;
          }
   if(nowTime > SubSetTime13 && Train4 == 13 &&  Train4Flag4==1 ){
         Train4Flag4=1;
         Train4TimeSetFlag4=1;
          }
   //===Train4=========13 一旦停止=============            
       if(Train4==13 &&  Train4TimeSetFlag4==1 && (Train1==21 || Train2==21 || Train3==21) 
          && (Train1==31 || Train2==31 || Train3==31)){//4
          Send4=0;              //21&&31_ON
          Train4TimeSetFlag4=1; 
         }
       if(Train4==13 && Train4TimeSetFlag4==1 && !(Train1==21 || Train2==21 || Train3==21)
          && !(Train1==31 || Train2==31 || Train3==31)){
            Send4=7;   // 2号車 //21_off &&31_off
            Data5=1;           
         Train4TimeSetFlag4=1;
          }
       if(Train4==13 && Train4TimeSetFlag4==1 && !(Train1==21 || Train2==21 || Train3==21)
           && (Train1==31 || Train2==31 || Train3==31)){
            Data5=1;
            Send4=7;   // 2号車  //31_ON
         Train4TimeSetFlag4=1;
          }
       if(Train4==13 && Train4TimeSetFlag4==1 && (Train1==21 || Train2==21 || Train3==21)
            && !(Train1==31 || Train2==31 || Train3==31)){
            Data5=2;
            Send4=7;   // 2号車  //21_ON
         Train4TimeSetFlag4=1;
          }
 
}

 
