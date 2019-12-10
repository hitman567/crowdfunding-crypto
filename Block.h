
#ifndef Block_h
#define Block_h

#include "TransactionData.h"
using namespace std;
// Block Class
class Block
{
private:
    int index;
    long long int nNonce ;
    size_t blockHash;
    size_t previousHash;
    string generateHash(long long int nNonce);
      size_t MineBlock();
    string sHash;
public:
    // Constuctor
    Block(int idx, TransactionData d, size_t prevHash);
    
    // Get Index
    int getIndex();
    
    // Get Original Hash
    size_t getHash();
    
    // Get Previous Hash
    size_t getPreviousHash();
    
    // Transaction Data
    // Would ordinarily be a private member with a "getter": getData()
    TransactionData data;
    
    // Validate Hash
    bool isHashValid();
};

#endif /* Block_h */
