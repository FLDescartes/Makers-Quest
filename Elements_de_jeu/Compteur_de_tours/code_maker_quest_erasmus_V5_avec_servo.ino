#include <Servo.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Constantes pour les boutons
const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 10;

Servo servo;

// Constantes pour l'écran
const int screenWidth = 16;
const int screenHeight = 2;

// Tableau pour stocker les jours de la semaine sur 6 semaines
const char* weekDays[] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
                          "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
                          "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
                          "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
                          "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
                          "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi"};

// Variable pour stocker le nombre de joueurs
int numPlayers = 0;

// Variable pour stocker le jour de la semaine actuel
int currentDay = 0;

int  lastButton1State = 0;
int  lastButton2State = 0;
int  lastButton3State = 0;

int fin_de_partie = 0;
int semaine_1 = 0;
int semaine_2 = 0;
int semaine_3 = 0;
int semaine_4 = 0;
int semaine_5 = 0;
int a=0;


void setup() {
  Serial.begin (9600);
  // Initialiser les boutons en tant qu'entrées
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

  servo.attach(11);


  // Initialiser l'écran LCD
  lcd.begin(screenWidth, screenHeight);
  lcd.setCursor(2, 0);
  lcd.print("Maker's Quest");
 // lcd.print(screenHeight);
}

void loop() {

    servo.write(175);
  // Si le bouton 1 est enfoncé, incrémenter le nombre de joueurs
  // si et seulement si le bouton n'est pas déjà enfoncé
  if (digitalRead(button1Pin) == LOW && digitalRead(button1Pin) != lastButton1State) {
    numPlayers++;
    fin_de_partie = 0;
    semaine_1 = -1;
    semaine_2 = -2;
    semaine_3 = -3;
    semaine_4 = -4;
    semaine_5 = -5;
    a=0;
    
    if (numPlayers > 5) {
      numPlayers = 1;
    }
    lcd.clear();
    lcd.print("Nb joueurs : ");
    lcd.print(numPlayers);
    // Ajouter un petit délai pour empêcher l'effet rebond
    delay(250);
  }
///////////////////////////////////////////////////////////////////////////////////////////
  

  // Si le bouton 2 est enfoncé, changer le jour de la semaine et afficher le joueur actuel
  if (digitalRead(button2Pin) == LOW && digitalRead(button2Pin) != lastButton2State) {

Serial.println (semaine_1);

   if (a==0){ 
    
cycle_jeu ();
    week_1 ();
    week_2 ();
    week_3 ();
    week_4 ();
    week_5 ();
fin_partie ();
   }

        // Enregistrer l'état actuel des boutons pour la prochaine itération
  lastButton1State = digitalRead(button1Pin);
  lastButton2State = digitalRead(button2Pin);
  lastButton3State = digitalRead(button3Pin);

  }

  if (digitalRead(button3Pin) == LOW && digitalRead(button3Pin) != lastButton3State) { 

  //  servo.write(0); 
  //   delay(1000); 

   servo.write(70); 
   delay(2000); 

       servo.write(175); 
     //delay(1000);

    }

}

 void cycle_jeu (){   
    if (currentDay > 29) {   // 29 est le nombres de jours pour 6 semaines +1 pour partie terminée.
      currentDay = -1;
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Joueur ");
    lcd.print((currentDay % numPlayers) + 1);
    lcd.print(" : ");
    lcd.setCursor(0, 1);
    lcd.print(weekDays[currentDay]);
    currentDay++; 
        fin_de_partie++;
    semaine_1 ++;
    semaine_2 ++;
    semaine_3 ++;
    semaine_4 ++;
    semaine_5 ++; 
//  Serial.println (semaine_1);   
    // Ajouter un petit délai pour empêcher l'effet rebond
    delay(150);
 }

   void fin_partie (){
    if (semaine_5 >= 31) {   
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("Partie");
      lcd.setCursor(4, 1);
      lcd.print("Terminee");
      Serial.print ("Partie Terminee");
       a=1;
    semaine_1 = -1;
    semaine_2 = -2;
    semaine_3 = -3;
    semaine_4 = -4;
    semaine_5 = -5;
    numPlayers = 0;
    }
   }

   void week_1 (){

        if (semaine_1 == 5) { 
              currentDay =currentDay -1;
              fin_de_partie = fin_de_partie -1;
                
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print(" Week-end");
      lcd.setCursor(3, 1);
      lcd.print("semaine 1");
      Serial.println ("semaine_1");
    }
   }

      void week_2 (){

          if (semaine_2 == 10) {  
              currentDay =currentDay -1;
              fin_de_partie = fin_de_partie -1;
              
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print(" Week-end");
      lcd.setCursor(3, 1);
      lcd.print("semaine 2");
      Serial.println ("semaine_2");      
    }
      }

         void week_3 (){
          
         
          if (semaine_3 == 15) {  
              currentDay =currentDay -1;
              fin_de_partie = fin_de_partie -1;
              
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print(" Week-end");
      lcd.setCursor(3, 1);
      lcd.print("semaine 3");
      Serial.println ("semaine_3");      
    }
  }

     void week_4 (){

          if (semaine_4 == 20) {  
             currentDay =currentDay -1;
              fin_de_partie = fin_de_partie -1;
              
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print(" Week-end");
      lcd.setCursor(3, 1);
      lcd.print("semaine 4");
      Serial.println ("semaine_4");      
    }
     }

        void week_5 (){

          if (semaine_5 == 25) {  
              currentDay =currentDay -1;
              fin_de_partie = fin_de_partie -1;
              
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print(" Week-end");
      lcd.setCursor(3, 1);
      lcd.print("semaine 5");
      Serial.println ("semaine_5");      
    }
        }
    
  
