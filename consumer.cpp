#include <chrono>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <thread>
#include <vector>

// Structure for image data (Struktur für Bilddaten)
struct ImageData {
  int width;                    // Width of the image (Breite des Bildes)
  int height;                   // Height of the image (Höhe des Bildes)
  char pixels[1920 * 1080 * 4]; // Pixel information (4 bytes per pixel)
                                // (Pixelinformationen, 4 Bytes pro Pixel)
};

int main() {
  // Create or connect to the Shared Memory (Erstelle oder verbinde mit dem
  // Shared Memory)
  key_t key = ftok("/tmp", 'X');
  int shmid = shmget(key, sizeof(ImageData), 0666);
  ImageData *sharedData = (ImageData *)shmat(shmid, nullptr, 0);

  // Measurement of runtime and calculation of data transfer rate (Messung der
  // Laufzeit und Berechnung der Datenübertragungsrate)
  auto start = std::chrono::high_resolution_clock::now();

  // Example: Output the first four pixel values (Beispiel: Ausgabe der ersten
  // vier Pixelwerte)
  std::cout << "First four Received pixels: ";
  for (int i = 0; i < 16; ++i) {
    std::cout << std::hex << (int)(unsigned char)sharedData->pixels[i];
    if (i == 3 || i == 7 || i == 11) {
      std::cout << " ";
    }
  }
  std::cout << std::dec << std::endl;

  // Here you could perform additional operations with the received data (Hier
  // könntest du weitere Operationen mit den empfangenen Daten durchführen)

  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Data Transfer Rate: " << 1.0 / (duration.count() / 1e6)
            << " fps" << std::endl;

  // Detach from Shared Memory (Trenne Shared Memory)
  shmdt(sharedData);

  return 0;
}
