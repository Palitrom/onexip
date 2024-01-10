#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <thread>
#include <chrono>
#include <sys/ipc.h>
#include <sys/shm.h>

// Structure for image data
struct ImageData {
    int width;            // Width of the image (Breite des Bildes)
    int height;           // Height of the image (Höhe des Bildes)
    char pixels[1920 * 1080 * 4];  // Pixel information (4 bytes per pixel) (Pixelinformationen, 4 Bytes pro Pixel)
};

// Function to change specific pixel values
void changeSpecificPixel(char* pixels, int pixelIndex, int newValue, std::vector<int>& changedPixelIndices) {
    // Only set the pixel at the specified index to the given value (0xCF5A5ACF)
    if (std::memcmp(&pixels[pixelIndex * 4], &newValue, sizeof(int)) != 0) {
        // Pixel was changed, save the index
        changedPixelIndices.push_back(pixelIndex);
    }
    std::memcpy(&pixels[pixelIndex * 4], &newValue, sizeof(int));
}

int main() {
    // Check if the Shared Memory segment already exists (Prüfe, ob das Shared Memory-Segment bereits existiert)
    key_t key = ftok("/tmp", 'X');
    int shmid = shmget(key, sizeof(ImageData), IPC_CREAT | IPC_EXCL | 0666);

    // If it exists, delete it (Falls es existiert, lösche es)
    if (shmid != -1) {
        std::cout << "Shared Memory segment already exists. Deleting it." << std::endl;
        shmctl(shmid, IPC_RMID, nullptr);
    }

    // Create or connect to the Shared Memory (Erstelle oder verbinde mit dem Shared Memory)
    shmid = shmget(key, sizeof(ImageData), IPC_CREAT | 0666);
    ImageData *sharedData = (ImageData *)shmat(shmid, nullptr, 0);

    // Set the second pixel to the desired value (e.g., 0xCF5A5ACF) (Setze das zweite Pixel auf den gewünschten Wert, z.B., 0xCF5A5ACF)
    int desiredValue = 0xCF5A5ACF;
    std::vector<int> changedPixelIndices;
    changeSpecificPixel(sharedData->pixels, 1, desiredValue, changedPixelIndices);

    // Output the first four transmitted pixels (Ausgabe der ersten vier übertragenen Pixel)
    std::cout << "First four transmitted pixels: ";
    for (int i = 0; i < 16; ++i) {
        std::cout << std::hex << (int)(unsigned char)sharedData->pixels[i];
        if (i == 3 || i == 7 || i == 11) {
          std::cout << " ";
        }
    }
    std::cout << std::dec << std::endl;

    // Output the changed pixel indices (Ausgabe der geänderten Pixel-Indizes)
    std::cout << "Changed pixel indices: ";
    for (int index : changedPixelIndices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Wait for a second (simulated image update interval) (Warte eine Sekunde, simuliertes Bildaktualisierungsintervall)
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Detach from Shared Memory (Trenne Shared Memory)
    shmdt(sharedData);

    return 0;
}

