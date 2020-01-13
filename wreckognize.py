# Load libraries
from pandas import read_csv
from pandas.plotting import scatter_matrix
from matplotlib import pyplot
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import StratifiedKFold
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC
import tkinter
from tabulate import tabulate
# Load dataset
url = "https://raw.githubusercontent.com/ramishsyed/Wreckognize/master/training%20data.csv"
names = ['month', 'hour', 'weather', 'driver', 'pf', 'pb', 'pl1', 'pl2', 'pr1', 'pr2', 'af', 'ab', 'al1', 'al2', 'ar1', 'ar2', 'danger']
dataset = read_csv(url, names=names)
# Split-out validation dataset
array = dataset.values
X = array[:,0:16]
y = array[:,16]
X_train, X_validation, Y_train, Y_validation = train_test_split(X, y, test_size=1, random_state=1)
model = SVC(gamma='auto')
model.fit(X_train, Y_train)
mon = input("Enter the month: ")
hou = input("Enter the hour of the day (1-24): ")
print(tabulate([['Clear', 1], ['Overcast', 2], ['Raining', 3], ['Snowing', 4], ['Freezing Rain', 5], ['Low Visibility',6],['Strong Wind',7]], headers=['Weather', 'Value']))
wea = input("Enter the weather: ")
dri = input("Enter driver risk value (1-4): ")
Xnew = [[mon,hou,wea,dri,1,1,1,1,1,1,1,1,1,1,1,1]]
#Xnew=[[6,13,2,1,2,1,2,2,2,1,1,2,2,1,2,2]]
ynew=model.predict(Xnew)
if ynew == 1:
    print("Minor (Level 1) Accident Detected")
if ynew == 2:
    print("Major (Level 2) Accident Detected")
if ynew == 3:
    print("Critical (Level 3) Accident Detected")
