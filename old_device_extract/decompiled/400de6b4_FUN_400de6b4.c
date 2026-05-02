// Function : FUN_400de6b4
// Address  : 0x400de6b4
// Size     : 82 bytes


void FUN_400de6b4(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = 0;
  memw();
  *(undefined1 *)(param_1 + 0x97) = 1;
  uVar1 = 0;
  for (; iVar2 < (int)(param_3 & 0xff); iVar2 = iVar2 + 1) {
    uVar1 = *(byte *)(param_2 + iVar2) + uVar1 & 0xff;
    FUN_400de664(param_1,(ushort)*(byte *)(param_2 + iVar2));
  }
  memw();
  memw();
  *(int *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + 1;
  FUN_400de664(param_1,uVar1 | 0x100);
  memw();
  *(undefined1 *)(param_1 + 0x97) = 0;
  return;
}

