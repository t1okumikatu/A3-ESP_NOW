//===========control_3=====================================================
   void control_3(){
    
    unsigned long nowTime = millis();                // 現在時刻セット
  // *** Start Contlor **********************************   
     //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
  // ** "21","31" Train3 ###########################################
 //==================1-0=========================================
  
   if(Train3==21 && (Train1==22 || Train2==22 || Train4==22)){//1
      Train3Flag3=0;
      Train3TimeSetFlag3=0;
      Send3=0;   // 1号車、消灯　停止
      //SubSetTime21= nowTime + random(5000,15000); // 経過時間+セット時間
      //Train3TimeSetFlag3=0;//22^1
     };
 if(Train3 == 21 &&  !(Train1==22 || Train2==22 || Train4==22)){
      Train3Flag3=0;
      Train3TimeSetFlag3=0;
      Send3=16;//20ok-19ok-18ok-17ok-16ok-15,16nG
      //Train3TimeSetFlag3=0;
   };
 
  //------------------1-0---------------------------------------
 
    
     if(Train3==31 && (Train1==32 || Train2==32 || Train4==32)){//1
      Train3Flag3=0;
      Train3TimeSetFlag3=0;
      Send3=0; // 1号車、消灯　停止
      //MainSetTime31 = nowTime + 10000;  // 経過時間+セット時間
     // Train3TimeSetFlag3 = 0;
    }
    if(Train3 == 31 && !(Train1==32 || Train2==32 || Train4==32)){//1 Main>>Main
     Train3Flag3=0;
     Train3TimeSetFlag3=0;
     Send3=16; // 1号車、前照灯    通常走行
     //Train3TimeSetFlag3 = 0;
    };
       
   // ** "22","32" Train3 ###########################################
    //==================0-1=========================================
    /*
   if(Train3==22 ){
   if(Train3==22 && Train3TimeSetFlag3==0 ){//1
      Send3=0;   // 1号車、消灯　停止
      SubSetTime22= nowTime + random(5000,15000); // 経過時間+セット時間
      Train3TimeSetFlag3=1;//22^1
    };
  if(nowTime > (SubSetTime22+Time22) && Train3 == 22 &&  Train3TimeSetFlag3==1 ){
      Data6=1;
      Data7=1;
      Send3=20;//20ok-19ok-18ok-17ok-16ok-15,16nG
      Train3TimeSetFlag3=1;
   };
   }; 
  //------------------0-1---------------------------------------
 
     if(Train3==32 ){
     if(Train3==32 && Train3TimeSetFlag3==0 ){//1
      Send3=0; // 1号車、消灯　停止
      MainSetTime32 = nowTime + 10000;  // 経過時間+セット時間
      Train3TimeSetFlag3 = 1;
    }
     if(nowTime > (MainSetTime32+Time32) && Train3 == 32 && Train3TimeSetFlag3==1 ){//1 Main>>Main
      Data6=2;
      Data7=2;    
      Send3=20; // 1号車、前照灯    通常走行
      Train3TimeSetFlag3 = 1;
       };
       }
      */ 
     //==========="3"====0-1================================== 
      if(Train3==3 && (Train1==4 || Train2==4 || Train4==4)){//4
            Send3=0;
           }
      if(Train3==3 && !(Train1==4 || Train2==4 || Train4==4)){
           Send3=22;
        }  
         
     //=========="4"==1-0=====================================
      if(Train3==4 && (Train1==5 || Train2==5 || Train4==5)){//4
            Send3=0;
    }
      if(Train3 == 4 && !(Train1==5 || Train2==5 || Train4==5 )){ //Sub>>>Sub//1//T1     
     Send3=22; // 1号車、前照灯、通常走行
   }  
     //=========="5"==0-1=====================================
      if(Train3==5 && (Train1==6 || Train2==6 || Train4==6)){//4
            Send3=0;
           //SubSetTime5 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train3TimeSetFlag3=1;
    }
      if(Train3 == 5 && !(Train1==6 || Train2==6 || Train4==6 )){ //Sub>>>Sub//1//T1
       
     Send3=22; // 1号車、前照灯、通常走行
   // Train3TimeSetFlag3=1;
   }  
          //=========="6"==1-0=====================================
      if(Train3==6 && (Train1==7 || Train2==7 || Train4==7)){//4
            Send3=0;
          // SubSetTime6 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train3TimeSetFlag3=0;
    }
      if(Train3 == 6 && !(Train1==7 || Train2==7 || Train4==7 )){ //Sub>>>Sub//1//T1
       
     Send3=22; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=0;
   }  
         //=========="7"==0-1=====================================
      if(Train3==7 && (Train1==8 || Train2==8 || Train4==8)){//4
            Send3=0;
           //SubSetTime7 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train3TimeSetFlag3=1;
    }
      if(Train3 == 7 && !(Train1==8 || Train2==8 || Train4==8 )){ //Sub>>>Sub//1//T1
       
     Send3=22; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=1;
   }  
      //=========="8"==1-0=====================================
      if(Train3==8 && (Train1==9 || Train2==9 || Train4==9)){//4
            Send3=0;
          // SubSetTime8 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train3TimeSetFlag3=0;
    }
      if(Train3 == 8 && !(Train1==9 || Train2==9 || Train4==9 )){ //Sub>>>Sub//1//T1
       
     Send3=22; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=0;
   }  
    //=========="9"==0-1=====================================
      if(Train3==9 && (Train1==10 || Train2==10 || Train4==10)){//4
            Send3=0;
          // SubSetTime9 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train3TimeSetFlag3=1;
    }
      if(Train3 == 9 && !(Train1==10 || Train2==10 || Train4==10 )){ //Sub>>>Sub//1//T1      
     Send3=22; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=1;
   }  
   //=========="10"==1-0=====================================
      if(Train3==10 && (Train1==11 || Train2==11 || Train4==11)){//4
            Send3=0;
           //SubSetTime10 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train3TimeSetFlag3=0;
    }
      if(Train3 == 10 && !(Train1==11 || Train2==11 || Train4==11 )){ //Sub>>>Sub//1//T1      
     Send3=22; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=0;
   }  
   //=========="11"==0-1=====================================
      if(Train3==11 && (Train1==12 || Train2==12 || Train4==12)){//4
            Send3=0;
           //SubSetTime11 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train3TimeSetFlag3=1;
    }
      if(Train3 == 11 && !(Train1==12 || Train2==12 || Train4==12 )){ //Sub>>>Sub//1//T1     
     Send3=22; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=1;
   }     
       //=========="12"==1-0=====================================
      if(Train3==12 && (Train1==13 || Train2==13 || Train4==13)){//4
            Send3=0;
           //SubSetTime12 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train3TimeSetFlag3=0;
    }
      if(Train3 == 12 
      && !(Train1==13 || Train2==13 || Train4==13 )){ //Sub>>>Sub//1//T1      
     Send3=18; // 1号車、前照灯、通常走行
   // Train3TimeSetFlag3=0;
   }     

  //======"13"====0-1=====一旦停止=====Train3===================      
       if(Train3==13 && Train3Flag3==0){//3
         Send3=0;   // 1号車、消灯　停止//ターマーなし
         SubSetTime13= nowTime + random(10000,13000);
         Train3Flag3=1;
          }
   if(nowTime > SubSetTime13 && Train3 == 13 &&  Train3Flag3==1 ){
          Send3=17;   // 1号車、消灯　停止//ターマーなし
          Train3Flag3=1;
          Train3TimeSetFlag3=1;
          }
    //======"13"====0-1=====一旦停止=====Train3===================      
      if(Train3==13 &&  Train3TimeSetFlag3==1 && (Train1==21 || Train2==21 || Train4==21) 
          && (Train1==31 || Train2==31 || Train4==31)){//4
          Send3=0;              //21&&31_ON
          Train3TimeSetFlag3=1; 
         }
       if(Train3==13 && Train3TimeSetFlag3==1 && !(Train1==21 || Train2==21 || Train4==21)
          && !(Train1==31 || Train2==31 || Train4==31)){
            Send3=17;   // 3号車 //21_off &&31_off
            Data5=1;           
         Train3TimeSetFlag3=1;
          }
         if(Train3==13 && Train3TimeSetFlag3==1 && !(Train1==21 || Train2==21 || Train4==21)
            && (Train1==31 || Train2==31 || Train4==31)){
            Data5=1;
            Send3=17;   // 2号車  //31_ON
         Train3TimeSetFlag3=1;
          }
         if(Train3==13 && Train3TimeSetFlag3==1 && (Train1==21 || Train2==21 || Train4==21)
            && !(Train1==31 || Train2==31 || Train4==31)){
            Data5=2;
            Send3=17;   // 2号車  //21_ON
         Train3TimeSetFlag3=1;
          }      
          
 
   }   
    
