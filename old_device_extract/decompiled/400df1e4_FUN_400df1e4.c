// Function : FUN_400df1e4
// Address  : 0x400df1e4
// Size     : 68 bytes


void FUN_400df1e4(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = 0;
  memw();
  *(undefined1 *)(param_1 + 0x7c) = 1;
  uVar1 = 0;
  for (; iVar2 < (int)(param_3 & 0xff); iVar2 = iVar2 + 1) {
    uVar1 = *(byte *)(param_2 + iVar2) + uVar1 & 0xff;
    FUN_400df194(param_1,(ushort)*(byte *)(param_2 + iVar2));
  }
  FUN_400df194(param_1,uVar1 | 0x100);
  memw();
  *(undefined1 *)(param_1 + 0x7c) = 0;
  return;
}

