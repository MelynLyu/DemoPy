import datetime
import numpy as np
from numpy.core.numeric import NaN
import pandas as pd
import re
import matplotlib.pyplot as plt
from pandas.core.frame import DataFrame
from pandas.core.indexes import category
import plotly
import seaborn

# Data Preparation and Cleansing

## 1
raw_data = pd.read_csv("HW6_pgcounty_food_inspection.csv")
#print(len(raw_data))

unique_Category = raw_data["Category"].unique()
#print(len(unique_Category))


## 2
raw_data["Inspection_date"] = pd.to_datetime(raw_data["Inspection_date"])
raw_data["Inspection_year"] = raw_data["Inspection_date"].dt.year
raw_data["Inspection_month"] = raw_data["Inspection_date"].dt.month
raw_data["Inspection_year_month"] = pd.to_datetime(raw_data["Inspection_year"].astype(str) + "-" + raw_data["Inspection_month"].astype(str))
#print(raw_data["Inspection_year_month"])

## 3
compliance_types = ["Food_from_approved_source", "Food_protected_from_contamination", "Ill_workers_restricted",
    "Proper_hand_washing", "Cooling_time_and_temperature", "Cold_holding_temperature", "Hot_holding_temperature",
    "Cooking_time_and_temperature", "Reheating_time_and_temperature", "Hot_and_cold_running_water_provided",
    "Proper_sewage_disposal", "No_bare_hand_contact", "Adequate_hand_washing_facilities", "Rodent_and_insects",
    "Food_contact_surfaces_and_equipment"]

def convert_compliance(value):
    res = NaN
    if value == "In Compliance":
        value = 0
    elif value == "Out of Compliance":
        value = 1
    else:
        value = NaN
    return value

for compliance_type in compliance_types:
    raw_data[compliance_type] = raw_data[compliance_type].apply(convert_compliance)
    #print(raw_data[compliance_type])

## 4
raw_data["Violations"] = raw_data[compliance_types].sum(axis=1)
raw_data["Is_Compliance"] = raw_data["Violations"].apply(lambda x: 0 if x == 0 else 1)

## 5
## Statistic data shows that
## each establishment Id only corresponds to only one category
IdToCategory = {}
cnt = 0
for i in range(len(raw_data)):
    Id = raw_data.at[i, "Establishment_id"]
    Category = raw_data.at[i, "Category"]
    
    if Id in IdToCategory:
        if Category != IdToCategory[Id]:
            cnt += 1
    else:
        IdToCategory[id] = Category
print(cnt)

new_df = raw_data[["Establishment_id", "Category", "Inspection_date", "Violations"]].copy()
multiInspection_df = new_df.drop_duplicates(subset=["Establishment_id", "Inspection_date"], keep="last")
pivot_df = multiInspection_df.pivot(index="Establishment_id", columns="Inspection_date", values="Violations")

# Statistics/Data Grouping
## 6
## Top 3 types of violations are:
## 1. Cold_holding_temperature
## 2. Food_contact_surfaces_and_equipment
## 3. Rodent_and_insects.

violation_table = {}
for compliance_type in compliance_types:
    violation_table[compliance_type] = raw_data[compliance_type].sum()

violation_table = pd.DataFrame.from_dict(violation_table, orient='index', columns=['Num of Violations'])
violation_table = violation_table.sort_values(by=["Num of Violations"], ascending=False)
#print(violation_table)

## 7
print(pivot_df)

# Data Visualization

## 8
labels = violation_table.index.tolist()
plt.bar(range(len(labels)), violation_table["Num of Violations"], color='g')
plt.show()

