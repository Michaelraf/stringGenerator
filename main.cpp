#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void writeInFile(vector<char>, int, fstream&);

int main()
{
    fstream file("pswd");
    int length(0);
    vector<char> pswd;
    int cursor(0);
    /**** initialisation de pswd ****/
    //Demande du nombre de caractère à l'utilisateur
    cout << "Saisir le nombre de caractère dans le mot de passe : ";
    cin >> length;
    cursor = length - 1;
    int check(0);
    for (int i = 0; i < length; i++)
    {
        pswd.push_back('a');
    }
    writeInFile(pswd, length, file);

    /**** Génération des possibilités pour pswd *****/
    while (true){
        while (cursor == length - 1 && pswd[cursor] != 'z'){
            pswd[cursor]++;
            writeInFile(pswd, length, file);
        }
        while(cursor>=0){
            if (pswd[cursor] == 'z'){
                if (cursor - 1 >= 0){
                    if (pswd[cursor - 1] != 'z'){
                        pswd[cursor - 1]++;
                        for(int i=cursor; i<length; i++){
                            pswd[i]='a';
                        }
                        writeInFile(pswd, length, file);
                        cursor = length-1;
                    }
                    else{
                        cursor--;
                    }
                }
                else{
                    break;
                }
            }
            else{
                pswd[cursor]++;
                writeInFile(pswd, length, file);
            }
        }
        
        check = 0;
        for(int i=0; i<length; i++){
            if(pswd[i]=='z'){
                check++;
            }
        }
        if(check == length)
            break;
    }

    return 0;
}

void writeInFile(vector<char> pswd, int length, fstream& file)
{
    for (int i = 0; i < length; i++)
        file << pswd[i];
    file << endl;
}