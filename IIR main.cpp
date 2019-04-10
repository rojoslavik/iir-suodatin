#include "mbed.h"
#include "rtos.h"
#include <aani.h>
#include <IRR-kertoimet.h>

#define TS 0.000125


Ticker kello;
AnalogIn AnalogToDigital(A0);
AnalogOut DigitalToAnalog(A2);

Serial pc(USBTX, USBRX);

//const int pituus = 51;
float muisti[4][3] = {0};
//float kertoimet[pituus] = {1.0, 1.0, 1.0};

int indeksi = 0;



float suodatin(float nayte)
{
    float tulos = nayte;
	

    for(int i= 0; i<4; i++){
        muisti[i][2] = muisti[i][1];
		muisti[i][1] = muisti[i][0];
		muisti[i][0] = tulos - SOS[i][4] * muisti[i][1] - SOS[i][5] * muisti[i][2];
		tulos = SOS[i][0]*muisti[i][0] + SOS[i][1] * muisti[i][1] + SOS[i][2] * muisti[i][2];
    }

	return tulos;

}

void kellonpalvelija() {
	indeksi = (indeksi +1)%80000;
	DigitalToAnalog = suodatin(taulukko[indeksi]);
	
}
int main() {
	
	kello.attach(&kellonpalvelija, TS);
	while(true){
		
		
		/*float input = 1.0;
		float output = 0.0;
		
		output = suodatin(input);
		DigitalToAnalog = output;
		//pc.printf("suodatuksen tulos = %f\r\n", output);
	*/
		
	//	led1 = !led1;
	//	wait(1.5);
		
	}
}

