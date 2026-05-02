// Function : FUN_4014b9e0
// Address  : 0x4014b9e0
// Size     : 49 bytes


void FUN_4014b9e0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_4014b4e4(param_1,param_2);
  if (((*(uint *)(iVar1 + 0x158) & 0x1000000) != 0) && ((*(ushort *)(param_1 + 0x57) & 2) != 0)) {
    *(undefined1 *)(param_1 + 0x2b) = *(undefined1 *)(iVar1 + 0x157);
    memw();
  }
  memw();
  FUN_4014b690((int)param_1 + 0xab);
  return;
}

