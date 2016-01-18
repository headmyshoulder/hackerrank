/*
 * largest-rectangle.cpp
 * Date: 2016-01-18
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main( int argc , char *argv[] )
{
    int N = 0;
    cin >> N;
    std::vector< int > buildings( N , 0 );
    std::stack< int > s;
    
    int max = 0;
    for( int i=0 ; i<N ; ++i )
    {
        int current = 0;
        cin >> current;
        buildings[i] = current;
        
        if( s.empty() || ( current > s.top() ) )
        {
            s.push( current );
        }
        else
        {
            
        }
    }
    return 0;
}
