// Function : FUN_400efe04
// Address  : 0x400efe04
// Size     : 37 bytes


undefined4 FUN_400efe04(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    param_2 = (int *)*param_2;
  }
  uVar1 = (*(code *)&LAB_40183a7b_1)();
  uVar1 = FUN_400efdec(param_1,param_2,uVar1);
  return uVar1;
}

