// Function : FUN_400e98ac
// Address  : 0x400e98ac
// Size     : 121 bytes


int FUN_400e98ac(int *param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  iVar3 = 1;
  if ((param_2 == (undefined1 *)0x0 && param_3 != 0) || ((int)(uVar1 | uVar1 - 1) < 0)) {
    return -1;
  }
  if (param_3 == 0) {
    return 0;
  }
  if (param_1[0xd] < 0) {
    iVar3 = 0;
  }
  else {
    *param_2 = (char)param_1[0xd];
    param_3 = param_3 + -1;
    param_1[0xd] = -1;
    if (param_3 == 0) {
      return 1;
    }
    if (uVar1 - 1 == 0) {
      return 1;
    }
    param_2 = param_2 + 1;
  }
  iVar2 = FUN_400eaae0(param_1[0xb],param_2,param_3);
  if (-1 < iVar2) {
    return iVar2 + iVar3;
  }
  (**(code **)(*param_1 + 0x3c))(param_1);
  if (iVar3 != 0) {
    return 1;
  }
  return iVar2;
}

