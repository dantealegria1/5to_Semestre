#Programa para calcular el modelo logistico para prediccion de poblacion
import numpy as np
anios = [1970, 1980, 1990, 2000, 2010,2020]
poblacion = [48.225,66.846,83.249,112.336,127.09]
#Funcion para calcular el modelo logistico
def modeloLogistico(x,a,b,c):
    return c/(1+a*np.exp(-b*x))
#Ajuste de curva
from scipy.optimize import curve_fit
parametrosIniciales = np.array([1,1,1])
parametrosOptimizados, pcov = curve_fit(modeloLogistico, anios, poblacion, parametrosIniciales, maxfev=10000)
#parametrosOptimizados, pcov = curve_fit(modeloLogistico, anios, poblacion, parametrosIniciales, maxfev=10000)
#Grafica de resultados
import matplotlib.pyplot as plt
plt.figure(figsize=(10,6))
x=np.linspace(1960,2030,100)
y=modeloLogistico(x,parametrosOptimizados[0],parametrosOptimizados[1],parametrosOptimizados[2])
plt.plot(anios,poblacion,'o',label='Datos Reales')
plt.plot(x,y,label='Modelo Logístico')
plt.xlabel('Años')
plt.ylabel('Población')
plt.legend()
plt.show()


