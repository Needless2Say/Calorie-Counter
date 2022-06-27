#include "calorie_counter.cpp"

int main(){
    stuff cal;
    std::ifstream info ("info.txt");
    info.is_open();
    cal.get_info(info);
    info.close();
    //cal.print_food_info_content();
    //cal.print_food_info_amount();
    //cal.print_food_serving_size();
    //cal.print_food_info_units();
    cal.check_serving_size();
    //cal.print_food_info_amount();
    cal.input_info_manual();
    //cal.input_info_textfile();
    //cal.print_food_info_input();
    cal.calculate_total_food_content();
    //cal.print_food_info_calculated_amount();
    cal.print_info();
}
