//===========control_1=====================================================
 void control_1(){
     
    unsigned long nowTime = millis();                // 現在時刻セット
  // *** Start Contlor **********************************   
     //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
  // ** "22","32" Train1 ###########################################
 //==================0-1=========================================

 /*
   if(Train1==22 ){
   if(Train1==22 && Train1TimeSetFlag1==0 ){//1
      Send1=0;   // 1号車、消灯　停止
      SubSetTime22= nowTime + random(5000,15000); // 経過時間+セット時間
      Train1TimeSetFlag1=1;//22^1
      //Serial.println(SubSetTime22-nowTime);
  };
   
 if(nowTime > (SubSetTime22+Time22) && Train1 == 22 ){
      Data6=1;
      Data7=1;
     
     Send1=10;//20ok-19ok-18ok-17ok-16ok-15,16nG
     Train1TimeSetFlag1=1;
    };
 
   }; 
   */
  //------------------0-1---------------------------------------
 /*
       if(Train1==32 ){
     if(Train1==32 && Train1TimeSetFlag1==0 ){//1
      Send1=0; // 1号車、消灯　停止
      //MainServoTime32Flag=0;
      MainSetTime32 = nowTime + 10000;  // 経過時間+セット時間
      
      //MainServoTime32=MainSetTime32-3000;
      Train1TimeSetFlag1 = 1;
     // MainServoTime32Flag=1;
  }
   if(nowTime > (MainSetTime32+Time32) && Train1 == 32 && Train1TimeSetFlag1==1 ){//1 Main>>Main
      Data6=2;
      Data7=2;    
      Send1=10; // 1号車、前照灯    通常走行
    
     //MainSetTime32=100;
     Train1TimeSetFlag1 = 1;
     //MainServoTime32Flag=0;
    // Data6=2;
    };
       }
       */
     
       
        //==========="3"====0-1================================== 
        
        if(Train1==3 && (Train2==4 || Train3==4 || Train4==4)){//4
            Send1=0;
           }
        if(Train1==3 && !(Train2==4 || Train3==4 || Train4==4)){
           Send1=7;
        }
        
     //=========="4"==1-0=====================================
      if(Train1==4 && (Train2==5 || Train3==5 || Train4==5)){//4
            Send1=0;
    }
      if(Train1 == 4 && !(Train2==5 || Train3==5 || Train4==5 )){ //Sub>>>Sub//1//T1       
     Send1=7; // 1号車、前照灯、通常走行
   }  
     //=========="5"==0-1=====================================
      if(Train1==5 && (Train2==6 || Train3==6 || Train4==6)){//4
            Send1=0;
          // SubSetTime5 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train1TimeSetFlag1=1;
    }
      if(Train1 == 5 && !(Train2==6 || Train3==6 || Train4==6 )){ //Sub>>>Sub//1//T1
       
     Send1=10; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=1;
   }  
          //=========="6"==1-0=====================================
      if(Train1==6 && (Train2==7 || Train3==7 || Train4==7)){//4
            Send1=0;
           //SubSetTime6 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
    }
      if(Train1 == 6 && !(Train2==7 || Train3==7 || Train4==7 )){ //Sub>>>Sub//1//T1
       
     Send1=10; // 1号車、前照灯、通常走行
   // Train1TimeSetFlag1=0;
   }  
         //=========="7"==0-1=====================================
      if(Train1==7 && (Train2==8 || Train3==8 || Train4==8)){//4
            Send1=0;
           //SubSetTime7 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=1;
    }
      if(Train1 == 7 && !(Train2==8 || Train3==8 || Train4==8 )){ //Sub>>>Sub//1//T1
       
     Send1=10; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=1;
   }  
      //=========="8"==1-0=====================================
      if(Train1==8 && (Train2==9 || Train3==9 || Train4==9)){//4
            Send1=0;
           //SubSetTime8 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
    }
      if(Train1 == 8 && !(Train2==9 || Train3==9 || Train4==9 )){ //Sub>>>Sub//1//T1
       
     Send1=10; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=0;
   }  
    //=========="9"==0-1=====================================
      if(Train1==9 && (Train2==10 || Train3==10 || Train4==10)){//4
            Send1=0;
           //SubSetTime9 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train1TimeSetFlag1=1;
    }
      if(Train1 == 9 && !(Train2==10 || Train3==10 || Train4==10 )){ //Sub>>>Sub//1//T1
       
     Send1=10; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=1;
   }  
   //=========="10"==1-0=====================================
      if(Train1==10 && (Train2==11 || Train3==11 || Train4==11)){//4
            Send1=0;
           //SubSetTime10 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
    }
      if(Train1 == 10 && !(Train2==11 || Train3==11 || Train4==11 )){ //Sub>>>Sub//1//T1
       
     Send1=10; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=0;
   }  
   //=========="11"==0-1=====================================
      if(Train1==11 && (Train2==12 || Train3==12 || Train4==12)){//4
            Send1=0;
           //SubSetTime11 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train1TimeSetFlag1=1;
    }
      if(Train1 == 11 && !(Train2==12 || Train3==12 || Train4==12 )){ //Sub>>>Sub//1//T1
       
     Send1=10; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=1;
   }     
       //=========="12"==1-0=====================================
      if(Train1==12 && (Train2==13 || Train3==13 || Train4==13)){//4
            Send1=0;
           //SubSetTime12 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
    }
      if(Train1 == 12 && !(Train2==13 || Train3==13 || Train4==13)){ //Sub>>>Sub//1//T1
       
     Send1=12; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=0;
   }     
 //================Sub>>Main==0-1===============================
 //============13 一旦停止=============
   if(Train1==13 && Train1Flag1==0){//3
         Send1=0;   // 1号車、消灯　停止//ターマーなし
         SubSetTime13= nowTime + random(10000,13000);
         Train1Flag1=1;
          }
   if(nowTime > SubSetTime13 && Train1 == 13 &&  Train1Flag1==1 ){
          Train1Flag1=1;
          Train1TimeSetFlag1=1;
          }           
  //===Train1=========13 一旦停止=============
         if(Train1==13 &&  Train1TimeSetFlag1==1 && (Train2==21 || Train3==21 || Train4==21) && (Train2==31 || Train3==31 || Train4==31)){//4
         Send1=0;                 //21&&31_ON
         Train1TimeSetFlag1=1; 
         }
         if(Train1==13 && Train1TimeSetFlag1==1 && !(Train2==21 || Train3==21 || Train4==21) 
          && !(Train2==31 || Train3==31 || Train4==31)){
            Send1=11;   // 1号車 //21_OFF &&31_OFF
            Data5=1;          
         Train1TimeSetFlag1=1;
          }
         if(Train1==13 && Train1TimeSetFlag1==1 && !(Train2==21 || Train3==21 || Train4==21)
           && (Train2==31 || Train3==31 || Train4==31)){
            Data5=1;
            Send1=11;   // 1号車  //31_ON
         Train1TimeSetFlag1=1;
          }
         if(Train1==13 && Train1TimeSetFlag1==1 && (Train2==21 || Train3==21 || Train4==21)
           && !(Train2==31 || Train3==31 || Train4==31)){
            Data5=2;
            Send1=11;   // 1号車  //21_ON
         Train1TimeSetFlag1=1;
          }
          
       
       
  
 
 //===================Main>>Sub==============================
    if(Train1==21 && (Train2==22 || Train3==22 || Train4==22 )){//4
        Train1Flag1=0;
        Train1TimeSetFlag1=0;
        Send1=0;   // 1号車、消灯　停止//タイマーなし
       //SubSetTime21 = nowTime + random(3000,10000);  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
    }
    if(Train1 == 21 && !(Train2==22 || Train3==22 || Train4==22 )){ //Sub>>>Sub//1//T1
      
    Send1=5; // 1号車、前照灯、通常走行
        Train1Flag1=0;
        Train1TimeSetFlag1=0;
    }
   //--------------1>>0---------------------------------------
      if(Train1==31 && (Train2==32 || Train3==32 || Train4==32 )){//4
      Train1Flag1=0;
      Train1TimeSetFlag1=0;
      Send1=0;   // 1号車、消灯　停止//タイマーなし
       //MainSetTime31 = nowTime + random(3000,10000);  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
      } 
      
      if(Train1 == 31 && !(Train2==32 || Train3==32 || Train4==32 )){ //Sub>>>Sub//1//T1
      Send1=5; // 1号車、前照灯、通常走行
      Train1Flag1=0;
      Train1TimeSetFlag1=0;
   }
 }
