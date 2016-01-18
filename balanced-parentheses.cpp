/*
 * balanced-parentheses.cpp
 * Date: 2016-01-18
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <stack>

using namespace std;

bool check_str( std::string const& str )
{
    std::stack< char > s;
    auto iter = str.begin();
    while( iter != str.end() )
    {
        char x = *iter++;
        switch( x )
        {
            case '[' :
            case '{' :
            case '(' :
                s.push( x );
                break;
            case ')':
                if( s.empty() ) return false;
                if( s.top() == '(' ) s.pop();
                else return false;
                break;
            case '}':
                if( s.empty() ) return false;
                if( s.top() == '{' ) s.pop();
                else return false;
                break;
            case ']':
                if( s.empty() ) return false;
                if( s.top() == '[' ) s.pop();
                else return false;
                break;
        }
    }
    return s.empty();
}

int main()
{
    int N = 0;
    cin >> N;
    for( int i=0 ; i<N ; ++i )
    {
        std::string str;
        cin >> str;
        cout << ( check_str( str ) ? "YES" : "NO" ) << endl;
    }
        
    return 0;
}
