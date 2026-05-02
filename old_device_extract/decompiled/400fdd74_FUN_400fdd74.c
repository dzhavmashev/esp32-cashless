// Function : FUN_400fdd74
// Address  : 0x400fdd74
// Size     : 91 bytes


void FUN_400fdd74(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x50);
  if (iVar2 == 5) {
    *param_2 = 0;
  }
  else {
    if (iVar2 != 6) {
      if (iVar2 == 7) {
        uVar1 = (*(code *)&SUB_40083730)();
        *param_2 = uVar1;
        memw();
      }
      goto LAB_400fdd85;
    }
    *param_2 = 1;
    memw();
  }
  param_2[1] = 1;
LAB_400fdd85:
  param_2[2] = "andled.";
  iVar2 = *(int *)(param_1 + 0x50);
  param_2[3] = 0;
  if ((iVar2 < 8) && (param_2[2] = *(undefined4 *)(&DAT_3f40e16c + iVar2 * 4), iVar2 == 1)) {
    param_2[1] = 0;
    param_2[4] = 0x400fdbf0;
  }
  memw();
  return;
}

