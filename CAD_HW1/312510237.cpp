#include <bits/stdc++.h>
using namespace std;
//////////Combine Implicant To Prime Implicant/////
set<string>::iterator iter;

class implicant
{
public:
    string binary;
    set<int> covermap;
    bool prime;
    implicant(string str, int num)
    {
        binary = str;
        prime = true;
        covermap.insert(num);
    }

    implicant(string str)
    {
        binary = str;
        prime = true;
    }
};

class comp
{
public:
    bool operator()(const implicant *a, const implicant *s)
    {
        return (a->binary > s->binary);
    }
};

class compstr
{
public:
    bool operator()(const string a, const string s)
    {
        return (a > s);
    }
};

class QMC
{
private:
    int var;
    list<int> dc_set, on_set;
    set<implicant *, comp> howmany1[9];
    set<implicant *, comp> prime_implicant;
    set <string,compstr> min_cover;
    unordered_map<int, vector<implicant *>> minterm_to_implicant;
    vector<vector<string>> POS;
    vector<set<string>> SOP_total;
    set<string> SOP_1;
public:
    void Set_var(int);
    void Insert_dcset(int);
    void Insert_onset(int);
    void Show_onset();
    void Insertto1(int);
    void Showmany1();
    int Findprime();
    void Write_file(string);
    void Find_essential_prime();
    void Show_rest_implicant();
    void Find_POS();
    void Do_Petrick();
    void Petrick(set<string> &, int, int);
    string Get_SOP_string(set<string> &);
    void Find_min_literals();
    int Find_total_interals();
};

void QMC::Set_var(int v)
{
    var = v;
}

void QMC::Insert_dcset(int v)
{
    dc_set.push_back(v);
}

void QMC::Insert_onset(int v)
{
    on_set.push_back(v);
}

void QMC::Show_onset()
{
    cout << "on set: ";
    for (auto &x : on_set)
    {
        cout << x << " ";
    }
    cout << endl;
}

void QMC::Insertto1(int num)
{
    string str;
    implicant *ptr;
    int x = num;
    int num_1 = 0;
    for (int i = 0; i < var; i++)
    {
        if (num % 2)
        {
            str = '1' + str;
            num_1++;
        }
        else
        {
            str = '0' + str;
        }
        num /= 2;
    }
    ptr = new implicant(str, x);
    howmany1[num_1].insert(ptr);
}

