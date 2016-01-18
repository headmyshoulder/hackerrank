/*
 * priyanka-and-toys.cpp
 * Date: 2016-01-16
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
//     int N = 5;
//     vector< int > w(N);
//     w[0] = 1; w[1] = 2; w[2] = 3; w[3] = 10; w[4] = 17;
    
    int N = 0;
    cin >> N;
    vector< int > w( N );
    for( int i=0 ; i<N ; ++i )
        cin >> w[i];
    std::sort( w.begin() , w.end() );

    int items = 0;
    for( int i=0 ; i<N ; )
    {
        int j=i+1;
        for( ; j<N ; ++j )
        {
            if( ( w[j] - w[j-1] ) > 4 ) break;
        }
        items += ( j - i - 1 ) / 4 + 1;
        i = j;
    }
    cout << items << endl;
    return 0;
}
