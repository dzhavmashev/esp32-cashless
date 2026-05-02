// Function : FUN_4015ebb4
// Address  : 0x4015ebb4
// Size     : 109 bytes


undefined4 FUN_4015ebb4(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (param_2 == 7) {
    piVar2 = (int *)&DAT_3ffbfea8;
joined_r0x4015ebe4:
    if (param_3 == 0) {
LAB_4015ebfa:
      pcVar4 = (code *)*piVar2;
      if ((pcVar4 == (code *)0x0) || (param_1 == 0)) {
        return 1;
      }
      goto LAB_4015ec0d;
    }
  }
  else if (param_2 < 8) {
    if ((param_2 == 3) && (iVar1 = 0x3ffbfeac, param_3 < 3)) {
LAB_4015ebf7:
      piVar2 = (int *)(param_3 * 4 + iVar1);
      goto LAB_4015ebfa;
    }
  }
  else if (param_2 == 8) {
    if (param_3 < 2) {
      iVar1 = 0x3ffbfe9c;
      goto LAB_4015ebf7;
    }
  }
  else if (param_2 == 0x7f) {
    piVar2 = (int *)&DAT_3ffbfea4;
    goto joined_r0x4015ebe4;
  }
  pcVar4 = (code *)&LAB_40186ab7_1;
  if (param_1 == 0) {
    return 1;
  }
LAB_4015ec0d:
  uVar3 = (*pcVar4)(param_1,param_2,param_3,param_4);
  return uVar3;
}

