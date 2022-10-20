#include "mainwindow.h"
 #include "xlsxdocument.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    Py_Initialize();
//          if ( !Py_IsInitialized() )
//          {
//          return -1;
//          }
//          PyRun_SimpleString("import sys");
//          PyRun_SimpleString("sys.argv = ['python.py']");
//          PyRun_SimpleString("sys.path.append('./')");

//          //导入scriptSecond.py模块
//          PyObject* pModule = PyImport_ImportModule("scriptSecond");
//          if (!pModule) {
//                  printf("Cant open python file!\n");
//                  return -1;
//              }
          //获取scriptSecond模块中的temperImg函数
//         PyObject* pFunhello= PyObject_GetAttrString(pModule,"temperImg");
         //注释掉的这部分是另一种获得scriptSecond模块中的temperImg函数的方法
     //    PyObject* pDict = PyModule_GetDict(pModule);
     //       if (!pDict) {
     //           printf("Cant find dictionary.\n");
     //           return -1;
     //       }
     //    PyObject* pFunhello = PyDict_GetItemString(pDict, "temperImg");

//          if(!pFunhello){
//              cout<<"Get function hello failed"<<endl;
//              return -1;
//          }
//          //调用temperImg函数
//          PyObject_CallFunction(pFunhello,NULL);
//          //结束，释放python

             return a.exec();
}
