
%module(directors="1") mitprotocol

%include "std_string.i"

%include "std_deque.i"

%{
#include "mitprotocol.h"
%}

namespace std {
   %template(IntDeque) deque<int>;
   %template(MitProtocolAnnNodeDeque) deque<MitProtocolAnnNode>;
   %template(StringDeque) deque<string>;
}

%feature("director") MitProtocolCallBack;

%include cpointer.i
%pointer_functions(int, intp);
%pointer_functions(double, doublep);

%pragma(java) jniclasscode=%{
  static {
    try {
        System.loadLibrary("mitprotocol");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("Native code library failed to load. \n" + e);
      System.exit(1);
    }
  }
%}


%include "../../mitprotocol/src/traffic/mitprotocol.h"

