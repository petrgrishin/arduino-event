class Listener {
    public:
        Listener& trigger(Event *event) {

            return *this;
        };

        Listener& on(Subscriber *subscriber) {

            return *this;
        };

    private:
        Subscriber subscriber[10];
};
