#ifndef __LCD__
#define __LCD__

class Lcd {
    public:
        Lcd(int sda, int scl);
        void display(char * msg);

    private:
        int sda;
        int scl;
};

#endif