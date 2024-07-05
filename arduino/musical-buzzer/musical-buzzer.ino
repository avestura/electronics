#define BUZZER_PIN 9

int noteToFrequency(char note)
{
  switch (note)
  {
  case 'c': return 262;
  case 'd': return 294;
  case 'e': return 330;
  case 'f': return 349;
  case 'g': return 392;
  case 'a': return 440;
  case 'b': return 494;
  case 'C': return 523;
  default:
    break;
  }
  return 0;
}

void playSong(String song, int beats[], int tempo) {
  for (int i = 0; i < notes.length(); i++)
  {
    int duration = beats[i] * tempo;
    if (notes[i] == ' ')
    {
      delay(duration);
    }
    else
    {
      tone(BUZZER_PIN, noteToFrequency(notes[i]), duration);
      delay(duration);
    }

    delay(tempo / 10);
  }
}

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
}


String notes = "cdfda ag cdfdg gf ";
int beats[] = {1, 1, 1, 1, 1, 1, 4, 4, 2, 1, 1, 1, 1, 1, 1, 4, 4, 2};
int tempo = 150;

void loop()
{
  playSong(notes, beats, tempo);
}

