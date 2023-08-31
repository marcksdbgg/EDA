# Purpose: Graficar histogramas de las dimensiones de la tabla de datos

import pandas as pd
import matplotlib.pyplot as plt

# Abrir archivo de datos separados por comas
df2 = pd.read_csv('Datos.txt', sep='/n', header=None)
dim2 = df2.T.squeeze()
dim2.plot.hist(grid=True, bins=20, rwidth=0.9, color='#607c8e')
plt.title('Histograma de la dimensión 500')
plt.xlabel('Valor')
plt.ylabel('Frecuencia')
plt.grid(axis='y', alpha=0.75)
plt.show()