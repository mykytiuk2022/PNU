#include <string.h>
#include <iostream>
#include <time.h>
#include <windows.h>

#define d 256
using namespace std;

double Th() {
    SYSTEMTIME time;
    GetSystemTime(&time);
    double chas;
    chas = time.wHour * 60 * 60 * 1000 + time.wMinute * 60 * 1000 + time.wSecond * 1000 + time.wMilliseconds;
    return chas;
}

void rabinKarp(char pattern[], char text[], int prime) {
    int pattern_len = strlen(pattern);
    int text_len = strlen(text);
    int i, j;
    int pattern_hash = 0;
    int text_hash = 0;
    int h = 1;

    for (i = 0; i < pattern_len - 1; i++)
        h = (h * d) % prime;

    for (i = 0; i < pattern_len; i++) {
        pattern_hash = (d * pattern_hash + pattern[i]) % prime;
        text_hash = (d * text_hash + text[i]) % prime;
    }

    for (i = 0; i <= text_len - pattern_len; i++) {
        if (pattern_hash == text_hash) {
            for (j = 0; j < pattern_len; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == pattern_len)
                cout << "Pattern is found at position: " << i + 1 << endl;
        }

        if (i < text_len - pattern_len) {
            text_hash = (d * (text_hash - text[i] * h) + text[i + pattern_len]) % prime;

            if (text_hash < 0)
                text_hash = (text_hash + prime);
        }
    }
}


void linearSearch(char* pattern, char* text) {
    int pattern_len = strlen(pattern);
    int text_len = strlen(text);

    for (int i = 0; i <= text_len - pattern_len; i++) {
        int j;
        for (j = 0; j < pattern_len; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == pattern_len)
            cout << "Pattern is found at position: " << i+1 << endl;
    }
}

int main() {
    double t0, t1, T;
    char text[] = "FINDTEXT: Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the right path for us.Embracing Change Finally, finding the right path requires us to be open to change. Life is full of unexpected twists and turns, and we may need to adjust our course along the way. Embracing change can be scary, but it can also lead us to new opportunities and experiences we never would have otherwise had. In conclusion, finding the right path in life is a journey. It requires self-reflection, goal-setting, seeking help, and embracing change. But by taking these steps, we can create a fulfilling life for ourselves, full of purpose and meaning. So let's take the first step on our journey and find the ";
    char pattern[] = "ourselves";
    int prime = 10111;

    t0 = Th();
    //cout << "Rabin-Karp algorithm: " << endl;
    //rabinKarp(pattern, text, prime);
    cout << "Linear algorithm: " << endl;
    linearSearch(pattern, text);
    t1 = Th();
    T = (t1 - t0);
    cout << "Algorithm operation time: " << T << endl;
}
