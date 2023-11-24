#ifndef __TESTLCD__
#define __TESTLCD__
#include "components/Lcd.h"

class TestLcd {
    public:
        TestLcd();
        void testDisplay(char *msg);
        void testClear();
        void testTwoLineText(char *msg);
    
    private:
        Lcd* lcd;
}
#endif