#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <numeric>

class stuff{
    private:
    // All food content manual input checker
    std::vector<std::string> all_food_content = 
    {"Calories","Total Fat","Saturated Fat","Trans Fat","Polyunsaturated Fat","Monounsaturated Fat","Cholesterol","Sodium","Potassium",
    "Total Carbohydrates","Dietary Fiber","Soluble Fiber","Dietary Sugars","Total Sugars","Added Sugars","Erythritol","Protein"};
    std::vector<double> all_food_content_amount = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<std::string> all_food_content_units = 
    {"calories", "grams", "grams", "grams", "grams", "grams", "milligrams", "milligrams",
    "milligrams", "grams", "grams", "grams", "grams", "grams", "grams", "grams", "grams"};

    // storing food info from info.txt
    std::map <std::string, std::vector<std::string>> food_info_content;
    std::map <std::string, std::vector<double>> food_info_amount;
    std::map <std::string, double> food_serving_size;

    // storing food amount consumed from user input
    std::map <std::string, double> food_info_input;

    // storing info on food info content for each food consumed
    std::map <std::string, std::vector<double>> food_info_calculated_amount;

    public:
    // main functions
    void get_info(std::ifstream &info);
    void check_serving_size();
    void input_info_manual();
    void input_info_textfile();
    void calculate_total_food_content();
    void print_info();
    void print_info_textfile();

    // print info functions
    void print_food_info_content();
    void print_food_info_amount();
    void print_food_serving_size();
    void print_food_info_input();
    void print_food_info_calculated_amount();
    void print_food_content_consumed();
};
