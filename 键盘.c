#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")

wchar_t lpWStr[1024] = { 0 };

void Play()
{
    srand((unsigned)time(NULL));
    int a = rand() % 30;
    wsprintfW(lpWStr, L"play 语音包\\%d.mp3", a);
    mciSendString(lpWStr, NULL, 0, NULL);
}

int main()
{
    while (1)
    {
        for (int i = 1; i < 255; i++)
        {
            if (GetAsyncKeyState(i))
            {
                while (GetAsyncKeyState(i)); // Wait until the key is released.

                HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Play, NULL, 0, NULL);

                // Note: The thread handle is not closed here, as it would block the main thread.
                // If you want to properly manage threads, consider using a synchronization mechanism like a semaphore.
            }
        }
    }

    return 0;
}