#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;
#include <string>

class BadLengthException : exception {

    private:

        int n;
        string msg;

    public:
    
        BadLengthException(int n) {
            this->n = n;
            this->msg = std::to_string(this->n);
        }

        virtual const char* what() {
            return msg.c_str();
        }
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}