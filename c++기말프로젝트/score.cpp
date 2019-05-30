class score{
public:
    void pushUp();
    void stepUp();
    int getPush();
    int getStep();
    score();
private:
    int stepNum;
    int pushNum;
};

score::score(){
    stepNum=0;
    pushNum=0;
}
void score::pushUp(){pushNum++;}
void score::stepUp(){stepNum++;}
int score::getPush(){return pushNum;}
int score ::getStep(){return stepNum;}