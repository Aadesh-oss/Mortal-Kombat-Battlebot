
void GrinderON(){
  digitalWrite(Grinder, LOW); 
}


void GrinderOFF(){
  digitalWrite(Grinder, HIGH); 
}


void stopR(){
  digitalWrite(A, HIGH); 
digitalWrite(B, HIGH); 

}
void stopL(){
 
digitalWrite(C, HIGH); 
digitalWrite(D, HIGH); 
  }

  void upR(){
  digitalWrite(A, HIGH); 
digitalWrite(B, LOW); 

  }
    void upL(){
 
digitalWrite(C, LOW); 
digitalWrite(D, HIGH); 
  }

  void downR(){
  digitalWrite(A, LOW); 
digitalWrite(B, HIGH); 

  }
   void downL(){

digitalWrite(C, HIGH); 
digitalWrite(D, LOW); 
  }
void forward(){
//  digitalWrite(C, HIGH); 
//digitalWrite(D, LOW); 

digitalWrite(A, HIGH); 
digitalWrite(B, LOW); 
  }

