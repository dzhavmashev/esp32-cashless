// Function : FUN_40146b04
// Address  : 0x40146b04
// Size     : 193 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40146b04(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_40155000();
  iVar2 = FUN_40155040();
  iVar2 = (iVar1 - iVar2) + 1;
  iVar1 = FUN_40155068();
  if (param_1 == 0) {
    iVar5 = 0x168;
    iVar4 = 0x78;
LAB_40146bba:
    if (iVar1 == 0) {
      iVar1 = iVar4 * 0xb + iVar5 * 3;
    }
    else {
      iVar1 = iVar2 * iVar4;
    }
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x14);
    iVar4 = 0x78;
    if (uVar3 != 0) {
      iVar4 = (uVar3 < 0x5dc) * uVar3 + (uint)(uVar3 >= 0x5dc) * 0x5dc;
    }
    uVar3 = *(uint *)(param_1 + 0x18);
    iVar5 = 0x168;
    if (uVar3 != 0) {
      iVar5 = (uVar3 < 0x5dc) * uVar3 + (uint)(uVar3 >= 0x5dc) * 0x5dc;
    }
    if (*(int *)(param_1 + 0xc) != 1) goto LAB_40146bba;
    iVar1 = iVar5 * iVar2;
  }
  if ((_DAT_3ffc8804 == 0) && ((_DAT_3ffc8800 == 0 || (*(int *)(_DAT_3ffc8800 + 0xe4) == 0))))
  goto LAB_40146b91;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      if (iVar4 <= (int)(uint)*(byte *)(_DAT_3ffc87f4 + 0x118)) goto LAB_40146b91;
    }
    else if ((*(int *)(param_1 + 0xc) != 1) ||
            (iVar5 <= (int)(uint)*(byte *)(_DAT_3ffc87f4 + 0x118))) goto LAB_40146b91;
  }
  iVar1 = iVar1 + (uint)*(byte *)(_DAT_3ffc87f4 + 0x118) * iVar2;
LAB_40146b91:
  return (iVar2 * 500 + iVar1 + 200) / 100;
}

