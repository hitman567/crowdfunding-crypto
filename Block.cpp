

#include <stdio.h>
#include <string>
#include <sstream>
#include <string>
#include "Block.h"
#include "TransactionData.h"
using namespace std;
// Constructor with params
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = MineBlock();
}

// private functions
int Block::getIndex()
{
    return index;
}

/*
 Generates hash for current block
 - Includes previousHash in generation
 - ^ Very important
*/

size_t Block::MineBlock() {
    char cstr[3 + 1];
    long long int nNonce = -1;
    for (uint32_t i = 0; i < 3; ++i) {
        cstr[i] = '1';
    }
    cstr[3] = '\0';

std::string str(cstr);

    do {
        nNonce++;
        
        sHash = generateHash(nNonce);
        printf("Mining  -----   ");
        printf("%s\n",sHash.c_str());
    } while (sHash.substr(0, 3) != str);
    stringstream geek(sHash);

    long long int i = 0;
    geek >> i; 
    return i;
}

string Block::generateHash(long long int nNonce)
{
    std::stringstream ss;

    ss<<std::to_string(data.amount)<< data.receiverKey <<data.senderKey <<std::to_string(data.timestamp)<<std::to_string(nNonce) ;
    std::string toHashS = ss.str();
   
    std::hash<std::string> tDataHash; 
    std::hash<std::string> prevHash; 
     std::hash<std::string> neww ; 
    
    return to_string(neww(to_string(tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1))));
}

// Public Functions
size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return MineBlock() == getHash();
}
