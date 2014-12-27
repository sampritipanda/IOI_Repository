// Naming Convention

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
class NamingConvention {
    public:
    string toCamelCase(string variableName);
};

string NamingConvention::toCamelCase(string variableName){
	std::string camelCase;
	bool next_camel_case = false;
	for ( std::string::iterator it=variableName.begin(); it!=variableName.end(); ++it) {
		if(*it == '_') {
			next_camel_case = true;
		}
		else if(next_camel_case == true){
			camelCase += toupper(*it);
			next_camel_case = false;
		}
		else {
			camelCase += *it;
		}
	}
	return camelCase;
}

int main() {
	NamingConvention test;
	std::string var_name = "the_variable_name_can_be_very_long_like_this";
	cout << test.toCamelCase(var_name) << endl;
}
