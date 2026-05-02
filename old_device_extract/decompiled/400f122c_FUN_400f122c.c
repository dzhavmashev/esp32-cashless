// Function : FUN_400f122c
// Address  : 0x400f122c
// Size     : 89 bytes


undefined4 FUN_400f122c(char *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  if (param_1 != param_2) {
    iVar1 = FUN_40184778(param_1);
    iVar2 = FUN_40184778(param_2);
    uVar3 = 0;
    if ((iVar1 == iVar2) && (uVar3 = 1, iVar1 != 0)) {
      if ((param_1[0xf] & 0x80U) == 0) {
        param_1 = *(char **)param_1;
      }
      if ((param_2[0xf] & 0x80U) == 0) {
        param_2 = *(char **)param_2;
      }
      do {
        if (*param_1 == '\0') {
          return 1;
        }
        iVar1 = func_0x4008cd54();
        param_1 = param_1 + 1;
        iVar2 = func_0x4008cd54(*param_2);
        param_2 = param_2 + 1;
      } while (iVar1 == iVar2);
      uVar3 = 0;
    }
  }
  return uVar3;
}

