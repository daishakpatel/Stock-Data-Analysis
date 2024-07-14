# Stock Analysis Project

## Project Overview
The Stock Analysis Project is a comprehensive Windows Form Application designed to load, display, and analyze stock data. The application allows users to visualize stock performance through candlestick charts, manage multiple stock displays, and identify various candlestick patterns. This project is divided into three parts, each building on the previous to enhance functionality and user experience.

## Features
- **Candlestick Charts:** Display OHLC (Open, High, Low, Close) data in a visually informative candlestick chart.
- **Volume Data:** Display stock volume as a column plot.
- **DataGridView Integration:** Show stock data in a tabular format for easy viewing and analysis.
- **User Inputs:** Allow users to specify stock symbols, date ranges, and candle periods (daily, weekly, monthly).
- **Multi-Stock Management:** Display and update multiple stocks each in their own form.
- **Candlestick Pattern Recognition:** Identify various candlestick patterns and highlight them using annotations.
- **Dynamic Controls:** Use of ComboBox to dynamically select and display patterns.

## Project Structure
### Part 1: Basic Stock Data Visualization
- **Goal:** Load and display stock data in candlestick chart format and in a DataGridView.
- **Input:** Stock data files in .csv format stored in a folder named "Stock Data". The data should include daily, weekly, and monthly versions named `xxx-Day.csv`, `xxx-Week.csv`, and `xxx-Month.csv` respectively.
- **Output:** Display the OHLC data in candlestick format and volume data as a column plot.

### Part 2: Enhanced Stock Management and Display
- **Goal:** Extend functionality to manage and display multiple stocks, each in their own form.
- **Features:**
  - Allow the user to pick multiple stocks and display each in a separate form.
  - Remove DataGridView for more space.
  - Ensure the charts are normalized and handle data gaps for weekends and holidays.
  - Enable real-time updates of chart data without reloading stock data.
  - Implement a new `SmartCandlestick` class with properties like range, body range, top and bottom prices, and tail heights.

### Part 3: Candlestick Pattern Recognition
- **Goal:** Implement advanced candlestick pattern recognition using specialized recognizer classes.
- **Features:**
  - Create a new class `SmartCandlestick` derived from the `Candlestick` class.
  - Implement various candlestick patterns (single, two, and three candlestick patterns) with recognizer classes.
  - Use annotations to highlight patterns on the charts.
  - Ensure the ComboBox dynamically lists all possible patterns.
  - Use an abstract base class `Recognizer` and implement specific pattern recognizers.
  - Implement a top-level object to manage all recognizers and facilitate pattern analysis.

## Getting Started
### Prerequisites
- Visual Studio with .NET Framework support.
- Basic understanding of C++ and Windows Forms.

### Installation
1. **Download the Project:**
   - Clone the repository or download the zip file.
2. **Open the Solution:**
   - Open the solution file in Visual Studio.
3. **Build the Solution:**
   - Go to `Build` -> `Build Solution` to compile the project.
4. **Run the Application:**
   - Press `F5` or go to `Debug` -> `Start Debugging`.

### Usage
1. **Load Stock Data:**
   - Place your stock .csv files in the `Stock Data` folder.
   - Ensure files are named correctly as `xxx-Day.csv`, `xxx-Week.csv`, `xxx-Month.csv`.
2. **Specify Parameters:**
   - Use the input controls to specify the stock symbol, date range, and candle period.
3. **View Charts:**
   - Analyze the candlestick and volume charts.
4. **Pattern Recognition (Part 3):**
   - Use the ComboBox to select and highlight specific candlestick patterns.

## Documentation
- **Comments:** All methods and significant code lines are commented.
- **Code Structure:** Follows naming conventions and best practices discussed.
- **Resources:**
  - [C# Syntax (w3schools.com)](https://www.w3schools.com/cs/)
  - [C# Tutorial - Stock Chart & Candlestick Chart C# Winforms .Net | FoxLearn - YouTube](https://www.youtube.com/watch?v=x8_lQda88Ro)
  - [Introducing Data Binding with Windows Form (c-sharpcorner.com)](https://www.c-sharpcorner.com/UploadFile/8911c4/data-binding-with-windows-forms/)
  - [C# Tutorial - How to Link Chart /Graph with Database | FoxLearn - YouTube](https://www.youtube.com/watch?v=_hJ3ygkNhoM)
  - [Overview of Data Binding and Windows Forms - Windows Forms .NET | Microsoft Learn](https://docs.microsoft.com/en-us/dotnet/desktop/winforms/data-binding/?view=netdesktop-6.0)
  - [A Detailed Data Binding Tutorial - CodeProject](https://www.codeproject.com/Articles/23259/A-Detailed-Data-Binding-Tutorial)

## Contribution
Feel free to fork the repository, make improvements, and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License
This project is licensed under the MIT License.

---

This README provides a comprehensive guide to all three parts of the Stock Analysis Project, making it clear and structured for users or contributors.