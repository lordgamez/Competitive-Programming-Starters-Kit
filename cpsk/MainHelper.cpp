/**
 *   Copyright 2019 Rajdeep Roy Chowdhury <rrajdeeproychowdhury@gmail.com>
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */
#include <unordered_map>
#include "MainHelper.h"
#include "Misc.h"

void cpsk::MainHelper::showHelp()
{
    // @TODO
    std::cout << "@TODO: Showing Help" << std::endl;
}
void cpsk::MainHelper::showVersion()
{
    Misc::drawLineTransition(60,50);
    Misc::transitionText(std::string("\tCompetitive Programming Starters Kit (CPSK)"),100);
    Misc::drawLineTransition(60,50);
    Misc::transitionText(std::string("Version 0.1"));
}
