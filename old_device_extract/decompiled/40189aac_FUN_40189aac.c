// Function : FUN_40189aac
// Address  : 0x40189aac
// Size     : 116 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40189aac(void)

{
  int iVar1;
  
  if (_DAT_3ffc7d68 != 0) {
    memw();
    _DAT_3ff73084 = _DAT_3ff73084 & 0x7fffffff;
    memw();
    memw();
    iVar1 = FUN_40189a7c();
    DAT_3ffc7d64 = (undefined1)iVar1;
    memw();
    if (iVar1 != 0) {
      memw();
      memw();
      _DAT_3ff73084 = _DAT_3ff73084 | 0x80000000;
      memw();
      return;
    }
    DAT_3ffc7d65 = 1;
    memw();
    memw();
    FUN_401899d8();
    _DAT_3ffc7d6c = FUN_401668f8();
    memw();
    FUN_40189960(_DAT_3ffc7d68);
    _DAT_3ffc7d70 = _DAT_3ffc06fc;
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x108))();
  }
  return;
}

