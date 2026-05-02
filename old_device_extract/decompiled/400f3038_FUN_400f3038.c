// Function : FUN_400f3038
// Address  : 0x400f3038
// Size     : 64 bytes


int FUN_400f3038(undefined1 *param_1,int *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  if (*param_2 == 1) {
    uVar1 = FUN_400f2f4c((char)param_2[1]);
    *param_1 = uVar1;
    param_1[1] = 0x3d;
    param_1[2] = 0x3d;
    puVar2 = param_1 + 3;
  }
  else {
    puVar2 = param_1;
    if (*param_2 == 2) {
      uVar1 = FUN_400f2f4c((char)param_2[1]);
      *param_1 = uVar1;
      param_1[1] = 0x3d;
      puVar2 = param_1 + 2;
    }
  }
  *puVar2 = 0;
  return (int)puVar2 - (int)param_1;
}

