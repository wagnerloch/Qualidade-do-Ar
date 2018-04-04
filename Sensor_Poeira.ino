/**
   connect the sensor as follows :
          Pin 2 of dust sensor PM1.0      -> Digital 3
    Pin 3 of dust sensor          -> +5V 
    Pin 4 of dust sensor PM2.5    -> Digital 4
    Pin 5 of dust sensor          -> Ground
  Datasheet: http://www.samyoungsnc.com/products/3-1%20Specification%20DSM501.pdf
*/
#include<DSM501.h>
#include<SPI.h>
#include<SD.h>

File arquivo;

#define DSM501_PM10 2
#define DSM501_PM25 3
#define LEDVERDE 9
#define LEDVERMELHO 8

DSM501 dsm501(DSM501_PM10, DSM501_PM25);

void setup()
{
  Serial.begin(115200); //for output information
  while (!Serial) {
    ;
  }
  pinMode (LEDVERDE, OUTPUT);
  pinMode (LEDVERMELHO, OUTPUT);
  Serial.println("Inicializando Cartão SD...");
  if (!SD.begin(10)) {
    Serial.println("Falha na inicialização do Cartão SD!");
    digitalWrite (LEDVERMELHO, HIGH);
    exit(0);
  }
  Serial.println("Cartão SD inicializado com sucesso!");
  Serial.println("Criando arquivo para os dados...");
  arquivo = SD.open("dados.txt", FILE_WRITE);
  if (!arquivo) {
    Serial.println("Erro ao criar/abrir arquivo dados.txt");
    digitalWrite (LEDVERMELHO, HIGH);
    exit(0);
  }
  
  // Initialize DSM501
  Serial.print("Inicializando Sensores...");
  dsm501.begin(MIN_WIN_SPAN);

  // wait 60s for DSM501 to warm up
  for (int i = 1; i <= 60; i++)
  {
    digitalWrite (LEDVERDE, HIGH);
    delay(500); // 1s
    Serial.print(i);
    Serial.println(" s (aguarde 60s para o DSM501 ser configurado)");
    digitalWrite (LEDVERDE, LOW);
    delay(500);
  }
  Serial.print("PM10;");
  Serial.print("PM10~25;");
  Serial.print("PM25;");
  Serial.println("AQI");
  arquivo.close();
}

void loop()
{
  digitalWrite (LEDVERDE, HIGH);
  arquivo = SD.open("dados.txt", FILE_WRITE);
  if (!arquivo) {
    Serial.println("Erro ao criar/abrir arquivo dados.txt");
    digitalWrite (LEDVERMELHO, HIGH);
    exit(0);
  }
  // call dsm501 to handle updates.
  digitalWrite (LEDVERMELHO, LOW);
  dsm501.update();
  digitalWrite (LEDVERMELHO, HIGH);

  //PM10
  Serial.print(dsm501.getParticalWeight(0));
  Serial.print(";");
  arquivo.print(dsm501.getParticalWeight(0));
  arquivo.print(";");
  //PM10~25
  Serial.print(dsm501.getPM25());
  Serial.print(";");
  arquivo.print(dsm501.getPM25());
  arquivo.print(";");
  //PM25
  Serial.print(dsm501.getParticalWeight(1));
  Serial.print(";");
  arquivo.print(dsm501.getParticalWeight(1));
  arquivo.print(";");
  //AQI
  Serial.println(dsm501.getAQI());
  arquivo.println(dsm501.getAQI());
  arquivo.close();
}

