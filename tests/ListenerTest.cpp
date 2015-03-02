#include "minunit/minunit.h"
#include "../src/Listener.cpp"

int i = 0;
class TestSubscriber: public Subscriber {
    void process(Event *event) {
        i = i + 1;
    }
};

MU_TEST(TestSubscribeAndTrigger) {
    i = 0;
    Listener *listener = new Listener();
    Subscriber *subscriber = new TestSubscriber();
    mu_check(i == 0);
    listener->on("test", subscriber)
            .trigger("test")
            .trigger("test");
    mu_check(i == 2);
    listener->on("test", subscriber);
    mu_check(i == 2);
    listener->trigger("test");
    mu_check(i == 4);
}

MU_TEST(TestVariousSubscribeAndTrigger) {
    i = 0;
    Listener *listener = new Listener();
    Subscriber *subscriber = new TestSubscriber();
    mu_check(i == 0);
    listener->on("test1", subscriber)
            .trigger("test1");
    mu_check(i == 1);
    listener->trigger("test2");
    mu_check(i == 1);
    listener->on("test2", subscriber);
    listener->trigger("test2");
    mu_check(i == 2);
}

MU_TEST_SUITE(Test) {
    MU_RUN_TEST(TestSubscribeAndTrigger);
    MU_RUN_TEST(TestVariousSubscribeAndTrigger);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(Test);
    MU_REPORT();
    return minunit_status;
}
