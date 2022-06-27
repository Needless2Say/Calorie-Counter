#include "calorie_counter.h"

void stuff::get_info(std::ifstream &info){
    // declare variable for text input
    std::string line;

    // read through entire file
    while(!std::getline(info, line).eof()) {
        // declare variables
        std::string name, units, temp_serving;
        double serving;

        // filter first line of info.txt for name, serving size, and units
        name = line.substr(0,line.find(':'));
        temp_serving = line.substr(line.find(':')+2);
        serving = stod(temp_serving);

        // insert serving size and units into hashmaps
        food_serving_size.insert(std::pair<std::string, double>(name,serving));

        // declare vector variables outside loop so they can be inserted into respective hashmaps after loop
        std::vector<std::string> food_content;
        std::vector<double> food_amount;

        // filter through contents of food and sort into hashmaps
        std::getline(info, line);
        while(line != ""){
            // declare variables
            std::string content, unit, temp;
            double amount;

            // filter lines of info.text for specific food and sort into content, amount, and unit
            content = line.substr(0,line.find(':'));
            temp = line.substr(line.find(':')+2);
            amount = stod(temp);

            // sort content, amount, and unit into vectors
            food_content.push_back(content);
            food_amount.push_back(amount);

            // grab the next line until the next line is empty
            std::getline(info, line);
        }
        // insert food_amount and food_units into respective hashmaps
        food_info_content.insert(std::pair<std::string, std::vector<std::string>>(name,food_content));
        food_info_amount.insert(std::pair<std::string, std::vector<double>>(name,food_amount));
    }
}

// function for changing the serving size to 1
void stuff::check_serving_size(){
    // loop checking for serving size to be equal to 1
    for(auto& [name, serving_size] : food_serving_size){
        if(serving_size > 1 || serving_size < 1){
            // loop to change the amount in the contents of the food label to fit a serving size of 1
            for(auto& [food_name, amount] : food_info_amount){
                if(food_name == name){
                    for(int i = 0; i < static_cast<int>(amount.size()); i++){
                        amount[i] = (amount[i]/serving_size);
                    }
                    break;
                }else{
                    continue;
                }
            }
            // set serving size to 1 after adjusting all values in content accordingly
            serving_size = 1;
        }
    }
}

void stuff::input_info_manual(){
    // output info for the user to read
    std::cout << "Input what you have eaten today below. Type in stop when you are done inputting your food info. ";
    std::cout << "If consumed amount is not a whole number, type it out in decimal format. ";
    std::cout << "Follow this example format below for this code to work.\n";
    std::cout << "Oatmeal: 0.5\n";

    // take input from user
    std::string line = "";
    std::getline(std::cin, line);
    std::cout << "\n";
    while(line != "stop"){
        // declare units
        std::string name, temp, units;
        double amount;

        // separate string into the three items to be stored
        name = line.substr(0,line.find(':'));
        temp = line.substr(line.find(':')+2);
        amount = stod(temp);

        // store info in food_info_input map for calculations and output
        food_info_input.insert(std::pair<std::string, double>(name, amount));

        // ask user to input info again
        std::getline(std::cin, line);
        std::cout << "\n";
    }
}

void stuff::input_info_textfile(){
    std::string line;
    std::ifstream info ("food_input.txt");
    info.is_open();
    while(!std::getline(info, line).eof()) {
        // declare variables
        std::string content, unit, temp;
        double amount;

        // filter lines of info.text for specific food and sort into content, amount, and unit
        content = line.substr(0,line.find(':'));
        temp = line.substr(line.find(':')+2);
        amount = stod(temp);

        // store info in food_info_input map for calculations and output
        food_info_input.insert(std::pair<std::string, double>(content, amount));
    }
    info.close();
}

