#include <iostream>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>


using namespace std;

using set_type = map< int , int >;

void ice_cream_parlor( set_type const& costs , int M )
{
    for( auto iter = costs.begin() ; iter != costs.end() ; ++iter )
    {
        int c1 = iter->first;
        int c2 = M - c1;
        auto iter2 = costs.find( c2 );
        if( iter2 != costs.end() )
        {
            cout << iter->second + 1 << " " << iter2->second + 1 << endl;
            break;
        }
    }
}

int main()
{
    int T = 0;
    cin >> T;
    for( int t = 0 ; t < T ; ++t )
    {
        int M = 0 , N = 0;
        cin >> M >> N;
        set_type costs;
        for( int i=0 ; i<N ; ++i )
        {
            int tmp;
            cin >> tmp;
            costs.insert( make_pair( tmp , i ) );
        }
        ice_cream_parlor( costs , M );
    }

    return 0;
}
