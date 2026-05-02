// Function : FUN_401688d0
// Address  : 0x401688d0
// Size     : 117 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401688d0(char param_1)

{
  int iVar1;
  
  if (param_1 == '\0') {
    _DAT_3ffca40c = (**(code **)(_DAT_3ffc1a34 + 0x15c))(0x3c);
    if (_DAT_3ffca40c == 0) {
      memw();
      FUN_40147fe4(1,0x100,2,0x3f4371df);
      return 0x101;
    }
    (*(code *)&SUB_4008b530)(_DAT_3ffca40c,0,0x3c);
    iVar1 = FUN_40165e64();
    if ((iVar1 != 0) &&
       (iVar1 = (**(code **)(_DAT_3ffc1a34 + 300))("gth:%d\n",1,_DAT_3ffca40c + 0x38), iVar1 != 0))
    {
      FUN_40147fe4(1,0x100,2,0x3f4371c0,iVar1);
      return iVar1;
    }
  }
  *(undefined4 *)(_DAT_3ffca40c + 8) = 0;
  memw();
  return 0;
}

