// Main.cpp

#include "OpenAddressing.hpp"
#include <iostream>

using namespace std;

int main (void) {
    HashTable hash_ (11);

    hash_.AddNode (new HashNode ("MSFT", "Microsoft Corporation"));
    hash_.AddNode (new HashNode ("JAVA", "Sun Microsystems"));
    hash_.AddNode (new HashNode ("REDH", "Red Hat Linux"));
    hash_.AddNode (new HashNode ("APAC", "Apache Org"));
    hash_.AddNode (new HashNode ("ZYMZZ", "Unisys Ops Check")); // collision with "APAC". upper node.
    hash_.AddNode (new HashNode ("IBM", "IBM Ltd."));
    hash_.AddNode (new HashNode ("ORCL", "Oracle Corporation"));
    hash_.AddNode (new HashNode ("CSCO", "Cisco Systems, Inc."));
    hash_.AddNode (new HashNode ("GOOG", "Google Inc."));
    hash_.AddNode (new HashNode ("YHOO", "Yahoo! Inc."));
    hash_.AddNode (new HashNode ("NOVL", "Novell, Inc."));

    cout << endl;
    cout << "Key: MSFT, Value: " << hash_.GetNodeValue("MSFT") << endl; 
    cout << "Key: REDH, Value: " << hash_.GetNodeValue("REDH") << endl;
    cout << "Key: APAC, Value: " << hash_.GetNodeValue("APAC") << endl;
    cout << "Key: ZYMZZ, Value: " << hash_.GetNodeValue("ZYMZZ") << endl;
    cout << "Key: JAVA, Value: " << hash_.GetNodeValue("JAVA") << endl;
    cout << "Key: IBM, Value: " << hash_.GetNodeValue("IBM") << endl;
    cout << "Key: ORCL, Value: " << hash_.GetNodeValue("ORCL") << endl;
    cout << "Key: CSCO, Value: " << hash_.GetNodeValue("CSCO") << endl;
    cout << "Key: GOOG, Value: " << hash_.GetNodeValue("GOOG") << endl;
    cout << "Key: YHOO, Value: " << hash_.GetNodeValue("YHOO") << endl;
    cout << "Key: NOVL, Value: " << hash_.GetNodeValue("NOVL") << endl;
    
    cout << endl;
    hash_.PrintHashTable ();

    return 0;
}