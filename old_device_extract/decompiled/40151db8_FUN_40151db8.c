// Function : FUN_40151db8
// Address  : 0x40151db8
// Size     : 194 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40151db8(int param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = **(byte **)(*(int *)(param_1 + 4) + 4);
  if ((bVar2 & 0xc) == 0) {
    bVar2 = bVar2 & 0xf0;
    if (((((*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) & 0x80000) == 0) && (_DAT_3ffc89f4 != 0)) &&
        ((_DAT_3ffc8800 == 0 || (*(char *)(_DAT_3ffc8800 + 0x154) == '\x06')))) &&
       ((bVar2 + 0x60 & 0xd0) == 0)) {
      _DAT_3ffc89f4 = 0;
      DAT_3ffc89f6 = 0;
      memw();
      memw();
      FUN_4015fde8(0,_DAT_3ffc89b8);
      if (_DAT_3ffc8940 != 0) {
        (**(code **)(_DAT_3ffc1a34 + 0xb0))();
        _DAT_3ffc8940 = 0;
      }
      if (_DAT_3ffc8930 != 0) {
        memw();
        (**(code **)(_DAT_3ffc1a34 + 0xb0))();
        _DAT_3ffc8930 = 0;
      }
      if (_DAT_3ffc8934 != 0) {
        memw();
        (**(code **)(_DAT_3ffc1a34 + 0xb0))();
        _DAT_3ffc8934 = 0;
      }
    }
    memw();
    iVar1 = FUN_4015eae0();
    if ((bVar2 == 0xd0) && (iVar1 != 0)) {
      FUN_4015eb08(*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x13 & 1,
                   *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x13));
    }
  }
  return;
}

