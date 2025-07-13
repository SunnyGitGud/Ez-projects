#include <iostream>
using namespace std;




double CelsiusToFahrenhiet(double celsius){
    return (celsius * 9.0/5.0) + 32.0;  
}

double FahrenheitToCelsius(double fahrenheit)
{
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double CelsiusToKelvin(double celsius)
{
  return celsius + 273.15;
}

double KelvinToCelsius(double kelvin)
{
  return kelvin - 273.15;
}

int main() {
    int choice;
    double temperature, convertedTemperature;
    cout << "Temperature converter" << endl;
    cout << "1. Celsius to fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Celsius to kelvin" << endl;
    cout << "4. Kelvin to Celsius" << endl;
    cout << "Enter Your Choice(1-4)" ; cin >> choice; 
    cout << "Enter the temprature" ; cin >> temperature;

    switch (choice)
    {
    case 1:
       convertedTemperature = CelsiusToFahrenhiet(temperature);
        break;
    case 2:
       convertedTemperature = FahrenheitToCelsius(temperature);
        break;
    case 3:
       convertedTemperature = CelsiusToKelvin(temperature);
        break;
    case 4:
       convertedTemperature = KelvinToCelsius(temperature);
        break;
    default: cout << "invalid choice." << endl;
        return 1;
        break;
    }

    cout << "Converted temprature: "<< convertedTemperature << endl;
    return 0;

}
