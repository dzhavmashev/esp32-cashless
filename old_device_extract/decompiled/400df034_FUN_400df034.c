// Function : FUN_400df034
// Address  : 0x400df034
// Size     : 87 bytes


void FUN_400df034(int param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  
  do {
    iVar1 = FUN_400f3f80(*(undefined1 *)(param_1 + 0x24));
  } while (iVar1 != 0);
  (*(code *)&SUB_40008534)(0x68);
  (*(code *)&SUB_40008534)(0x34);
  uVar3 = 0;
  uVar2 = 0;
  do {
    iVar1 = FUN_400f3f80(*(undefined1 *)(param_1 + 0x24));
    uVar3 = (ushort)(iVar1 << 0x20 - (0x20 - (uVar2 & 0x1f))) | uVar3;
    uVar2 = uVar2 + 1;
    (*(code *)&SUB_40008534)(0x68);
  } while (uVar2 != 9);
  if (param_2 != (char *)0x0) {
    *param_2 = (char)uVar3 + *param_2;
  }
  return;
}

