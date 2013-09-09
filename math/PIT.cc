/**
 * 一个叫Programmable Interrupt Timer 的东西, 是一个中断发生器，每隔一个时间T就发一个中断，然后调用中断处理器(handler), 支持两种操作：
 * a) set_handler(handler) // 把hander设置为interrupt接收者， handler是一个函数
 * b) set_interval(time) // 把 interrupt 发送间隔设置为time
 * 问题，如果现在有两个函数A, B。 要使A每t1秒执行一次， B每t2秒执行一次， 要怎么做？ （handler函数里面可以修改PIT的时间间隔）
 */

void handler() {
    static int next1 = 0, next2 = 0;
    if (next1 < next2) {
        next2 -= next1;
        next1 = t1;
        A();
    } else if (next1 > next2) {
        next1 -= next2;
        next2 = t2;
        B();
    } else {
       next1 = t1, next2 = t2;
       A();
       B();
    }
    set_interval(min(next1, next2));
}
