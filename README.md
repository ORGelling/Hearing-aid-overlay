# Hearing-aid-overlay
Making a hearing aid for people who cannot discern the direction of sounds. 
Using an overlay that displays arrows in the edge of the screen.

Using SDL2 and FMOD, initially working on Linux to then test and implement on
Windows. SDL2 component is implemented and working, with different options for
rendering (ellips or circle, arrow angle and size). Still have to implement
line thickness option if necessary. Will also expand the commandline argument
parsing significantly with either getopt or my own Arg class.

Now comes FMOD, have not started yet. Should be interesting. Have to use the
audio engine to extract the relative location of dynamic sounds from so arrows 
can be displayed in that direction, or one closest in a grid. Working with 
SDL2 and getting it to render the arrows was fun, properly implementing the 
audio engine might be a bit harder though.
