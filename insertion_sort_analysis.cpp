/*
 * insertion_sort_analysis.cpp
 * Date: 2014-08-27
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using element_container = std::vector< int >;


size_t calculate_shifts( element_container& elements )
{
    if( elements.empty() ) return 0;
    
    size_t shifts = 0;
    auto first = elements.begin();
    for( auto first = elements.begin() + 1 ; first != elements.end() ; ++first )
    {
        auto iter = std::upper_bound( elements.begin() , first , *first );
        if( iter != first )
        {
            shifts += std::distance( iter , first );
            std::rotate( iter , first , first + 1 );
        }
    }
    return shifts;
}



int main( int argc , char *argv[] )
{
    size_t number_of_test_cases;
    cin >> number_of_test_cases;
    for( size_t i=0 ; i<number_of_test_cases ; ++i )
    {
        size_t number_of_elements;
        cin >> number_of_elements;
        element_container elements( number_of_elements );
        for( size_t i=0 ; i<number_of_elements ; ++i )
            cin >> elements[i];
        cout << calculate_shifts( elements ) << endl;
    }
    
    return 0;
}
// }