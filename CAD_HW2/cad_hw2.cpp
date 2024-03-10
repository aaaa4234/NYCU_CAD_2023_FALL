#include <bits/stdc++.h>
#include <string>

using namespace std;

class CELL;
class WIRE;




class LIB_DATA
{
private:

public:
    vector<double> out_capacitance;
    vector<double> in_transition;
    vector<double> nor_in_c;
    vector<vector<double>> nor_cell_rise;
    vector<vector<double>> nor_cell_fall;
    vector<vector<double>> nor_rise_transition;
    vector<vector<double>> nor_fall_transition;
    vector<double> nand_in_c;
    vector<vector<double>> nand_cell_rise;
    vector<vector<double>> nand_cell_fall;
    vector<vector<double>> nand_rise_transition;
    vector<vector<double>> nand_fall_transition;
    double inv_in_c;
    vector<vector<double>> inv_cell_rise;
    vector<vector<double>> inv_cell_fall;
    vector<vector<double>> inv_rise_transition;
    vector<vector<double>> inv_fall_transition;
    LIB_DATA()
    {
        out_capacitance = {0.001400, 0.003000, 0.006200, 0.012500, 0.025100, 0.050400, 0.101000};
        in_transition = {0.0208, 0.0336, 0.06, 0.1112, 0.2136, 0.4192, 0.8304};
        nor_in_c = {0.0105008, 0.0108106};
        nor_cell_rise = {{0.023104, 0.026347, 0.032439, 0.037211, 0.050187, 0.075629, 0.108930},
                         {0.027062, 0.029858, 0.036397, 0.042338, 0.055823, 0.083858, 0.119420},
                         {0.034333, 0.037002, 0.043649, 0.050318, 0.064815, 0.089926, 0.138270},
                         {0.048838, 0.051443, 0.053267, 0.064115, 0.083493, 0.112050, 0.170690},
                         {0.076172, 0.077668, 0.081485, 0.089780, 0.112630, 0.149040, 0.203590},
                         {0.133510, 0.134860, 0.138470, 0.146350, 0.162780, 0.209740, 0.279490},
                         {0.247770, 0.248880, 0.252340, 0.259710, 0.275960, 0.309680, 0.403930}};
        nor_cell_fall = {{0.017693, 0.020473, 0.024855, 0.029528, 0.034750, 0.038561, 0.030505},
                         {0.019856, 0.022665, 0.027792, 0.033415, 0.039820, 0.045554, 0.039165},
                         {0.024076, 0.026936, 0.032932, 0.040339, 0.048928, 0.057779, 0.054661},
                         {0.032280, 0.035141, 0.041568, 0.051796, 0.064313, 0.069003, 0.080192},
                         {0.048376, 0.051227, 0.057825, 0.070186, 0.089026, 0.098520, 0.118860},
                         {0.078389, 0.080130, 0.090011, 0.091689, 0.112830, 0.150920, 0.179760},
                         {0.142020, 0.143720, 0.147350, 0.154830, 0.170740, 0.213410, 0.290100}};
        nor_rise_transition = {{0.047372, 0.047388, 0.052910, 0.069558, 0.079757, 0.112950, 0.162980},
                               {0.055454, 0.057237, 0.061359, 0.076048, 0.089491, 0.122180, 0.178600},
                               {0.070803, 0.069305, 0.077650, 0.088390, 0.107060, 0.158050, 0.204620},
                               {0.097384, 0.095745, 0.106670, 0.113940, 0.137200, 0.176410, 0.237050},
                               {0.166060, 0.163680, 0.167160, 0.170000, 0.185930, 0.235810, 0.338230},
                               {0.296300, 0.290000, 0.290770, 0.299970, 0.295960, 0.342040, 0.431200},
                               {0.556050, 0.540720, 0.539690, 0.541850, 0.563770, 0.570260, 0.652330}};
        nor_fall_transition = {{0.017800, 0.020672, 0.025912, 0.038106, 0.054758, 0.087109, 0.140530},
                               {0.022110, 0.024126, 0.029235, 0.043016, 0.061952, 0.094784, 0.152170},
                               {0.029050, 0.032076, 0.035248, 0.050710, 0.073218, 0.110450, 0.170340},
                               {0.045602, 0.046546, 0.049838, 0.065112, 0.089226, 0.138180, 0.220760},
                               {0.077240, 0.077419, 0.079545, 0.087836, 0.115320, 0.180490, 0.259710},
                               {0.135930, 0.133980, 0.141400, 0.146810, 0.168520, 0.225280, 0.343700},
                               {0.259810, 0.254610, 0.253670, 0.262630, 0.277020, 0.332350, 0.443690}};
        nand_in_c = {0.00683597, 0.00798456};
        nand_cell_rise = {{0.020844, 0.024310, 0.030696, 0.039694, 0.048205, 0.072168, 0.101880},
                          {0.024677, 0.027942, 0.035042, 0.045467, 0.054973, 0.082349, 0.115390},
                          {0.032068, 0.035394, 0.042758, 0.055361, 0.065991, 0.090936, 0.138470},
                          {0.046811, 0.049968, 0.057164, 0.064754, 0.086481, 0.116760, 0.157440},
                          {0.073919, 0.078805, 0.080873, 0.091007, 0.116550, 0.157900, 0.214480},
                          {0.131620, 0.133630, 0.138300, 0.147930, 0.168500, 0.220320, 0.300540},
                          {0.246610, 0.248350, 0.252940, 0.262210, 0.282000, 0.324170, 0.427830}};
        nand_cell_fall = {{0.020382, 0.023257, 0.027894, 0.033548, 0.035740, 0.041790, 0.044857},
                          {0.024029, 0.026956, 0.032263, 0.039221, 0.042085, 0.050402, 0.056660},
                          {0.031269, 0.034119, 0.039869, 0.049176, 0.053737, 0.065333, 0.075780},
                          {0.045259, 0.047829, 0.053987, 0.057975, 0.072805, 0.089369, 0.109580},
                          {0.071393, 0.072867, 0.076097, 0.082901, 0.102690, 0.130350, 0.160910},
                          {0.127140, 0.128510, 0.131750, 0.138250, 0.152920, 0.192220, 0.245200},
                          {0.238460, 0.239670, 0.242900, 0.249230, 0.262520, 0.293170, 0.371160}};
        nand_rise_transition = {{0.030236, 0.032250, 0.038219, 0.052208, 0.080479, 0.107190, 0.151470},
                                {0.039514, 0.039353, 0.046985, 0.061163, 0.087011, 0.116970, 0.175150},
                                {0.051087, 0.053959, 0.058155, 0.070827, 0.109340, 0.152230, 0.206410},
                                {0.085969, 0.084220, 0.092301, 0.096621, 0.129250, 0.199410, 0.265970},
                                {0.153720, 0.147050, 0.154690, 0.160300, 0.179550, 0.248520, 0.357890},
                                {0.286690, 0.280220, 0.281210, 0.288880, 0.278630, 0.331600, 0.482560},
                                {0.552500, 0.535920, 0.534410, 0.535030, 0.556830, 0.542710, 0.659570}};
        nand_fall_transition = {{0.027802, 0.028745, 0.035327, 0.047243, 0.067704, 0.097889, 0.151650},
                                {0.034160, 0.036630, 0.041513, 0.054197, 0.079795, 0.110130, 0.165450},
                                {0.048764, 0.050279, 0.053838, 0.065970, 0.098021, 0.133030, 0.195920},
                                {0.076954, 0.077267, 0.077694, 0.089180, 0.115280, 0.172860, 0.238320},
                                {0.133070, 0.133160, 0.135080, 0.141060, 0.162490, 0.213700, 0.324300},
                                {0.247090, 0.241360, 0.245160, 0.250640, 0.263980, 0.319640, 0.446030},
                                {0.474440, 0.460220, 0.462840, 0.466540, 0.481330, 0.489290, 0.603170}};
        inv_in_c = 0.0109115;
        inv_cell_rise = {{0.013379, 0.016044, 0.019907, 0.022481, 0.031726, 0.040185, 0.050385},
                         {0.015250, 0.018376, 0.022972, 0.026053, 0.037050, 0.047418, 0.059875},
                         {0.018871, 0.022403, 0.028108, 0.032610, 0.045789, 0.059925, 0.076608},
                         {0.025970, 0.029306, 0.033033, 0.042608, 0.054479, 0.080008, 0.103940},
                         {0.040047, 0.040538, 0.045817, 0.058067, 0.076355, 0.099330, 0.146830},
                         {0.066295, 0.068558, 0.073341, 0.083717, 0.108210, 0.143970, 0.189040},
                         {0.122230, 0.124410, 0.129200, 0.138630, 0.159470, 0.208640, 0.279200}};
        inv_cell_fall = {{0.015975, 0.018648, 0.022904, 0.028037, 0.031885, 0.041402, 0.053623},
                         {0.018156, 0.021149, 0.026094, 0.032287, 0.036680, 0.048075, 0.062383},
                         {0.022594, 0.025590, 0.031664, 0.039739, 0.044932, 0.059061, 0.077439},
                         {0.031149, 0.034095, 0.040822, 0.051786, 0.060032, 0.076833, 0.102310},
                         {0.047947, 0.047918, 0.057692, 0.063035, 0.082424, 0.107350, 0.140340},
                         {0.079511, 0.081269, 0.085301, 0.093628, 0.116410, 0.154500, 0.202000},
                         {0.146040, 0.147720, 0.151580, 0.159670, 0.176810, 0.223720, 0.298480}};
        inv_rise_transition = {{0.017522, 0.021682, 0.028803, 0.041672, 0.052872, 0.081109, 0.128370},
                               {0.021980, 0.024661, 0.033109, 0.046939, 0.060235, 0.088586, 0.137120},
                               {0.029796, 0.032708, 0.038207, 0.056464, 0.078060, 0.099037, 0.155610},
                               {0.044871, 0.046301, 0.051610, 0.068661, 0.102220, 0.124680, 0.182110},
                               {0.076836, 0.076772, 0.076054, 0.089262, 0.128370, 0.186760, 0.232160},
                               {0.141700, 0.141210, 0.141980, 0.142120, 0.171260, 0.244100, 0.354290},
                               {0.270810, 0.266810, 0.269430, 0.274220, 0.274290, 0.332280, 0.473410}};
        inv_fall_transition = {{0.017349, 0.017893, 0.024178, 0.035104, 0.051821, 0.075654, 0.123160},
                               {0.018614, 0.022157, 0.027649, 0.040185, 0.059238, 0.085087, 0.133440},
                               {0.027419, 0.029372, 0.034899, 0.049446, 0.072893, 0.104290, 0.152460},
                               {0.043657, 0.044863, 0.049056, 0.060723, 0.091025, 0.132310, 0.185960},
                               {0.076530, 0.073661, 0.079082, 0.087928, 0.120850, 0.173160, 0.248810},
                               {0.137490, 0.135180, 0.137930, 0.149130, 0.165850, 0.229130, 0.339420},
                               {0.265330, 0.262480, 0.265530, 0.265920, 0.286880, 0.331030, 0.452580}};
    }
};

