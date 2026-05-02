// Function : FUN_40121960
// Address  : 0x40121960
// Size     : 57 bytes


undefined4 FUN_40121960(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*(code *)&SUB_40086eac)();
  uVar2 = 7;
  if (uVar1 != 4) {
    if (uVar1 < 5) {
      iVar3 = uVar1 - 2;
    }
    else {
      if (uVar1 == 5) {
        uVar1 = (*(code *)&SUB_40083c60)();
        if (uVar1 < 300) {
          return 7;
        }
        return 0x12;
      }
      iVar3 = uVar1 - 6;
      uVar2 = 0x12;
    }
    if (iVar3 != 0) {
      uVar2 = 10;
    }
  }
  return uVar2;
}

