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
    vector<vector<double>> nor_rise_power;
    vector<vector<double>> nor_fall_power;
    vector<vector<double>> nor_cell_rise;
    vector<vector<double>> nor_cell_fall;
    vector<vector<double>> nor_rise_transition;
    vector<vector<double>> nor_fall_transition;
    double inv_in_c;
    vector<vector<double>> inv_rise_power;
    vector<vector<double>> inv_fall_power;
    vector<vector<double>> inv_cell_rise;
    vector<vector<double>> inv_cell_fall;
    vector<vector<double>> inv_rise_transition;
    vector<vector<double>> inv_fall_transition;
    vector<double> nand_in_c;
    vector<vector<double>> nand_rise_power;
    vector<vector<double>> nand_fall_power;
    vector<vector<double>> nand_cell_rise;
    vector<vector<double>> nand_cell_fall;
    vector<vector<double>> nand_rise_transition;
    vector<vector<double>> nand_fall_transition;

    void Read_lib_Data(string name)
    {
        ifstream ifs;
        string str_tmp;
        string sub_string;
        ifs.open(name);

        while (getline(ifs, str_tmp))
        {
            sub_string = str_tmp;
            size_t found;

            found = sub_string.find("lu_table_template");
            if (found != string::npos) // found "lu_table_template"
            {
                while (getline(ifs, sub_string))
                {
                    string temp = "";
                    bool leave_or_not = false;

                    // double value_tmp;

                    found = sub_string.find("index_1");
                    if (found != string::npos)
                    { // found "index_1"
                        sub_string = sub_string.substr(found + 7);
                        for (int i = 0; i < sub_string.length(); i++)
                        {
                            char ch = sub_string[i];
                            if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                temp += ch;
                            else if ((ch == ',') || (ch == ';'))
                            {
                                if (temp != "")
                                {
                                    out_capacitance.push_back(stod(temp));
                                }
                                temp = "";
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }

                    found = sub_string.find("index_2");
                    if (found != string::npos)
                    { // found "index_2"
                        sub_string = sub_string.substr(found + 7);
                        leave_or_not = true;
                        for (int i = 0; i < sub_string.length(); i++)
                        {
                            char ch = sub_string[i];
                            if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                temp += ch;
                            else if ((ch == ',') || (ch == ';'))
                            {
                                if (temp != "")
                                {
                                    in_transition.push_back(stod(temp));
                                }
                                temp = "";
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }

                    if (leave_or_not)
                        break;
                }
            }

            found = sub_string.find("cell");
            if (found != string::npos)
            { // found cell
                found = sub_string.find("NOR2X1");

                if (found != string::npos)
                { // found NOR2
                    int pin_num = 0;
                    while (getline(ifs, sub_string))
                    {
                        string temp = "";
                        found = sub_string.find("pin(");
                        if (found != string::npos)
                        { // found pin
                            pin_num++;
                            getline(ifs, str_tmp);
                            getline(ifs, str_tmp);
                            sub_string = str_tmp;
                            for (int i = 0; i < sub_string.length(); i++)
                            {
                                char ch = sub_string[i];
                                if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                    temp += ch;
                                else if ((ch == ';'))
                                {
                                    nor_in_c.push_back(stod(temp));
                                    temp = "";
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }

                        if (pin_num == 2)
                            break;
                    } // end find input capacitance

                    while (getline(ifs, sub_string))
                    {
                        bool leave_nor = false;

                        found = sub_string.find("rise_power");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nor_rise_power.push_back(one_row_tmp);

                                if (leave)
                                    break;
                            }
                        } // end nor rise power

                        found = sub_string.find("fall_power");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nor_fall_power.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nor fall power

                        found = sub_string.find("cell_rise");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nor_cell_rise.push_back(one_row_tmp);

                                if (leave)
                                    break;
                            }

                        } // end cell rise delay

                        found = sub_string.find("cell_fall");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nor_cell_fall.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nor cell fall

                        found = sub_string.find("rise_transition");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nor_rise_transition.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nor rise transition

                        found = sub_string.find("fall_transition");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                        leave_nor = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nor_fall_transition.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nor fall transition

                        if (leave_nor)
                            break;

                    } // end rise/fall power  rise/fall  transition time  rise/fall delay

                } // end cell nor2

                found = sub_string.find("INVX1");
                if (found != string::npos)
                { // found INV
                    int pin_num = 0;
                    while (getline(ifs, sub_string))
                    {
                        string temp = "";
                        found = sub_string.find("pin(");
                        if (found != string::npos)
                        { // found pin
                            pin_num++;
                            getline(ifs, str_tmp);
                            getline(ifs, str_tmp);
                            sub_string = str_tmp;
                            for (int i = 0; i < sub_string.length(); i++)
                            {
                                char ch = sub_string[i];
                                if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                    temp += ch;
                                else if ((ch == ';'))
                                {
                                    inv_in_c = stod(temp);
                                    temp = "";
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        if (pin_num == 1)
                            break;
                    } // end find input capacitance

                    while (getline(ifs, sub_string))
                    {
                        bool leave_inv = false;

                        found = sub_string.find("rise_power");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                inv_rise_power.push_back(one_row_tmp);

                                if (leave)
                                    break;
                            }
                        } // end inv rise power

                        found = sub_string.find("fall_power");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                inv_fall_power.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end inv fall power

                        found = sub_string.find("cell_rise");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                inv_cell_rise.push_back(one_row_tmp);

                                if (leave)
                                    break;
                            }
                            // cout << "nor cell rise : " << endl;
                            // for (auto x:nor_cell_rise){
                            //     for (auto y:x){
                            //         cout << y << " ";
                            //     }
                            //     cout << endl;
                            // }
                            // cout << endl;
                        } // end cell rise delay

                        found = sub_string.find("cell_fall");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                inv_cell_fall.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nor cell fall

                        found = sub_string.find("rise_transition");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                inv_rise_transition.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end inv rise transition

                        found = sub_string.find("fall_transition");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                        leave_inv = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                inv_fall_transition.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end inv fall transition

                        if (leave_inv)
                            break;

                    } // end rise/fall power  rise/fall  transition time  rise/fall delay

                } // end cell inv

                found = sub_string.find("NANDX1");
                if (found != string::npos)
                { // found NAND
                    int pin_num = 0;
                    while (getline(ifs, sub_string))
                    {
                        string temp = "";
                        found = sub_string.find("pin(");
                        if (found != string::npos)
                        { // found pin
                            pin_num++;
                            getline(ifs, str_tmp);
                            getline(ifs, str_tmp);
                            sub_string = str_tmp;
                            for (int i = 0; i < sub_string.length(); i++)
                            {
                                char ch = sub_string[i];
                                if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                    temp += ch;
                                else if ((ch == ';'))
                                {
                                    nand_in_c.push_back(stod(temp));
                                    temp = "";
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        if (pin_num == 2)
                            break;
                    } // end find input capacitance

                    while (getline(ifs, sub_string))
                    {
                        bool leave_nand = false;

                        found = sub_string.find("rise_power");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nand_rise_power.push_back(one_row_tmp);

                                if (leave)
                                    break;
                            }
                        } // end nand rise power

                        found = sub_string.find("fall_power");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nand_fall_power.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nand fall power

                        found = sub_string.find("cell_rise");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nand_cell_rise.push_back(one_row_tmp);

                                if (leave)
                                    break;
                            }

                        } // end cell rise delay

                        found = sub_string.find("cell_fall");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nand_cell_fall.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nor cell fall

                        found = sub_string.find("rise_transition");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nand_rise_transition.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nand rise transition

                        found = sub_string.find("fall_transition");
                        if (found != string::npos)
                        {
                            while (getline(ifs, sub_string))
                            {
                                string temp = "";
                                bool leave = false;
                                vector<double> one_row_tmp;
                                for (int i = 0; i < sub_string.length(); i++)
                                {
                                    char ch = sub_string[i];
                                    if ((ch >= '0' && ch <= '9') || (ch == '.'))
                                        temp += ch;
                                    else if ((ch == ','))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                    }
                                    else if ((ch == ';'))
                                    {
                                        one_row_tmp.push_back(stod(temp));
                                        temp = "";
                                        leave = true;
                                        leave_nand = true;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }

                                nand_fall_transition.push_back(one_row_tmp);
                                if (leave)
                                    break;
                            }

                        } // end nand fall transition

                        if (leave_nand)
                            break;

                    } // end rise/fall power  rise/fall  transition time  rise/fall delay

                } // end cell nand
            }
        } // end all lib

        ifs.close();
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
    vector<double> transition_time;
    vector<double> delay;
    vector<double> total_delay;
    vector<double> internal_power;
    double switch_power;
    int toggle_0_to_1_time, toggle_1_to_0_time;
    bool visited;
    bool is_first;
    bool fall_rise;
    WIRE *before_wire;
    CELL *before_cell;
    CELL(int cell_type, string gate_name, double o_c, WIRE *I1, WIRE *I2, WIRE *OUT)
    {
        which_cell = cell_type;
        name = gate_name;
        in1 = I1;
        in2 = I2;
        out = OUT;
        out_capa = o_c;
        switch_power = 0;
        toggle_0_to_1_time = 0;
        toggle_1_to_0_time = 0;
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
    vector<bool> pattern_num;
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
    if (getnum(cell1->name) < getnum(cell2->name))
    {
        return true;
    }
    return false;
}

class STA
{
private:
    vector<WIRE *> all_wire;
    unordered_map<string, WIRE *> name_wire;
    vector<CELL *> cell_vec;
    vector<CELL *> input_cell;
    vector<CELL *> output_cell;
    vector<CELL *> top_order;
    vector<WIRE *> longest_path;
    vector<WIRE *> shortest_path;
    vector<double> total_power;
    vector<double> covera;
    int total_pat_number;
    LIB_DATA data;
    LIB_DATA *data_ptr;

public:
    STA();
    void Read_circuit(string);
    void Read_lib_data(string);
    void Read_pat_file(string);
    void Calculate_output_capacitance(void);
    void Write_output_load_file(string);
    void Write_delay_file(string);
    void Write_power_file(string);
    void Write_coverage_file(string);
    void Show_input_cell(void);
    void Topological_sort(void);
    double Get_data_from_table(int, bool, bool, bool, double, double);
    void Calulate_delay(void);
};

STA::STA()
{
    data_ptr = &data;
    total_pat_number = 0;
}

void STA::Read_lib_data(string lib_name)
{
    data.Read_lib_Data(lib_name);
}

void STA::Read_circuit(string f_lib)
{
    ifstream ifs;
    string str_tmp;
    string sub_string;
    ifs.open(f_lib);

    while (getline(ifs, str_tmp))
    {
        sub_string = str_tmp;

        size_t found;

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
                    WIRE *w = new WIRE(temp, 0, true);
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
                    WIRE *w = new WIRE(temp, 0, false);
                    name_wire[temp] = w;
                    temp = "";
                }
            }
        }
        // cout << sub_string << endl;
        found = sub_string.find("INVX1");
        if (found != string::npos)
        { // found "inverter"
            sub_string = sub_string.substr(found + 5);
            string name = "";
            string out = "";
            string in = "";
            string substr = "";
            found = sub_string.find("(");
            substr = sub_string.substr(0, found + 1);
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
            substr = sub_string.substr(found + 4);
            if (found != string::npos)
            {
                // sub_string = sub_string.substr(found+4);
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
            substr = sub_string.substr(found + 3);
            if (found != string::npos)
            {
                // sub_string = sub_string.substr(found+3);
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
            // nor_in_c nand_in_c inv_in_c
            CELL *g = new CELL(1, name, 0, name_wire[in], NULL, name_wire[out]);
            cell_vec.push_back(g);
            name_wire[out]->front_cell = g;
            name_wire[in]->back_cell.push_back(g);
            if (name_wire[in]->is_input)
            {
                input_cell.push_back(g);
                g->is_first = true;
            }
            if (name_wire[out]->is_out)
            {
                output_cell.push_back(g);
            }

            // cout << "Cell name: " << name << " Out : " << name_wire[out] -> wire_name << " Input : " << name_wire[in] -> wire_name << endl;
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
            substr = sub_string.substr(0, found + 1);
            for (int i = 0; i < substr.length(); i++) // get CELL name
            {
                char ch = substr[i];
                if (ch == ' ')
                    continue;
                else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                    name += ch;
                else if ((ch == '('))
                {
                    // cout << name << endl;
                }
            }

            // cout << sub_string << endl;
            found = sub_string.find(".ZN("); // Output
            substr = sub_string.substr(found + 4);
            if (found != string::npos)
            {
                // sub_string = sub_string.substr(found+4);
                // cout << sub_string << endl;
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
            substr = sub_string.substr(found + 4);
            if (found != string::npos)
            {
                // sub_string = sub_string.substr(found+4);
                // cout << sub_string << endl;
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
            substr = sub_string.substr(found + 4);
            if (found != string::npos)
            {
                // sub_string = sub_string.substr(found+4);
                // cout << sub_string << endl;
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
            CELL *g = new CELL(2, name, 0, name_wire[in1], name_wire[in2], name_wire[out]);
            cell_vec.push_back(g);
            name_wire[out]->front_cell = g;
            if (in1 == in2)
            {
                name_wire[in1]->back_cell.push_back(g);
            }
            else
            {
                name_wire[in1]->back_cell.push_back(g);
                name_wire[in2]->back_cell.push_back(g);
            }
            if (name_wire[in1]->is_input && name_wire[in2]->is_input)
            {
                input_cell.push_back(g);
                g->is_first = true;
            }
            if (name_wire[out]->is_out)
            {
                output_cell.push_back(g);
            }
            // cout << "Cell name: " << name << " Out : " << name_wire[out] -> wire_name << " Input1 : " << name_wire[in1] -> wire_name << " Input2 : " << name_wire[in2] -> wire_name<< endl;
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
            substr = sub_string.substr(0, found + 1);
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
            substr = sub_string.substr(found + 4);
            if (found != string::npos)
            {
                // sub_string = sub_string.substr(found+4);
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
            substr = sub_string.substr(found + 4);
            if (found != string::npos)
            {
                // sub_string = sub_string.substr(found+4);
                // cout << sub_string << endl;
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
                // cout << in1 << endl;
            }
            found = sub_string.find(".A2("); // Input2
            substr = sub_string.substr(found + 4);
            if (found != string::npos)
            {
                // sub_string = sub_string.substr(found+4);
                // cout << sub_string << endl;
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
                // cout << in2 << endl;
            }

            // cout << "in NAND " << name << " " << in1  << " " << in2 << " " << out << endl;
            CELL *g = new CELL(0, name, 0, name_wire[in1], name_wire[in2], name_wire[out]);
            cell_vec.push_back(g);
            name_wire[out]->front_cell = g;
            if (in1 == in2)
            {
                name_wire[in1]->back_cell.push_back(g);
            }
            else
            {
                name_wire[in1]->back_cell.push_back(g);
                name_wire[in2]->back_cell.push_back(g);
            }
            if (name_wire[in1]->is_input && name_wire[in2]->is_input)
            {
                input_cell.push_back(g);
                g->is_first = true;
            }
            if (name_wire[out]->is_out)
            {
                output_cell.push_back(g);
            }
            // cout << "Cell name: " << name << " Out : " << name_wire[out] -> wire_name << " Input1 : " << name_wire[in1] -> wire_name << " Input2 : " << name_wire[in2] -> wire_name<< endl;
        }
    }

    // for (auto x : output_cell){
    //     cout << x ->name << endl;
    // }
    ifs.close();
}

void STA::Read_pat_file(string pat_f)
{
    ifstream ifs;
    string str_tmp;
    size_t found;
    string sub_string;
    vector<string> input_name;
    ifs.open(pat_f);
    getline(ifs, str_tmp);
    sub_string = str_tmp;
    found = sub_string.find("input");
    sub_string = sub_string.substr(found + 5);
    if (found != string::npos)
    {
        string temp = "";
        for (int i = 0; i <= sub_string.length(); i++)
        {
            char ch = sub_string[i];
            if (ch == ' ')
                continue;
            else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                temp += ch;
            else if ((ch == ',') || i == sub_string.length())
            {
                input_name.push_back(temp);
                temp = "";
            }
        }
    } // get input

    while (getline(ifs, str_tmp))
    {
        total_pat_number++;
        sub_string = str_tmp;
        found = sub_string.find(".end");
        if (found != string::npos)
        {
            total_pat_number--;
            break;
        }

        int count = 0;
        for (int i = 0; i < sub_string.length(); i++)
        {
            char ch = sub_string[i];
            if (ch == ' ')
                continue;
            else if ((ch == '0' || ch == '1'))
            {
                name_wire[input_name[count]]->pattern_num.push_back(ch - '0');
                count++;
            }
        }

        total_power.push_back(0);
        covera.push_back(0);
    }

    ifs.close();
}

void STA::Calculate_output_capacitance(void)
{
    for (auto cell : cell_vec) // all cell
    {
        if (cell->out->is_out) // output is primary output
            cell->out_capa = 0.03;

        for (auto output_wire_fanout : cell->out->back_cell) // all output fanout
        {

            if (output_wire_fanout->which_cell == 0) // nor
            {
                if (output_wire_fanout->in1 == cell->out)
                {
                    cell->out_capa += data_ptr->nor_in_c[0];
                }
                if (output_wire_fanout->in2 == cell->out)
                {
                    cell->out_capa += data_ptr->nor_in_c[1];
                }
            }
            else if (output_wire_fanout->which_cell == 1) // inv
            {
                cell->out_capa += data_ptr->inv_in_c;
            }
            else if (output_wire_fanout->which_cell == 2) // nand
            {
                if (output_wire_fanout->in1 == cell->out)
                    cell->out_capa += data_ptr->nand_in_c[0];
                if (output_wire_fanout->in2 == cell->out)
                    cell->out_capa += data_ptr->nand_in_c[1];
            }
        }
        cell->switch_power = (cell->out_capa * 0.9 * 0.9) / 2.0;
    }
    sort(cell_vec.begin(), cell_vec.end(), capacitance_compare);
}

void STA::Write_output_load_file(string file)
{
    string filename = "312510237_";
    file.erase(file.size() - 2);
    filename.append(file);
    filename.append("_load.txt");
    ofstream ofs;
    ofs.open(filename);
    for (auto cell : cell_vec) // all cell
    {
        ofs << cell->name << " " << fixed << setprecision(6) << cell->out_capa << endl;
    }
    ofs.close();
}

void STA::Write_delay_file(string file)
{
    string filename = "312510237_";
    file.erase(file.size() - 2);
    filename.append(file);
    filename.append("_gate_info.txt");
    ofstream ofs;
    ofs.open(filename);
    for (int i = 0; i < total_pat_number; i++)
    {
        for (auto cell : top_order) // all cell
        {
            ofs << cell->name << " " << cell->out->pattern_num[i] << " " << fixed << setprecision(6) << cell->delay[i] << " " << fixed << setprecision(6) << cell->transition_time[i] << endl;
        }
        ofs << endl;
    }

    ofs.close();
}

void STA::Write_power_file(string file)
{
    string filename = "312510237_";
    file.erase(file.size() - 2);
    filename.append(file);
    filename.append("_gate_power.txt");
    ofstream ofs;
    ofs.open(filename);
    for (int i = 0; i < total_pat_number; i++)
    {
        for (auto cell : top_order) // all cell
        {
            ofs << cell->name << " " << fixed << setprecision(6) << cell->internal_power[i] << " " << fixed << setprecision(6) << cell->switch_power << endl;
        }
        ofs << endl;
    }

    ofs.close();
}

void STA::Write_coverage_file(string file)
{
    string filename = "312510237_";
    file.erase(file.size() - 2);
    filename.append(file);
    filename.append("_coverage.txt");
    ofstream ofs;
    ofs.open(filename);
    double total_toggle = 0;
    double cover = 0;
    for (int i = 0; i < total_pat_number; i++)
    {

        // for (auto cell : top_order) // all cell
        // {
        //     total_toggle = total_toggle + cell->toggle_0_to_1_time + cell->toggle_1_to_0_time;
        // }
        if (i != 0)
            covera[i] += covera[i - 1];
        cover = 100 * (covera[i] / (top_order.size() * 40));

        ofs << i + 1 << " " << fixed << setprecision(6) << total_power[i] << " " << fixed << setprecision(2) << cover << "%" << endl;
        ofs << endl;
    }

    ofs.close();
}

void STA::Topological_sort(void)
{
    queue<CELL *> q;
    for (auto x : input_cell)
    {
        q.push(x);
    }

    while (!q.empty())
    { // create topological order
        CELL *q_pop = q.front();
        q.pop();
        if (q_pop->visited)
            continue;

        if (q_pop->which_cell == 1) // is_inverter
        {
            if (q_pop->is_first) // the first cell
            {
                top_order.push_back(q_pop);
                q_pop->visited = true;
                for (auto x : q_pop->out->back_cell)
                {
                    q.push(x);
                }
            }
            else // not the first
            {
                if (q_pop->in1->front_cell->visited)
                {
                    top_order.push_back(q_pop);
                    q_pop->visited = true;
                    for (auto x : q_pop->out->back_cell)
                    {
                        q.push(x);
                    }
                }
                else
                {
                    q.push(q_pop);
                }
            }
        }
        else // not inverter
        {
            if (q_pop->is_first) // the first cell
            {
                top_order.push_back(q_pop);
                q_pop->visited = true;
                for (auto x : q_pop->out->back_cell)
                {
                    q.push(x);
                }
            }
            else // not the first
            {

                if (q_pop->in1->is_input)
                {
                    if (q_pop->in2->front_cell->visited)
                    {
                        top_order.push_back(q_pop);
                        q_pop->visited = true;
                        for (auto x : q_pop->out->back_cell)
                        {
                            q.push(x);
                        }
                    }
                    else
                    {
                        q.push(q_pop);
                    }
                }
                else if (q_pop->in2->is_input)
                {
                    if (q_pop->in1->front_cell->visited)
                    {
                        top_order.push_back(q_pop);
                        q_pop->visited = true;
                        for (auto x : q_pop->out->back_cell)
                        {
                            q.push(x);
                        }
                    }
                    else
                    {
                        q.push(q_pop);
                    }
                }
                else
                {
                    if (q_pop->in1->front_cell->visited && q_pop->in2->front_cell->visited)
                    {
                        top_order.push_back(q_pop);
                        q_pop->visited = true;
                        for (auto x : q_pop->out->back_cell)
                        {
                            q.push(x);
                        }
                    }
                    else
                    {
                        q.push(q_pop);
                    }
                }
            }
        }
    }
}

double STA::Get_data_from_table(int which, bool transtime_or_delay, bool fall_or_rise, bool power_or_not, double output_c, double input_trans)
{
    int x_1, x_2, y_1, y_2;
    vector<vector<double>> table;

    if (output_c > data_ptr->out_capacitance[data_ptr->out_capacitance.size() - 1])
    {
        y_1 = data_ptr->out_capacitance.size() - 2;
        y_2 = data_ptr->out_capacitance.size() - 1;
    }
    else if (output_c < data_ptr->out_capacitance[0])
    {
        y_1 = 0;
        y_2 = 1;
    }
    else
    {
        for (int j = 1; j < data_ptr->out_capacitance.size(); j++)
        {
            if (output_c == data_ptr->out_capacitance[j - 1])
            {
                y_1 = j - 1;
                y_2 = j - 1;
                break;
            }
            else if (output_c == data_ptr->out_capacitance[j])
            {
                y_1 = j;
                y_2 = j;
                break;
            }
            else if (output_c > data_ptr->out_capacitance[j - 1] && output_c < data_ptr->out_capacitance[j])
            {
                y_1 = j - 1;
                y_2 = j;
                break;
            }
        }
    }
    // Get x_1, x_2
    if (input_trans > data_ptr->in_transition[data_ptr->in_transition.size() - 1])
    {
        x_1 = data_ptr->in_transition.size() - 2;
        x_2 = data_ptr->in_transition.size() - 1;
    }
    else if (input_trans < data_ptr->in_transition[0])
    {
        x_1 = 0;
        x_2 = 1;
    }
    else
    {
        for (int i = 1; i < data_ptr->in_transition.size(); i++)
        {
            if (input_trans == data_ptr->in_transition[i - 1])
            {
                x_1 = i - 1;
                x_2 = i - 1;
                break;
            }
            else if (input_trans == data_ptr->in_transition[i])
            {
                x_1 = i;
                x_2 = i;
                break;
            }
            else if (input_trans > data_ptr->in_transition[i - 1] && input_trans < data_ptr->in_transition[i])
            {
                x_1 = i - 1;
                x_2 = i;
                break;
            }
        }
    }

    // Calculate temp1, temp2
    double a1, a2, b1, b2;

    // 0:nor 1:inv 2:nand
    if (!power_or_not)
    {
        if (which == 0 && transtime_or_delay == false && fall_or_rise == false)
        {
            table = data_ptr->nor_fall_transition;
        }
        else if (which == 0 && transtime_or_delay == false && fall_or_rise == true)
        {
            table = data_ptr->nor_rise_transition;
        }
        else if (which == 0 && transtime_or_delay == true && fall_or_rise == false)
        {
            table = data_ptr->nor_cell_fall;
        }
        else if (which == 0 && transtime_or_delay == true && fall_or_rise == true)
        {
            table = data_ptr->nor_cell_rise;
        }
        else if (which == 1 && transtime_or_delay == false && fall_or_rise == false)
        {
            table = data_ptr->inv_fall_transition;
        }
        else if (which == 1 && transtime_or_delay == false && fall_or_rise == true)
        {
            table = data_ptr->inv_rise_transition;
        }
        else if (which == 1 && transtime_or_delay == true && fall_or_rise == false)
        {
            table = data_ptr->inv_cell_fall;
        }
        else if (which == 1 && transtime_or_delay == true && fall_or_rise == true)
        {
            table = data_ptr->inv_cell_rise;
        }
        else if (which == 2 && transtime_or_delay == false && fall_or_rise == false)
        {
            table = data_ptr->nand_fall_transition;
        }
        else if (which == 2 && transtime_or_delay == false && fall_or_rise == true)
        {
            table = data_ptr->nand_rise_transition;
        }
        else if (which == 2 && transtime_or_delay == true && fall_or_rise == false)
        {
            table = data_ptr->nand_cell_fall;
        }
        else if (which == 2 && transtime_or_delay == true && fall_or_rise == true)
        {
            table = data_ptr->nand_cell_rise;
        }
    }
    else
    {
        if (which == 0 && fall_or_rise == false)
        {
            table = data_ptr->nor_fall_power;
        }
        else if (which == 0 && fall_or_rise == true)
        {
            table = data_ptr->nor_rise_power;
        }
        else if (which == 1 && fall_or_rise == false)
        {
            table = data_ptr->inv_fall_power;
        }
        else if (which == 1 && fall_or_rise == true)
        {
            table = data_ptr->inv_rise_power;
        }
        else if (which == 2 && fall_or_rise == false)
        {
            table = data_ptr->nand_fall_power;
        }
        else if (which == 2 && fall_or_rise == true)
        {
            table = data_ptr->nand_rise_power;
        }
    }

    a1 = table[x_1][y_1];
    a2 = table[x_1][y_2];
    b1 = table[x_2][y_1];
    b2 = table[x_2][y_2];

    double temp, temp1, temp2;

    if (output_c < data_ptr->out_capacitance[0]) // under
    {
        temp = (data_ptr->out_capacitance[y_1] - output_c) / (data_ptr->out_capacitance[y_2] - data_ptr->out_capacitance[y_1]);
        temp1 = a1 - ((a2 - a1) * temp);
        temp2 = b1 - ((b2 - b1) * temp);
    }
    else if (output_c > data_ptr->out_capacitance[data_ptr->out_capacitance.size() - 1]) // over
    {
        temp = (output_c - data_ptr->out_capacitance[y_2]) / (data_ptr->out_capacitance[y_2] - data_ptr->out_capacitance[y_1]);
        temp1 = a2 + ((a2 - a1) * temp);
        temp2 = b2 + ((b2 - b1) * temp);
    }
    else
    {
        if (y_2 == y_1)
        {
            temp1 = a1;
            temp2 = b1;
        }
        else
        {
            temp = (output_c - data_ptr->out_capacitance[y_1]) / (data_ptr->out_capacitance[y_2] - data_ptr->out_capacitance[y_1]);
            temp1 = a1 + ((a2 - a1) * temp);
            temp2 = b1 + ((b2 - b1) * temp);
        }
    }

    double number;
    double number_temp;
    if (x_2 == x_1)
        number_temp = 0;
    else
        number_temp = (temp2 - temp1) / (data_ptr->in_transition[x_2] - data_ptr->in_transition[x_1]);

    if (input_trans < data_ptr->in_transition[0])
    {
        number = temp1 - number_temp * (data_ptr->in_transition[x_1] - input_trans);
    }
    else if (input_trans > data_ptr->in_transition[data_ptr->in_transition.size() - 1])
    {
        number = temp2 + number_temp * (input_trans - data_ptr->in_transition[x_2]);
    }
    else
    {
        number = temp1 + number_temp * (input_trans - data_ptr->in_transition[x_1]);
    }

    return number;
}

void STA::Calulate_delay(void)
{
    for (auto cell : top_order) // caculate all cell delay in order
    {
        // cout << cell -> name << " first " << cell -> is_first << endl;
        if (cell->which_cell == 0) // nor
        {
            // cout << cell -> name << " first " << cell -> is_first << endl;
            if (cell->is_first) //  is first gate
            {
                for (int i = 0; i < total_pat_number; i++)
                {
                    bool out_logic = !(cell->in1->pattern_num[i] || cell->in2->pattern_num[i]);
                    double trans_time = Get_data_from_table(0, 0, out_logic, 0, cell->out_capa, 0);
                    double out_delay = Get_data_from_table(0, 1, out_logic, 0, cell->out_capa, 0);
                    double in_power = Get_data_from_table(0, 1, out_logic, 1, cell->out_capa, 0);
                    cell->internal_power.push_back(in_power);
                    cell->out->pattern_num.push_back(out_logic);
                    cell->transition_time.push_back(trans_time);
                    cell->delay.push_back(out_delay);
                    cell->total_delay.push_back(out_delay);
                    if (i == 0)
                    {
                        if (out_logic)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    else
                    {
                        if (out_logic == 0 && cell->out->pattern_num[i - 1] == 1)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                        else if (out_logic == 1 && cell->out->pattern_num[i - 1] == 0)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    total_power[i] = total_power[i] + in_power;
                } // every pattern
            }

            else // not first gate
            {
                for (int i = 0; i < total_pat_number; i++)
                {
                    double in_trans;
                    double in_delay;
                    bool out_logic = !(cell->in1->pattern_num[i] || cell->in2->pattern_num[i]);
                    if (cell->in1->is_input)
                    {
                        // in_trans = cell -> in2 -> front_cell -> transition_time[i];
                        in_trans = (cell->in1->pattern_num[i] == 1) ? 0 : cell->in2->front_cell->transition_time[i];
                        in_delay = (cell->in1->pattern_num[i] == 1) ? 0 : cell->in2->front_cell->total_delay[i];
                    }
                    else if (cell->in2->is_input)
                    {
                        // in_trans = cell -> in1 -> front_cell -> transition_time[i];
                        in_trans = (cell->in2->pattern_num[i] == 1) ? 0 : cell->in1->front_cell->transition_time[i];
                        in_delay = (cell->in2->pattern_num[i] == 1) ? 0 : cell->in1->front_cell->total_delay[i];
                    }
                    else
                    {
                        if (cell->in1->pattern_num[i] == 1 && cell->in2->pattern_num[i] == 1)
                        {
                            in_trans = (cell->in1->front_cell->total_delay[i] < cell->in2->front_cell->total_delay[i]) ? cell->in1->front_cell->transition_time[i] : cell->in2->front_cell->transition_time[i];
                            in_delay = (cell->in1->front_cell->total_delay[i] < cell->in2->front_cell->total_delay[i]) ? cell->in1->front_cell->total_delay[i] : cell->in2->front_cell->total_delay[i];
                            // in_trans = (cell->in1->front_cell->transition_time[i] < cell->in2->front_cell->transition_time[i]) ? cell->in1->front_cell->transition_time[i] : cell->in2->front_cell->transition_time[i];
                        }
                        else if (cell->in1->pattern_num[i] == 1 && cell->in2->pattern_num[i] == 0)
                        {
                            in_trans = cell->in1->front_cell->transition_time[i];
                            in_delay = cell->in1->front_cell->total_delay[i];
                        }
                        else if (cell->in1->pattern_num[i] == 0 && cell->in2->pattern_num[i] == 1)
                        {
                            in_trans = cell->in2->front_cell->transition_time[i];
                            in_delay = cell->in2->front_cell->total_delay[i];
                        }
                        else
                        {
                            in_delay = (cell->in1->front_cell->total_delay[i] > cell->in2->front_cell->total_delay[i]) ? cell->in1->front_cell->total_delay[i] : cell->in2->front_cell->total_delay[i];
                            in_trans = (cell->in1->front_cell->total_delay[i] > cell->in2->front_cell->total_delay[i]) ? cell->in1->front_cell->transition_time[i] : cell->in2->front_cell->transition_time[i];
                            // in_trans = (cell->in1->front_cell->transition_time[i] > cell->in2->front_cell->transition_time[i]) ? cell->in1->front_cell->transition_time[i] : cell->in2->front_cell->transition_time[i];
                        }
                    }

                    double trans_time = Get_data_from_table(0, 0, out_logic, 0, cell->out_capa, in_trans);
                    double out_delay = Get_data_from_table(0, 1, out_logic, 0, cell->out_capa, in_trans);
                    double in_power = Get_data_from_table(0, 1, out_logic, 1, cell->out_capa, in_trans);
                    cell->internal_power.push_back(in_power);
                    cell->out->pattern_num.push_back(out_logic);
                    cell->transition_time.push_back(trans_time);
                    cell->delay.push_back(out_delay);
                    cell->total_delay.push_back(in_delay + out_delay);
                    if (i == 0)
                    {
                        if (out_logic)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    else
                    {
                        if (out_logic == 0 && cell->out->pattern_num[i - 1] == 1)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                        else if (out_logic == 1 && cell->out->pattern_num[i - 1] == 0)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    total_power[i] = total_power[i] + in_power;

                } // every pattern
            }
        }
        else if (cell->which_cell == 1) // inv
        {
            if (cell->is_first) //  is first gate
            {
                for (int i = 0; i < total_pat_number; i++)
                {
                    bool out_logic = !(cell->in1->pattern_num[i]);
                    double trans_time = Get_data_from_table(1, 0, out_logic, 0, cell->out_capa, 0);
                    double out_delay = Get_data_from_table(1, 1, out_logic, 0, cell->out_capa, 0);
                    double in_power = Get_data_from_table(1, 1, out_logic, 1, cell->out_capa, 0);
                    cell->internal_power.push_back(in_power);
                    cell->out->pattern_num.push_back(out_logic);
                    cell->transition_time.push_back(trans_time);
                    cell->delay.push_back(out_delay);
                    cell->total_delay.push_back(out_delay);
                    if (i == 0)
                    {
                        if (out_logic)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    else
                    {
                        if (out_logic == 0 && cell->out->pattern_num[i - 1] == 1)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                        else if (out_logic == 1 && cell->out->pattern_num[i - 1] == 0)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    total_power[i] = total_power[i] + in_power;
                } // every pattern
            }
            else // not first gate
            {
                for (int i = 0; i < total_pat_number; i++)
                {
                    double in_trans;
                    double in_delay = cell->in1->front_cell->total_delay[i];
                    bool out_logic = !(cell->in1->pattern_num[i]);
                    in_trans = cell->in1->front_cell->transition_time[i];
                    double trans_time = Get_data_from_table(1, 0, out_logic, 0, cell->out_capa, in_trans);
                    double out_delay = Get_data_from_table(1, 1, out_logic, 0, cell->out_capa, in_trans);
                    double in_power = Get_data_from_table(1, 1, out_logic, 1, cell->out_capa, in_trans);
                    cell->internal_power.push_back(in_power);
                    cell->out->pattern_num.push_back(out_logic);
                    cell->transition_time.push_back(trans_time);
                    cell->delay.push_back(out_delay);
                    cell->total_delay.push_back(in_delay + out_delay);
                    if (i == 0)
                    {
                        if (out_logic)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    else
                    {
                        if (out_logic == 0 && cell->out->pattern_num[i - 1] == 1)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                        else if (out_logic == 1 && cell->out->pattern_num[i - 1] == 0)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    total_power[i] = total_power[i] + in_power;

                } // every pattern
            }
        }
        else if (cell->which_cell == 2) // nand
        {
            if (cell->is_first) //  is first gate
            {
                for (int i = 0; i < total_pat_number; i++)
                {
                    bool out_logic = !(cell->in1->pattern_num[i] && cell->in2->pattern_num[i]);
                    double trans_time = Get_data_from_table(2, 0, out_logic, 0, cell->out_capa, 0);
                    double out_delay = Get_data_from_table(2, 1, out_logic, 0, cell->out_capa, 0);
                    double in_power = Get_data_from_table(2, 1, out_logic, 1, cell->out_capa, 0);
                    cell->internal_power.push_back(in_power);
                    cell->out->pattern_num.push_back(out_logic);
                    cell->transition_time.push_back(trans_time);
                    cell->delay.push_back(out_delay);
                    cell->total_delay.push_back(out_delay);
                    if (i == 0)
                    {
                        if (out_logic)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    else
                    {
                        if (out_logic == 0 && cell->out->pattern_num[i - 1] == 1)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                        else if (out_logic == 1 && cell->out->pattern_num[i - 1] == 0)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    total_power[i] = total_power[i] + in_power;

                } // every pattern
            }
            else // not first gate
            {
                for (int i = 0; i < total_pat_number; i++)
                {
                    double in_trans;
                    double in_delay;
                    bool out_logic = !(cell->in1->pattern_num[i] && cell->in2->pattern_num[i]);
                    if (cell->in1->is_input)
                    {
                        // in_trans = cell -> in2 -> front_cell -> transition_time[i];
                        in_trans = (cell->in1->pattern_num[i] == 0) ? 0 : cell->in2->front_cell->transition_time[i];
                        in_delay = (cell->in1->pattern_num[i] == 0) ? 0 : cell->in2->front_cell->total_delay[i];
                    }
                    else if (cell->in2->is_input)
                    {
                        // in_trans = cell -> in1 -> front_cell -> transition_time[i];
                        in_trans = (cell->in2->pattern_num[i] == 0) ? 0 : cell->in1->front_cell->transition_time[i];
                        in_delay = (cell->in2->pattern_num[i] == 0) ? 0 : cell->in1->front_cell->total_delay[i];
                    }
                    else
                    {
                        if (cell->in1->pattern_num[i] == 0 && cell->in2->pattern_num[i] == 0)
                        {
                            // in_trans = (cell->in1->front_cell->transition_time[i] < cell->in2->front_cell->transition_time[i]) ? cell->in1->front_cell->transition_time[i] : cell->in2->front_cell->transition_time[i];
                            in_delay = (cell->in1->front_cell->total_delay[i] < cell->in2->front_cell->total_delay[i]) ? cell->in1->front_cell->total_delay[i] : cell->in2->front_cell->total_delay[i];
                            in_trans = (cell->in1->front_cell->total_delay[i] < cell->in2->front_cell->total_delay[i]) ? cell->in1->front_cell->transition_time[i] : cell->in2->front_cell->transition_time[i];
                        }
                        else if (cell->in1->pattern_num[i] == 0 && cell->in2->pattern_num[i] == 1)
                        {
                            in_delay = cell->in1->front_cell->total_delay[i];
                            in_trans = cell->in1->front_cell->transition_time[i];
                        }
                        else if (cell->in1->pattern_num[i] == 1 && cell->in2->pattern_num[i] == 0)
                        {
                            in_delay = cell->in2->front_cell->total_delay[i];
                            in_trans = cell->in2->front_cell->transition_time[i];
                        }
                        else
                        {
                            in_delay = (cell->in1->front_cell->total_delay[i] > cell->in2->front_cell->total_delay[i]) ? cell->in1->front_cell->total_delay[i] : cell->in2->front_cell->total_delay[i];
                            in_trans = (cell->in1->front_cell->total_delay[i] > cell->in2->front_cell->total_delay[i]) ? cell->in1->front_cell->transition_time[i] : cell->in2->front_cell->transition_time[i];
                            // in_trans = (cell->in1->front_cell->transition_time[i] > cell->in2->front_cell->transition_time[i]) ? cell->in1->front_cell->transition_time[i] : cell->in2->front_cell->transition_time[i];
                        }
                    }

                    double trans_time = Get_data_from_table(2, 0, out_logic, 0, cell->out_capa, in_trans);
                    double out_delay = Get_data_from_table(2, 1, out_logic, 0, cell->out_capa, in_trans);
                    double in_power = Get_data_from_table(2, 1, out_logic, 1, cell->out_capa, in_trans);
                    cell->internal_power.push_back(in_power);
                    cell->out->pattern_num.push_back(out_logic);
                    cell->transition_time.push_back(trans_time);
                    cell->delay.push_back(out_delay);
                    cell->total_delay.push_back(in_delay + out_delay);
                    if (i == 0)
                    {
                        if (out_logic)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    else
                    {
                        if (out_logic == 0 && cell->out->pattern_num[i - 1] == 1)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                        else if (out_logic == 1 && cell->out->pattern_num[i - 1] == 0)
                        {
                            if (cell->toggle_0_to_1_time < 20)
                            {
                                cell->toggle_0_to_1_time++;
                                covera[i]++;
                            }
                            total_power[i] += cell->switch_power;
                        }
                    }
                    total_power[i] = total_power[i] + in_power;

                } // every pattern
            }
        }
    }

    sort(top_order.begin(), top_order.end(), capacitance_compare);
}

int main(int argc, char *argv[])
{
    STA sta_time;
    sta_time.Read_lib_data(argv[3]);
    sta_time.Read_circuit(argv[1]);
    sta_time.Read_pat_file(argv[2]);
    sta_time.Calculate_output_capacitance();
    sta_time.Write_output_load_file(argv[1]);
    sta_time.Topological_sort();
    sta_time.Calulate_delay();
    sta_time.Write_delay_file(argv[1]);
    sta_time.Write_power_file(argv[1]);
    sta_time.Write_coverage_file(argv[1]);
    return 0;
}