class CELL
{
private:
public:
    int which_cell; // 0:nor 1:inv 2:nand
    string name;
    WIRE *in1;
    WIRE *in2;
    WIRE *out;
    double out_capa;
    double transition_time;
    double delay;
    double total_delay;
    bool visited;
    bool is_first;
    bool fall_rise;
    WIRE * before_wire;
    CELL * before_cell;
    CELL(int cell_type, string gate_name, double o_c, WIRE * I1, WIRE * I2, WIRE * OUT)
    {
        which_cell = cell_type;
        name = gate_name;
        in1 = I1;
        in2 = I2;
        out = OUT;
        out_capa = o_c;
        transition_time = 0;
        delay = 0;
        total_delay = 0;
        visited = false;
        is_first = false;
        before_wire = NULL;
        before_cell = NULL;
    }
};

class WIRE
{
private:
    // string wire_name;
    // bool is_out;
    // CELL *input_cell = NULL;
    // vector <CELL*> output_cell;

public:
    string wire_name;
    bool is_out;
    bool is_input;
    CELL *front_cell = NULL;
    vector<CELL *> back_cell;
    WIRE(string n, bool need_out_capacitance, bool is_in)
    {
        wire_name = n;
        is_out = need_out_capacitance;
        is_input = is_in;
    }
};

