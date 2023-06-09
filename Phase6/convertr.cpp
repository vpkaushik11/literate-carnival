#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;
// Structure to store a quadruple
struct Quadruple {
    string opcode;
    string arg1;
    string arg2;
    string result;

    Quadruple(string op, string a1, string a2, string res) {
        opcode = op;
        arg1 = a1;
        arg2 = a2;
        result = res;
    }
};

// Function to convert ICG to Quadruples
vector<Quadruple> icg_to_quadruples(vector<vector<string> > icg) {
    vector<Quadruple> quadruples;

    // Map to keep track of temporary variables
    map<string, int> temp_var_count;
    for (int i = 0; i < icg.size(); i++) {
        vector<string> code = icg[i];

        // Check the operator and generate the appropriate quadruple
        if (code[3] == "+") {
            // Addition operation
            // string temp_var = "t" + to_string(temp_var_count["t"]);
            // temp_var_count["t"]++;
            quadruples.push_back(Quadruple("+", code[2], code[4], code[0]));
            // quadruples.push_back(Quadruple("=", temp_var, "", code[3]));
        } else if (code[3] == "-") {
            // Subtraction operation
            // string temp_var = "t" + to_string(temp_var_count["t"]);
            // temp_var_count["t"]++;

            quadruples.push_back(Quadruple("-", code[2], code[4], code[0]));
            // quadruples.push_back(Quadruple("=", temp_var, "", code[3]));
        } else if (code[3] == "*") {
            // Multiplication operation
            // string temp_var = "t" + to_string(temp_var_count["t"]);
            // temp_var_count["t"]++;

            quadruples.push_back(Quadruple("*", code[2], code[4], code[0]));
            // quadruples.push_back(Quadruple("=", temp_var, "", code[3]));
        } else if (code[3] == "/") {
            // Division operation
            // string temp_var = "t" + to_string(temp_var_count["t"]);
            // temp_var_count["t"]++;

            quadruples.push_back(Quadruple("/", code[2], code[4], code[0]));
            // quadruples.push_back(Quadruple("=", temp_var, "", code[3]));
        } else if (code[1] == "=") {
            // Assignment operation
            quadruples.push_back(Quadruple("=", code[2], "$", code[0]));
        } else if (code[0] == "goto") {
            // Goto statement
            quadruples.push_back(Quadruple("GOTO", "$", "$", code[1]));
        } else if (code[0] == "if") {
            // If statement
            string NOT = "!";
            if(code[1][0] == NOT[0] && code.size() == 4){
                if(code[1].size() == 4){ // checking if it of the form !(x) where x is any number
                    string x = "";
                    x += code[1][2];
                    quadruples.push_back(Quadruple("NOT", x, "$", code[3]));
                }else if(code[1][0] == NOT[0] && code.size() > 4){
                    string temp_var = "s" + to_string(temp_var_count["s"]);
                    temp_var_count["s"]++;

                    string a = code[1];
                    string b = code[3];
                    a.erase(0,2);
                    cout <<"Debug: " << a << endl;
                    b.pop_back();
                    
                    quadruples.push_back(Quadruple(code[2], a, b, temp_var));
                    quadruples.push_back(Quadruple(NOT, temp_var, "$", code[5]));
                }
            }else{
                char x = code[1][1];
                char y = code[3][0];
                string a = "";
                a+= x;
                string b = "";
                b+= y;
                quadruples.push_back(Quadruple(code[2], a, b, code[5]));
            }
        } else if (code.size() == 1) {
            // Label statement
            quadruples.push_back(Quadruple("label", "$", "$", code[0].substr(0, code[0].size() - 1)));
        }
    }

    return quadruples;
}

int main() {
    // Sample ICG
    fstream inp, out;
    inp.open("output.txt", ios::in);
    out.open("code.txt", ios::out);
    vector<vector<string> > ICG;
    vector<string> bla;
    if(inp.is_open()){
        string x;
        while (getline(inp, x))
        {
            if(x != ""){
                bla.push_back(x);
            }
        }
    }
    for(int i = 0; i < bla.size(); i++){
        vector<string> vec;

        istringstream iss(bla[i]);
        string word;

        while (iss >> word) {
            vec.push_back(word);
        }
        ICG.push_back(vec);
    }
    vector<Quadruple> q = icg_to_quadruples(ICG);
    string final;
    for(auto it : q){
        cout << it.opcode << " " << it.arg1 << " " << it.arg2 << " "<< it.result << endl;
        final.append(it.opcode + " " + it.arg1 + " " + it.arg2 + " " + it.result + "\n");
    }
    final.pop_back();
    out << final;
    return 0;
}