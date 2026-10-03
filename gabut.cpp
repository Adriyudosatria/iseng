#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class labvent {
private :
    double voclevel;
    bool liquidDetected;
    string fanspeed;
    bool visuaAlarm;
    bool doorLocked;
    bool audioAlarm;

    const double safetyBoundaries = 5.0; //contoh angkanya aja aslinya mah gatau berapa batas amanya


public :
    labvent (){
        voclevel = 0;
        liquidDetected = false;
        fanspeed = "OFF";
        visuaAlarm = false;
        doorLocked = false;
        audioAlarm = false;

    }

    void setvoc (double level) {
        voclevel = level;
    }

    void liquidDetector (bool detected){
        liquidDetected = detected;
    }

    void hazard (){
        if (voclevel > safetyBoundaries){
            cout << "bahaya jir";

            fanspeed = "MAX";
            visuaAlarm = true;
            doorLocked = true;
            audioAlarm = true;

        }

        else if (liquidDetected){
            cout << "bahaya dikit";
            fanspeed = "LOW";
            visuaAlarm = true;
            doorLocked = false;
            audioAlarm = false;

        }

        else {
            cout << "aman coy";
            fanspeed = "OFF";
            visuaAlarm = false;
            doorLocked = false;
            audioAlarm = false;
        }

    }
};
int main () {
labvent vent;
double voc;
int liquid;


    while (true){
        cout << "input voc level :" << endl;
        cin >> voc;

        cout << "ada liquid ga?" << endl;
        cin >> liquid; //input 1 untuk ada dan 0 untuk gaada

        vent.setvoc (voc);

        vent.liquidDetector(liquid == 1);

        vent.hazard();

        return 0;


    }

}