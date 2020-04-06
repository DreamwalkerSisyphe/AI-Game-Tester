
#include <string>
#include "Scenario.hpp"
#include "Spell.hpp"

using namespace std;

class Transcript {
public:
    Transcript();
    Scenario *getScenario();
    Spell *getStartSpell();

private:
    std::vector<Scenario> allScenarios;
};
