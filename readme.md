# Prüfungsleistung C/C++
### TODO
- [x] Statistiken
    - [x] Vergleiche
    - [x] Zuweisungen
    - [x] Konditionale Kompilierung
- [x] Daten einlesen
- [x] Daten exportieren
    - [x] Für von Datei geladene Werte sortiert.txt
    - [x] Für selber generierte Daten Statistiken in Ergebnisse.txt
- [x] Zufallsdaten generieren
    - [x] Zufälliger Seed
- [x] UI
    - [x] Sortieren eines Array mit Nutzerdefinierten Werten
        - [x] Statistiken Ausgabe
    - [x] Sortieren einer Datei
        - [x] Speichern in *-sort Datei
        - [x] Statistiken Ausgabe
    - [x] Sortieren von Generierten Daten

## Anleitung
Funktionen für Datenzugriffe befinden sich in src/lib/data.h
Funktionen für Laden und Speichern in Dateien in src/lib/file.h
Sortierfunktion in src/lib/file.h

In src/ui befinden sich Funktionen für das Kommandozeilenprogramm

Zählstatistiken werden durch COLLECT_STATS ausgegeben

`make COLLECT_STATS=1`

Verstöße gegen bound checks können durch LOGGING aktiviert werden

`make LOGGING=1`

Releaseprofil mit -O3 ist release
`make release`

Bsp. Kompilieren mit Releaseoptimierungen und zählen der Swaps/Vergleiche und loggen für out of bounds zugriffe:
`make release COLLECT_STATS=1 LOGGING=1`

### Verwendung in anderen Programmen
Benötigt werden immer data.c/h und sort.c/h 

# Statistiken
Durchschnittliche Vergleiche und Swaps und Trendlinie:
![Diagramme](/Diagramme.png)
