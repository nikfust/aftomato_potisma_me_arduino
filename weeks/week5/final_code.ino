//**************************************************
//* Περιβαλλοντική Ομάδα 5ου Γυμνασίου Πτολεμαΐδας *
//* ---------------------------------------------- *
//* Week5:Ολοκλήρωση κατασκευής - σύνδεση και προ- *
//* γραμματισμός - είσοδος από αισθητήρα υγρασίας  *
//* - έξοδος στο ρελέ που ενεργοποιεί την ηλεκτρο- *
//* βάνα ποτίσματος                                *
//**************************************************
#define RELAY 8             // Συνδέουμε το RELAY στο pin 8
const int hygrometer = A0;  // Σταθερά με όνομα hygrometer όπου αντιστοιχίζεται με την
              // αναλογική είσοδο Α0 όπου συνδέουμε τον αισθητήρα εδάφους 
int value;    // Μεταβλητή που δέχεται τιμές από τον αισθητήρα
              // από 0 (μέγιστη υγρασία) μέχρι 1023 (ελάχιστη υγρασία)
              // Ο κατασκευαστής προτείνει τιμή 380 - 400 για την παρουσία
              // σωστής υγρασίας για τα περισσότερα φυτά

// Κώδικας αρχικοποίησης 
void setup() 
{  
  pinMode(RELAY, OUTPUT);   // Ορίζουμε το pin8 ως έξοδο (όπου συνδέσαμε το ρελέ)
  Serial.begin(9600);       // Ορίζουμε τον ρυθμό ανανέσωσης της σειριακής εισόδου στα 9600 bps
  digitalWrite(RELAY, HIGH); // Αρχικά ανοίγουμε τον διακόπτη (ρελέ)
}

// Κώδικας που επαναλαμβάνεται συνέχεια
void loop() 
{
  value = analogRead(hygrometer);    // Ανάγνωση από τον αισθητήρα υγρασίας
  Serial.print("Timi Ygrasias: ");    
  Serial.print(value);   // εμφάνιση της τιμής στην παρακολούθηση σειριακής του Arduino IDE
  Serial.println();      // αλλαγή γραμμής

   if (value<400)       // Αν η τιμή υγρασίας είναι κάτω από 400, αυτό 
                        // σημαίνει ότι υπάρχει ικανοποιητική υγρασία
   {
      digitalWrite(RELAY, HIGH);      // Ο διακόπτης στο ON (ποτίζουμε)
   }
   else
   {
      digitalWrite(RELAY, LOW);       // αλλιώς ο διακόπτης στο OFF (σταματάμε το πότισμα)
   }
   delay(5000);                       // Ορίζουμε καθυστέρηση 5 δευτ. Μετά επαναλαμβάνεται η όλη διαδικασία
}
