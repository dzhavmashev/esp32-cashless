// Function : FUN_4016357c
// Address  : 0x4016357c
// Size     : 115 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4016357c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((_DAT_3ffc7bf8 != 0) && (_DAT_3ffc7be8 != 0)) {
    _DAT_3ffc7bf4 = (**(code **)(_DAT_3ffc1a34 + 0x34))(1,0);
    if (_DAT_3ffc7bf4 != 0) {
      iVar1 = (*(code *)&SUB_40087bcc)(0xf,0);
      if (iVar1 == 0) {
        (**(code **)(_DAT_3ffc1a34 + 0x3c))(_DAT_3ffc7bf4,0xffffffff);
      }
      else {
        FUN_401629ac();
      }
      (**(code **)(_DAT_3ffc1a34 + 0x9c))(1);
      (**(code **)(_DAT_3ffc1a34 + 0x38))(_DAT_3ffc7bf4);
      memw();
      _DAT_3ffc7bf4 = 0;
      return 0;
    }
    memw();
    _DAT_3ffc7bf4 = 0;
  }
  uVar2 = FUN_401629ac();
  return uVar2;
}

