void emergency(){
   if(digitalRead(StartSW) ==0){
    while(1){
      if(restart==1){
        break;   
      }
    
    Send1=0;
    Send2=0;
    Send3=0;
    Send4=0;
   test_struct test;
 // test.Send5 = Send5;
  test.x = ctr;
  //Serial.println(test.Send);
   // Serial.print("Speed ==  ");
  test.One = Send1;//1号車　速度
 // Serial.print(test.One);
  test.Two = Send2;//2号車　速度
 // Serial.println(test.Two);
  test.Three = Send3;//3号車　速度
  //Serial.print(test3.Three);
  test.Four = Send4;//4号車　速度
  //Serial.println(test3.Four);
  //test.Five = Send5;//5号車　速度
  //Serial.println(test3.Four);
  
  //==========================
 // Serial.print("Poji1234==");
  test.first = Data1;//1号車 poji
  test.second = Data2;//2号車poji
  test.third = Data3;//3号車poji
  test.fourth = Data4;//4号車poji
 // Serial.print(test.first);
 // Serial.println(test.second);
  //Serial.print(test3.third);
  //Serial.println(test3.fourth);
  //==============
  //Serial.print("SIn-SOut==");
  test.SIn = Data5;//入口
  test.SOut = Data6;//出口
 test.SubLed = Data7;
 test.MainLed =Data7;
 
    //===Send1=======================
  test_struct test2;
  test2.Send1 = Send1;
  test2.y = ctr;
  //Serial.println(test2.Send);
  //=====Send2====================-
   test_struct test3;
  test3.Send2 = Send2;
  test3.z = ctr;
  //=====Send3=================
    test_struct test4;
  test4.Send3 = Send3;
  test4.v = ctr;
  //=====Send4=================
    test_struct test5;
  test5.Send4 = Send4;
  test5.w = ctr;
  //======================
   //===========result1===Train5========
    esp_err_t result1 = esp_now_send(
    broadcastAddress1, 
    (uint8_t *) &test,
    sizeof(test_struct));
   
  if (result1 == ESP_OK) {
    //Serial.println("Sent5 success");
  }
  else {
   // Serial.println("Sent5_Error sending the data");
  }
  delay(1);
  //===========result2===Train1========
  
  esp_err_t result2 = esp_now_send(
    broadcastAddress2, 
    (uint8_t *) &test2,
    sizeof(test_struct));

  if (result2 == ESP_OK) {
   //Serial.println("Send1 success");
  }
  else {
   // Serial.println("Send1_Error sending the data");
  }
  
   //===========result3===Train2========
  
  esp_err_t result3 = esp_now_send(
    broadcastAddress3, 
    (uint8_t *) &test3,
    sizeof(test_struct));

  if (result3 == ESP_OK) {
  // Serial.println("Send2 success");
  }
  else {
   // Serial.println("Send2_Error sending the data");
  }
   //===========result4===Train3========
  esp_err_t result4 = esp_now_send(
    broadcastAddress4, 
    (uint8_t *) &test4,
    sizeof(test_struct));

  if (result4 == ESP_OK) {
  // Serial.println("Send2 success");
  }
  else {
   // Serial.println("Send2_Error sending the data");
  }
     //===========result5===Train4========
  esp_err_t result5 = esp_now_send(
    broadcastAddress5, 
    (uint8_t *) &test5,
    sizeof(test_struct));

  if (result5 == ESP_OK) {
  // Serial.println("Send2 success");
  }
  else {
   // Serial.println("Send2_Error sending the data");
  }
  
   delay(1);
}
   }

 }
 
