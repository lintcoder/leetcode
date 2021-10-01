class Foo {
public:
    Foo() {
        flag1 = 0;
        flag2 = 0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag1 = 1;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while (flag1 == 0)
            ;
        printSecond();
        flag2 = 1;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while (flag2 == 0)
            ;
        printThird();
    }
private:
    volatile int flag1;
    volatile int flag2;
};