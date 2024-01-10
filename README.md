# onexip-example1

---------------------- English ---------------------------------------

Shared memory project to simulate a transfer of large image data under Linux.

Set up two command line programs with C++. Find an IPC technology. Transfer large image data simulated
(approx. FullHD image 1920x1080x4 RGA change pixels (1920x1080x4)2 to a comprehensible value, for example 0xCF5A5ACF) from one program to the second as efficiently as possible.
Measure the data rate for data transfer in fps.

To run the two programs, you must first compile them and then run them in different terminals. Here are the steps to run it on Linux:

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

Um die beiden Programme auszuführen, musst du sie zuerst kompilieren und dann in verschiedenen Terminals ausführen. Hier sind die Schritte für die Ausführung unter Linux:

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
