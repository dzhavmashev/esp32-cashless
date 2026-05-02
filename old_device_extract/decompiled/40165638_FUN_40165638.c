// Function : FUN_40165638
// Address  : 0x40165638
// Size     : 49 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40165638(char param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (((param_1 == '\0') || (DAT_3ffc072c == '\0')) || ((_DAT_3ffc0730 & 2) == 0)) {
    uVar2 = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    uVar2 = _DAT_3ffc1bbc;
  }
  FUN_401676f4(1,uVar1,uVar2);
  return 0;
}

