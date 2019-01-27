#include "filters.h"

extern int filterIndex;

int filter(int input, channel_t channel)
{
  int i;
  int output;
  int currentSampleIndex;
  int localFilterIndex;

  currentSampleIndex = sampleIndex[channel];
  sampleBuffer[channel][currentSampleIndex] = input >> 8;
  localFilterIndex = filterIndex;

  if (localFilterIndex < NUMBER_OF_FILTERS) //apply filters if one of the first 3 buttons were pressed
  {
  	output = 0;

    for (i=0; i < FIR_LENGTH; i++)
    {
      output += filterCoefficients[localFilterIndex][i]* sampleBuffer[channel][(currentSampleIndex - i + FIR_LENGTH) % FIR_LENGTH];
    }

    output <<= 8;
  } else //no filtering if button 4 was pressed
  {
    output = input;
  }

  sampleIndex[channel] = (currentSampleIndex + 1) % FIR_LENGTH;

  return output;
}
