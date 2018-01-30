/*  Eoin Finlay
    08/01/2018
    Ex 15 - Sinewave Calculations */

//Preprocessor directives
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;


//Class
class Waveform
{
    private:
                double amp, dcOff, freq, phase, instantVol, time, period, phaseRad, vrms;

    public:

                Waveform(void)
                {
                    amp = 1;
                    freq = 1000;
                    phase = 0;
                    dcOff = 0;
                }

                //Reading in values of diffenent members
                void getValues (void)
                {
                    cout << "Amplitude :\t" ;
                    cin >> amp;
                    cout << "\nFrequency :\t" ;
                    cin >> freq;
                    cout << "\nPhase angle :\t" ;
                    cin >> phase;
                    cout << "\nDC offset :\t" ;
                    cin >> dcOff;
                    cout << "\nTime :\t" ;
                    cin >> time;
                }

                // Instantaneous voltage function
                double Vinst(void)
                {
                    //calculating phase angle in Rads
                    phaseRad = phase * (M_PI / 180);
                    //calcuating instantaneous voltage
                    instantVol = amp * sin((2 * M_PI * freq * time) + phaseRad) + dcOff;
                    //displaying result
                    cout << "\nInstantaneous Voltage: \t" << instantVol << endl;
                    return instantVol;
                }

                // Period function
                double periodCal(void)
                {
                    //calculating period
                    period = 1.0 / freq;
                    //displaying result
                    cout << "\nPeriod :\t" << period << endl;
                    return period;
                }

                // Vrms  function
                double vrmsCal(void)
                {
                    //calculating VRMS
                    vrms = amp / sqrt(2.0);
                    //displaying result
                    cout << "\nVrms :\t" << vrms << endl << endl;
                    return vrms;
                }

};

//Main function
int main()
{
    // object instantiation
    Waveform sinewave;


    //Calling member functions within the class
    sinewave.getValues();
    sinewave.Vinst();
    sinewave.periodCal();
    sinewave.vrmsCal();


    return 0;
}
