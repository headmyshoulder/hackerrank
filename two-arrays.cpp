/*
 * main.cpp
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
    int num_of_testcase = 0;
    cin >> num_of_testcase;
    for( int test_case = 0 ; test_case < num_of_testcase ; ++test_case )
    {
        int N , K;
        cin >> N >> K;
        vector< int > a( N ) , b( N );
        for( int i=0 ; i<N ; ++i ) cin >> a[i];
        for( int i=0 ; i<N ; ++i ) cin >> b[i];
        
        std::sort( a.begin() , a.end() );
        std::sort( b.begin() , b.end() , []( auto x , auto y ) { return x > y; } );
        
        bool ok = true ;
        for( int i=0 ; i<N ; ++i )
        {
            if( a[i] + b[i] < K )
            {
                ok = false;
                break;
            }
        }
        cout << ( ok ? "YES" : "NO" ) << endl;
    }
    return 0;
}