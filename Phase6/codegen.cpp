#include <iostream>
#include <vector>
#include <string>
// #include <bits/stdc++.h>
#include <fstream>
#include <map>
#include <sstream>


using namespace std;

struct Quadruple
{
    string op;
    string arg1;
    string arg2;
    string result;
};

vector<Quadruple> quad_table;

void generate_code()
{
    ofstream asm_file("output.asm");
    int reg_count = 0;        // count of available registers
    map<string, int> reg_map; // map of variable names to registers
    for (int i = 0; i < quad_table.size(); i++)
    {
        Quadruple q = quad_table[i];
        if (q.op == "=")
        {
            if (reg_map.count(q.result)!=0)
            {
                asm_file << "MOV R" << reg_map[q.result] << ", " << q.arg1 << endl;
            }
            else
            {
                reg_map[q.result] = ++reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
            }
        }
        else if (q.op == "+")
        {
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // int r2 = reg_map.count(q.arg2) ? reg_map[q.arg2] : ++reg_count;
            // if(reg_map.count(q.arg1)!=0){
            //     if(q.arg1>='0' && q.arg1<='9'){
            //         regmap[arg1]=++reg_count;
            //         asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
            //     }
            //     if(arg2>='0' && arg2<='9'){
            //         regmap[arg2]=++reg_count;
            //         asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
            //     }
            // }
            int r1,r2,r3;
            if(reg_map.count(q.arg1)!=0 && reg_map.count(q.arg2)!=0){
                r1=reg_map[q.arg1];
                r2=reg_map[q.arg2];
            }
            if(reg_map.count(q.arg1)==0){
                reg_map[q.arg1] = ++reg_count;
                r1=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
            }
            if(reg_map.count(q.arg2)==0){
                reg_map[q.arg2] = ++reg_count;
                r2=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
            }
            // reg_map[q.result] = r1;
            if(reg_map.count(q.result)==0){
                reg_map[q.result] = ++reg_count;
                r3=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.result << endl;
            }
            else{
                r3=reg_map[q.result];
            }
            asm_file << "ADD R" << r3 << ", R" << r2 << ", R" << r1 << endl;
        }
        else if (q.op == "-")
        {
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // int r2 = reg_map.count(q.arg2) ? reg_map[q.arg2] : ++reg_count;
            int r1,r2,r3;
            if(reg_map.count(q.arg1)!=0 && reg_map.count(q.arg2)!=0){
                r1=reg_map[q.arg1];
                r2=reg_map[q.arg2];
            }
            if(reg_map.count(q.arg1)==0){
                reg_map[q.arg1] = ++reg_count;
                r1=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
            }
            if(reg_map.count(q.arg2)==0){
                reg_map[q.arg2] = ++reg_count;
                r2=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
            }
            // reg_map[q.result] = r1;
            if(reg_map.count(q.result)==0){
                reg_map[q.result] = ++reg_count;
                r3=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.result << endl;
            }
            else{
                r3=reg_map[q.result];
            }
            asm_file << "SUB R" << r3 << ", R" << r2 << ", R" << r1 << endl;
        }
        else if (q.op == "*")
        {
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // int r2 = reg_map.count(q.arg2) ? reg_map[q.arg2] : ++reg_count;
            int r1,r2,r3;
            if(reg_map.count(q.arg1)!=0 && reg_map.count(q.arg2)!=0){
                r1=reg_map[q.arg1];
                r2=reg_map[q.arg2];
            }
            if(reg_map.count(q.arg1)==0){
                reg_map[q.arg1] = ++reg_count;
                r1=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
            }
            if(reg_map.count(q.arg2)==0){
                reg_map[q.arg2] = ++reg_count;
                r2=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
            }
            // reg_map[q.result] = r1;
            if(reg_map.count(q.result)==0){
                reg_map[q.result] = ++reg_count;
                r3=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.result << endl;
            }
            else{
                r3=reg_map[q.result];
            }
            asm_file << "MUL R" << r3 << ", R" << r2 << ", R" << r1 << endl;
        }
        else if (q.op == "/")
        {
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // int r2 = reg_map.count(q.arg2) ? reg_map[q.arg2] : ++reg_count;
            int r1,r2,r3;
            if(reg_map.count(q.arg1)!=0 && reg_map.count(q.arg2)!=0){
                r1=reg_map[q.arg1];
                r2=reg_map[q.arg2];
            }
            if(reg_map.count(q.arg1)==0){
                reg_map[q.arg1] = ++reg_count;
                r1=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
            }
            if(reg_map.count(q.arg2)==0){
                reg_map[q.arg2] = ++reg_count;
                r2=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
            }
            // reg_map[q.result] = r1;
            if(reg_map.count(q.result)==0){
                reg_map[q.result] = ++reg_count;
                r3=reg_count;
                asm_file << "MOV R" << reg_count << ", " << q.result << endl;
            }
            else{
                r3=reg_map[q.result];
            }
            asm_file << "DIV R" << r3 << ", R" << r2 << ", R" << r1 << endl;
        }
        else if (q.op == "<")
        {
            int r1,r2,r3;
            int f1,f2;
            if(q.arg1>="0" && q.arg1<="9"){
                r1=stoi(q.arg1);
                f1=0;
            }
            else{
                if(reg_map.count(q.arg1)!=0){
                    r1=reg_map[q.arg1];
                }
                else{
                    reg_map[q.arg1] = ++reg_count;
                    r1=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
                }
                f1=1;
            }
            if(q.arg2>="0" && q.arg2<="9"){
                r2=stoi(q.arg2);
                f2=0;
            }
            else{
                if(reg_map.count(q.arg2)!=0){
                    r2=reg_map[q.arg2];
                }
                else{
                    reg_map[q.arg2] = ++reg_count;
                    r2=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
                }
                f2=1;
            }
            
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // reg_map[q.result] = r1;
            // if(reg_map.count(q.result)==0){
            //     reg_map[q.result] = ++reg_count;
            //     r3=reg_count;
            //     asm_file << "MOV R" << reg_count << ", " << q.result << endl;
            // }
            // else{
            //     r3=reg_map[q.result];
            // }

            if(f1==0 && f2==0){
                asm_file << "CMP #" << r1 << ", #" << r2 << endl;
                asm_file << "JL " << q.result << endl;
            }
            else if(f1==0 && f2==1){
                asm_file << "CMP #" << r1 << ", R" << r2 << endl;
                asm_file << "JL " << q.result << endl;
            }
            else if(f1==1 && f2==0){
                asm_file << "CMP R" << r1 << ", #" << r2 << endl;
                asm_file << "JL " << q.result << endl;
            }
            else{
                asm_file << "CMP R" << r1 << ", R" << r2 << endl;
                asm_file << "JL " << q.result << endl;
            }
            // asm_file << "CMP R" << r1 << ", " << q.arg2 << endl;
            // asm_file << "JL " << q.result << endl;
        }
        else if (q.op == "<=")
        {
            int r1,r2,r3;
            int f1,f2;
            if(q.arg1>="0" && q.arg1<="9"){
                r1=stoi(q.arg1);
                f1=0;
            }
            else{
                if(reg_map.count(q.arg1)!=0){
                    r1=reg_map[q.arg1];
                }
                else{
                    reg_map[q.arg1] = ++reg_count;
                    r1=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
                }
                f1=1;
            }
            if(q.arg2>="0" && q.arg2<="9"){
                r2=stoi(q.arg2);
                f2=0;
            }
            else{
                if(reg_map.count(q.arg2)!=0){
                    r2=reg_map[q.arg2];
                }
                else{
                    reg_map[q.arg2] = ++reg_count;
                    r2=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
                }
                f2=1;
            }
            
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // reg_map[q.result] = r1;
            // if(reg_map.count(q.result)==0){
            //     reg_map[q.result] = ++reg_count;
            //     r3=reg_count;
            //     asm_file << "MOV R" << reg_count << ", " << q.result << endl;
            // }
            // else{
            //     r3=reg_map[q.result];
            // }

            if(f1==0 && f2==0){
                asm_file << "CMP #" << r1 << ", #" << r2 << endl;
                asm_file << "JLE " << q.result << endl;
            }
            else if(f1==0 && f2==1){
                asm_file << "CMP #" << r1 << ", R" << r2 << endl;
                asm_file << "JLE " << q.result << endl;
            }
            else if(f1==1 && f2==0){
                asm_file << "CMP R" << r1 << ", #" << r2 << endl;
                asm_file << "JLE " << q.result << endl;
            }
            else{
                asm_file << "CMP R" << r1 << ", R" << r2 << endl;
                asm_file << "JLE " << q.result << endl;
            }
            // asm_file << "CMP R" << r1 << ", " << q.arg2 << endl;
            // asm_file << "JL " << q.result << endl;
        }
        
        else if (q.op == ">")
        {
            int r1,r2,r3;
            int f1,f2;
            if(q.arg1>="0" && q.arg1<="9"){
                r1=stoi(q.arg1);
                f1=0;
            }
            else{
                if(reg_map.count(q.arg1)!=0){
                    r1=reg_map[q.arg1];
                }
                else{
                    reg_map[q.arg1] = ++reg_count;
                    r1=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
                }
                f1=1;
            }
            if(q.arg2>="0" && q.arg2<="9"){
                r2=stoi(q.arg2);
                f2=0;
            }
            else{
                if(reg_map.count(q.arg2)!=0){
                    r2=reg_map[q.arg2];
                }
                else{
                    reg_map[q.arg2] = ++reg_count;
                    r2=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
                }
                f2=1;
            }

            if(f1==0 && f2==0){
                asm_file << "CMP #" << r1 << ", #" << r2 << endl;
                asm_file << "JG " << q.result << endl;
            }
            else if(f1==0 && f2==1){
                asm_file << "CMP #" << r1 << ", R" << r2 << endl;
                asm_file << "JG " << q.result << endl;
            }
            else if(f1==1 && f2==0){
                asm_file << "CMP R" << r1 << ", #" << r2 << endl;
                asm_file << "JG " << q.result << endl;
            }
            else{
                asm_file << "CMP R" << r1 << ", R" << r2 << endl;
                asm_file << "JG " << q.result << endl;
            }
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // reg_map[q.result] = r1;
            // asm_file << "CMP R" << r1 << ", " << q.arg2 << endl;
            // asm_file << "JG " << q.result << endl;
        }
        
        else if (q.op == ">=")
        {
            int r1,r2,r3;
            int f1,f2;
            if(q.arg1>="0" && q.arg1<="9"){
                r1=stoi(q.arg1);
                f1=0;
            }
            else{
                if(reg_map.count(q.arg1)!=0){
                    r1=reg_map[q.arg1];
                }
                else{
                    reg_map[q.arg1] = ++reg_count;
                    r1=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
                }
                f1=1;
            }
            if(q.arg2>="0" && q.arg2<="9"){
                r2=stoi(q.arg2);
                f2=0;
            }
            else{
                if(reg_map.count(q.arg2)!=0){
                    r2=reg_map[q.arg2];
                }
                else{
                    reg_map[q.arg2] = ++reg_count;
                    r2=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
                }
                f2=1;
            }

            if(f1==0 && f2==0){
                asm_file << "CMP #" << r1 << ", #" << r2 << endl;
                asm_file << "JGE " << q.result << endl;
            }
            else if(f1==0 && f2==1){
                asm_file << "CMP #" << r1 << ", R" << r2 << endl;
                asm_file << "JGE " << q.result << endl;
            }
            else if(f1==1 && f2==0){
                asm_file << "CMP R" << r1 << ", #" << r2 << endl;
                asm_file << "JGE " << q.result << endl;
            }
            else{
                asm_file << "CMP R" << r1 << ", R" << r2 << endl;
                asm_file << "JGE " << q.result << endl;
            }
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // reg_map[q.result] = r1;
            // asm_file << "CMP R" << r1 << ", " << q.arg2 << endl;
            // asm_file << "JG " << q.result << endl;
        }
        else if (q.op == "==")
        {
            int r1,r2,r3;
            int f1,f2;
            if(q.arg1>="0" && q.arg1<="9"){
                r1=stoi(q.arg1);
                f1=0;
            }
            else{
                if(reg_map.count(q.arg1)!=0){
                    r1=reg_map[q.arg1];
                }
                else{
                    reg_map[q.arg1] = ++reg_count;
                    r1=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
                }
                f1=1;
            }
            if(q.arg2>="0" && q.arg2<="9"){
                r2=stoi(q.arg2);
                f2=0;
            }
            else{
                if(reg_map.count(q.arg2)!=0){
                    r2=reg_map[q.arg2];
                }
                else{
                    reg_map[q.arg2] = ++reg_count;
                    r2=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
                }
                f2=1;
            }

            if(f1==0 && f2==0){
                asm_file << "CMP #" << r1 << ", #" << r2 << endl;
                asm_file << "JE " << q.result << endl;
            }
            else if(f1==0 && f2==1){
                asm_file << "CMP #" << r1 << ", R" << r2 << endl;
                asm_file << "JE " << q.result << endl;
            }
            else if(f1==1 && f2==0){
                asm_file << "CMP R" << r1 << ", #" << r2 << endl;
                asm_file << "JE " << q.result << endl;
            }
            else{
                asm_file << "CMP R" << r1 << ", R" << r2 << endl;
                asm_file << "JE " << q.result << endl;
            }
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // reg_map[q.result] = r1;
            // asm_file << "CMP R" << r1 << ", " << q.arg2 << endl;
            // asm_file << "JE " << q.result << endl;
        }
        else if (q.op == "!=")
        {
            int r1,r2,r3;
            int f1,f2;
            if(q.arg1>="0" && q.arg1<="9"){
                r1=stoi(q.arg1);
                f1=0;
            }
            else{
                if(reg_map.count(q.arg1)!=0){
                    r1=reg_map[q.arg1];
                }
                else{
                    reg_map[q.arg1] = ++reg_count;
                    r1=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg1 << endl;
                }
                f1=1;
            }
            if(q.arg2>="0" && q.arg2<="9"){
                r2=stoi(q.arg2);
                f2=0;
            }
            else{
                if(reg_map.count(q.arg2)!=0){
                    r2=reg_map[q.arg2];
                }
                else{
                    reg_map[q.arg2] = ++reg_count;
                    r2=reg_count;
                    asm_file << "MOV R" << reg_count << ", " << q.arg2 << endl;
                }
                f2=1;
            }

            if(f1==0 && f2==0){
                asm_file << "CMP #" << r1 << ", #" << r2 << endl;
                asm_file << "JNE " << q.result << endl;
            }
            else if(f1==0 && f2==1){
                asm_file << "CMP #" << r1 << ", R" << r2 << endl;
                asm_file << "JNE " << q.result << endl;
            }
            else if(f1==1 && f2==0){
                asm_file << "CMP R" << r1 << ", #" << r2 << endl;
                asm_file << "JNE " << q.result << endl;
            }
            else{
                asm_file << "CMP R" << r1 << ", R" << r2 << endl;
                asm_file << "JNE " << q.result << endl;
            }
            // int r1 = reg_map.count(q.arg1) ? reg_map[q.arg1] : ++reg_count;
            // reg_map[q.result] = r1;
            // asm_file << "CMP R" << r1 << ", " << q.arg2 << endl;
            // asm_file << "JE " << q.result << endl;
        }
        else if (q.op == "goto")
        {
            asm_file << "JMP " << q.result << endl;
        }
        else if (q.op == "label")
        {
            asm_file << q.result << ":" << endl;
        }
    }
    asm_file.close();
}

