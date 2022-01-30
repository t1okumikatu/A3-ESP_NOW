//===========control_2=====================================================
void control_2(){
       // *** Start Contlor **********************************
     //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
   unsigned long nowTime = millis();
   // ** "22","32" Train2 ###########################################
   //===========Train2==start==0-1=========================================
  
   /*
    if(Train2==22){
       if(Train2==22 && Train2TimeSetFlag2==0 ){ //1
       
        
      Send2=0;
      SubSetTime22 = nowTime + random(5000,15000);  // 経過時間+セット時間//T1
      Train2TimeSetFlag2=1;
   }
  
   if(nowTime > (SubSetTime22+Time22) && Train2 == 22 && Train2TimeSetFlag2==1 ){ //Sub>>>Sub//1//T1
    Data6=1;
    Data7=1;
    Send2=22; // 2号車、前照灯、通常走行
    Train2TimeSetFlag2=1;
     
    //SubSetTime22=SubSetTime22-random(2000,6000);
   }
    }
  //---------------0>>1---------------------------------
   if( Train2==32){
     if(Train2==32 && Train2TimeSetFlag2==0 ){ //1
      Send2=0;
     // MainServoTime32Flag=0;
      MainSetTime32 = nowTime +random(5000,15000);  // 経過時間+セット時間//T2
      //MainServoTime32=MainSetTime32-5000;
      Train2TimeSetFlag2=1;
     // MainServoTime32Flag=1;
      }
     
     //  if(nowTime > MainServoTime32 && MainServoTime32Flag==1 && Train2==32 && !(Train1==3)){
        //Data6=2;
     //   MainServoTime32Flag=1;
     // }
     
      if(nowTime > (MainSetTime32+Time32) && Train2 == 32 &&  Train2TimeSetFlag2==1 ){
       Data6=2;
       Data7=2;
      Send2=02; // 2号車、前照灯、通常走行
      //Data6=2;
     
     //MainSetTime32=100;
      Train2TimeSetFlag2=1;
     
      //MainServoTime32Flag=0;
      }
     
   };
*/
//==========="3"====0-1================================== 

       if(Train2==3 && (Train1==4 || Train3==4 || Train4==4)){//4
            Send2=0;
           }
       if(Train2==3 && !(Train1==4 || Train3==4 || Train4==4)){
           Send2=25;
        }
        
 //=========="4"==1-0=====================================
      if(Train2==4 && (Train1==5 || Train3==5 || Train4==5)){//4
            Send2=0;
    }
      if(Train2 == 4 && !(Train1==5 || Train3==5 || Train4==5 )){ //Sub>>>Sub//1//T1    
     Send2=24; // 1号車、前照灯、通常走行
   }  
    
//=========="5"==0-1=====================================
      if(Train2==5 && (Train1==6 || Train3==6 || Train4==6)){//4
            Send2=0;
          // SubSetTime5 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train2TimeSetFlag2=1;
    }
      if(Train2 == 5 && !(Train1==6 || Train3==6 || Train4==6 )){ //Sub>>>Sub//1//T1
       
     Send2=23; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=1;
   }  
       
//=========="6"==1-0=====================================
      if(Train2==6 && (Train1==7 || Train3==7 || Train4==7)){//4
            Send2=0;
          // SubSetTime6 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train2TimeSetFlag2=0;
    }
      if(Train2 == 6 && !(Train1==7 || Train3==7 || Train4==7 )){ //Sub>>>Sub//1//T1
       
     Send2=24; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=0;
   }  
      
//=========="7"==0-1=====================================
      if(Train2==7 && (Train1==8 || Train3==8 || Train4==8)){//4
            Send2=0;
           //SubSetTime7 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=1;
    }
      if(Train2 == 7 && !(Train1==8 || Train3==8 || Train4==8 )){ //Sub>>>Sub//1//T1
       
     Send2=24; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=1;
   } 
//=========="8"==1-0=====================================
      if(Train2==8 && (Train1==9 || Train3==9 || Train4==9)){//4
            Send2=0;
           //SubSetTime8 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=0;
    }
      if(Train2 == 8 && !(Train1==9 || Train3==9 || Train4==9 )){ //Sub>>>Sub//1//T1
       
     Send2=24; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=0;
   }    
//=========="9"==0-1=====================================
      if(Train2==9 && (Train1==10 || Train3==10 || Train4==10)){//4
            Send2=0;
           //SubSetTime9 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=1;
    }
      if(Train2 == 9 && !(Train1==10 || Train3==10 || Train4==10 )){ //Sub>>>Sub//1//T1
       
     Send2=24; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=1;
   }         
//=========="10"==1-0=====================================
      if(Train2==10 && (Train1==11 || Train3==11 || Train4==11)){//4
            Send2=0;
           //SubSetTime10 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=0;
    }
      if(Train2 == 10 && !(Train1==11 || Train3==11 || Train4==11 )){ //Sub>>>Sub//1//T1
       
     Send2=24; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=0;
   }      
//=========="11"==0-1=====================================
      if(Train2==11 && (Train1==12 || Train3==12 || Train4==12)){//4
            Send2=0;
           //SubSetTime11 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=1;
    }
      if(Train2 == 11 && !(Train1==12 || Train3==12 || Train4==12 )){ //Sub>>>Sub//1//T1
       
     Send2=23; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=1;
   }           
   //=========="12"==1-0=====================================
         if(Train2==12 && (Train1==13 || Train3==13 || Train4==13)){//4
            Send2=0;
           //MainSetTime12 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=0;
    }
      if(Train2 == 12 
      && !(Train1==13 || Train3==13 || Train4==13 )){ //Sub>>>Sub//1//T1
    Send2=18; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=0;
   }     
  
 
   //======"13"====0-1=====一旦停止========================
         if(Train2==13 && Train2Flag2==0){//3
         Send2=0;   // 1号車、消灯　停止//ターマーなし
         SubSetTime13= nowTime + random(10000,13000);
         Train2Flag2=1;
          }
   if(nowTime > SubSetTime13 && Train2 == 13 &&  Train2Flag2==1 ){
         Train2Flag2=1;
         Train2TimeSetFlag2=1;
          }
      //===Train2=========13 一旦停止=============            
       if(Train2==13 &&  Train2TimeSetFlag2==1 && (Train1==21 || Train3==21 || Train4==21) 
          && (Train1==31 || Train3==31 || Train4==31)){//4
          Send2=0;              //21&&31_ON
          Train2TimeSetFlag2=1; 
         }
       if(Train2==13 && Train2TimeSetFlag2==1 && !(Train1==21 || Train3==21 || Train4==21)
          && !(Train1==31 || Train3==31 || Train4==31)){
            Send2=20;   // 2号車 //21_off &&31_off
            Data5=1;           
         Train2TimeSetFlag2=1;
          }
         if(Train2==13 && Train2TimeSetFlag2==1 && !(Train1==21 || Train3==21 || Train4==21)
           && (Train1==31 || Train3==31 || Train4==31)){
            Data5=1;
            Send2=15;   // 2号車  //31_ON
         Train2TimeSetFlag2=1;
          }
         if(Train2==13 && Train2TimeSetFlag2==1 && (Train1==21 || Train3==21 || Train4==21)
            && !(Train1==31 || Train3==31 || Train4==31)){
            Data5=2;
            Send2=15;   // 2号車  //21_ON
         Train2TimeSetFlag2=1;
          }
                   
     
      
      
     
  
   
    
 
     //==1-0=======Train2=="21"===1-0===================Main>>>Sub
     if(Train2==21 && (Train1==22 || Train3==22 || Train4==22 )){//4
      Send2=0;   // 2号車、
        Train2Flag2=0;
        Train2TimeSetFlag2=0;
       //SubSetTime21 = nowTime +  20000;  // 経過時間+セット時間//T1
     // Train2TimeSetFlag2=0;
      }

    if(Train2 == 21 && !(Train1==22 || Train3==22 || Train4==22 )){ //Sub>>>Sub//1//T1
    Send2=18; // 1号車、前照灯、通常走行
        Train2Flag2=0;
        Train2TimeSetFlag2=0;
   }
  
   //=========Train2 pattern2========================Main>>>Sub

 //-------------------1>>0--------------------------------------------
     if(Train2==31 && (Train1==32 || Train3==32 || Train4==32 )){//4
      Send2=0;   // 2号車、
       Train2Flag2=0;
       Train2TimeSetFlag2=0;
       //MainSetTime31 = nowTime + random(3000,10000);  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=0;
      } 
      
    if(Train2 == 31 && !(Train1==32 || Train3==32 || Train4==32 )){ //Sub>>>Sub//1//T1
    Send2=18; // 2号車、
        Train2Flag2=0;
        Train2TimeSetFlag2=0;
     }
}
