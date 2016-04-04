#include <iostream> 
#include <vector>
#include <string>
#include <stdio.h> 
#include <fstream> 
using namespace std; 

void header_information(ofstream &out);
void title(ofstream &out);
void body(ofstream &out); 
string commands (string k);
void structure_loop(ofstream &out);
void logic();

int main()
{
	logic(); 
	
	return 0; 

}

void logic()
{
	string file_name; 
	cout << "Enter a filename without '.html': "; 
	cin >> file_name; 
	string user_file = file_name + ".html"; 
	ofstream outfile;
	outfile.open(user_file.c_str());
	outfile << "<html>" << endl;
	structure_loop(outfile); 
	outfile << "</html>" << endl; 
	outfile.close(); 
}
void title(ofstream &out)
{
	vector <string> value;
	cout << "Enter your Title: ";
	string k; 
	while (cin >> k)
	{
		if(cin.get() == '\n')
		{
			break;
		}
		value.push_back(k); 
		value.push_back(" "); 
	}
	string output; 
	for(int i = 0; i < value.size(); i++)
	{
		output += value[i]; 
	}

	out << "<head>" << endl;
	out << "<title> " << output << "</title>" << endl;
	out << "</head>" << endl; 

}
void header_information(ofstream &out)
{
	string k; 
	vector <string> value;
	int h_level;
	cout << "Please enter your header level (0 - 5): "; 
	cin >> h_level; 

	while(h_level < 0 || h_level > 5 || cin.fail())
	{
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Please enter a header level within the range of 0 to 5: "; 
		cin >> h_level; 
	}
	cout << "Enter your Header: ";
	while (cin >> k)
	{
		if(cin.get() == '\n')
		{
			break;
		}
		value.push_back(k); 
		value.push_back(" "); 
	}
	string output; 
	for(int i = 0; i < value.size(); i++)
	{
		output += value[i]; 
	}
	  out << "<h" << h_level+1 << ">" << output << "</h" << h_level+1 << ">\n";
}

void body(ofstream &out)
{
	string k, in; 
	vector <string> value; 

	cout << "Enter par start paragraph tag type /par to end" << endl; 
	cout << "Enter ul for unorder or ol for ordered list at the end of the list enter /ul or /ol to end the list" << endl;
	cout << "Enter li at the begginning of each list item followed by /li at the end" << endl; 
	cout << "Enter the body of your message: ";
		
	while (cin >> k)
	{
		if(cin.get() == '\n')
		{
			return;
		}
		in = commands(k); 
		value.push_back(in); 
		value.push_back(" "); 
	}
	string output; 
	for(int i = 0; i < value.size(); i++)
	{
		output += value[i]; 
	}
	out << "<body>" << endl;
	out << output << endl; 
	out << "</body>" << endl;
}

string commands (string k)
{
	if(k == "p")
	{
		k = "<p>"; 
	}
	else if(k == "/p")
	{
		k = "</p>";
	}
	else if(k == "l")
	{
		k = "<li>"; 
	}
	else if(k == "/l")
	{
		k = "</li>\n"; 
	}
	else if(k == "ul")
	{
		k = "<ul>";
	}
	else if(k == "/ul")
	{
		k = "</ul>"; 
	}
	else if(k == "ol")
	{
		k = "<ol>\n";
	}
	else if(k == "/ol")
	{
		k = "</ol>\n" ; 
	}
	return k; 
}
void structure_loop(ofstream &out)
{
	string value; 
	cout << "[T] title" << endl;
	cout << "[H] header" << endl; 
	cout << "[B] body" << endl;
	cout << "[Q] to quit" << endl; 
	cin >> value; 
	
	while(true)
	{
		if(value == "T" || value == "t")
		{
			title(out);
			//cin.clear();
		}
		else if(value == "H" || value == "h")
		{
			header_information(out); 	
			//cin.clear();
		}
		else if(value == "B" || value == "b")
		{
			body(out); 
			//cin.clear();
		}
		else if(value == "q" || value == "Q")
		{
			return; 
		}
		/*else
		{
			cout << "Wrong input\n";
			cout << "[T] title\n";
			cout << "[H] header\n"; 
			cout << "[B] body\n";
			cin >> value; 
		}*/
		
		cout << "[T] title" << endl;
		cout << "[H] header" << endl; 
		cout << "[B] body" << endl;
		cin >> value; 
	}
	
}