int getnum(string s) // to catch the part of number of cell name
{
    string s_num = s.substr(1);
    return stoi(s_num);
}

bool capacitance_compare(CELL *cell1, CELL *cell2)
{
    if (cell1->out_capa > cell2->out_capa)
    {
        return true;
    }
    else if (cell1->out_capa == cell2->out_capa && getnum(cell1 -> name) < getnum(cell2 -> name))
    {
        return true;
    }
    return false;
}

bool delay_compare(CELL *cell1, CELL *cell2)
{
    if (cell1->delay > cell2->delay)
    {
        return true;
    }
    else if (cell1->delay == cell2->delay && getnum(cell1->name) < getnum(cell2->name))
    {
        return true;
    }
    return false;
}

bool total_delay_comapare(CELL *cell1, CELL *cell2){
    if (cell1-> total_delay > cell2-> total_delay)
    {
        return true;
    }
    return false;
}


class STA
{
private:
    vector<WIRE *> all_wire;
    unordered_map <string, WIRE *> name_wire;
    vector <CELL *> cell_vec;
    vector <CELL *> input_cell;
    vector <CELL *> output_cell;
    vector <CELL *> top_order;
    vector <WIRE *> longest_path;
    vector <WIRE *> shortest_path;
    LIB_DATA* data;
public:
    STA();
    void Read_circuit(string);
    void Show_All_Wire(void)
    {
        for (auto x : name_wire)
        {
            //cout << "Name: " << x.first << " Is output: " << x.second -> wire_name << endl;
            // if (x.second -> front_cell != NULL)
                // cout << "Front Gate Name: " <<x.second -> front_cell -> name << endl; 
            // for (auto y : x.second -> back_cell)
            // {
                // cout << "Back Gate Name: " <<y -> name << endl;
            // }
            
        }
    }
    void Calculate_output_capacitance(void);
    void Write_output_load_file(string);
    void Write_delay_file(string);
    void Write_path_file(string);
    void Show_input_cell(void);
    void Topological_sort(void);
    double Get_data_from_table(int , bool , bool , double , double);
    void Calulate_delay(void);
    void Find_delay_path(void);
};

STA::STA()
{
    data = new LIB_DATA;
}

