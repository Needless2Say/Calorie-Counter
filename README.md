# Calorie-Counter
This is a C++ program with 3 files: calorie_counter.h, calorie_counter.cpp, and main.cpp.
The main function is to help track as many nutritional facts as possible by saving info in a text file that is read by the program.
The user then inputs the food they ate and the amount, which can range from amount as in number eaten or in grams or in cups.
The input text file that it reads info about the food nutrition facts is in a set format as shown below:

Oatmeal: 0.5
Calories: 150
Total Fat: 3
Saturated Fat: 0.5
Polyunsaturated Fat: 1
Monounsaturated Fat: 1
Potassium: 150
Total Carbohydrates: 27
Dietary Fiber: 4
Soluble Fiber: 2
Total Sugars: 1
Protein: 5

Milk: 1
Calories: 120
Total Fat: 5
Saturated Fat: 3
Cholesterol: 20
Sodium: 115
Potassium: 350
Total Carbohydrates: 12
Total Sugars:12
Protein: 8

The first line is the food name followed by a colon then a space then the serving size. The next lines are the Nutrition facts.
The info needs to be stored in a text file called info.txt and after every food info should be followed by an empty line.
See info.txt for more examples.

The different nutrition facts currently stored in the class are shown below:
std::vector<std::string> all_food_content = 
    {"Calories","Total Fat","Saturated Fat","Trans Fat","Polyunsaturated Fat","Monounsaturated Fat","Cholesterol","Sodium","Potassium",
    "Total Carbohydrates","Dietary Fiber","Soluble Fiber","Dietary Sugars","Total Sugars","Added Sugars","Erythritol","Protein"};

Any other nutrition facts that are missing can be added manually as well with adding the units to the units vector:
std::vector<std::string> all_food_content_units = 
    {"calories", "grams", "grams", "grams", "grams", "grams", "milligrams", "milligrams",
    "milligrams", "grams", "grams", "grams", "grams", "grams", "grams", "grams", "grams"};

and adding a zero to the all_food_content_amount vector:
std::vector<double> all_food_content_amount = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  
The input can be typed in a separate text file and then copy pasted into the terminal. Below is an example:
Oatmeal: 1.5
Blue Berries: 0.5
Banana: 326
Whole Milk: 2
Adult Vitamins: 8
Nectarine: 1
Coffee Cookie: 1
Milk Chocolate Rice Cake: 1
stop

The format for inputting info is the food name followed by a colon and then followed by a space and then the serving amount eaten.
The units do not matter as long as the serving size and info inputted into the info.txt file is correct. The program will calculate everything.
The input needs to end with "stop" as that tells the program to stop reading in info from the user.
The output will add everything up and display it on the terminal.
Have fun!
