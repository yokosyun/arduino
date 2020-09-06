#include <GNSS.h>
#include <SDHCI.h>

#define STRING_BUFFER_SIZE  128

#define RESTART_CYCLE       (60 * 5)

static SpGnss Gnss;
SDClass SD;
File myFile;

static void Led_isActive(void)
{
  static int state = 1;
  if (state == 1)
  {
    ledOn(PIN_LED0);
    state = 0;
  }
  else
  {
    ledOff(PIN_LED0);
    state = 1;
  }
}

static void Led_isPosfix(bool state)
{
  if (state)
  {
    ledOn(PIN_LED1);
  }
  else
  {
    ledOff(PIN_LED1);
  }
}

static void GNSS_isError(bool state)
{
  if (state)
  {
    ledOn(PIN_LED3);
  }
  else
  {
    ledOff(PIN_LED3);
  }
}

static void SD_isError(bool state)
{
  if (state)
  {
    ledOn(PIN_LED2);
  }
  else
  {
    ledOff(PIN_LED2);
  }
}

void setup() {

  int error_flag = 0;
  int sd_error_flag = 0;

  sleep(3);

  myFile = SD.open("posData.txt", FILE_WRITE);

  if (!myFile)
  {
    SD_isError(true);
    myFile.close();
    exit(0);
  }

  ledOn(PIN_LED0);
  ledOn(PIN_LED1);
  ledOn(PIN_LED2);
  ledOn(PIN_LED3);

  Gnss.setDebugMode(PrintInfo);

  int result;

  result = Gnss.begin();

  if (result != 0)
  {
    myFile.println("Gnss begin error!!");
    error_flag = 1;
  }
  else
  {
    result = Gnss.start(COLD_START);
    if (result != 0)
    {
      myFile.println("Gnss start error!!");
      error_flag = 1;
    }
    else
    {
      myFile.println("Gnss setup OK");
    }
  }

  ledOff(PIN_LED0);
  ledOff(PIN_LED1);
  ledOff(PIN_LED2);
  ledOff(PIN_LED3);

  if (error_flag == 1)
  {
    GNSS_isError(true);
    myFile.close();
    exit(0);
  }
  myFile.close();
}

static void print_pos(SpNavData *pNavData)
{
  char StringBuffer[STRING_BUFFER_SIZE];

  snprintf(StringBuffer, STRING_BUFFER_SIZE, "%04d/%02d/%02d ", pNavData->time.year, pNavData->time.month, pNavData->time.day);
  myFile.print(StringBuffer);

  snprintf(StringBuffer, STRING_BUFFER_SIZE, "%02d:%02d:%02d.%06d, ", pNavData->time.hour, pNavData->time.minute, pNavData->time.sec, pNavData->time.usec);
  myFile.print(StringBuffer);

  snprintf(StringBuffer, STRING_BUFFER_SIZE, "numSat:%2d, ", pNavData->numSatellites);
  myFile.print(StringBuffer);

  if (pNavData->posDataExist == 0)
  {
    myFile.print("pos not fixed");
    ledOff(PIN_LED3);
  }
  else
  {
    myFile.print("Lat=");
    myFile.print(pNavData->latitude, 6);
    myFile.print(", Lon=");
    myFile.print(pNavData->longitude, 6);

    ledOn(PIN_LED0);
    ledOn(PIN_LED3);
  }

  myFile.println("");
}

static void print_condition(SpNavData *pNavData)
{
  char StringBuffer[STRING_BUFFER_SIZE];
  unsigned long cnt;

  snprintf(StringBuffer, STRING_BUFFER_SIZE, "numSatellites:%2d\n", pNavData->numSatellites);
  myFile.print(StringBuffer);

  for (cnt = 0; cnt < pNavData->numSatellites; cnt++)
  {
    const char *pType = "---";

    if ( pNavData->isSatelliteTypeGps(cnt) )
    {
      pType = "GPS";
    }
    else if ( pNavData->isSatelliteTypeGlonass(cnt))
    {
      pType = "GLN";
    }

    unsigned long Id  = pNavData->getSatelliteId(cnt);
    unsigned long Elv = pNavData->getSatelliteElevation(cnt);
    unsigned long Azm = pNavData->getSatelliteAzimuth(cnt);
    float sigLevel = pNavData->getSatelliteSignalLevel(cnt);

    snprintf(StringBuffer, STRING_BUFFER_SIZE, "[%2d] Type:%s, Id:%2d, Elv:%2d, Azm:%3d, Lv:", cnt, pType, Id, Elv, Azm );
    myFile.print(StringBuffer);
    myFile.println(sigLevel, 6);
  }
}

void loop()
{
  static int LoopCount = 0;
  static int LastPrintMin = 0;

  Led_isActive();

  myFile = SD.open("posData.txt", FILE_WRITE);

  if (!myFile)
  {
    SD_isError(true);
    myFile.close();
    exit(0);
  }

  if (Gnss.waitUpdate(-1))
  {
    SpNavData NavData;
    Gnss.getNavData(&NavData);

    bool LedSet = (NavData.posDataExist && (NavData.posFixMode != FixInvalid));
    Led_isPosfix(LedSet);

    if (NavData.time.minute != LastPrintMin)
    {
      print_condition(&NavData);
      LastPrintMin = NavData.time.minute;
    }
    print_pos(&NavData);
  }
  else
  {
    myFile.println("data not update");
  }

  LoopCount++;
  if (LoopCount >= RESTART_CYCLE)
  {
    int error_flag = 0;

    ledOff(PIN_LED0);
    ledOff(PIN_LED3);

    Led_isPosfix(false);

    if (Gnss.stop() != 0)
    {
      myFile.println("Gnss stop error!!");
      error_flag = 1;
    }
    else if (Gnss.end() != 0)
    {
      myFile.println("Gnss end error!!");
      error_flag = 1;
    }
    else
    {
      myFile.println("Gnss stop OK.");
    }

    if (Gnss.begin() != 0)
    {
      myFile.println("Gnss begin error!!");
      error_flag = 1;
    }
    else if (Gnss.start(HOT_START) != 0)
    {
      myFile.println("Gnss start error!!");
      error_flag = 1;
    }
    else
    {
      myFile.println("Gnss restart OK.");
    }

    LoopCount = 0;

    if (error_flag == 1)
    {
      GNSS_isError(true);
      myFile.close();
      exit(0);
    }
  }
  myFile.close();
}
