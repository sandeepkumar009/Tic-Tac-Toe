#include <iostream>
#include <vector>

using namespace std;

class play
{
public:
    vector<char> current_screen = {'1', '2', '3',
                                   '4', '5', '6',
                                   '7', '8', '9'};
    vector<string> players_name = {"player1", "player2"};
    vector<char> mark = {'X', 'O'};

    void display_current_screen()
    {
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "| " << current_screen[i*3] << " | " << current_screen[i*3 + 1] << " | " << current_screen[i*3 + 2] << " |" << endl;
            cout << endl;
        }
    }

    bool check_winning(int x)
    {
        if(current_screen[0] == current_screen[1] && current_screen[1] == current_screen[2]
        || current_screen[3] == current_screen[4] && current_screen[4] == current_screen[5]
        || current_screen[6] == current_screen[7] && current_screen[7] == current_screen[8]
        || current_screen[0] == current_screen[3] && current_screen[3] == current_screen[6]
        || current_screen[1] == current_screen[4] && current_screen[4] == current_screen[7]
        || current_screen[2] == current_screen[5] && current_screen[5] == current_screen[8]
        || current_screen[0] == current_screen[4] && current_screen[4] == current_screen[8]
        || current_screen[2] == current_screen[4] && current_screen[4] == current_screen[6])
        {
            cout<<players_name[x]<<" WON THE GAME:"<<endl;
            return true;
        }
        else
            return false;
    }
};

int main()
{
    play p;
    cout<<"Enter player1 name: ";
    getline(cin, p.players_name[0]);
    cout<<"Enter player2 name: ";
    getline(cin, p.players_name[1]);

    cout<<"'X': "<<p.players_name[0]<<endl;
    cout<<"'O': "<<p.players_name[1]<<endl;

    p.display_current_screen();

    int x=0, n;
    while(1)
    {
        x = (x+1)%2;
        cout<<p.players_name[x]<<" choise: ";
        cin>>n;
        p.current_screen[n-1] = p.mark[x];

        p.display_current_screen();
        if(p.check_winning(x))
            break;
    }
}