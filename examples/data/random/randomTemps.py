import pandas as pd
import numpy as np

targetPath = "lib/data/generated/random"

def calculateRain(humidity : int, windSpeed : int, temperature : int):
    if(temperature < 0): return False
    sum = (humidity * 1.5 - 10) + (windSpeed * 0.25) + (temperature * 0.8)
    if sum >= 100:
        print("returning true")
        return True
    else: return False

def main():
    # Generate random temperature data
    length = int(input("Length of data (default: 30): ")   )
    if not length: length = 30

    data = {
        'Date': pd.date_range(start='2023-01-01', periods=length, freq='d'),
        'Temperature': np.random.randint(low=-10, high=35, size=length),
        'WindSpeed' : np.random.randint(low = 2, high=40, size = length),
        'Humidity' : np.random.randint(low=0, high=100, size=length)
    }

    df = pd.DataFrame(data)
    df['Rain'] = df.apply(lambda row: calculateRain(row['Humidity'], row['WindSpeed'], row['Temperature']), axis=1)
    
    #Create a sub-dataframe with only the rows that have Rain
    rain_df = df[df['Rain'] == True]
    print("Sub-Dataframe: ")
    print(rain_df)

    mean_humidity = rain_df['Humidity'].mean()
    mean_windspeed = rain_df['WindSpeed'].mean()
    mean_temperature = rain_df['Temperature'].mean()

    print("Average humidity: ", mean_humidity)
    print("Averge windspeed: ", mean_windspeed)
    print("Average temperature: ", mean_temperature)

    # Create a DataFrame
    print(df)

    fname = input("Save to fname: (default: random_temps)")
    if not fname: fname = "random_temps"

    # Save DataFrame to a .csv file
    csv_path = f"{targetPath}/{fname}.csv"
    df.to_csv(csv_path, index=False)

if __name__ == '__main__':
    main()