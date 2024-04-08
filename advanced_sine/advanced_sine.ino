
#include "ArduTouch.h"                    // use the ArduTouch library 

about_program( advanced_sine, 1.00 )                // specify sketch name & version

class AdvancedSine : public Synth           
{                                         // and control its frequency by the top pot
   public:

   Sine osc;                          // a Sine oscillator does the sinewave calculation

   // Initialisierung
   void welcome()
   {
      osc.reset();                        // initialize oscillator
      osc.setFreq( 100.0 );               // set initial freqeuncy to 100.0 Hz
   }

   // the evHandler() control the frequency with the potentiometer
   boolean evHandler( obEvent e )         // event handler
   {
      switch ( e.type() )                 // branch on event type
      {
         case POT0:                       // top pot was moved

            osc.setFreq( e.getPotVal() ); // set freq from pot value (0-255)
            return true;                  // event was handled
            break;

         default:                         // pass all other events to normal Synth handler

            return Synth::evHandler(e); 
      }
   }


   void output( char *buf )               // output 1 buffer of audio
   {
      // easy no calculation of sine is needed
      osc.output( buf );                  // pass buffer to oscillator
   }

};

AdvancedSine my_advanced_sine_synth;                                // instantiate synthesizer 


void setup()
{
   ardutouch_setup( &my_advanced_sine_synth );           // initialize ArduTouch resources
}


void loop()
{
   ardutouch_loop();                      // perform ongoing ArduTouch tasks  
}  
