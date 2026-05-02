// Function : FUN_40186ad0
// Address  : 0x40186ad0
// Size     : 41 bytes


undefined4 FUN_40186ad0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xa0);
  iVar1 = *(int *)(iVar2 + 4);
  *(int *)(*(int *)(param_2 + 4) + 4) = *(int *)(*(int *)(param_2 + 4) + 4) + param_3 + iVar1;
  *(short *)(param_2 + 0x16) =
       *(short *)(param_2 + 0x16) - ((short)*(undefined4 *)(iVar2 + 8) + (short)iVar1);
  memw();
  memw();
  return 1;
}

