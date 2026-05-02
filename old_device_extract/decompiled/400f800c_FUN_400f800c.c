// Function : FUN_400f800c
// Address  : 0x400f800c
// Size     : 165 bytes


undefined4 FUN_400f800c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint auStack_60 [6];
  undefined4 auStack_48 [18];
  
  if (param_1 != 0) {
    iVar1 = FUN_400f7e4c(param_1,0);
    if (iVar1 != 0) {
      return 0x1503;
    }
    if (*(int *)(param_1 + 4) == 0) {
      uVar5 = *(uint *)(param_1 + 8);
      if (uVar5 == 0) {
        iVar1 = FUN_400f8eb4(1,0,0);
        if (iVar1 == 0) {
          return 0x105;
        }
        uVar2 = FUN_400f9018(iVar1,0,*(undefined4 *)(iVar1 + 0x10));
        return uVar2;
      }
      iVar1 = FUN_400f7e98(auStack_60);
      if (iVar1 == 0) {
        return 0x105;
      }
      uVar3 = FUN_400f7fd0();
      uVar5 = uVar5 & 0xf;
      if (uVar3 <= uVar5) {
        return 0x102;
      }
      uVar4 = FUN_400f84a4(auStack_60);
      uVar5 = uVar5 + 1;
      if (uVar4 == 0xffffffff) {
        memw();
        uVar3 = 0;
        auStack_48[0] = 0;
      }
      else {
        for (uVar5 = uVar5 % uVar3; uVar5 < auStack_60[uVar4 * 8]; uVar5 = uVar5 + uVar3) {
        }
        uVar3 = (uVar4 ^ 0xffffffff) & 1;
        auStack_48[uVar3 * 8] = 0;
      }
      memw();
      uVar2 = FUN_400f7f24(auStack_60,uVar5,uVar3,iVar1);
      return uVar2;
    }
  }
  return 0x102;
}

