#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef enum
{
  false,
  true
} bool;

typedef struct Gericht
{
  unsigned int id;
  char name[255];
  unsigned int energie;
  // Die folgenden sind boolean Werte
  bool vegan;
  bool vegetarisch;
  bool glutenfrei;
  bool allergenfrei;
  unsigned preisInCent;
} Gericht;

typedef struct Node
{
  struct Node *next;
  struct Node *prev;
  Gericht *gericht;
} Node;

int gerichtCounter = 0;

Gericht *erstelleGericht(char *name, unsigned energie, unsigned preisInCent, bool vegan, bool vegetarisch, bool glutenfrei, bool allergenfrei);
void fuegeEinInListe(Node *liste, Gericht *gericht);
void gebeListeAus(Node *liste);
Gericht *sucheGlutenfreiesGericht(Node *liste);

int main()
{
  // Initialisiere Liste
  Node *liste = malloc(sizeof(Node));
  // liste->gericht = NULL;

  Gericht *gericht = erstelleGericht("Schnitzel Wiener Art", 1800, 11000, false, false, false, false);
  fuegeEinInListe(liste, gericht);

  gericht = erstelleGericht("Cordon Bleu", 1500, 11000, false, false, false, false);
  fuegeEinInListe(liste, gericht);

  gericht = erstelleGericht("Salat 1", 500, 11000, false, false, true, false);
  fuegeEinInListe(liste, gericht);

  gericht = erstelleGericht("Salat 2", 500, 11000, false, false, true, false);
  fuegeEinInListe(liste, gericht);

  gericht = erstelleGericht("Pommes", 2200, 11000, false, false, false, false);
  fuegeEinInListe(liste, gericht);

  gericht = erstelleGericht("Süßkartoffelpommes", 2200, 11000, false, false, false, false);
  fuegeEinInListe(liste, gericht);

  gebeListeAus(liste);

  Gericht *glutenfreiesGericht = sucheGlutenfreiesGericht(liste);
  if (glutenfreiesGericht == NULL)
  {
    printf("Kein glutenfreies Gericht gefunden!\n");
  }
  else
  {
    printf("Glutenfreies Gericht: %s\n Id: %d\n Energie: %d\n Preis: %d\n\n", glutenfreiesGericht->name, glutenfreiesGericht->id, glutenfreiesGericht->energie, glutenfreiesGericht->preisInCent);
  }

  return 0;
}

Gericht *erstelleGericht(char *name, unsigned energie, unsigned preisInCent, bool vegan, bool vegetarisch, bool glutenfrei, bool allergenfrei)
{
  Gericht *gericht = NULL;
  gericht = malloc(sizeof(Gericht));

  gericht->id = gerichtCounter++;
  gericht->energie = energie;
  strcpy(gericht->name, name);
  gericht->preisInCent = preisInCent;
  gericht->vegan = vegan;
  gericht->vegetarisch = vegetarisch;
  gericht->glutenfrei = glutenfrei;
  gericht->allergenfrei = allergenfrei;

  return gericht;
}

void fuegeEinInListe(Node *liste, Gericht *gericht)
{
  if (liste->gericht == NULL && liste->next == NULL && liste->prev == NULL)
  {
    // Liste noch nicht initialisiert
    liste->gericht = gericht;
    return;
  }

  // Schau, ob das aktuelle Knotengericht kleiner oder größer als das einzufügende ist
  // - Wenn kleiner
  //  -> Wenn kein linker Knoten vorhanden ist, erstelle einen und füge Gericht ein
  //  -> Schau ob auch kleiner oder gleich linker Knotenpunkt
  //    - Ja -> Führe Funktion rekursiv für linken Punkt aus
  //    - Nein -> Füge neuen Knoten zwischen aktuellen und linken Knoten ein
  //  -> Analog das gleiche für rechts

  // TODO: DRY-Prinzip berücksichtigen
  if (gericht->energie < liste->gericht->energie)
  {
    // Kleiner -> Handling für links
    if (liste->prev == NULL)
    {
      // Erstelle linken Knoten und füge Gericht ein
      liste->prev = malloc(sizeof(Node));
      liste->prev->next = liste;
      liste->prev->gericht = gericht;
    }
    else if (gericht->energie <= liste->prev->gericht->energie)
    {
      // Gib an linken Knoten weiter
      fuegeEinInListe(liste->prev, gericht);
    }
    else
    {
      // Füge dazwischen ein
      Node *new = malloc(sizeof(Node));
      new->gericht = gericht;
      new->prev = liste->prev;
      new->next = liste;
      liste->prev->next = new;
      liste->prev = new;
    }
  }
  else if (gericht->energie > liste->gericht->energie)
  {
    // Größer -> Handling für rechts
    if (liste->next == NULL)
    {
      liste->next = malloc(sizeof(Node));
      liste->next->gericht = gericht;
      liste->next->prev = liste;
    }
    else if (gericht->energie >= liste->next->gericht->energie)
    {
      fuegeEinInListe(liste->next, gericht);
    }
    else
    {
      // Füge dazwischen ein
      Node *new = malloc(sizeof(Node));
      new->gericht = gericht;
      new->next = liste->next;
      new->prev = liste;
      liste->next->prev = new;
      liste->next = new;
    }
  }
  else
  {
    // Exakt gleich groß
    if (strcmp(liste->gericht->name, gericht->name) < 0)
    {
      // Füge rechts ein
      // Wenn rechtes Gericht ebenfalls gleich ist, gebe Handling an rechtes weiter
      if (liste->next != NULL && liste->next->gericht->energie == gericht->energie)
      {
        fuegeEinInListe(liste->next, gericht);
      }
      else
      {
        Node *new = malloc(sizeof(Node));
        new->gericht = gericht;
        new->next = liste->next;
        new->prev = liste;
        if (liste->next != NULL)
        {
          liste->next->prev = new;
        }
        liste->next = new;
      }
    }
    else
    {
      // Füge links ein
      // Wenn linkes Gericht ebenfalls gleich ist, gebe Handling an rechtes weiter
      // Füge rechts ein
      // Wenn rechtes Gericht ebenfalls gleich ist, gebe Handling an rechtes weiter
      if (liste->prev != NULL && liste->prev->gericht->energie == gericht->energie)
      {
        fuegeEinInListe(liste->prev, gericht);
      }
      else
      {
        Node *new = malloc(sizeof(Node));
        new->gericht = gericht;
        new->prev = liste->prev;
        new->next = liste;
        if (liste->prev != NULL)
        {
          liste->prev->next = new;
        }
        liste->prev = new;
      }
    }
  }
}

void gebeListeAus(Node *liste)
{
  // Ganz nach links gehen
  while (liste->prev != NULL)
  {
    liste = liste->prev; // Darf modifiziert werden, weil es by Value übergeben wurde
  }

  // Von links nach rechts gehen und alles ausgeben
  while (liste != NULL)
  {
    printf("Gericht: %s\n Id: %d\n Energie: %d\n Preis: %d\n\n", liste->gericht->name, liste->gericht->id, liste->gericht->energie, liste->gericht->preisInCent);

    liste = liste->next;
  }
}

Gericht *sucheGlutenfreiesGericht(Node *liste)
{
  // Suche von links nach rechts -> Erst ganz nach links gehen
  while (liste->prev != NULL)
  {
    liste = liste->prev; // Darf modifiziert werden, weil es by Value übergeben wurde
  }

  while (liste != NULL)
  {
    if (liste->gericht->glutenfrei == true)
    {
      return liste->gericht;
    }

    liste = liste->next;
  }

  return NULL;
}
