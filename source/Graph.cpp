void dotParse(vector<string> vn , vector <string> vi , vector<vector <string>> vf , string fileName){
    ofstream outdata(fileName);
    char q ='"' ;
    vector<string> vtest;
    outdata<< "digraph G {" << endl;
    for(int i =0 ; i<vn.size() ; i++){
        vtest = vf[i];
        outdata << i+1 <<  "[label = "   << q  << vn[i]  << " | " << "id=" << vi[i] << q << "]" << endl ;
        outdata << i+1 << "->  {" ;
        if(vtest.size()==0){
            outdata<<"}"<<endl;
        }
        for(int j =0 ; j<vtest.size() ; j++){
            if ( j == vtest.size() - 1){
                outdata << vtest[j];
                outdata << "}" << endl;
            }
            else{
              outdata << vtest[j] << "," ;
            }
        }
    }
    outdata <<"}";
}

void vectorextract(string in,string out){
	ifstream indata(in);
	ofstream outdata(out);
	string line;
    stack<string> Tags;
    vector<string> ids;
    vector<vector<string>> followers;
    vector<string> minifollowers;
    vector<string> names;
    int i =0;
	while (getline(indata,line)){
        int id =line.find("<id>");
        int follow = line.find("<follow");
        int name = line.find("<name>");
        int nameEnd = line.find("</name>");
        int openTag = line.find("<");
        int closeTag = line.find(">");
        string tag = line.substr(openTag+1,(closeTag-openTag-1));
        if(follow>=0){
            Tags.push(line.substr(follow+1,line.size()-2-follow));
        }
        if(openTag>=0 && Tags.empty()==false){
            if(tag =="/"+Tags.top()){
                Tags.pop();
                }
            }
        if(id>=0 && Tags.empty()==false){
            if(Tags.top()=="follower"){
                minifollowers.push_back(line.substr(id+4,1));
            }
        }
        if(tag == "/followers") {
            followers.push_back(minifollowers);
            minifollowers.clear();
        }
        if(id>=0 &&Tags.empty()==true){
            ids.push_back(line.substr(id+4,1));
        }
        if(name>=0){
            names.push_back(line.substr(name+6,(nameEnd-(name+6))));
        }
        /*if(Tags.empty()==false){
            cout<<Tags.top()<<endl;
        }*/
    }
    dotParse(names,ids,followers,out);

	indata.close();
}

