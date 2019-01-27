#ifndef __Filters_DEFINED
#define __Filters_DEFINED

#define FIR_LENGTH 9
#define NUMBER_OF_FILTERS 3

typedef enum
{
  left0 = 0,
  right0,
  left1,
  right1,
  numberOfChannels
}channel_t;

static int sampleBuffer[numberOfChannels][FIR_LENGTH];

static int sampleIndex[numberOfChannels];

static const float filterCoefficients[NUMBER_OF_FILTERS][FIR_LENGTH] = {
  {-0.02771010f, 0.05351285f, 0.13862957f, 0.22591615f, 0.26270698f, 0.22591615f, 0.13862957f, 0.05351285f, -0.02771010f},     //lowpass
  {0.04580234f, -0.03762617f, -0.10357527f, -0.25501761f, 0.61416455f, -0.25501761f, -0.10357527f, -0.03762617f, 0.04580234f}, //highpass
  {-0.15872657f, -0.21070283f, -0.03056337f, 0.13461129f, 0.39489365f, 0.13461129f, -0.03056337f, -0.21070283f, -0.15872657f}  //bandpass
};

int filter(int input, channel_t channel);

#endif
