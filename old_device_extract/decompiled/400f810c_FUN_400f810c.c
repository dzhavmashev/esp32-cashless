// Function : FUN_400f810c
// Address  : 0x400f810c
// Size     : 175 bytes


bool FUN_400f810c(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char acStack_62 [2];
  int aiStack_60 [8];
  undefined1 auStack_40 [64];
  
  iVar1 = FUN_400f7e98(acStack_62 + 2);
  if ((iVar1 != 0) && (uVar2 = FUN_400f7fd0(), uVar2 != 0)) {
    acStack_62[0] = FUN_400f8368(acStack_62 + 2);
    memw();
    memw();
    acStack_62[1] = FUN_400f8368(auStack_40);
    memw();
    memw();
    uVar3 = FUN_4018487c(acStack_62 + 2,acStack_62,1);
    if (uVar3 != 0xffffffff) {
      uVar3 = (uVar3 ^ 0xffffffff) & 1;
      if (acStack_62[uVar3] == '\0') {
        iVar1 = FUN_400f8eb4(0,0,0);
        if ((iVar1 != 0) && (iVar1 = FUN_400f7e4c(iVar1,1), iVar1 == 0)) {
          return true;
        }
        if (acStack_62[uVar3] == '\0') {
          return false;
        }
      }
      iVar1 = FUN_400f8eb4(0,(*(int *)(acStack_62 + uVar3 * 0x20 + 2) - 1U) % uVar2 + 0x10);
      if (iVar1 != 0) {
        iVar1 = FUN_400f7e4c(iVar1,1);
        return iVar1 == 0;
      }
    }
  }
  return false;
}

