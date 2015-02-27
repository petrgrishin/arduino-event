class Subscriber {
public:
    void takeEvent(Event *event) {
        if (identity(event)) {
            process(event);
        }
    }

    virtual void process(Event *event) {
    }

    virtual bool identity(Event *event) {
        return true;
    }
};
