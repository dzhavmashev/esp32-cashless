// Function : FUN_4014e314
// Address  : 0x4014e314
// Size     : 149 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4014e314(void)

{
  int iVar1;
  
  iVar1 = 0x3007;
  if (_DAT_3ffc8800 != 0) {
    FUN_40161498();
    FUN_4015549c();
    if (*(int *)(_DAT_3ffc8800 + 0x98) != 0) {
      FUN_40157594(&DAT_3ffc87f0,0);
      FUN_401615bc();
      return 0;
    }
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffc8800 + 4);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(_DAT_3ffc8800 + 4);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffc8800 + 0x18);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(_DAT_3ffc8800 + 0x18);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffc8800 + 0x68);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(_DAT_3ffc8800 + 0x68);
    *(undefined1 *)(_DAT_3ffc8800 + 0x7c) = 0;
    memw();
    memw();
    FUN_401615bc();
    iVar1 = -(uint)(_DAT_3ffc8864 != 0);
  }
  return iVar1;
}

