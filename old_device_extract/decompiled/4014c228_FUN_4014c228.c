// Function : FUN_4014c228
// Address  : 0x4014c228
// Size     : 148 bytes


undefined4 FUN_4014c228(uint *param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  if (uVar1 == 0x4ac0f00) {
    return 3;
  }
  if (uVar1 < 0x4ac0f01) {
    if (uVar1 == 0x1ac0f00) {
      if (param_2 == (undefined1 *)0x0) {
        return 6;
      }
      uVar2 = 5;
LAB_4014c2ab:
      *param_2 = uVar2;
      memw();
      memw();
      return 6;
    }
    if (uVar1 < 0x1ac0f01) {
      uVar3 = 0;
      uVar4 = 0xac0f00;
    }
    else {
      if (uVar1 == 0x2ac0f00) {
        return 1;
      }
      uVar3 = 2;
      uVar4 = 0x3ac0f00;
    }
  }
  else {
    if (uVar1 == 0x6ac0f00) {
      return 9;
    }
    if (uVar1 < 0x6ac0f01) {
      if (uVar1 != 0x5ac0f00) {
        return 0x20;
      }
      if (param_2 == (undefined1 *)0x0) {
        return 6;
      }
      uVar2 = 0xd;
      goto LAB_4014c2ab;
    }
    if (uVar1 == 0xbac0f00) {
      return 0xd;
    }
    uVar3 = 0xe;
    uVar4 = 0xcac0f00;
  }
  if (uVar1 != uVar4) {
    return 0x20;
  }
  return uVar3;
}

