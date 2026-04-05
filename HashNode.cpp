#include "HashNode.h"

HashNode::HashNode(long long k, const University& v) 
    : key(k), value(v), next(nullptr) {
}