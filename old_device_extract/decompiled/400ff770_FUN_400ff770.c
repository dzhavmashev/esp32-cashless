// Function : FUN_400ff770
// Address  : 0x400ff770
// Size     : 39 bytes


int FUN_400ff770(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(&DAT_3f40e4e8 + param_1 * 4);
  iVar1 = *(int *)(iVar2 + 4);
  if (iVar1 == -1) {
    iVar1 = (**(code **)(iVar2 + 0x20))(param_1);
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 0xffffffff;
  }
  memw();
  return iVar1;
}

