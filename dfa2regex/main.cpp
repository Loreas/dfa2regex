#include <fstream>
#include "Dfa.h"
#include "json.hpp"
using json = nlohmann::json;
int main() {

    std::ifstream file("DFA.json");
    json j;
    j << file;

    Dfa dfa;

    std::set<std::string> alphabet = j["alphabet"]
    dfa.setAlphabet(alphabet);

    for (auto& st : j["states"]) {
        State* state = new State;
        state->setName(st["name"]);
        if(st["starting"])
        {
            state->setStarting(true);
        }
        if(st["accepting"])

            state->setAccepting(true);
        dfa.addState(st["name"], state);

    }
    for(auto& tr: j["transitions"]) {
        Transition* transition = new Transition;
        transition->setNext(dfa.getAlphabet().find(tr["to"]);
        transition->setNext(dfa.getAlphabet().find(tr["to"]);


    }
    return 0;
}