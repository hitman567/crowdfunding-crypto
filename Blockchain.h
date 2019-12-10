
#ifndef Blockchain_h
#define Blockchain_h
using namespace std;
#include <vector>

// Blockchain Class
class Blockchain
{
private:
    Block createGenesisBlock();
    

public:
    // Constuctor
    Blockchain();
    std::vector<Block> chain;
    // Public Functions
    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
};

#endif /* Blockchain_h */
