// Function : FUN_401046a8
// Address  : 0x401046a8
// Size     : 81 bytes


undefined4 FUN_401046a8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0x224));
    if ((param_2 == 0) || (param_3 == 0)) {
      *(undefined4 *)(param_1 + 0x224) = 0;
      *(undefined4 *)(param_1 + 0x228) = 0;
      memw();
      return 0;
    }
    iVar1 = FUN_401052ac(param_2,param_3);
    *(int *)(param_1 + 0x224) = iVar1;
    if (iVar1 != 0) {
      *(int *)(param_1 + 0x228) = param_3;
      memw();
      return 0;
    }
  }
  return 0xffffffff;
}

