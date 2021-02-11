#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


int main() {
    string text;
    getline(cin,text);
    string ans;
    for (char c : text){
//        cout<<c;
        if(ispunct(c)){
            ans+=" ";
        } else {

            ans += (string (1,c));
        }
    }
    vector<string>  final={ "the", "a", "to", "if", "is", "it", "of", "and", "or", "an", "as", "i", "me", "my",
    "we", "our", "ours", "you", "your", "yours", "he", "she", "him", "his", "her", "hers", "its", "they", "them",
    "their", "what", "which", "who", "whom", "this", "that", "am", "are", "was", "were", "be", "been", "being",
    "have", "has", "had", "do", "does", "did", "but", "at", "by", "with", "from", "here", "when", "where", "how",
    "all", "any", "both", "each", "few", "more", "some", "such", "no", "nor", "too", "very", "can", "will", "just"};
    vector<string> res=split(ans," ");
    vector<string> final_ans;
    for (string word :res) {
        bool flag= false;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        for (string temp :final){
                if(word.compare(temp)==0){
                    flag=true;
                }
            }
            if(!flag){
                final_ans.push_back(word);
            }


    }
    for (string s:final_ans){
        cout<<" "<<s;
    }

    int i, found;
    ofstream write("M:\\uni\\thirdsummestur\\work\\5\\word_cloud.html");

    vector<string> stopwords = final;
    vector< pair<string, int> > list;
    vector< pair<string, int> >::iterator itarator;

    if(  !write.is_open()) {
        cout << "Error opening files." << endl;
        return 0;
    }

    for(string str: final_ans)
    {
       //  Checking for stopwords
        if (find(stopwords.begin(), stopwords.end(), str) != stopwords.end()) {
            continue;
        }

        found = 0;
        // Searching if word already exists
        for (i = 0; i < list.size(); i++) {
            if (str == list[i].first) {
                found = 1;
                break;
            }
        }

        if (found == 1) {		// Increment Frequency if exists
            list[i].second = list[i].second + 1;
        } else {				// Add to the list if does not exists
            list.push_back(make_pair(str, 1));
        }
    }

    write << "<html>\n<title>Word Cloud</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n</head>\n<body>\n<div class=\"para\">\n";

    for ( itarator = list.begin() ; itarator != list.end() ; itarator++) {

        if (itarator->second == 1) {
            write << "<span class=\"text1\">" + itarator->first + "</span>\n";
        }
        else if (itarator->second == 2) {
            write << "<span class=\"text2\">" + itarator->first + "</span>\n";
        }
        else if (itarator->second == 3) {
            write << "<span class=\"text3\">" + itarator->first + "</span>\n";
        }
        else if (itarator->second == 4) {
            write << "<span class=\"text4\">" + itarator->first + "</span>\n";
        }
        else if (itarator->second > 4) {
            write << "<span class=\"text5\">" + itarator->first + "</span>\n";
        }
    }

    write << "</div>\n</body>\n</html>";

    write.close();
    return 0;
}

