import numpy as np
import matplotlib.pyplot as plt

arr = np.loadtxt('max_lik.dat',dtype = 'double')
x = np.arange(0,1000000)
plt.scatter(x,arr)
plt.grid()
plt.xlabel('$X-AXIS$')
plt.ylabel('$Y$')
plt.legend(loc='best')
plt.grid()
plt.savefig('5-2.png')
plt.show()
