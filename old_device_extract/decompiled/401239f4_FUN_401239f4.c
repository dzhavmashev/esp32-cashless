// Function : FUN_401239f4
// Address  : 0x401239f4
// Size     : 71 bytes


undefined4 FUN_401239f4(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4015a0c4();
  if (iVar1 == 0) {
    iVar1 = FUN_4015a0f4();
    if ((iVar1 == 0) && (iVar1 = FUN_4015a140(), iVar1 == 0)) {
      iVar1 = FUN_4015a120();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      uVar2 = FUN_40159fd8();
      FUN_401042ac(4,uVar2);
      return 0;
    }
    uVar2 = FUN_40159fd8();
    uVar3 = 2;
  }
  else {
    uVar2 = FUN_40159fd8();
    uVar3 = 1;
  }
  FUN_401042ac(uVar3,uVar2);
  return 0;
}

