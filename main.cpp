#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <sstream>

using namespace std;

vector<vector<string>*>* read(int n,int m){
    vector<vector<string>*> *x;
    x=new vector<vector<string>*>(15);
    for (int i = 0; i <15 ; ++i) {
        auto z=new vector<string>();
        (*x)[i]=z;
    }
    ifstream file;
    file.open ("M:\\uni\\thirdsummestur\\work\\4\\input.txt");
    if (!file.is_open()) return x;

    string word;
    while (file >> word)
    {
//        cout<<word<<endl;
       int len=word.length();
       if((len<=n|| len<=m)&&len!=0) {
           x->at(len-1)->push_back(word);
       }

    }
 
    return x;
}
int main() {
    srand (time(NULL));
    cout<<"please enter row and column  number : ";
    int row,column;
    cin>>row;
    cin>>column;

    vector<vector<string>*>* words ;

    words=read(row,column);

    char  map[row][column];
    //initialize map
    for (int k = 0; k <row ; ++k) {
        for (int i = 0; i <column ; ++i) {
            map[k][i]='X';
        }
    }
    // number of black boxes is row
    // make black boxes with random
    for (int i = 0; i <row ; ++i) {
        int x,y;
        //use 1 char to full black boxes
        x=rand()%row;
        y=rand()%row;
        while (map[x][y]=='1'){
            x=rand()%row;
            y=rand()%column;
        }
        map[x][y]='1';
    }
    for (int m = 0; m <row ; ++m) {
        for (int i = 0; i <column ; ++i) {
            cout<<" "<<map[m][i];

        }
        cout<<endl;

    }
    cout<<endl<<endl;
    int counter=0;
    //qesmat amodi
    for (int l = 0; l <2 ; ++l) {
        for (int i = 0; i <row ; ++i) {
            if (map[i][l]!='X')
                continue;
            int emptyX=0;
            for (int k = i; k <row ; ++k) {
                if(map[k][l]=='X')
                    emptyX++;
                if(map[k][l]=='1')
                    break;
            }
            cout<<emptyX<<endl;
            string word=words->at(emptyX-1)->at(rand()%words->at(emptyX-1)->size());
            cout<<word<<endl;
            for (int j = 0; j <emptyX ; ++j) {
                map[j+i][l]=word [j];
                for (int m = 0; m <row ; ++m) {
                    for (int i = 0; i <column ; ++i) {
                        cout<<" "<<map[m][i];

                    }
                    cout<<endl;

                }
                cout<<endl<<endl;
            }
        }
    }
    //qesmat haye ofoqi
    for (int j = 0; j <row ; ++j) {
        for (int i = 2; i <column ; ++i) {
            if(map[j][i]!='X')
                continue;
            // 2 soton avval amodi baqie ofoqi
            int emptyY=0;
            for (int k = i; k <column ; ++k) {
                if(map[j][k]=='X')
                    emptyY++;
            }

            string y;

             y = words->at(emptyY-1)->at(rand()%words->at(emptyY-1)->size());
            cout<<y<<endl;
            for (int s = 0; s <emptyY ; ++s) {
                map[j][s+i]=y [s];
            }
            counter++;
        }
    }
    for (int m = 0; m <row ; ++m) {
        for (int i = 0; i <column ; ++i) {
            cout<<map[m][i]<<" ";

        }
        cout<<endl;

    }
    // real print
    string text="";
    for (int n = 0; n <column*7+1 ; ++n) {
        cout<<"-";
        text.append("-");

    }
    cout<<endl;
    text.append("\n");
    int rowc,columnc=0;
    for (int i1 = 0; i1 <3*row ; ++i1) {
        if(i1%3!=1){
            cout<<" ";
            for (int i = 0; i <7*column+1 ; ++i) {
                if(i%7==0) {
                    cout << "|";
                    text.append("|");
                }
                else {
                    cout << " ";
                    text.append(" ");
                }
            }
            text.append("\n");
            cout<<endl;
        }
        else{

            text.append(" ");
            for (int i = 0; i <7*column+1 ; ++i) {
                if(i%7==4){
                if (map[i1/3][i/7] == '1') {
                    text.append("🚫");
                    cout << "🚫";
                } else
                    cout << map[i1/3][i/7];
                    text.append(string(1,map[i1/3][i/7]));
                }

                else
                 if(i%7==0) {
                     cout << "|";
                     text.append("|");
                 }
                else {
                     cout << " ";
                     text.append(" ");
                 }
            }
            text.append("\n");
            cout<<endl;
        }
    }
    for (int n = 0; n <column*7 ; ++n) {
        cout<<"-";
        text.append("-");

    }
    /*
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 2;
    int thickness = 3;

   cv:: Mat img(600, 800, CV_8UC3, Scalar::all(0));

    int baseline=0;
    Size textSize = getTextSize(text, fontFace,
                                fontScale, thickness, &baseline);
    baseline += thickness;

// center the text
    Point textOrg((img.cols - textSize.width)/2,
                  (img.rows + textSize.height)/2);

// draw the box
    rectangle(img, textOrg + Point(0, baseline),
              textOrg + Point(textSize.width, -textSize.height),
              Scalar(0,0,255));
// ... and the baseline first
    line(img, textOrg + Point(0, thickness),
         textOrg + Point(textSize.width, thickness),
         Scalar(0, 0, 255));

// then put the text itself
    putText(img, text, textOrg, fontFace, fontScale,
            Scalar::all(255), thickness, 8);
*/
//    int i, found;
//    string str;
//    ofstream write("M:\\uni\\thirdsummestur\\work\\4\\word_cloud.html");
//
//
//    if(  !write.is_open()) {
//        cout << "Error opening files." << endl;
//        return 0;
//    }
//
//    write << "<html>\n<title>Word Cloud</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n</head>\n<body>\n<div class=\"para\">\n";
//
//
//
//            write << "<span class=\"text1\">" + text + "</span>\n";
//
//
//
//    write << "</div>\n</body>\n</html>";
//
//    write.close();
return 0;
}

