// Function : FUN_40128094
// Address  : 0x40128094
// Size     : 70 bytes


undefined4 FUN_40128094(int *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  param_3 = param_3 & 0xffff;
  puVar3 = param_2;
  if (param_2 != (uint *)0x0) {
    do {
      uVar2 = *puVar3;
      if ((int)uVar2 < 1) {
        if (param_3 != uVar2) {
          return 0x4d;
        }
        break;
      }
      puVar3 = puVar3 + 1;
    } while (param_3 != uVar2);
  }
  if (*param_1 == 1) {
    if (param_3 != param_1[0xf]) {
      return 0x4d;
    }
  }
  else if ((param_3 != param_1[0xf]) && (iVar1 = FUN_40127254(param_1), iVar1 < 0)) {
    return 0x4d;
  }
  if (param_1[0x12] == 0) {
    return 1;
  }
  if ((*(int *)(param_1[0x12] + 0x48) != 0) && (param_2 == (uint *)0x0)) {
    return 0x4d;
  }
  return 0;
}

