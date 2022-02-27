from matplotlib import markers
import matplotlib.pyplot as plt 
import numpy as np

x = np.array([1,2,2,3,4,4,5,5,7])
y= np.array([2,6,4,4,5,3,1,8,6])
hx=np.array([1,2,5,5,7])
hy=np.array([2,6,1,8,6])


plt.plot(x,y,'.')
plt.plot(hx,hy,'.',marker='o',ms=10,mec='g')
plt.show()
plt.close()