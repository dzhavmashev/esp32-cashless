// Function : FUN_400fae58
// Address  : 0x400fae58
// Size     : 124 bytes


int FUN_400fae58(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *local_24 [9];
  
  uVar1 = (*(code *)&SUB_4008c01c)(param_2);
  iVar2 = 0x102;
  if (uVar1 < 0x11) {
    iVar3 = FUN_400facd8(param_1,param_2);
    iVar2 = 0;
    if (iVar3 == 0) {
      local_24[0] = (int *)0x0;
      memw();
      iVar2 = FUN_400fc538(param_2,local_24);
      if (iVar2 == 0) {
        uVar1 = (**(code **)(*local_24[0] + 0x24))();
        iVar2 = FUN_400fad94(param_1,local_24[0],0,uVar1 >> 0xc);
        if (iVar2 == 0) {
          iVar3 = *(int *)(param_1 + 0x20);
          if (iVar3 != 0) {
            *(int **)(iVar3 + 8) = local_24[0];
          }
          local_24[0][2] = 0;
          local_24[0][1] = iVar3;
          *(int **)(param_1 + 0x20) = local_24[0];
          if (*(int *)(param_1 + 0x1c) == 0) {
            *(int **)(param_1 + 0x1c) = local_24[0];
          }
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          goto LAB_400faec0;
        }
      }
      if (local_24[0] != (int *)0x0) {
        (**(code **)(*local_24[0] + 4))();
      }
    }
  }
LAB_400faec0:
  memw();
  return iVar2;
}

