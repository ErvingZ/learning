#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
	public:
		string simplifyPath(string path){
			stack<string> s;
			int i=0;
			while(i<path.size())
			{
				if(path[i]=='/')
				{
					while(i<path.size() && path[i]=='/')
					{	
				 		++i;
					}
					break;
				}
				else if(path[i]=='.')
				{
					if(i==path.size()-1 || path[i+1]=='/')
					{
						++i;
						break;
					}
					else if(i==path.size()-2 && path[i+1]=='.' || i<path.size()-2 && path[i+1]=='.'
							&& path[i+2]=='/')
					{
						if(!s.empty())
							s.pop();
						i=i+2;
						break;
					}
				}
				string cur;
				while(i<path.size() && path[i]!='/')
				{
					cur.push_back(path[i]);
					++i;
				}
				s.push(cur);
			}
			// rebuild
			string res;
			while(!s.empty())
			{
				string cur="/"+s.top();
				s.pop();
				res=cur+res;
			}
			return res;
		}

};

int main()
{
	Solution a;
	string input="/home/";
	string r=a.simplifyPath(input);
	cout<<r;
	return 0;
}


