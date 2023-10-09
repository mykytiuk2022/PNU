#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 50;
const int ARRAY_SIZE = 10;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, RectangleShape rectArr[]) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1, rectArr);
        quickSort(arr, pivotIndex + 1, high, rectArr);
    }
    // update rectangles
    for (int i = 0; i < ARRAY_SIZE; i++) {
        rectArr[i].setPosition(i * RECT_WIDTH, WINDOW_HEIGHT - arr[i] * RECT_HEIGHT);
    }
}

int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Quick Sort Visualization");

    // create array and rectangles
    int arr[ARRAY_SIZE];
    RectangleShape rectArr[ARRAY_SIZE];
    srand(time(0)); // seed the random number generator
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % (WINDOW_HEIGHT / RECT_HEIGHT);
        rectArr[i].setSize(Vector2f(RECT_WIDTH, arr[i] * RECT_HEIGHT));
        rectArr[i].setPosition(i * RECT_WIDTH, WINDOW_HEIGHT - arr[i] * RECT_HEIGHT);
        rectArr[i].setFillColor(Color::White);
    }

    // start sorting
    quickSort(arr, 0, ARRAY_SIZE - 1, rectArr);

    while (window.isOpen())
    {
        // handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // draw rectangles
        window.clear();
        for (int i = 0; i < ARRAY_SIZE; i++) {
            window.draw(rectArr[i]);
        }
        window.display();
    }

    return 0;
}