void STA::Read_circuit(string f_lib)
{
    ifstream ifs;
    string str_tmp;
    string sub_string;
    ifs.open(f_lib);
    int state = 0; // 0:ok 1:notok
    while (getline(ifs, str_tmp))
    {
        sub_string = str_tmp;

        size_t found = sub_string.find("/*");
        size_t found_1 = sub_string.find("*/");
        //cout << sub_string << endl;

        if (found_1 != string::npos && state == 1)
        { // "*/" in "/*" next line
            sub_string = str_tmp.substr(found_1 + 2);
            state = 0;
        }
        //cout << state << endl;
        if (state == 1)
        { // in "/*" to find "*/"
            while (getline(ifs, str_tmp))
            {
                found_1 = str_tmp.find("*/");
                if (found_1 != string::npos)
                {
                    sub_string = str_tmp.substr(found_1 + 2);
                    state = 0;
                    break;
                }
            }
        }
        else
        { // not in "/*"
            found = sub_string.find("/*");
            if (found != string::npos)
            { // found "/*"
                if (found_1 != string::npos)
                { // "/*" and "*/" in same line
                    //string str_front = sub_string.substr(0,found);
                    //sub_string = str_front.substr(found_1 + 2);
                    cout << sub_string << endl;
                    sub_string.erase(found, found_1 - found + 2);
                    state = 0;
                }
                else
                { // "/*" and "*/" not in same line
                    sub_string = sub_string.substr(0, found);
                    state = 1;
                }
            }

            //cout << state << endl;

            found = sub_string.find("//");
            if (found != string::npos)
            { // found "//"
                sub_string = sub_string.substr(0, found);
            }

            //cout << sub_string << endl;
            
            found = sub_string.find("output");
            if (found != string::npos)
            { // found "output"
                sub_string = sub_string.substr(found + 6);
                string temp = "";
                for (int i = 0; i < sub_string.length(); i++)
                {
                    char ch = sub_string[i];
                    if (ch == ' ')
                        continue;
                    else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                        temp += ch;
                    else if ((ch == ',') || (ch == ';'))
                    {
                        WIRE *w = new WIRE(temp, true, false);
                        name_wire[temp] = w;
                        temp = "";
                    }
                }
            }

            found = sub_string.find("input");
            if (found != string::npos)
            { // found "input"
                sub_string = sub_string.substr(found + 5);
                string temp = "";
                for (int i = 0; i < sub_string.length(); i++)
                {
                    char ch = sub_string[i];
                    if (ch == ' ')
                        continue;
                    else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                        temp += ch;
                    else if ((ch == ',') || (ch == ';'))
                    {
                        WIRE *w = new WIRE(temp, 0 , true);
                        name_wire[temp] = w;
                        temp = "";
                    }
                }
            }

            found = sub_string.find("wire");
            if (found != string::npos)
            { // found "wire"
                sub_string = sub_string.substr(found + 4);
                string temp = "";
                for (int i = 0; i < sub_string.length(); i++)
                {
                    char ch = sub_string[i];
                    if (ch == ' ')
                        continue;
                    else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                        temp += ch;
                    else if ((ch == ',') || (ch == ';'))
                    {
                        WIRE *w = new WIRE(temp, 0 , false);
                        name_wire[temp] = w;
                        temp = "";
                    }
                }
            }

            //cout << sub_string << endl;

            found = sub_string.find("INVX1");
            if (found != string::npos)
            { // found "inverter"
                sub_string = sub_string.substr(found + 5);
                string name = "";
                string out = "";
                string in = "";
                string substr = "";
                found = sub_string.find("(");
                substr = sub_string.substr(0,found+1);
                for (int i = 0; i < substr.length(); i++) // get CELL name
                {
                    char ch = substr[i];
                    if (ch == ' ')
                        continue;
                    else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                        name += ch;
                    else if ((ch == '('))
                    {

                    }
                }
                
                
                found = sub_string.find(".ZN("); // Output
                substr = sub_string.substr(found+4);
                if (found != string::npos)
                {
                    //sub_string = sub_string.substr(found+4);
                    for (int i = 0; i < substr.length(); i++) // get Output name
                    {
                        char ch = substr[i];
                        if (ch == ' ')
                            continue;
                        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                            out += ch;
                        else if ((ch == ')'))
                        {
                            break;
                        }
                    }
                }

                found = sub_string.find(".I("); // Input
                substr = sub_string.substr(found+3);
                if (found != string::npos)
                {
                    //sub_string = sub_string.substr(found+3);
                    for (int i = 0; i < substr.length(); i++) // get Input name
                    {
                        char ch = substr[i];
                        if (ch == ' ')
                            continue;
                        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                            in += ch;
                        else if ((ch == ')'))
                        {
                            break;
                        }
                    }
                }

                //nor_in_c nand_in_c inv_in_c
                CELL *g = new CELL(1, name, 0, name_wire[in] , NULL , name_wire[out]);
                cell_vec.push_back(g);
                name_wire[out] -> front_cell = g;
                name_wire[in] -> back_cell.push_back(g);
                if (name_wire[in] -> is_input) {
                    input_cell.push_back(g);
                    g -> is_first = true;
                }
                if (name_wire[out] -> is_out) {
                    output_cell.push_back(g);
                }
                    
                //cout << "Cell name: " << name << " Out : " << name_wire[out] -> wire_name << " Input : " << name_wire[in] -> wire_name << endl;
            } // end INV

            found = sub_string.find("NANDX1");
            if (found != string::npos)
            { // found "nand"
                sub_string = sub_string.substr(found + 6);
                string name = "";
                string out = "";
                string in1 = "";
                string in2 = "";
                string substr = "";
                found = sub_string.find("(");
                substr = sub_string.substr(0,found+1);
                for (int i = 0; i < substr.length(); i++) // get CELL name
                {
                    char ch = substr[i];
                    if (ch == ' ')
                        continue;
                    else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                        name += ch;
                    else if ((ch == '('))
                    {
                        //cout << name << endl;
                    }
                }
                
                //cout << sub_string << endl;
                found = sub_string.find(".ZN("); // Output
                substr = sub_string.substr(found+4);
                if (found != string::npos)
                {
                    //sub_string = sub_string.substr(found+4);
                    //cout << sub_string << endl;
                    for (int i = 0; i < substr.length(); i++) // get Output name
                    {
                        char ch = substr[i];
                        if (ch == ' ')
                            continue;
                        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                            out += ch;
                        else if ((ch == ')'))
                        {
                            break;
                        }
                    }
                }

                found = sub_string.find(".A1("); // Input1
                substr = sub_string.substr(found+4);
                if (found != string::npos)
                {
                    //sub_string = sub_string.substr(found+4);
                    //cout << sub_string << endl;
                    for (int i = 0; i < substr.length(); i++) // get Input name
                    {
                        char ch = substr[i];
                        if (ch == ' ')
                            continue;
                        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                            in1 += ch;
                        else if ((ch == ')'))
                        {
                            break;
                        }
                    }
                }

                found = sub_string.find(".A2("); // Input2
                substr = sub_string.substr(found+4);
                if (found != string::npos)
                {
                    //sub_string = sub_string.substr(found+4);
                    //cout << sub_string << endl;
                    for (int i = 0; i < substr.length(); i++) // get Input name
                    {
                        char ch = substr[i];
                        if (ch == ' ')
                            continue;
                        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                            in2 += ch;
                        else if ((ch == ')'))
                        {
                            break;
                        }
                    }
                }

                CELL *g = new CELL(2, name, 0, name_wire[in1] , name_wire[in2] , name_wire[out]);
                cell_vec.push_back(g);
                name_wire[out] -> front_cell = g;
                if (in1 == in2) {
                    name_wire[in1] -> back_cell.push_back(g);
                }
                else {
                    name_wire[in1] -> back_cell.push_back(g);
                    name_wire[in2] -> back_cell.push_back(g);
                }
                if (name_wire[in1] -> is_input && name_wire[in2] -> is_input) {
                    input_cell.push_back(g);
                    g -> is_first = true;
                }    
                if (name_wire[out] -> is_out) {
                    output_cell.push_back(g);
                }
                //cout << "Cell name: " << name << " Out : " << name_wire[out] -> wire_name << " Input1 : " << name_wire[in1] -> wire_name << " Input2 : " << name_wire[in2] -> wire_name<< endl;
            }

            found = sub_string.find("NOR2X1");
            if (found != string::npos)
            { // found "nor"
                sub_string = sub_string.substr(found + 6);
                string name = "";
                string out = "";
                string in1 = "";
                string in2 = "";
                string substr = "";
                found = sub_string.find("(");
                substr = sub_string.substr(0,found+1);
                for (int i = 0; i < substr.length(); i++) // get CELL name
                {
                    char ch = substr[i];
                    if (ch == ' ')
                        continue;
                    else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                        name += ch;
                    else if ((ch == '('))
                    {
                        
                    }
                }
                
                found = sub_string.find(".ZN("); // Output
                substr = sub_string.substr(found+4);
                if (found != string::npos)
                {
                    //sub_string = sub_string.substr(found+4);
                    for (int i = 0; i < substr.length(); i++) // get Output name
                    {
                        char ch = substr[i];
                        if (ch == ' ')
                            continue;
                        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                            out += ch;
                        else if ((ch == ')'))
                        {
                            break;
                        }
                    }
                }

                found = sub_string.find(".A1("); // Input1
                substr = sub_string.substr(found+4);
                if (found != string::npos)
                {
                    //sub_string = sub_string.substr(found+4);
                    //cout << sub_string << endl;
                    for (int i = 0; i < substr.length(); i++) // get Input name
                    {
                        char ch = substr[i];
                        if (ch == ' ')
                            continue;
                        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                            in1 += ch;
                        else if ((ch == ')'))
                        {
                            break;
                        }
                    }
                    //cout << in1 << endl;
                }

                found = sub_string.find(".A2("); // Input2
                substr = sub_string.substr(found+4);
                if (found != string::npos)
                {
                    //sub_string = sub_string.substr(found+4);
                    //cout << sub_string << endl;
                    for (int i = 0; i < substr.length(); i++) // get Input name
                    {
                        char ch = substr[i];
                        if (ch == ' ')
                            continue;
                        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                            in2 += ch;
                        else if ((ch == ')'))
                        {
                            break;
                        }
                    }
                    //cout << in2 << endl;
                }
            
                
            
                //cout << "in NAND " << name << " " << in1  << " " << in2 << " " << out << endl;

                CELL *g = new CELL(0, name, 0, name_wire[in1] , name_wire[in2] , name_wire[out]);
                cell_vec.push_back(g);
                name_wire[out] -> front_cell = g;
                if (in1 == in2) {
                    name_wire[in1] -> back_cell.push_back(g);
                }
                else {
                    name_wire[in1] -> back_cell.push_back(g);
                    name_wire[in2] -> back_cell.push_back(g);
                }
                if (name_wire[in1] -> is_input && name_wire[in2] -> is_input) {
                    input_cell.push_back(g);
                    g -> is_first = true;
                }    
                if (name_wire[out] -> is_out) {
                    output_cell.push_back(g);
                }
                //cout << "Cell name: " << name << " Out : " << name_wire[out] -> wire_name << " Input1 : " << name_wire[in1] -> wire_name << " Input2 : " << name_wire[in2] -> wire_name<< endl;

            }
        }
        //cout << "Back" <<sub_string << endl;
    }

    // for (auto x : output_cell){
    //     cout << x ->name << endl;
    // }
    ifs.close();
}