void QMC::Showmany1()
{
    cout << "//////Showmany1//////" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "Group " << i << ": ";
        for (auto &y : howmany1[i])
        {
            cout << y->binary << " ";
        }
        cout << endl;
    }

    cout << "///////Prime implicant/////" << endl;
    cout << "Prime implicant: ";
    for (auto &y : prime_implicant)
    {
        cout << y->binary << ": ";
        for (auto &x : y->covermap)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int QMC::Findprime()
{
    set<implicant *, comp> tmp_list;
    string cmp;          // combined implicant
    int dif;             // compare two implicant how many different
    int combine_num = 0; // how many implicant combined in this round
    for (int i = 0; i <= var; i++)
    {
        for (auto &less : howmany1[i])
        {
            for (auto &more : howmany1[i + 1])
            {
                for (int j = 0; j < var; j++)
                {
                    if (dif > 1) // early stop
                    {
                        break;
                    }

                    if (less->binary[j] == more->binary[j])
                    {
                        cmp = cmp + less->binary[j];
                    }
                    else
                    {
                        cmp = cmp + "-";
                        dif++;
                    }
                }

                if (dif == 1) // only 1 difference
                {
                    combine_num++;
                    less->prime = false;
                    more->prime = false;
                    implicant *ptr = new implicant(cmp);
                    for (auto &x : less->covermap)
                    {
                        ptr->covermap.insert(x);
                    }
                    for (auto &x : more->covermap)
                    {
                        ptr->covermap.insert(x);
                    }
                    tmp_list.insert(ptr);
                }
                dif = 0;  // reload
                cmp = ""; // reload
            }
            if (less->prime == true)
            {
                prime_implicant.insert(less);
            }
        }
        howmany1[i] = tmp_list;
        tmp_list.clear();
    }
    return combine_num;
} // end Findprime

void QMC::Write_file(string fileout)
{
    ofstream ofs;
    ofs.open(fileout);
    char alphbet[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int count = 0;
    int total_literal = Find_total_interals();
    if (!ofs.is_open())
    {
        cout << "Failed to open file.\n";
    }
    ofs << ".p " << prime_implicant.size() << endl;
    for (const auto &e : prime_implicant) // write prime implicant
    {
        if (count == 15)
            break;
        for (int i = 0; i < var; i++)
        {
            if (e->binary[i] == '1')
            {
                ofs << alphbet[i];
            }
            else if (e->binary[i] == '0')
            {
                ofs << alphbet[i] << "'";
            }

            if (i == var - 1)
                ofs << endl;
        }
        count++;
    }
    
    ofs << "\n.mc " << min_cover.size() << endl;
    for (const auto &e : min_cover) // write min_cover
    {
        for (int i = 0; i < var; i++)
        {
            if (e[i] == '1')
            {
                ofs << alphbet[i];
            }
            else if (e[i] == '0')
            {
                ofs << alphbet[i] << "'";
            }

            if (i == var - 1)
                ofs << endl;
        }
    }
    ofs << "literal=" <<total_literal ;
    ofs.close();
}

void QMC::Find_essential_prime()
{
    int num;
    implicant *ptr;
    set<int> delete_term;
    for (auto &on : on_set)
    {
        num = 0;
        for (auto &prime : prime_implicant)
        {
            auto it = find(prime->covermap.begin(), prime->covermap.end(), on);
            if (it != prime->covermap.end())
            {
                num++;
                ptr = prime;
                minterm_to_implicant[on].push_back(prime);
            }
        }
        if (num == 1)
        {
            min_cover.insert(ptr->binary); 
            for (auto &minterm : ptr->covermap)
            {
                delete_term.insert(minterm);
            }
        }
    }

    for (auto &x :delete_term)
        {
            minterm_to_implicant.erase(x);
        } 
    
}

void QMC::Find_POS()
{
    for (auto &minterm : minterm_to_implicant)
    {
        vector<string> total;
        for (auto &implicant : minterm.second)
        {
            total.push_back(implicant->binary);
        }
        POS.push_back(total);
    }
}

void QMC::Do_Petrick()
{
    set<string> ss;
    Petrick(ss, 0, POS.size());
}

void QMC::Petrick(set<string> &prod, int i, int max)
{
    if (i == max)
    { // interruption condition
        string s = Get_SOP_string(prod);
        if (SOP_1.find(s) == SOP_1.end()){
            SOP_1.insert(s); 
            SOP_total.push_back(prod); // SOP_total = total Product
        }
    }

    else {
        int size = POS[i].size();
        for (int j = 0; j < size; j++){
            if (prod.find(POS[i][j]) == prod.end()) {// not found
                //cout << "i = " << i << "j = " << j << "size = " << size << "POS[i][j] = " << POS[i][j] << endl;
                prod.insert(POS[i][j]);
                Petrick(prod, i + 1, max);
                //cout << "i = " << i << "j = " << j << "size = " << size << "POS[i][j] = " << POS[i][j] << endl;
                prod.erase(POS[i][j]);
            }
            else // found
                Petrick(prod, i + 1, max);
        }
    }    
}

string QMC::Get_SOP_string(set<string> &temp)
{
    stringstream s_temp;

    for (iter = temp.begin(); iter != temp.end(); iter++)
        s_temp << *iter;
    string s_out;
    //cout << s_temp << endl;
    s_temp >> s_out;
    return s_out;
}

void QMC::Find_min_literals(){
    int min_literal = 10000;
    int min_cover_num = 10000;
    set <string> best_SOP;
    for (auto &product:SOP_total){
        int literal = 0;
        int cover_num = 0;
        for (auto &prime :product){ // count literal in product
            cover_num = prime.size();
            for (auto &lit:prime){
                if (lit != '-'){
                    literal ++;
                }
            }
        }
        if (cover_num <= min_cover_num)
            min_cover_num = cover_num;
            if (literal < min_literal){ // update min_literal and best product
                best_SOP = product;
                min_literal = literal;
            }
    }

    
    for(auto &x:best_SOP){ // update rest prime implicant to min cover
        min_cover.insert(x);
    }
}

int QMC::Find_total_interals(){
    int literal = 0;
    for (auto &prime:min_cover){
            for (auto &lit:prime){
                if (lit != '-'){
                    literal ++;
                }
            }
        }
    return literal;
}


int main(int argc, char *argv[])
{
    ifstream ifs;
    string s, s1;
    int variable_num, on_num, dc_num;
    int find_prime_num = 1;
    ifs.open(argv[1]);
    if (!ifs.is_open())
    {
        cout << "Failed to open file.\n";
        return 1; // EXIT_FAILURE
    }

    QMC twolevel;

    while (ifs >> s) // read file
    {
        if (s == ".i") ///// input variable number
        {
            ifs >> variable_num;
            twolevel.Set_var(variable_num);
        }
        if (s == ".m")
        {
            ifs >> s1;
            while (s1 != ".d") ///// input on set number
            {
                on_num = stoi(s1);
                twolevel.Insert_onset(on_num);
                twolevel.Insertto1(on_num);
                ifs >> s1;
            }
            while (ifs >> dc_num) ///// input dont care set number
            {
                twolevel.Insert_dcset(dc_num);
                twolevel.Insertto1(dc_num);
            }
        }
    }


    while (find_prime_num > 0) /// find prime implicant
    {
        find_prime_num = twolevel.Findprime();
    }
    twolevel.Find_essential_prime();
    twolevel.Find_POS();
    twolevel.Do_Petrick();
    twolevel.Find_min_literals();
    twolevel.Write_file(argv[2]); 
    ifs.close();
    return 0;
}
