#pragma once

namespace Config
{
    //generally main colors, doesnt count the UI elements
    namespace Colors
    {
        struct ColorPairFile { // will be used for the File type colors, but not right now as ill have to code it
            int BG;
            int FG;
            int SelectedBG;
            int SelectedFG;
        };

        struct ColorPair {
            int BG;
            int FG;
        };

        // The first one is for the background and the 2nd one is for the foreground
        // you may also create macros/new integers for colors as you please as it is a c++ header after all :D
        // set to 0 to choose nothing.
        #define BACKGROUND 0x323232 

        inline ColorPair Executable     = { BACKGROUND, 0x00CD00 };
        inline ColorPair Regular        = { BACKGROUND, 0xFFFFFF };
        inline ColorPair Directory      = { BACKGROUND, 0x0000EE };
        inline ColorPair NamedPipe      = { BACKGROUND, 0xFFFFFF };
        inline ColorPair NamedIPCSocket = { BACKGROUND, 0xFFFFFF };
        inline ColorPair SymbolicLink   = { BACKGROUND, 0xFFFFFF };
        inline ColorPair Character      = { BACKGROUND, 0xFFFFFF };
        inline ColorPair Block          = { BACKGROUND, 0xFFFFFF };
        inline ColorPair Other          = { BACKGROUND, 0xFFFFFF };

        //the color you see behind everything
        inline int Background           = BACKGROUND;

        // colors for the UI, you can see the UI namespace right below us.
        inline ColorPair Horizontal     = { 0x4B4B4B, 0x4B4BFF };
        inline ColorPair Vertical       = { BACKGROUND, 0xFFFFFF };
        inline ColorPair Crossing       = { BACKGROUND, 0x0000EE };
    }

    namespace UserInterface
    {
        inline char horizontal[] = u8"─";
        inline char vertical[]   = u8"│";
        inline char crossing[]   = u8"┼";
    }
    
    namespace Input
    {
    /*
* planning to add a function where you can add custom keybinds
* 
* void processInput()
* {
*   if (keydown('q'))
*   {
*       quit();
*   }
* }
* 
* like try to think of it like that, itll will be played on each update
*/
    }
}
