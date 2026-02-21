#include "conversoes.h"

float fah_to_cel(float a){
	return (a - 32) / 1.8;
};

float cel_to_fah(float a){
	return a * 1.8 + 32;
};

float m_to_km(float a){
	return a / 1000;
};

float km_to_m(float a){
	return a * 1000;
};

float s_to_h(float a){
	return a / 60;
};

float h_to_s(float a){
	return a * 60;
};
