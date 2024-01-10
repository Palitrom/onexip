# onexip-example1

---------------------- English ---------------------------------------

Shared memory project to simulate a transfer of large image data under Linux.

Set up two command line programs with C++. Find an IPC technology. Transfer large image data simulated
(approx. FullHD image 1920x1080x4 RGA change pixels (1920x1080x4)2 to a comprehensible value, for example 0xCF5A5ACF) from one program to the second as efficiently as possible.
Measure the data rate for data transfer in fps.

### A notice:

The wording "change pixels (1920x1080x4)2" is a bit unclear and could be interpreted differently.
It seems to be some sort of typo or possibly a mix-up.

Normally one would expect to want to change the pixel values for an image with dimensions 1920x1080 and 4 color components (e.g. R, G, B, A for red, green, blue, alpha).
However, the addition "(1920x1080x4)2" is not understandable by default.

It could be that the expression "(1920x1080x4)2" is a placeholder for the number of pixels in the image, indicating doubling.
In this case the pixel values would be changed for twice the number of pixels (if correct).

I interpreted the following:
The instruction, "change pixel (1920x1080x4)2 to a comprehensible value, for example 0xCF5A5ACF", means that the pixel value for the second pixel in the image should be changed to the value "0xCF5A5ACF".
Normally the second pixel would be at coordinates (1,0) since counting starts at 0 in most programming languages.

In this case the pixel values for the second pixel would be:

- Red: [value]
- Green: [value]
- Blue: [value]
- Alpha (Transparency): [Value]

and all of these values would be set to the specific hexadecimal value "0xCF5A5ACF".

**To run the two programs, you must first compile them and then run them in different terminals. Here are the steps to run it on Linux:**

1. Compile:

Compile both programs with a C++ compiler like g++:
  g++ producer.cpp -o producer -std=c++11
  g++ consumer.cpp -o consumer -std=c++11

2. Run:

Open two separate terminals.
   - In the first terminal run the producer program:  
  ./producer

The program will write image data to shared memory and then pause for one second.
   - In the second terminal run the consumer program:
   ./consumer
3. Check results:

After both programs have run, you can see the results in the consumer terminal, including the received pixel values and the measured data transfer rate.

Note that this is a simple example and actual performance may vary depending on the system. If you have problems or errors running the programs, check the compilation steps and places in the code that need to be adjusted for your specific environment.

---------------------- Deutsch ---------------------------------------

Shared Memory Projekt zur Simulation eines Transfers großer Bilddaten, unter Linux.

Setze zwei Kommandozeilenprogramme mit C++ auf. Finde eine IPC-Technologie. Transferiere große Bilddaten simuliert 
(ca. FullHD image 1920x1080x4 RGA ändere Pixel (1920x1080x4)2 auf einen nachvollziehbaren Wert zum Beispiel 0xCF5A5ACF) von einem Programm in das zweite möglichst performant. 
Messe die Datenrate für den Datentransfer in fps.

### Hinweis:

Die Formulierung "ändere Pixel (1920x1080x4)2" ist etwas unklar und könnte unterschiedlich interpretiert werden. 
Es scheint eine Art Schreibfehler zu sein oder möglicherweise eine Verwechslung.

Normalerweise würde man erwarten, dass die Pixelwerte für ein Bild mit den Dimensionen 1920x1080 und 4 Farbkomponenten (z. B. R, G, B, A für Rot, Grün, Blau, Alpha) geändert werden sollen. 
Der Zusatz "(1920x1080x4)2" ist jedoch nicht standardmäßig verständlich.

Es könnte sein, dass der Ausdruck "(1920x1080x4)2" als Platzhalter für die Anzahl der Pixel im Bild steht, was auf eine Verdoppelung hindeutet. 
In diesem Fall würden die Pixelwerte für die doppelte Anzahl der Pixel (wenn dies korrekt ist) geändert werden.

Ich habe folgndes Interprtiert:
Die Anweisung, "ändere Pixel (1920x1080x4)2 auf einen nachvollziehbaren Wert zum Beispiel 0xCF5A5ACF", bedeutet, dass der Pixelwerte für das zweite Pixel im Bild auf den Wert "0xCF5A5ACF" geändert werden sollen. 
Normalerweise würde das zweite Pixel bei den Koordinaten (1,0) liegen, da die Zählung in den meisten Programmiersprachen bei 0 beginnt.

In diesem Fall wären die Pixelwerte für das zweite Pixel:

- Rot: [Wert]
- Grün: [Wert]
- Blau: [Wert]
- Alpha (Transparenz): [Wert]

und alle diese Werte würden auf den spezifischen Hexadezimalwert "0xCF5A5ACF" gesetzt werden.


**Um die beiden Programme auszuführen, musst du sie zuerst kompilieren und dann in verschiedenen Terminals ausführen. Hier sind die Schritte für die Ausführung unter Linux:**

1. Kompilieren:

Kompiliere beide Programme mit einem C++-Compiler wie g++:
  g++ producer.cpp -o producer -std=c++11
  g++ consumer.cpp -o consumer -std=c++11

2. Ausführen:

Öffne zwei separate Terminals.
  - Im ersten Terminal führe das Producer-Programm aus:
  ./producer

Das Programm wird Bilddaten in den Shared Memory schreiben und dann eine Sekunde lang pausieren.
  - Im zweiten Terminal führe das Consumer-Programm aus:
  ./consumer

3. Ergebnisse prüfen:

Nachdem beide Programme ausgeführt wurden, kannst du die Ergebnisse im Consumer-Terminal sehen, einschließlich der empfangenen Pixelwerte und der gemessenen Datenübertragungsrate.

Beachte, dass dies ein einfaches Beispiel ist, und die tatsächliche Leistung kann je nach System variieren. Wenn du Probleme oder Fehler beim Ausführen der Programme hast, überprüfe die Kompilierungsschritte und Stellen im Code, die an deine spezifische Umgebung angepasst werden müssen.
