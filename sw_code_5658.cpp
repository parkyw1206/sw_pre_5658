#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,N,K,answer;
	char temp, lastIndex;
    unsigned int x;
	stringstream ss;
    vector<char> v;
    vector<pair<unsigned int,string>> numKey;
	vector<string> s;
    int lenEach;
    
    cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
        
        numKey.clear();
        v.clear();        
        for(int i = 0 ; i < N ; i++){
        	cin >> temp;
            v.push_back(temp);
        }
        string tempStr = "";
        lenEach = N/4;
        for(int i = 0 ; i <lenEach ; i++){
            tempStr = "";
        	for(int j = 0 ; j < N; j++){
            	if(j%lenEach == (lenEach-1)){
                	tempStr.push_back(v[j]);
                    if(find(s.begin(),s.end(),tempStr) == s.end()){
	                    s.push_back(tempStr);
                        lastIndex = v[j];
                        x = stoul(tempStr, nullptr, 16);
		                numKey.push_back(make_pair(x,tempStr));
                    }
                	tempStr = "";
                }
                else{
                	tempStr.push_back(v[j]);
                }
            }
            v.emplace(v.begin(),lastIndex);
            v.pop_back();
        }
       
        sort(numKey.begin(),numKey.end());
        if(numKey.size() < K)
      	  cout << "#" << test_case << " " << 0<< endl;
        else
	      cout << "#" << test_case << " " << numKey[numKey.size()-K].first<< endl;
        
        numKey.clear();
       	v.clear();
        s.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}