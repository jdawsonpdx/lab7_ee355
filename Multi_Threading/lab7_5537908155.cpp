#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <pthread.h>

using namespace std;

int main(int argc, char* argv[]){

	string filename = "input-Step1-2.txt";
	//string filename = "input-Step3.txt";
	ifstream infile;
    infile.open(filename.c_str());

    string buff;
    string lines;
    int num_lines;

    getline(infile, lines);
    istringstream(lines) >> num_lines;
    //cout << num_lines << endl;

    string *total = new string[num_lines];
    string *out = new string[num_lines];
    int i = 0;
    while(getline(infile, buff)){
    	//cout << buff << endl;
    	total[i] = buff;
    	i++;
        /*
        lname = buff.substr(0, buff.find(','));
        fname = buff.substr(buff.find(',')+2);
        */

        
    }
    infile.close();

    ofstream my_file;
    my_file.open("MT_Step1_out.txt");
    
    char prev_val;
    for(int i = 0; i < num_lines; i++){
    	prev_val = total[i].at(0);
    	for(int j = 0; j < total[i].length(); ++j){
    		if((j+1) >= total[i].length()){
    			break;
    		}

    		char curr_val = total[i].at(j);
    		char next_val = total[i].at(j+1);

    		if(j != 0){
    			prev_val = total[i].at(j-1);
    		}
    		
    		
    		if((next_val == '[') || (j == 0)){
    			

    			stringstream str;
    			str << curr_val;
    			int i_curr_val;
    			str >> i_curr_val;
    			
    			for(int k = j+1; k < (i_curr_val + j + 1); k++)
    			{
    				//cout << "k=" << k << " " << "curr_val=" << i_curr_val << endl;
    				int z = j+2;
    				next_val = total[i].at(z);
    				//curr_val = total[i].at(z);
    				while(next_val != ']')
    				{
    					curr_val = total[i].at(z);
    					//cout << curr_val;
    					my_file << curr_val;
    					next_val = total[i].at(z+1);
    					z++;
    				}
    				
    			}
    
    		}
			
    		/*
    		if(next_val == ']'){
    			cout << "here";
    		}

    		else{
    			cout << curr_val;
    		}
    		*/
    	}
    	//cout << endl;
    	my_file << endl;
    	//cout << "hey " << endl;

    }
    

    //cout << total[1].at(0) << endl;;

    //cout << total[5] << endl;

    my_file.close();
    
    


    delete[] total;
	return 0;
}