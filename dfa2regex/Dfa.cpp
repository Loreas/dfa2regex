//
// Created by loreas on 26.03.17.
//
#include "Dfa.h"
#include <vector>
using namespace std;

State *Transition::getPrevious() const {
    return previous;
}

void Transition::setPrevious(State *previous) {
    Transition::previous = previous;
}

State *Transition::getNext() const {
    return next;
}

void Transition::setNext(State *next) {
    Transition::next = next;
}

const string &Transition::getVoorwaarde() const {
    return voorwaarde;
}

void Transition::setVoorwaarde(const string &voorwaarde) {
    Transition::voorwaarde = voorwaarde;
}

set<Transition *> &State::getTo() {
    return to;
}

void State::setTo(set<Transition *> &to) {
    State::to = to;
}

const set<Transition *> &State::getFrom() const {
    return from;
}

void State::setFrom(const set<Transition *> &from) {
    State::from = from;
}

const string &State::getName() const {
    return name;
}

void State::setName(const string &name) {
    State::name = name;
}

bool State::isAccepting() const {
    return accepting;
}

void State::setAccepting(bool accepting) {
    State::accepting = accepting;
}

bool State::isStarting() const {
    return starting;
}

void State::setStarting(bool starting) {
    State::starting = starting;
}

void State::addFrom(Transition *from) {
    State::from.insert(from);
}

State::State() {
    State::starting = false;
    State::accepting = false;
}


void Dfa::to_regex() {
    //heel de map met states doorlopen
    //eerst elke ronde pijl een ster van maken

    //state verwijderen en transitie concateneren;
    for(auto &it : Dfa::states){
        if(!it.second->isAccepting() and !it.second->isStarting() ){
            remove_state(it.second);
        }

    }
    //only begin and end states


}

void Dfa::remove_state(State* state) {
    //keep previous transition
    set<Transition*> &to = state->getTo();
    set<Transition*> from =state->getFrom();
    vector<State*> temp_previous;
    vector<State*> temp_next;
    string regex = "(";

    //hou alle state* bij in een vector

    for (auto &i : from){
        //hou alle state* bij in een vector
        temp_next.push_back(i->getNext());
        for (auto &j: to){
            //regex string maken
            temp_previous.push_back(j->getPrevious());
            regex += "(" + i->getVoorwaarde() + ")" + j->getVoorwaarde() + "+";
            //hou alle state* bij in een vector


        }
    }
    regex += ")";
    //alle transities verwijderen


    for(auto &i: to){
        i->getPrevious()->getTo().erase(i);
        delete[] i;
    }
    for (auto &i : from){
        i->getPrevious()->getTo().erase(i);
        delete[] i;
    }

    //en nieuwe transitie maken
    Transition* total = new Transition;
    //met regex als voorwaarde
    total->setVoorwaarde(regex);
    //previous en next blijven nullptrs

    //pointers van states naar nieuwe transition laten wijzen
    //"pointless pointers" (oh the pun) verwijderen uit state vector
    for(auto &i: temp_previous){


    }
    for (auto &i : temp_next){

    }


    //state verwijderen
    delete[] state;



}

const map<string, State *> &Dfa::getStates() const {
    return states;
}

void Dfa::setStates(const map<string, State *> &states) {
    Dfa::states = states;
}

const set<string> &Dfa::getAlphabet() const {
    return alphabet;
}

void Dfa::setAlphabet(const set<string> &alphabet) {
    Dfa::alphabet = alphabet;
}

void Dfa::addState(string naam, State *state) {
    Dfa::states[naam] = state;
}


