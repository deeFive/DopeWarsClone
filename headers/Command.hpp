#pragma once
struct Command {
    virtual void call() const = 0;
};