# Hearing-aid-overlay
Making a screen overlay to aid people with hearing trouble in where the 
direction of in-game sounds are coming from.

Using SDL2 and FMOD, initially working on Linux to then test and implement on
Windows. SDL2 component is implemented and working, with different options for
rendering (ellips or circle, arrow angle and size). Still have to implement
line thickness option if necessary. Will also expand the commandline argument
parsing significantly with either getopt or my own Arg class.

Now comes FMOD, have not started yet. Should be interesting, have to use it as
audio engine to extract the relative location of dynamic sounds from so it can
trigger the arrows in the closest direction. Working with SDL2 and getting it
to render my arrows was fun though.
