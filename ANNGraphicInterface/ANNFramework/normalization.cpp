#include "normalization.h"

Normalization::Normalization()
{
	setNormalization(LinearAutoRange);
	setMaxValue(999999999);
	setMinValue(-999999999);
	setThreshold(0);
	setAmplitude(1);
	setElongation(1);
}

Normalization::Normalization(NormalizationType nt, double max, double min, double threshold, double amp, double elong)
{
	setNormalization(nt);
	setMaxValue(max);
	setMinValue(min);
	setThreshold(threshold);
	setAmplitude(amp);
	setElongation(elong);
}

void Normalization::setNormalization(Normalization::NormalizationType nt)
{
	norType = nt;
}

Normalization::NormalizationType Normalization::getNormalization() const
{
	return norType;
}

void Normalization::setMaxValue(double max)
{
	maxValue = max;
}

double Normalization::getMaxValue() const
{
	return maxValue;
}

void Normalization::setMinValue(double min)
{
	minValue = min;
}

double Normalization::getMinValue() const
{
	return minValue;
}

void Normalization::setThreshold(double threshold)
{
	this->threshold = threshold;
}

double Normalization::getThreshold() const
{
	return threshold;
}

void Normalization::setAmplitude(double amp)
{
	amplitude = amp;
}

double Normalization::getAmplitude() const
{
	return amplitude;
}

void Normalization::setElongation(double elong)
{
	elongation = elong;
}

double Normalization::getElongation() const
{
	return elongation;
}

Normalization Normalization::operator=(const Normalization &nor)
{
	Normalization output;
	output.setMaxValue(nor.getMaxValue());
	output.setMinValue(nor.getMinValue());
	output.setThreshold(nor.getThreshold());
	return output;
}

bool Normalization::operator==(const Normalization &param1)
{
	if(param1.getMaxValue() == this->getMaxValue() &&
	   param1.getMinValue() == this->getMinValue() &&
	   param1.getThreshold() == this->getThreshold()){
		return true;
	}else{
		return false;
	}
}

bool Normalization::operator!=(const Normalization &param1)
{
	if(param1.getMaxValue() == this->getMaxValue() &&
	   param1.getMinValue() == this->getMinValue() &&
	   param1.getThreshold() == this->getThreshold()){
		return false;
	}else{
		return true;
	}
}
