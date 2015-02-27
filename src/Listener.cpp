#define MAX_SUBSCRIBER 10

class Listener {
public:
    Listener() {
        _size = 0;
    };

    Listener &trigger(const char *name, Event *event) {
        int _pos = 0;
        while (_pos++ < _size) {
            if (_subscriberId[_pos] != (char *) name) {
                continue;
            }
            _subscriber[_pos]->takeEvent(event);
        }
        return *this;
    };

    Listener &trigger(const char *name) {
        int _pos = 0;
        while (_pos++ < _size) {
            if (_subscriberId[_pos] != (char *) name) {
                continue;
            }
            _subscriber[_pos]->takeEvent(new Event());
        }
        return *this;
    }

    Listener &on(const char *name, Subscriber *subscriber) {
        _size++;
        _subscriberId[_size] = (char *) name;
        _subscriber[_size] = subscriber;
        return *this;
    };

private:
    Subscriber *_subscriber[MAX_SUBSCRIBER];
    char *_subscriberId[MAX_SUBSCRIBER];
    unsigned int _size;
};

