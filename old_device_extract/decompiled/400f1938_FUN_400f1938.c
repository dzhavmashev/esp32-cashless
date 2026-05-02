// Function : FUN_400f1938
// Address  : 0x400f1938
// Size     : 35 bytes


void FUN_400f1938(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    piVar1 = (int *)*param_2;
    uVar2 = 0;
    if (piVar1 != (int *)0x0) {
      uVar2 = param_2[2];
    }
  }
  else {
    uVar2 = (uint)param_2[3] >> 0x18 & 0x7f;
    piVar1 = param_2;
  }
  FUN_400f188c(param_1,piVar1,uVar2);
  return;
}

