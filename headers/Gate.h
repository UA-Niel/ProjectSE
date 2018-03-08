//Header file for Gate-class

#ifndef GATE_H
#define GATE_H

class Gate {
    public:
    //Constructors
    Gate();
    
    //Getters and setters
    void setId(const int id);
    int getId() const;

    //Initialized
    bool properlyInitialized() const;

    private:
    int _id;
    Gate* _initCheck;    
};


#endif