void stuff::calculate_total_food_content(){    
    // loop through items consumed and calculate total food content by multiplying serving size to all food content amounts
    for(auto [name, servings_consumed] : food_info_input){
        // declare vectors to store name of food content and amount calculated
        std::vector<std::string> food_content;
        std::vector<double> content_amount;

        // loop for storing info in vectors to be stored in maps
        for(auto [food, content_name_vector] : food_info_content){
            std::string name_lower = name, food_lower = food;
                for (int i = 0; i < static_cast<int>(name_lower.length()); i++){
  		            name_lower[i] = tolower(name_lower[i]);
  	            }
                for (int i = 0; i < static_cast<int>(food_lower.length()); i++){
  		            food_lower[i] = tolower(food_lower[i]);
  	            }

            if(food_lower == name_lower){
                food_content = content_name_vector;
                break;
            }
        }

        // loop for storing food amount in vectors
        for(auto [food, food_amount_vector] : food_info_amount){
            std::string name_lower = name, food_lower = food;
                for (int i = 0; i < static_cast<int>(name_lower.length()); i++){
  		            name_lower[i] = tolower(name_lower[i]);
  	            }
                for (int i = 0; i < static_cast<int>(food_lower.length()); i++){
  		            food_lower[i] = tolower(food_lower[i]);
  	            }
            if(food_lower == name_lower){
                content_amount = food_amount_vector;
                break;
            }
        }

        // loop through to make the serving size amount multiplied by the amount consumed
        for(auto [food, serving_size] : food_info_input){
            std::string name_lower = name, food_lower = food;
                for (int i = 0; i < static_cast<int>(name_lower.length()); i++){
  		            name_lower[i] = tolower(name_lower[i]);
  	            }
                for (int i = 0; i < static_cast<int>(food_lower.length()); i++){
  		            food_lower[i] = tolower(food_lower[i]);
  	            }
            if(food_lower == name_lower){
                // loop through content amount and multiply all numbers by the amount consumed in input vector
                for(int i = 0; i < static_cast<int>(content_amount.size()); i++){
                    content_amount[i] = content_amount[i]*serving_size;
                }
                break;
            }
        }

        // store calculated amount of food info content consumed
        food_info_calculated_amount.insert(std::pair<std::string, std::vector<double>>(name, content_amount));

        // store total of all food content in map for output
        for(int i = 0; i < static_cast<int>(all_food_content.size()); i++){
            for(int j = 0; j < static_cast<int>(food_content.size()); j++){
                std::string all_food_content_lower = all_food_content[i], food_content_lower = food_content[j];
                for (int i = 0; i < static_cast<int>(all_food_content_lower.length()); i++){
  		            all_food_content_lower[i] = tolower(all_food_content_lower[i]);
  	            }
                for (int i = 0; i < static_cast<int>(food_content_lower.length()); i++){
  		            food_content_lower[i] = tolower(food_content_lower[i]);
  	            }

                if(all_food_content_lower == food_content_lower){
                    all_food_content_amount[i] += content_amount[j];
                }
            }
        }
    }
}

void stuff::print_info(){
    std::cout << "Total info for today:\n";
    for(int i = 0; i < static_cast<int>(all_food_content.size()); i++){
        std::cout << all_food_content[i] << ": " << all_food_content_amount[i] << " " << all_food_content_units[i] << "\n";
    }
}







// print functions
void stuff::print_food_info_content(){
    std::cout << "This is food_info_content:\n";
    for(auto [food, content_info] : food_info_content){
        std::cout << food << ": ";
        for(int i = 0; i < static_cast<int>(content_info.size()); i++){
            std::cout << content_info[i] << " ";
        }
        std::cout << "\n";
    }
}

void stuff::print_food_info_amount(){
    std::cout << "This is food_info_amount:\n";
    for(auto [food, amount]: food_info_amount){
        std::cout << food << ": ";
        for(int i = 0; i < static_cast<int>(amount.size()); i++){
            std::cout << amount[i] << " ";
        }
        std::cout << "\n";
    }
}

void stuff::print_food_serving_size(){
    std::cout << "This is food_serving_size:\n";
    for(auto [food, serving_size] : food_serving_size){
        std::cout << food << ": " << serving_size << "\n";
    }
}

void stuff::print_food_info_input(){
    std::cout << "This is food_info_input:\n";
    for(auto [name, amount] : food_info_input){
        std::cout << name << ": " << amount << "\n";
    }
}

void stuff::print_food_info_calculated_amount(){
    std::cout << "This is food_info_calculated_amount:\n";
    for(auto [name, amount] : food_info_calculated_amount){
        std::cout << name << ": ";
        for(int i = 0; i < static_cast<int>(amount.size()); i++){
            std::cout << amount[i] << " ";
        }
        std::cout << "\n";
    }
}
