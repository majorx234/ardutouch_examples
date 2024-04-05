#include "ArduTouch.h"                    // use the ArduTouch library

about_program( Output, 1.00 )             // specify sketch name & version

class SimpleSine : public Synth        // output a sawtooth waveform
{
   public:

   char  sample;                          // sample value used in output()

   // to make a sound with ArduTouch, you simply fill an audio buffer
   // (given to you by the system) with your desired waveform.

   // whenever the ArduTouch system needs an audio buffer to be filled
   // output() is automatically called by ardutouch_loop().

   // the following fills the audio buffer with a sawtooth waveform
   void output( char *buf )               // output 1 buffer of audio
   {
      for( int i = 0; i< audioBufSz; i++ )                    // for each byte in buffer
         *buf++ = sin(i*0.01 * 3.14)* 128;               // write sample to buffer,
                                          // and bump it (wraps at 127)
   }

} my_simple_sine;

void setup()
{
   ardutouch_setup( &my_simple_sine );           // initialize ArduTouch resources
}

void loop()
{
   ardutouch_loop();                      // perform ongoing ArduTouch tasks
}