void STA::Calculate_output_capacitance(void){
    for (auto cell : cell_vec) // all cell
    {
        if (cell -> out -> is_out) // output is primary output
            cell -> out_capa = 0.03;

        // if (cell ->name  == "U1"){
        //     cout << cell -> out_capa << endl;
        // }

        for (auto output_wire_fanout : cell->out->back_cell) // all output fanout
        {
            
            if (output_wire_fanout -> which_cell == 0) // nor
            {
                if (output_wire_fanout -> in1 == cell -> out) {
                    cell -> out_capa += data -> nor_in_c[0];
                    
                }    
                if (output_wire_fanout -> in2 == cell -> out) {
                    cell -> out_capa += data -> nor_in_c[1];
                }
            }
            else if (output_wire_fanout -> which_cell == 1) // inv
            {
                cell -> out_capa += data -> inv_in_c;
            }
            else if (output_wire_fanout -> which_cell == 2) // nand
            {
                if (output_wire_fanout -> in1 == cell -> out)
                    cell -> out_capa += data -> nand_in_c[0];
                if (output_wire_fanout -> in2 == cell -> out)
                    cell -> out_capa += data -> nand_in_c[1];
            }
        }
    }
    sort (cell_vec.begin(),cell_vec.end(),capacitance_compare);
    
}

void STA::Write_output_load_file(string file){
    string filename = "312510237_";
    file.erase(file.size()-2);
    filename.append(file);
    filename.append("_load.txt");
    ofstream ofs;
    ofs.open(filename);
    for (auto cell : cell_vec) // all cell
    {
        ofs << cell ->name << " " << fixed << setprecision(6) << cell ->out_capa << endl;
    }
    ofs.close();

}

void STA::Write_delay_file(string file){
    string filename = "312510237_";
    file.erase(file.size()-2);
    filename.append(file);
    filename.append("_delay.txt");
    ofstream ofs;
    ofs.open(filename);
    for (auto cell : top_order) // all cell
    {
        ofs << cell -> name << " " << cell -> fall_rise << " " << fixed << setprecision(6) << cell -> delay << " " << fixed << setprecision(6) << cell -> transition_time << endl;
    }
    ofs.close();

}

void STA::Write_path_file(string file){
    string filename = "312510237_";
    file.erase(file.size()-2);
    filename.append(file);
    filename.append("_path.txt");
    ofstream ofs;
    ofs.open(filename);
    
    ofs << "Longest delay = "  << fixed << setprecision(6) << output_cell[0] -> total_delay << ", the path is:" ;
    for (int i = 0;i<longest_path.size();i++){
        if (i == 0)
            ofs << " " <<  longest_path[i] -> wire_name << " ";
        else 
            ofs << "-> " <<  longest_path[i] -> wire_name << " ";
    }
    ofs << endl;

    ofs << "Shortest delay = "  << fixed << setprecision(6) << output_cell[output_cell.size()-1] -> total_delay << ", the path is:" ;
    for (int i = 0;i<shortest_path.size();i++){
        if (i == 0)
            ofs << " " <<  shortest_path[i] -> wire_name << " ";
        else 
            ofs << "-> " <<  shortest_path[i] -> wire_name << " ";
    }
    ofs << endl;


    ofs.close();
}

