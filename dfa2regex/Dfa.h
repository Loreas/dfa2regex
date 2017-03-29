//
// Created by loreas on 25.03.17.
//

#ifndef DFA2REGEX_TRANSITION_H
#define DFA2REGEX_TRANSITION_H

#include <iostream>
#include <map>
#include <set>


using namespace std;
//forward decleration

class State ;

class Transition {
private:
    State* previous = nullptr;
    State* next = nullptr;
    string voorwaarde;

public:
    State *getPrevious() const;

    void setPrevious(State *previous);

    State *getNext() const;

    void setNext(State *next);

    const string &getVoorwaarde() const;

    void setVoorwaarde(const string &voorwaarde);
};


class State{
private:
    set<Transition*> to;
    set<Transition*> from;
    string name;
    bool accepting;
    bool starting;
public:
    State();

    set<Transition *> &getTo() ;

    void setTo(set<Transition *> &to);

    const set<Transition *> &getFrom() const;

    void setFrom(const set<Transition *> &from);

    const string &getName() const;

    void setName(const string &name);

    bool isAccepting() const;

    void setAccepting(bool accepting);

    bool isStarting() const;

    void setStarting(bool starting);

    void addFrom(Transition * from);
};


class Dfa{
private:
    map<string, State*> states;
    set<string> alphabet;
public:
    void to_regex();

    void remove_state(State* state);

    const map<string, State *> &getStates() const;

    void setStates(const map<string, State *> &states);

    const set<string> &getAlphabet() const;

    void setAlphabet(const set<string> &alphabet);

    void addState(string naam, State* state);

};

#endif //DFA2REGEX_TRANSITION_H
