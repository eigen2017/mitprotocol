/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.zhuxin.mitprotocol;

public class mitprotocolJNI {
  public final static native boolean IntDeque_empty(long jarg1, IntDeque jarg1_);
  public final static native long new_IntDeque__SWIG_0();
  public final static native long new_IntDeque__SWIG_1(long jarg1, int jarg2);
  public final static native long new_IntDeque__SWIG_2(long jarg1);
  public final static native long new_IntDeque__SWIG_3(long jarg1, IntDeque jarg1_);
  public final static native void delete_IntDeque(long jarg1);
  public final static native void IntDeque_assign(long jarg1, IntDeque jarg1_, long jarg2, int jarg3);
  public final static native void IntDeque_swap(long jarg1, IntDeque jarg1_, long jarg2, IntDeque jarg2_);
  public final static native long IntDeque_size(long jarg1, IntDeque jarg1_);
  public final static native long IntDeque_max_size(long jarg1, IntDeque jarg1_);
  public final static native void IntDeque_resize__SWIG_0(long jarg1, IntDeque jarg1_, long jarg2, int jarg3);
  public final static native void IntDeque_resize__SWIG_1(long jarg1, IntDeque jarg1_, long jarg2);
  public final static native int IntDeque_front(long jarg1, IntDeque jarg1_);
  public final static native int IntDeque_back(long jarg1, IntDeque jarg1_);
  public final static native void IntDeque_push_front(long jarg1, IntDeque jarg1_, int jarg2);
  public final static native void IntDeque_push_back(long jarg1, IntDeque jarg1_, int jarg2);
  public final static native void IntDeque_pop_front(long jarg1, IntDeque jarg1_);
  public final static native void IntDeque_pop_back(long jarg1, IntDeque jarg1_);
  public final static native void IntDeque_clear(long jarg1, IntDeque jarg1_);
  public final static native int IntDeque_getitem(long jarg1, IntDeque jarg1_, int jarg2);
  public final static native void IntDeque_setitem(long jarg1, IntDeque jarg1_, int jarg2, int jarg3);
  public final static native void IntDeque_delitem(long jarg1, IntDeque jarg1_, int jarg2);
  public final static native long IntDeque_getslice(long jarg1, IntDeque jarg1_, int jarg2, int jarg3);
  public final static native void IntDeque_setslice(long jarg1, IntDeque jarg1_, int jarg2, int jarg3, long jarg4, IntDeque jarg4_);
  public final static native void IntDeque_delslice(long jarg1, IntDeque jarg1_, int jarg2, int jarg3);
  public final static native void MitProtocolCallBack_TestFunc(long jarg1, MitProtocolCallBack jarg1_, long jarg2, IntDeque jarg2_);
  public final static native long new_MitProtocolCallBack();
  public final static native void delete_MitProtocolCallBack(long jarg1);
  public final static native void MitProtocolCallBack_director_connect(MitProtocolCallBack obj, long cptr, boolean mem_own, boolean weak_global);
  public final static native void MitProtocolCallBack_change_ownership(MitProtocolCallBack obj, long cptr, boolean take_or_release);
  public final static native void MitProtocolInterface_ReleaseMe(long jarg1, MitProtocolInterface jarg1_);
  public final static native void MitProtocolInterface_SetCallBack(long jarg1, MitProtocolInterface jarg1_, long jarg2, MitProtocolCallBack jarg2_);
  public final static native void MitProtocolInterface_UnTar(long jarg1, MitProtocolInterface jarg1_, String jarg2);
  public final static native void MitProtocolInterface_SetMitFilePath(long jarg1, MitProtocolInterface jarg1_, String jarg2, String jarg3);
  public final static native long MitProtocolInterface_GetDat(long jarg1, MitProtocolInterface jarg1_, int jarg2);
  public final static native void delete_MitProtocolInterface(long jarg1);
  public final static native long CreateMitProtocolInterface();

  public static void SwigDirector_MitProtocolCallBack_TestFunc(MitProtocolCallBack jself, long param) {
    jself.TestFunc(new IntDeque(param, false));
  }

  private final static native void swig_module_init();
  static {
    swig_module_init();
  }
}