void STA::Show_input_cell(void){
    for(auto x:input_cell){
        cout << x ->name << endl;
    }
}

void STA::Topological_sort(void){
    queue <CELL *> q; 
    for (auto x:input_cell){
        q.push(x);
    }

    while(!q.empty()){ // create topological order
        CELL *q_pop = q.front();
        q.pop();
        if (q_pop -> visited)
            continue;

        if (q_pop -> which_cell == 1) // is_inverter
        {
            if (q_pop ->is_first) // the first cell
            { 
                top_order.push_back(q_pop);
                q_pop -> visited = true;
                for (auto x:q_pop -> out -> back_cell)
                {
                    q.push(x);
                }
                
            }  
            else // not the first
            {
                if (q_pop -> in1 -> front_cell -> visited){
                    top_order.push_back(q_pop);
                    q_pop -> visited = true;
                    for (auto x:q_pop -> out -> back_cell)
                    {
                        q.push(x);
                    }
                }
                else {
                    q.push(q_pop);
                }
            }  
        }
        else // not inverter
        {   
            if (q_pop ->is_first) // the first cell
            { 
                top_order.push_back(q_pop);
                q_pop -> visited = true;
                for (auto x:q_pop -> out -> back_cell)
                {
                    q.push(x);
                }
            }  
            else // not the first
            {

                if (q_pop -> in1 -> is_input){
                    if (q_pop -> in2 -> front_cell -> visited){
                        top_order.push_back(q_pop);
                        q_pop -> visited = true;
                        for (auto x:q_pop -> out -> back_cell)
                        {
                            q.push(x);
                        }
                    }
                    else {
                        q.push(q_pop);
                    }
                } 
                else if (q_pop -> in2 -> is_input){
                    if (q_pop -> in1 -> front_cell -> visited){
                        top_order.push_back(q_pop);
                        q_pop -> visited = true;
                        for (auto x:q_pop -> out -> back_cell)
                        {
                            q.push(x);
                        }
                    }
                    else {
                        q.push(q_pop);
                    }
                } 
                else {
                    if (q_pop -> in1 -> front_cell -> visited && q_pop -> in2 -> front_cell -> visited){
                        top_order.push_back(q_pop);
                        q_pop -> visited = true;
                        for (auto x:q_pop -> out -> back_cell)
                        {
                            q.push(x);
                        }
                    }
                    else {
                        q.push(q_pop);
                    }
                }
            }  
        }    
    }
}


double STA::Get_data_from_table(int which , bool transtime_or_delay , bool fall_or_rise , double output_c, double input_trans)
{
    int x_1, x_2, y_1, y_2;
    vector< vector<double>> table;

    if (output_c > data -> out_capacitance[data -> out_capacitance.size() - 1])
    {
        y_1 = data -> out_capacitance.size() - 2; y_2 = data -> out_capacitance.size() - 1;
    }
    else if (output_c < data -> out_capacitance[0])
    {
        y_1 = 0; y_2 = 1;
    }
    else
    {
        for (int j = 1; j < data -> out_capacitance.size(); j++)
        {
            if (output_c == data -> out_capacitance[j - 1])
            {
                y_1 = j - 1; y_2 = j - 1;
                break;
            }
            else if (output_c == data -> out_capacitance[j])
            {
                y_1 = j; y_2 = j;
                break;
            }
            else if (output_c > data -> out_capacitance[j - 1] && output_c < data -> out_capacitance[j])
            {
                y_1 = j - 1; y_2 = j;
                break;
            }
        }
    }
    // Get x_1, x_2
    if (input_trans > data -> in_transition[data -> in_transition.size() - 1])
    {
        x_1 = data -> in_transition.size() - 2; x_2 = data -> in_transition.size() - 1;
    }
    else if (input_trans < data -> in_transition[0])
    {
        x_1 = 0; x_2 = 1;
    }
    else
    {
        for (int i = 1; i < data -> in_transition.size(); i++)
        {
            if (input_trans == data -> in_transition[i - 1])
            {
                x_1 = i - 1; x_2 = i - 1;
                break;
            }
            else if (input_trans == data -> in_transition[i])
            {
                x_1 = i; x_2 = i;
                break;
            }
            else if (input_trans > data -> in_transition[i - 1] && input_trans < data -> in_transition[i])
            {
                x_1 = i - 1; x_2 = i;
                break;
            }
        }
    }

    // Calculate temp1, temp2
    double a1, a2, b1, b2;

    //          y_1         y_2
    //     ┌──────────┬──────────┐
    // x_1 │    a1    │    a2    │
    //     ├──────────┼──────────┤
    // x_2 │    b1    │    b2    │
    //     └──────────┴──────────┘
    //
    
    // 0:nor 1:inv 2:nand 
    if (which == 0 && transtime_or_delay == false && fall_or_rise == false) {
        table = data -> nor_fall_transition;
    } else if (which == 0 && transtime_or_delay == false && fall_or_rise == true ) {
        table = data -> nor_rise_transition;
    } else if (which == 0 && transtime_or_delay == true  && fall_or_rise == false) {
        table = data -> nor_cell_fall;
    } else if (which == 0 && transtime_or_delay == true  && fall_or_rise == true ) {
        table = data -> nor_cell_rise;
    } else if (which == 1 && transtime_or_delay == false && fall_or_rise == false) {
        table = data -> inv_fall_transition;
    } else if (which == 1 && transtime_or_delay == false && fall_or_rise == true ) {
        table = data -> inv_rise_transition;
    } else if (which == 1 && transtime_or_delay == true  && fall_or_rise == false) {
        table = data -> inv_cell_fall;
    } else if (which == 1 && transtime_or_delay == true  && fall_or_rise == true ) {
        table = data -> inv_cell_rise;
    } else if (which == 2 && transtime_or_delay == false && fall_or_rise == false) {
        table = data -> nand_fall_transition;
    } else if (which == 2 && transtime_or_delay == false && fall_or_rise == true)  {
        table = data -> nand_rise_transition;
    } else if (which == 2 && transtime_or_delay == true && fall_or_rise == false)  {
        table = data -> nand_cell_fall;
    } else if (which == 2 && transtime_or_delay == true && fall_or_rise == true )  {
        table = data -> nand_cell_rise;
    }    

    a1 = table[x_1][y_1]; a2 = table[x_1][y_2]; b1 = table[x_2][y_1]; b2 = table[x_2][y_2];


    double temp,temp1,temp2;

    if (output_c < data -> out_capacitance[0]) // under
    {
        temp = (data -> out_capacitance[y_1] - output_c) / (data -> out_capacitance[y_2] - data -> out_capacitance[y_1]);
        temp1 = a1 - ((a2 - a1) * temp);
        temp2 = b1 - ((b2 - b1) * temp);
    }
    else if (output_c > data -> out_capacitance[data -> out_capacitance.size() - 1]) //over
    {
        temp = (output_c - data -> out_capacitance[y_2]) / (data -> out_capacitance[y_2] - data -> out_capacitance[y_1]);
        temp1 = a2 + ((a2 - a1) * temp);
        temp2 = b2 + ((b2 - b1) * temp);
    }
    else
    {
        if (y_2 == y_1) {
            temp1 = a1;
            temp2 = b1;
        }
        else {
            temp = (output_c - data -> out_capacitance[y_1]) / (data -> out_capacitance[y_2] - data -> out_capacitance[y_1]);
            temp1 = a1 + ((a2 - a1) * temp);
            temp2 = b1 + ((b2 - b1) * temp);
        }
    }
 
    double number;
    double number_temp;
    if (x_2 == x_1)
        number_temp = 0;
    else 
        number_temp = (temp2 - temp1) / (data -> in_transition[x_2] - data -> in_transition[x_1]);

    if (input_trans < data -> in_transition[0])
    {
        number = temp1 - number_temp * (data -> in_transition[x_1] - input_trans);
    }
    else if (input_trans > data -> in_transition[data -> in_transition.size() - 1])
    {
        number = temp2 + number_temp * (input_trans - data -> in_transition[x_2]);
    }
    else
    {
        number = temp1 + number_temp * (input_trans - data -> in_transition[x_1]);
    }
    
    return number;
}

