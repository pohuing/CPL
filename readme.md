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
    - [ ] Zufälliger Seed
- [x] UI
    - [x] Sortieren eines Array mit Nutzerdefinierten Werten
        - [ ] Statistiken Ausgabe
    - [x] Sortieren einer Datei
        - [x] Speichern in *-sort Datei
        - [x] Statistiken Ausgabe
    - [x] Sortieren von Generierten Daten

Zählstatistiken werden durch COUNT_SWAPS ausgegeben

`make statistics="-D COLLECT_STATS`

Verstöße gegen bound checks können durch LOGGING aktiviert werden

`make statistics="-D LOGGING"`

Releaseprofil mit -O3 ist release

`make release`

### Durchschnittliche Vergleiche und Swaps und Trendlinie:
![Diagramme](/Diagramme.png)
