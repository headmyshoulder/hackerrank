/*
 * median-updates.cpp
 * Date: 2016-01-21
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void insert( vector< int >& numbers , int a )
{
    auto iter = std::upper_bound( numbers.begin() , numbers.end() , a );
    numbers.insert( iter , a );
}

bool remove( vector< int >& numbers , int a )
{
    auto iter = std::lower_bound( numbers.begin() , numbers.end() , a );
    if( ( iter == numbers.end() ) || ( *iter != a ) )
    {
        return false;
    }
    else
    {
        numbers.erase( iter );
        return true;
    }
}

void print_median( vector< int > const& numbers )
{
    if( numbers.empty() )
    {
        cout << "Wrong!" << endl;
    }
    else
    {
        if( ( numbers.size() % 2 ) == 0 )
        {
            int i = numbers.size() / 2;
            double x = 0.5 * ( double( numbers[ i -1 ] ) + double( numbers[ i ] ) );
            cout << x << endl;
        }
        else
        {
            cout << numbers[ numbers.size() / 2 ] << endl;
        }
    }
}

void print_numbers( vector< int > const& numbers )
{
    for( auto n : numbers )
        cout << n << " ";
    cout << endl << endl;
}

void median( vector<char> s , vector<int> X )
{
    vector< int > numbers;
    for( int i=0 ; i<s.size() ; ++i )
    {
        switch( s[i] )
        {
            case 'a':
                insert( numbers , X[i] );
                print_median( numbers );
                // print_numbers( numbers );
                break;
            case 'r':
                if( remove( numbers , X[i] ) )
                    print_median( numbers );
                else
                    cout << "Wrong!" << endl;
                // print_numbers( numbers );
                break;
        }
        
    }
}
int main(void)
{
    cout.precision( 14 );
    
    int N;
    cin >> N;

    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for(int i = 0; i < N; i++)
    {
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s,X);
    return 0;
}
