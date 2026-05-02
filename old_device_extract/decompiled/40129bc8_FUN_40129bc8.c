// Function : FUN_40129bc8
// Address  : 0x40129bc8
// Size     : 98 bytes


uint FUN_40129bc8(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0xffff8f00;
  if ((param_1[9] != 0) && (uVar2 = 0, param_1[0x36] != 0)) {
    while (iVar1 = param_1[0x36], iVar1 != 0) {
      uVar2 = (*(code *)param_1[9])(param_1[0xc],param_1[0x30] - iVar1,iVar1);
      if ((int)uVar2 < 1) {
        return uVar2;
      }
      if ((uint)param_1[0x36] < uVar2) {
        return 0xffff9400;
      }
      param_1[0x36] = param_1[0x36] - uVar2;
    }
    iVar1 = param_1[0x2e];
    if (*(char *)(*param_1 + 5) != '\x01') {
      iVar1 = iVar1 + 8;
    }
    param_1[0x30] = iVar1;
    memw();
    FUN_40185840(param_1,param_1[0x13]);
    uVar2 = 0;
  }
  return uVar2;
}