int main()
{
    fstream inp, out;
    inp.open("code.txt", ios::in);
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
        Quadruple x;
        x.op = vec[0];
        if(vec[1] == "$"){
            x.arg1 = " ";
        } else{
            x.arg1 = vec[1];
        }
        if(vec[2] == "$"){
            x.arg2 = " ";
        } else{
            x.arg2 = vec[2];
        }
        x.result = vec[3];
        // cout << x.op << " " << x.arg1 << " " << x.arg2 << " " << x.result << endl;
        quad_table.push_back(x);
    }
    // quad_table.push_back({"=", "5", " ", "x"});
    // quad_table.push_back({"=", "3", " ", "y"});
    // quad_table.push_back({"+", "x", "y", "z"});
    // quad_table.push_back({"<=", "t1", "10", "L1"});
    // quad_table.push_back({"*", "t1", "2", "t2"});
    // quad_table.push_back({"=", "t2", " ", "z"});
    // quad_table.push_back({"goto", " ", " ", "L2"});
    // quad_table.push_back({"label", " ", " ", "L1"});
    // quad_table.push_back({"/", "t1", "2", "t3"});
    // quad_table.push_back({"=", "t3", " ", "z"});
    // quad_table.push_back({"label", " ", " ", "L2"});
    generate_code();
    return 0;
}