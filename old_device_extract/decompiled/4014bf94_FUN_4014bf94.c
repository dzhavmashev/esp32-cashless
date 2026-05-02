// Function : FUN_4014bf94
// Address  : 0x4014bf94
// Size     : 107 bytes


int FUN_4014bf94(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0x15 < (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14)) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    *param_2 = CONCAT11(*(undefined1 *)(iVar1 + 0xc),*(undefined1 *)(iVar1 + 0xd)) + 6;
    *(char *)(iVar1 + 0xc) = (char)*(undefined2 *)(iVar1 + 0x14);
    *(char *)(iVar1 + 0xd) = (char)((ushort)*(undefined2 *)(iVar1 + 0x14) >> 8);
    memw();
    memw();
    (*(code *)&SUB_4008b4c8)(iVar1 + 8,iVar1,0xe);
    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(*(int *)(param_1 + 4) + 4) + 8;
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -8;
    memw();
    iVar1 = param_1;
  }
  memw();
  return iVar1;
}

