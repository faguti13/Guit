#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

class CommandHandler {
public:
    void init(int argc, char* argv[]);
    void help();
    void add(int argc, char* argv[]);
    void commit(int argc, char* argv[]);
    void status(int argc, char* argv[]);
    void rollback(int argc, char* argv[]);
    void reset(int argc, char* argv[]);
    void sync(int argc, char* argv[]);
};

#endif // COMMAND_HANDLER_H
