This project filters 4 channels of analog audio in real time using an Analog Devices ADSP-BF533 evaluation board. The code is based on the Audio Codec Talkthrough - TDM (C) example that comes with VisualDSP. The filtering is done by applying FIR filters on a circular buffer of audio samples. There are 3 filters that can be selected from the board's buttons. The 4th button disables filtering.

The filter coefficients were calculated using Matlab. The Matlab script is included in this project.

For the project to work, the DIP switch SW9 on the board needs to be set like this:
    SW9 : 1,2,3,4 -> ON
              5,6 -> OFF

Use VisualDSP to open the project and compile the code.

Developed by Stelian Saracut
2019
