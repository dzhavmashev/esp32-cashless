// Function : FUN_40139b8c
// Address  : 0x40139b8c
// Size     : 35 bytes


undefined4 FUN_40139b8c(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffc180;
  if ((param_2 != 0) && (*param_1 == 0)) {
    iVar1 = (**(code **)(param_2 + 0x24))();
    param_1[1] = iVar1;
    uVar2 = 0xffffc080;
    if (iVar1 != 0) {
      *param_1 = param_2;
      uVar2 = 0;
    }
  }
  memw();
  return uVar2;
}

