//
// Created by leah on 22/01/18.
//

#ifndef SERVER_TASK_H
#define SERVER_TASK_H
class Task {
public:
    Task(void * (*func)(void *arg), void* arg) :
            func(func), arg(arg) {}
    void execute() {
        func(arg);
    }
    virtual ~Task() { delete this; }
private:
    void * (*func)(void *arg);
    void *arg;
};
#endif //SERVER_TASK_H
