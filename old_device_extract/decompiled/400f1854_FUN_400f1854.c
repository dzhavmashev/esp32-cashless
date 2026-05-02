// Function : FUN_400f1854
// Address  : 0x400f1854
// Size     : 26 bytes


undefined4 FUN_400f1854(int *param_1)

{
  undefined4 uVar1;
  
  if (((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) &&
     (param_1 = (int *)*param_1, param_1 == (int *)0x0)) {
    return 0;
  }
  uVar1 = func_0x4008a420(param_1);
  return uVar1;
}

