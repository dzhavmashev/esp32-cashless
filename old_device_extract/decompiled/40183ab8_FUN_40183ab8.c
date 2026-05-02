// Function : FUN_40183ab8
// Address  : 0x40183ab8
// Size     : 66 bytes


int FUN_40183ab8(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_2 + 8);
  if (uVar2 < *(int *)(param_2 + 4) + 0x10U) {
    *(undefined1 *)(param_2 + 0x10) = 1;
    iVar3 = 0;
  }
  else {
    iVar3 = uVar2 - 0x10;
    *(int *)(param_2 + 8) = iVar3;
    if (iVar3 != 0) {
      iVar1 = param_1[1];
      if (iVar1 == 0) {
        *param_1 = iVar3;
      }
      else {
        *(short *)(iVar1 + 10) = (short)(iVar3 - iVar1 >> 4);
      }
      param_1[1] = iVar3;
      *(undefined2 *)(uVar2 - 6) = 0;
      *(undefined1 *)(uVar2 - 8) = 0;
      *(undefined4 *)(uVar2 - 4) = 0;
    }
  }
  return iVar3;
}

