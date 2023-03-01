#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <Servo.h>
#include "deklarasi.h"
#include "us.h"

// Insert your network credentials
// Provide the token generation process info.
// #include "addons/TokenHelper.h"
// // Provide the RTDB payload printing info and other helper functions.
// #include "addons/RTDBHelper.h"
#define WIFI_SSID "R1 - 610"
#define WIFI_PASSWORD "Gian0506"

#define FIREBASE_HOST "https://glori01-default-rtdb.asia-southeast1.firebasedatabase.app" //https://jarak-monitoring-default-rtdb.asia-southeast1.firebasedatabase.app https://monitoring-jarak-1a92c-default-rtdb.firebaseio.com/
#define FIREBASE_AUTH "KJGa3VVruEd2UHb2ztLbB1IT1eJFiswlc4GTax8J" //mBFExemhJCahhAlFtAGEBnx8JDG5Vjr7WxqamTLI 72qQBsZ9UYhAjfJzfbdKm9AR7j0DwIIyXtnmyH3h

FirebaseData firebaseData;

// Insert Firebase project API Key
// #define API_KEY "AIzaSyC3giUatUfysWDnShWK9b4pgwo5OOj_sSU"

// // Insert Authorized Email and Corresponding Password
// #define DATABASE_URL "https://console.firebase.google.com/u/0/project/jarak-monitoring/database/jarak-monitoring-default-rtdb/data/~2F"
// #define USER_EMAIL "exelindoyeremia03@gmail.com"
// #define USER_PASSWORD "Eteng12!"
// #define USER_PASSWORD "your_user_password"

// // Define Firebase objects
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// // Variable to save USER UID
// String uid;
// unsigned long sendDataPrevMillis = 0;
// int count = 0;
// bool signupOK = false;

// Initialize WiFi

void setup() {
  Serial.begin(115200);
  wifi();
  deklarasi();
}

void wifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // /* Assign the api key (required) */
  // config.api_key = API_KEY;

  // /* Assign the RTDB URL (required) */
  // config.database_url = DATABASE_URL;

  // /* Sign up */
  // if (Firebase.signUp(&config, &auth, "", "")) {
  //   Serial.println("ok");
  //   signupOK = true;
  // } else {
  //   Serial.printf("%s\n", config.signer.signupError.message.c_str());
  // }

  // /* Assign the callback function for the long running token generation task */
  // config.token_status_callback = tokenStatusCallback;  //see addons/TokenHelper.h

  // Firebase.begin(&config, &auth);
  // Firebase.reconnectWiFi(true);
}

void loop() {
  sensors();
  palang();
  // Firebase.setInt("Distance 1", d);
  if (Firebase.setFloat(firebaseData, "/US/Distance_1", d)) {
    Serial.println("distance 1 terkirim");
  } else {
    Serial.println("distance 1 terkirim");
    Serial.println("Karena: " + firebaseData.errorReason());
  }

  if (Firebase.setFloat(firebaseData, "/US/Distance_2", e)) {
    Serial.println("distance 2 terkirim");
    Serial.println();
  } else {
    Serial.println("distance 2 tidak terkirim");
    Serial.println("Karena: " + firebaseData.errorReason());
  }

  if (Firebase.setFloat(firebaseData, "/US/Distance_3", k)) {
    Serial.println("distance 3 terkirim");
    Serial.println();
  } else {
    Serial.println("distance 3 tidak terkirim");
    Serial.println("Karena: " + firebaseData.errorReason());
  }
  // delay (1000);
  // if (Firebase.ready() && signupOK) {

  //   if (Firebase.RTDB.setFloat(&fbdo, "US/Distance_1", distance)) {
  //     //      Serial.println("PASSED");
  //     Serial.print("Distance 1: ");
  //     Serial.println(distance);

  //   } else {
  //     Serial.println("FAILED");
  //     Serial.println("REASON: " + fbdo.errorReason());
  //   }


  //   // Write an Float number on the database path test/float
  //   if (Firebase.RTDB.setFloat(&fbdo, "US/Distance_2", distance_1)) {
  //     //      Serial.println("PASSED");
  //     Serial.print("Distance 2: ");
  //     Serial.println(distance_1);
  //   } else {
  //     Serial.println("FAILED");
  //     Serial.println("REASON: " + fbdo.errorReason());
  //   }
  // }
  // Serial.println("______________________________");
}