void STA::Calulate_delay(void){
    for (auto cell:top_order) // caculate all cell delay in order
    {
        if (cell -> which_cell == 0) // nor
        {
            if (cell -> is_first) //  is first gate
            {
                int f_r;
                double fall_delay = Get_data_from_table(0, 1 , 0 , cell -> out_capa, 0);
                double rise_delay = Get_data_from_table(0, 1 , 1 , cell -> out_capa, 0);
                f_r = (rise_delay > fall_delay) ? 1 : 0 ; // f_r = 1: rise  f_r = 0: fall
                cell -> delay = (rise_delay > fall_delay) ? rise_delay : fall_delay ;
                cell -> transition_time = Get_data_from_table(0, 0 , f_r , cell -> out_capa, 0);
                cell -> fall_rise = f_r;
                cell -> total_delay = cell -> delay;
                cell -> before_wire = cell -> in1;
            }

            else // not first gate
            {
                int f_r;
                double in_trans;
                double in_delay;
                int which_input;
                if (cell -> in1 -> is_input){
                    which_input = 0;
                    in_trans = cell -> in2 -> front_cell -> transition_time;
                    in_delay = cell -> in2 -> front_cell -> total_delay;
                }
                else if (cell -> in2 -> is_input){
                    which_input = 1;
                    in_trans = cell -> in1 -> front_cell -> transition_time;
                    in_delay = cell -> in1 -> front_cell -> total_delay;
                }
                else {
                    which_input = (cell -> in1 -> front_cell -> total_delay > cell -> in2 -> front_cell -> total_delay) ? 1 : 0;
                    in_trans = (which_input) ? cell -> in1 -> front_cell -> transition_time : cell -> in2 -> front_cell -> transition_time;
                    in_delay = (which_input) ? cell -> in1 -> front_cell -> total_delay     : cell -> in2 -> front_cell -> total_delay;
                    //in_trans = (cell -> in1 -> front_cell -> total_delay > cell -> in2 -> front_cell -> total_delay) ? cell -> in1 -> front_cell -> transition_time : cell -> in2 -> front_cell -> transition_time;
                    //in_delay = (cell -> in1 -> front_cell -> total_delay > cell -> in2 -> front_cell -> total_delay) ? cell -> in1 -> front_cell -> total_delay     : cell -> in2 -> front_cell -> total_delay;
                }    
                //cout << "in nor" << endl;
                double fall_delay = Get_data_from_table(0, 1 , 0 , cell -> out_capa, in_trans);
                double rise_delay = Get_data_from_table(0, 1 , 1 , cell -> out_capa, in_trans);
                f_r = (rise_delay > fall_delay) ? 1 : 0 ; // f_r = 1: rise  f_r = 0: fall
                cell -> delay = (rise_delay > fall_delay) ? rise_delay : fall_delay ;
                cell -> transition_time = Get_data_from_table(0, 0 , f_r , cell -> out_capa, in_trans);
                cell -> fall_rise = f_r;
                cell -> total_delay = in_delay + cell -> delay + 0.005;
                cell -> before_wire = (which_input) ? cell -> in1  : cell -> in2 ;
                cell -> before_cell = (which_input) ? cell -> in1 -> front_cell : cell -> in2 -> front_cell;
            }
            
        }
        else if (cell -> which_cell == 1) // inv
        {
            if (cell -> is_first) //  is first gate
            {
                int f_r;
                double fall_delay = Get_data_from_table(1, 1 , 0 , cell -> out_capa, 0);
                double rise_delay = Get_data_from_table(1, 1 , 1 , cell -> out_capa, 0);
                f_r = (rise_delay > fall_delay) ? 1 : 0 ; // f_r = 1: rise  f_r = 0: fall
                cell -> delay = (rise_delay > fall_delay) ? rise_delay : fall_delay ;
                cell -> transition_time = Get_data_from_table(1, 0 , f_r , cell -> out_capa, 0);
                cell -> fall_rise = f_r;
                cell -> total_delay = cell -> delay;
                cell -> before_wire = cell -> in1;
            }
            else // not first gate
            {
                int f_r;
                //int which_input;
                //which_input = (cell -> in1 -> front_cell -> total_delay > cell -> in2 -> front_cell -> total_delay) ? 1 : 0;
                double in_trans = cell -> in1 -> front_cell -> transition_time;
                double fall_delay = Get_data_from_table(1, 1 , 0 , cell -> out_capa, in_trans);
                double rise_delay = Get_data_from_table(1, 1 , 1 , cell -> out_capa, in_trans);
                f_r = (rise_delay > fall_delay) ? 1 : 0 ; // f_r = 1: rise  f_r = 0: fall
                cell -> delay = (rise_delay > fall_delay) ? rise_delay : fall_delay ;
                cell -> transition_time = Get_data_from_table(1, 0 , f_r , cell -> out_capa, in_trans);
                cell -> fall_rise = f_r;
                cell -> total_delay = cell -> in1 -> front_cell -> total_delay + 0.005 + cell -> delay;
                cell -> before_wire = cell -> in1 ;
                cell -> before_cell = cell -> in1 -> front_cell;
            }
        }
        else if (cell -> which_cell == 2) // nand
        {
            if (cell -> is_first) //  is first gate
            {
                int f_r;
                double fall_delay = Get_data_from_table(2, 1 , 0 , cell -> out_capa, 0);
                double rise_delay = Get_data_from_table(2, 1 , 1 , cell -> out_capa, 0);
                f_r = (rise_delay > fall_delay) ? 1 : 0 ; // f_r = 1: rise  f_r = 0: fall
                cell -> delay = (rise_delay > fall_delay) ? rise_delay : fall_delay ;
                cell -> transition_time = Get_data_from_table(2, 0 , f_r , cell -> out_capa, 0);
                cell -> fall_rise = f_r;
                cell -> total_delay = cell -> delay;
                cell -> before_wire = cell -> in1;
            }
            else // not first gate
            {
                int f_r;
                double in_trans;
                double in_delay;
                int which_input;
                if (cell -> in1 -> is_input){
                    which_input = 0;
                    in_trans = cell -> in2 -> front_cell -> transition_time;
                    in_delay = cell -> in2 -> front_cell -> total_delay;
                }
                else if (cell -> in2 -> is_input){
                    which_input = 1;
                    in_trans = cell -> in1 -> front_cell -> transition_time;
                    in_delay = cell -> in1 -> front_cell -> total_delay;
                }
                else {
                    which_input = (cell -> in1 -> front_cell -> total_delay > cell -> in2 -> front_cell -> total_delay) ? 1 : 0;
                    in_trans = (which_input) ? cell -> in1 -> front_cell -> transition_time: cell -> in2 -> front_cell -> transition_time;
                    in_delay = (which_input) ? cell -> in1 -> front_cell -> total_delay : cell -> in2 -> front_cell -> total_delay;
                    // in_trans = (cell -> in1 -> front_cell -> total_delay > cell -> in2 -> front_cell -> total_delay) ? cell -> in1 -> front_cell -> transition_time: cell -> in2 -> front_cell -> transition_time;
                    // in_delay = (cell -> in1 -> front_cell -> total_delay > cell -> in2 -> front_cell -> total_delay) ? cell -> in1 -> front_cell -> total_delay : cell -> in2 -> front_cell -> total_delay;
                }
                double fall_delay = Get_data_from_table(2, 1 , 0 , cell -> out_capa, in_trans);
                double rise_delay = Get_data_from_table(2, 1 , 1 , cell -> out_capa, in_trans);
                f_r = (rise_delay > fall_delay) ? 1 : 0 ; // f_r = 1: rise  f_r = 0: fall
                cell -> delay = (rise_delay > fall_delay) ? rise_delay : fall_delay ;
                cell -> transition_time = Get_data_from_table(2, 0 , f_r , cell -> out_capa, in_trans);
                cell -> fall_rise = f_r;
                cell -> total_delay = in_delay + cell -> delay + 0.005;
                cell -> before_wire = (which_input) ? cell -> in1  : cell -> in2 ;
                cell -> before_cell = (which_input) ? cell -> in1 -> front_cell : cell -> in2 -> front_cell;
            }
        }
    }

    sort(top_order.begin(),top_order.end(),delay_compare);
}

void STA::Find_delay_path(void){
    sort(output_cell.begin(), output_cell.end() ,total_delay_comapare);
    
    CELL * trace_cell = output_cell[0]; 
    longest_path.insert(longest_path.begin(),trace_cell -> out);
    while (trace_cell != NULL) {
        longest_path.insert(longest_path.begin(),trace_cell -> before_wire);
        trace_cell = trace_cell -> before_cell;
    }
    

    trace_cell = output_cell[output_cell.size()-1];
    shortest_path.insert(shortest_path.begin(),trace_cell -> out);
    while (trace_cell != NULL) {
        shortest_path.insert(shortest_path.begin(),trace_cell -> before_wire);
        trace_cell = trace_cell -> before_cell;
    }

}


int main(int argc, char *argv[])
{
    STA sta_time;
    sta_time.Read_circuit(argv[1]);
    sta_time.Calculate_output_capacitance();
    sta_time.Write_output_load_file(argv[1]);
    sta_time.Topological_sort();    
    sta_time.Calulate_delay();
    sta_time.Write_delay_file(argv[1]);
    sta_time.Find_delay_path();
    sta_time.Write_path_file(argv[1]);
    return 0;
}
