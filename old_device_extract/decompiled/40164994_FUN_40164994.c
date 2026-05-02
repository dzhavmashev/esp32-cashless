// Function : FUN_40164994
// Address  : 0x40164994
// Size     : 77 bytes


bool FUN_40164994(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  puVar3 = *(undefined1 **)(param_1 + 0x60);
  iVar1 = FUN_40164858(*(undefined1 *)(param_1 + 1),*puVar3);
  iVar2 = 0x5a;
  uVar4 = (uint)(byte)puVar3[9];
  if ((uVar4 != 0) && (iVar2 = 100, 0x40 < uVar4)) {
    return 100U - iVar1 < param_2 && (uVar4 + 2) - iVar1 < param_2;
  }
  return (uint)(iVar2 - iVar1) < param_2;
}

