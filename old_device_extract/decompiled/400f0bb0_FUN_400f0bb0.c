// Function : FUN_400f0bb0
// Address  : 0x400f0bb0
// Size     : 53 bytes


void FUN_400f0bb0(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_400f0b60(param_1,param_3);
  if (iVar1 == 0) {
    FUN_400f0a38(param_1);
  }
  else {
    piVar2 = param_1;
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      piVar2 = (int *)*param_1;
    }
    func_0x4008b4d0(piVar2,param_2,param_3 + 1);
    FUN_40184790(param_1,param_3);
  }
  return;
}

