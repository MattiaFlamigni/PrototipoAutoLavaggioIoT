#ifndef __TESTPIR__
#define __TESTPIR__

#include "components/Pir.h"

class TestPir {
    public:
        TestPir();
        void testDetected();
    private:
    Pir* pir;
};
#endif