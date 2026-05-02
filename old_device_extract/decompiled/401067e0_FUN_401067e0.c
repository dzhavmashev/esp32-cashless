// Function : FUN_401067e0
// Address  : 0x401067e0
// Size     : 118 bytes


int FUN_401067e0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  uVar2 = *(undefined4 *)(param_1 + 0x1bc);
  if (param_2 != 0) {
    memw();
    uVar1 = FUN_40106748(uVar2,0,param_2,param_4);
    *(undefined4 *)(param_1 + 0x1c0) = uVar1;
  }
  if ((*(int *)(param_1 + 0x1c0) == 0) && (param_3 != 0)) {
    memw();
    uVar1 = FUN_40106748(uVar2,param_3,0,param_4);
    *(undefined4 *)(param_1 + 0x1c0) = uVar1;
  }
  if (((*(int *)(param_1 + 0x1c0) == 0) && (param_5 != 0)) && (param_3 != 0)) {
    memw();
    uVar2 = FUN_40106788(uVar2,param_4,param_3);
    *(undefined4 *)(param_1 + 0x1c0) = uVar2;
  }
  memw();
  return -(uint)(*(int *)(param_1 + 0x1c0) == 0);
}

