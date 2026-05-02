// Function : FUN_400ff420
// Address  : 0x400ff420
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ff420(char param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if (param_1 == '\0') {
    for (iVar1 = 0; iVar1 != _DAT_3ffc5804; iVar1 = iVar1 + 1) {
      iVar2 = *(int *)(iVar1 * 4 + 0x3ffc5808);
      if ((iVar2 != 0) && (pcVar3 = *(code **)(iVar2 + 0x98), pcVar3 != (code *)0x0)) {
        memw();
        (*pcVar3)();
        return;
      }
    }
  }
  else {
    (*(code *)&SUB_4008fde8)(param_2,param_3);
  }
  return;
}

