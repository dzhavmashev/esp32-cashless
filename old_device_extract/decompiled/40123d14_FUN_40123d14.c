// Function : FUN_40123d14
// Address  : 0x40123d14
// Size     : 235 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_40123d14(int param_1,int param_2,int param_3,short param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 != 1) {
    if (param_3 != 2) {
      return 0xffffffff;
    }
    if ((_DAT_3ffc7604 == 2) && (iVar2 = FUN_40128584(&DAT_3ffc7604,param_1,param_2), iVar2 == 0)) {
      _DAT_3ffc7604 = 3;
      memw();
      FUN_40104304(0x3ffc760a,0x3ffc762a,1);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
    FUN_40123ccc();
    return uVar1;
  }
  if (_DAT_3ffc7604 == 1) {
    if (param_4 == 0x4c) {
      if (_DAT_3ffc7600 != 0) {
        FUN_4010531c();
      }
      uVar1 = (uint)DAT_3ffc7654;
      if ((DAT_3ffc7654 & 1) == 0) {
        _DAT_3ffc7600 = FUN_401052f0(param_1 + 2,param_2 + -2);
        memw();
        return uVar1 & 1;
      }
      if (*(char *)(param_1 + 2) != -1) {
        return 0xffffffff;
      }
      if (*(byte *)(param_1 + 3) == 0) {
        return 0xffffffff;
      }
      if (param_2 - 4U < (uint)*(byte *)(param_1 + 3)) {
        return 0xffffffff;
      }
      if (*(char *)(param_1 + 4) != ']') {
        return 0xffffffff;
      }
      _DAT_3ffc7600 = FUN_401052f0(param_1 + 5,param_2 + -5);
      memw();
      return 0;
    }
    memw();
    uVar1 = FUN_401280e0(&DAT_3ffc7604,param_1,param_2,0,0,0x3ffbf740,param_4 == 0x7e);
    if (uVar1 != 0xffff) {
      if (uVar1 != 0) {
        return uVar1;
      }
      uVar1 = FUN_40127c64(&DAT_3ffc7604);
      return uVar1;
    }
  }
  return 0x3017;
}

