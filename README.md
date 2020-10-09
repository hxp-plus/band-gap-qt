# 禁带宽度处理程序 by hxp

此程序为Qt程序，后端运算需要MATLAB R2019b。其中`band-gap-qt`是编译好的可执行程序。



如果不能运行那可能是因为MATLAB库的位置问题，需要修改`band-gap-qt.pro`中

```
INCLUDEPATH += /usr/local/Polyspace/R2019b/extern/include

LIBS += /usr/local/Polyspace/R2019b/extern/bin/glnxa64/libMatlabDataArray.so

LIBS += /usr/local/Polyspace/R2019b/extern/bin/glnxa64/libMatlabEngine.so
```

这几行到你的MATLAB相应类库的位置。



程序会自动开启MATLAB Session。