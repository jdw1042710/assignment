#include <iostream>
#define MAX_RECIPE 100
#define MAX_INGREDIENT 100

using namespace std;

class Greeter {
    private:
        RecipeDB recipeDB;
        PlanManager planManager;
    public:
        Greeter();
        void browse();//print defult screen
        void editPlan(); //add or annotate or delete a plan
        void editRecipe(); //add or annotate or delete a Recipe
};

class PlanManager {
    private:
        Date week[7]; //a Plan of course in this week 
    public:
        PlanManager();
        void addPlan(Date data); // add Plan to week
        void annotatePlan(); // annotate one of Plan in  week
        Recipe deletePlan(); // delete existing Plan in week
        void browsePlan(); // print Plans (which is in this week) into screen
};

class RecipeDB{
    private:
        Recipe recipeList[MAX_RECIPE];
    public:
        RecipeDB();
        void addRecipe(Recipe data); // add recipe at recipeList
        void anotateRecipe(); // annotate one of Recipes in recipeList
        void deleteRecipe(); // delete existing recipe in recipeList
        void browseRecipe(); // print recipeList
        Recipe getRecipe(); // return recipe in recipeList
};

class Date{
    private:
        Meal meal; 
        string annotation;
    public:
        Date();
        void printGroceryList(); // print all grocery list 
};

class Meal{
    private:
        Recipe* RecipeList;
        int peopleNum;
    public:
        Meal();
        void setMeal(int peopleNum); // automatically set this meal depending on peopleNum
        Ingredient* getAllGrocery(); // get entire Grocery from Recipes in this meal
};

class Recipe{
    private:
        Ingredient Grocery[MAX_INGREDIENT];
        void addIngredient(); // add Ingredient in this recipe
        void deleteIngredient(); // delete Ingredient in this recipe
    public:
        Recipe();
        void editIngredient(); // add or delete Inredients in this recipe
        Ingredient* getGrocery(); // return Ingredients used in this recipe
        void printRecipe();// print recipe and all ingredients
};

class Ingredient{
    private:
        string name; //Ingredient name
        int num; // number of Ingredient
    public:
        Ingredient(string name, int num);
        void printIngredient();// print Information of this ingredient
        Ingredient getIngredient(); // return this ingredient object
};