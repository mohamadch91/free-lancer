#include <iostream>
#include "film.h"
#include <vector>
#include <sstream>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

string * commandSeprator (string x){
stringstream ss(x);
string word;
string  words[6];
int  i =0;
while (ss >> word) {
words[i++]=word;
}
    return words;
}
void Swap (film **a, film* *b)
{
    film *temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort (std::vector<film*> &array)
{
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            if (array[j]->score > array[j+1]->score)
                Swap(&array[j], &array[j+1]);
        }
    }
}
void BubbleSortN (std::vector<film*> &array)
{
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            if (array[j]->name > array[j+1]->name)
                Swap(&array[j], &array[j+1]);
        }
    }
}
int main() {
   vector<film*> x;
   srand(time (NULL));
    string command;
    getline(cin,command);
    string *words=commandSeprator(command);
    while (true){
        if(words[0]=="add"){
            x.push_back(new film(words[1],stoi(words[2]),stoi(words[3]),stoi(words[4]),words[5],rand()));
        }
        if(words[0]=="remove"){
            string name=words[1];
            for (int i = 0; i <x.size() ; ++i) {
                if(x[i]->name=="name"){
                    //delete x[i];
                    x.erase(x.begin()+i);
                }
            }
        }
        if(words[0]=="sort-by"){
            if(words[1]=="score"){
                BubbleSort(x);
            }
            if(words[1]=="name"){
                BubbleSortN(x);
            }
        }
        if(words[0]=="show"){
            string name=words[1];
            for (int i = 0; i <x.size() ; ++i) {
                if(x[i]->name=="name"){
                    cout<<x[i]->name<<" "<<x[i]->id<<x[i]->country<<x[i]->score<<x[i]->date<<x[i]->time<<endl;
                }
            }
        }
        if(words[0]=="show-all"){
            for (int i = 0; i <x.size() ; ++i) {
                    cout<<x[i]->name<<" "<<x[i]->id<<x[i]->country<<x[i]->score<<x[i]->date<<x[i]->time<<endl;

            }
        }
        if(words[0]=="average-score"){
            int sum=0;
            for (int i = 0; i <x.size() ; ++i) {
                sum+=x[i]->score;

            }
            sum/=x.size();
            cout<<sum;
        }
        if(words[0]=="help"){
            cout<<"type add add <movie_name> <score> <data> <time> <country>"<<endl;
            cout<<"like add SpiderMan3 10 2014 120 Iran"<<endl;
            cout<<"for remove type remove <movie_name> \n like remove Spiderman3 "<<endl;
            cout<<"for sort by score type sort-by score \n and for sort by name type sort-by name"<<endl;
            cout<<"for show all details of one film show <movie_name> like : show spiderman3 "<<endl;
            cout <<" and for show all just type show-all"<<endl;
            cout<<" for find average score in films tyoe average-score"<<endl;
        }
        getline(cin,command);
        string *words=commandSeprator(command);
    }

    return 0;
}
