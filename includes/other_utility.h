/*THIS FILE CONTAIN HELPER FUNCTION USED IN MODULES OTHER THAT MAIN.CPP*/

#pragma once

#include <string>
#include <vector>
#include <cctype>

/* HELPER FUNCTION FOR SEARCH CONTACTS BY NAME
    IT TAKES ARGUMENT AS REFERENCE AND CONVERTS THE INPUT TO LOWERCASE IN PLACE
    RETURN NOTHING */
void toLowerCase(std::string& query)
{
    for(char &c: query)
    {
        c = static_cast<char>(std::tolower(static_cast<unsigned char> (c)));
    }
}

/* RECURSIVE BINARY SEARCH TO FIND THE INDEX OF THE FIRST OCCURRENCE OF THE QUERY
    RETURNS THE INDEX OF FIRST OCCURRENCE*/
int binarySearch(const std::string& query,int start_index, int last_index, std::vector<Contact>& contacts)
{
    if(start_index > last_index)
        return -1;

    int mid = (start_index + last_index)/2;
    int contact_index = -1;
    int search_value;

    std::string lowercase_query = query;
    toLowerCase(lowercase_query);

    std::string lowercase_contact_name = contacts[mid].getName();
        toLowerCase(lowercase_contact_name);

    int compare = lowercase_contact_name.compare(0, query.length(), lowercase_query);

    if(compare == 0)
    {
        contact_index = mid;
        last_index = mid - 1;

        search_value = binarySearch(query, start_index, last_index, contacts);
        }
    else if(compare > 0)
    {
        search_value = binarySearch(query, start_index, mid - 1, contacts);
    }
    else if( compare < 0)
    {
        search_value = binarySearch(query, mid + 1, last_index, contacts);
    }

    if(search_value >= 0)
    {
        contact_index = search_value;
    }
    
    return contact_index;    
}

/*HELPER FUNCTION TO REDUCE CODE DUPLICATION
    DOES A LINEAR SEARCH FROM THE GIVEN INDEX TO THE FIRST MISMATCH OF THE QUERY IN THE GIVEN VECTOR
    RETURNS A VECTOR OF POINTER TO CONTACTS*/
std::vector<Contact*> linearSearchByName(const int index, const std::string& query, std::vector<Contact>& contacts)
{   
    std::vector<Contact*>found_contacts;
    
    std::string lowercase_query = query;
    toLowerCase(lowercase_query);

    bool first_match_status = false;
    bool mismatch_status = false;

    #if DEBUG
    std::cout << "First index: " << index << std::endl; 
    #endif

    for(int i = index; i < contacts.size(); i++)
    {
        std::string lowercase_contact_name = contacts[i].getName();
        toLowerCase(lowercase_contact_name);

        if(lowercase_contact_name.compare(0, lowercase_query.length(), lowercase_query) == 0)
        {
            first_match_status = true;
            mismatch_status = false;
            found_contacts.push_back(&contacts[i]);
        }
        else
        {
            mismatch_status = true;
        }

        if(first_match_status && mismatch_status)
        {
            break;
        }
    }
    return found_contacts;
}