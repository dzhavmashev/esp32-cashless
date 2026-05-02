// Function : FUN_40133068
// Address  : 0x40133068
// Size     : 52 bytes


undefined4 FUN_40133068(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffff9f00;
  if (param_2 != 0) {
    (*(code *)&SUB_4008b530)(param_1,0,0x40);
    iVar1 = (**(code **)(*(int *)(param_2 + 0x1c) + 0x24))();
    param_1[0xf] = iVar1;
    uVar2 = 0xffff9e80;
    if (iVar1 != 0) {
      *param_1 = param_2;
      memw();
      FUN_40132fe8(param_1,0);
      uVar2 = 0;
    }
  }
  return uVar2;
}

