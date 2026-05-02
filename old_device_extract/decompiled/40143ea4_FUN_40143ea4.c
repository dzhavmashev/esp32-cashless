// Function : FUN_40143ea4
// Address  : 0x40143ea4
// Size     : 113 bytes


int FUN_40143ea4(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar2 = *(uint *)(param_1 + 4);
  if ((uVar2 == param_3) &&
     (iVar1 = FUN_4018681c(param_2,*(undefined4 *)(param_1 + 8),uVar2), iVar1 == 0)) {
    return 0;
  }
  iVar1 = (*(code *)&SUB_4008c01c)(param_2);
  if (((2 < uVar2) && (pcVar4 = *(char **)(param_1 + 8), *pcVar4 == '*')) &&
     (iVar3 = 0, pcVar4[1] == '.')) {
    for (; iVar1 != iVar3; iVar3 = iVar3 + 1) {
      if (*(char *)(param_2 + iVar3) == '.') {
        if (iVar3 == 0) {
          return -1;
        }
        if (iVar1 - iVar3 == uVar2 - 1) {
          iVar1 = FUN_4018681c(pcVar4 + 1);
          return -(uint)(iVar1 != 0);
        }
        return -1;
      }
    }
  }
  return -1;
}

