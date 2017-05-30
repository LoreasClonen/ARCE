//
// Created by sergio on 11/05/17.
//

#include <fstream>
#include "Bot.h"
#include "Parser.h"
#include "TFA/tfa.h"

void bulkTest(std::string fileName, DFA& dfa){
    std::fstream file(fileName);
    if(!file.is_open()) return;

    std::string line;
    while(getline(file, line)){
        if(dfa.checkString(line))
            std::cout << "Accepted string: " << line << std::endl;
        else
            std::cout << "Rejected string: " << line << std::endl;
    }

}

int main(unsigned int argc, char* argv[]){

    //// DEBUG & TESTING ZONE ////
    Parser parser;
    std::string dfaString = parser.parseRegex("./customCommands.json");
    std::string test;
    if(argc == 1) test = "List1";
    else if(argc == 2){
        ///// TEMP: Grab the first argument as testing regex
        test = argv[1];
    }

    Bot bot;
    bot.buildDFA(dfaString, true);

    bulkTest("./testInput.txt", *bot.getDFA());

    return 0;
}
