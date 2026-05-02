// Function : FUN_400f0d18
// Address  : 0x400f0d18
// Size     : 49 bytes


void FUN_400f0d18(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != param_2) {
    if (((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) &&
       (param_2 = (int *)*param_2, param_2 == (int *)0x0)) {
      FUN_400f0a38(param_1);
    }
    else {
      uVar1 = FUN_40184778();
      FUN_400f0bb0(param_1,param_2,uVar1);
    }
  }
  return;
}

