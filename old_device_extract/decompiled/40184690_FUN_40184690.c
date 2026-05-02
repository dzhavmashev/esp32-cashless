// Function : FUN_40184690
// Address  : 0x40184690
// Size     : 107 bytes


undefined4 FUN_40184690(int param_1,byte *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  while( true ) {
    while( true ) {
      uVar1 = (ushort)*param_2;
      if (uVar1 == 0) {
        if (uVar3 == 3) {
          *(char *)(param_1 + 7) = (char)uVar2;
          return 1;
        }
        return 0;
      }
      param_2 = param_2 + 1;
      if (9 < (uVar1 - 0x30 & 0xff)) break;
      uVar2 = uVar2 * 10 + -0x30 + uVar1;
      if (0xff < uVar2) {
        return 0;
      }
    }
    if (uVar3 == 3) break;
    if (uVar1 != 0x2e) {
      return 0;
    }
    *(char *)(param_1 + uVar3 + 4) = (char)uVar2;
    uVar3 = uVar3 + 1 & 0xff;
    uVar2 = 0;
  }
  return 0;
}

