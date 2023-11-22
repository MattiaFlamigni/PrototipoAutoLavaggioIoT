#ifndef __LCD__
#define __LCD__

#include <String.h>

class Lcd {
    public:
        Lcd(int sda, int scl);
        void display(char* msg);
        void clear();
        void twoLineText(char *msg);
        
        /*void scrollText(String text);*/

    private:
        int sda;
        int scl;
};

#endif