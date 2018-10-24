// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO -- convert the numerator char and denominator char into ints, return value of (numer. int/denom. int) * 8 == duration in 8th notes
    double numerator = fraction[0] - '0';
    double denomenator = fraction[2] - '0';
    double frac = numerator / denomenator;
    int dur = frac * 8;
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO -- parse the string into the correct note (including accidentals) and then modulate that to the right octave

    //parse the string
    char letter = note[0];  //accidentals or not, below with hold true
    double octave = 4;
    char accidental = 'a';
    double hertz = 0;
    if (strlen(note) == 2)  //handle following string characters depending on accidentals or not
    {
        octave = note[1] - '0';

    }
    if (strlen(note) == 3)
    {
        accidental = note[1];
        octave = note[2] - '0';
    }

    //modulate to the correct letter of the note
    switch (letter)
    {
        case 'C'  :
            hertz = 261.626;
            break;

        case 'D'  :
            hertz = 293.665;
            break;

        case 'E'  :
            hertz = 329.628;
            break;

        case 'F'  :
            hertz = 349.228;
            break;

        case 'G'  :
            hertz = 391.995;
            break;

        case 'A'  :
            hertz = 440.00;
            break;

        case 'B'  :
            hertz = 493.883;
            break;
    }

    //modulate to the correct octave of the note
    double jump = octave - 4; //yields float equal to number of octaves above or below the 4th
    hertz = hertz * pow(2.0, jump);  //multiplies the note's hertz value by 2^octaveJump power to alter hertz to correct octave

    //modulate for the accidental, if present
    if (accidental == '#')
    {
        //modulate up a semitone
        double semitone = 1.05946309436;
        hertz = round(hertz * semitone);

    }
    if (accidental == 'b')
    {
        //modulate down a semitone
        double semitone = 1.05946309436;
        hertz = round(hertz / semitone);
    }

    //return that good frekuncsee boiii
    int finalhertz = round(hertz);
    return finalhertz;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO -- return true is string represents a rest, else return false
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
