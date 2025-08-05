#pragma once
#include "files.hpp"

namespace Config
{
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
        #define BACKGROUND_SELECTED 0x757575

        inline ColorPairFile Executable     = { BACKGROUND, 0x00CD00, BACKGROUND_SELECTED, 0x00CD00};
        inline ColorPairFile Regular        = { BACKGROUND, 0xFFFFFF, BACKGROUND_SELECTED, 0x00CD00};
        inline ColorPairFile Directory      = { BACKGROUND, 0x0000EE, BACKGROUND_SELECTED, 0x00CD00};
        inline ColorPairFile NamedPipe      = { BACKGROUND, 0xFFFFFF, BACKGROUND_SELECTED, 0x00CD00};
        inline ColorPairFile NamedIPCSocket = { BACKGROUND, 0xFFFFFF, BACKGROUND_SELECTED, 0x00CD00 };
        inline ColorPairFile SymbolicLink   = { BACKGROUND, 0xFFFFFF, BACKGROUND_SELECTED, 0x00CD00 };
        inline ColorPairFile Character      = { BACKGROUND, 0xFFFFFF, BACKGROUND_SELECTED, 0x00CD00 };
        inline ColorPairFile Block          = { BACKGROUND, 0xFFFFFF, BACKGROUND_SELECTED, 0x00CD00 };
        inline ColorPairFile Other          = { BACKGROUND, 0xFFFFFF, BACKGROUND_SELECTED, 0x00CD00 };

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
        //not added yet
        /*void processInput()
        {
            if(blah blah k down )
            {
                FilesCPP::Selected++;
            }
            if(blah blah j down )
            {
                FilesCPP::Selected--;
            }
        }*/
    }
}
