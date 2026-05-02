// Function : FUN_400eea5c
// Address  : 0x400eea5c
// Size     : 155 bytes


void FUN_400eea5c(int *param_1)

{
  int iVar1;
  
  if ((int *)param_1[2] != (int *)0x0) {
    (**(code **)(*(int *)param_1[2] + 0x3c))();
  }
  iVar1 = param_1[0x23];
  if (iVar1 != 0) {
    iVar1 = iVar1 + *(int *)(iVar1 + -4) * 0x20;
    while (param_1[0x23] != iVar1) {
      FUN_400f0a50(iVar1 + -0x10);
      FUN_400f0a50(iVar1 + -0x20);
      iVar1 = iVar1 + -0x20;
    }
    FUN_4016fffc(iVar1 + -4);
  }
  if (param_1[1] != 0) {
    param_1[1] = 0;
    FUN_40184618();
  }
  if (*param_1 != 0) {
    *param_1 = 0;
    FUN_40184628();
  }
  FUN_400f0a50(param_1 + 0x2a);
  FUN_400f0a50(param_1 + 0x1f);
  FUN_400f0a50(param_1 + 0x1b);
  FUN_400f0a50(param_1 + 0x17);
  FUN_400f0a50(param_1 + 0x13);
  FUN_400f0a50(param_1 + 0xf);
  FUN_400f0a50(param_1 + 0xb);
  FUN_400f0a50(param_1 + 3);
  FUN_400ee804(param_1 + 1);
  FUN_400ee920(param_1);
  return;
}

