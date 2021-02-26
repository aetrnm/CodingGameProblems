#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

queue<int> q1;
queue<int> q2;

int card_p1;
int card_p2;

queue<int> tempDeckP1;
queue<int> tempDeckP2;

map<string, int> my_map = { { "2", 2 }, { "3", 3 }, { "4", 4 }, { "5", 5 }, { "6", 6 },
    { "7", 7 }, { "8", 8 }, { "9", 9 }, { "10", 10 }, { "J", 11 }, { "Q", 12 }, { "K", 13 }, { "A", 14}
};

int roundsCounter = 0;

void pat_checking()
{
    if (q1.size() < 4 || q2.size() < 4)
    {
        cout << "PAT" << endl;
        exit(0);
    }
}

void card_comparison()
{
    card_p1 = q1.front();
    card_p2 = q2.front();

    // take the next significant pair of cards
    tempDeckP1.push(q1.front());
    tempDeckP2.push(q2.front());
    q1.pop();
    q2.pop();

    if (card_p1 > card_p2)
    {
        while (!tempDeckP1.empty())
        {
            q1.push(tempDeckP1.front());
            tempDeckP1.pop();
        }
        while (!tempDeckP2.empty())
        {
            q1.push(tempDeckP2.front());
            tempDeckP2.pop();
        }
    }
    else if (card_p2 > card_p1)
    {
        while (!tempDeckP1.empty())
        {
            q2.push(tempDeckP1.front());
            tempDeckP1.pop();
        }
        while (!tempDeckP2.empty())
        {
            q2.push(tempDeckP2.front());
            tempDeckP2.pop();
        }
    }
    else
    {
        pat_checking();

        // skip three pairs that don't influence the result of the war
        for (int i = 0; i < 3; i++) {
            tempDeckP1.push(q1.front());
            q1.pop();
        }
        for (int i = 0; i < 3; i++) {
            tempDeckP2.push(q2.front());
            q2.pop();
        }

        card_comparison();
    }
}

void print_winner()
{
	if(q1.empty())
	{
        cout << 2 << " " << roundsCounter;
	}
    else
    {
        cout << 1 << " " << roundsCounter;
    }
}

int main()
{
    int n;
    cin >> n;
	for(int i = 0; i < n; i++)
	{
        string s;
        cin >> s;
        s.erase(prev(s.end())); //deleting last character (card suit)
        q1.push(my_map.operator[](s));
	}

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        s.erase(prev(s.end())); //deleting last character (card suit)
        q2.push(my_map.operator[](s));
    }

    while(!q1.empty() && !q2.empty())
    {
        card_comparison();
        roundsCounter++;
    }

    print_winner();
}